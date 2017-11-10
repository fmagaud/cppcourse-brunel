#include "neuron.h"
#include <cmath>

//-----------------------------CONSTRUCTOR----------------------------//
Neuron::Neuron(bool excitatory, double dt, unsigned int Delay_Steps, unsigned int Refractory_Time_Steps, double Vthr, double Vreset, double JE, double JI, double J, double TAU, double R, double Iext)
: dt_(dt), Delay_Steps_(Delay_Steps), Refractory_Time_Steps_(Refractory_Time_Steps)
, Vthr_(Vthr), Vreset_(Vreset)
, JE_(JE), JI_(JI), J_(J)
, TAU_(TAU), R_(R)
, excitatory_(excitatory), membrane_potential_(0.0), refractory_(false), Iext_(Iext)
, time_(0)
, nb_of_spikes_(0)
, size_of_buffer_(Delay_Steps+1), current_index_(0)
{
	for (unsigned int i(0); i<size_of_buffer_+1 ; ++i) {
		signals_buffer_.push_back(0.0);
	}
}

//-------------------------------GETTERS------------------------------//
double Neuron::get_membrane_potential() const
{
	return membrane_potential_;
}

int Neuron::get_nb_of_spikes() const
{
	return nb_of_spikes_;
}

unsigned int Neuron::get_nb_of_signals(unsigned int buffer_index) const
{
	return signals_buffer_[buffer_index];
}

//--------------------------------SETTERS-----------------------------//
void Neuron::set_Iext(double Iext)
{
	Iext_ = Iext;
}

//--------------------------------UPDATE------------------------------//
bool Neuron::update(unsigned long T, unsigned int random_input)
{
	unsigned int t(T-time_);
	
	//update of the signals
	signals_update(t);
	
	//calculation of the new membrane potential
	membrane_update(t, random_input);
	
	bool spike(false);
	
	//a spike appears
	if (membrane_potential_ > Vthr_) {
		spike_update(T);
		spike = true;
	}
	
	//update of time
	time_ = T;
	
	return spike;
}

bool Neuron::add_signals()
{
	bool spike(false);
	
	if (not refractory_) {
		//modifying the membrane potential, counting the signals received
		membrane_potential_ += signals_buffer_[current_index_]*J_;
		
		//checking new spikes
		if (membrane_potential_ > Vthr_) {
			spike_update(time_);
			spike = true;
		}
	}
	signals_buffer_[current_index_] = 0;
	
	return spike;
}

void Neuron::signals_update(unsigned int t)
{
	//we're still in the array
	if (current_index_+t<size_of_buffer_) { 
		current_index_ = current_index_+t;
		
		//this part never occurs in our case, can be uncommented if needed
		/*if (t>1) {
			for (unsigned int i(current_index_-t); i<current_index_ ; ++i) {
				signals_buffer_[current_index_] += signals_buffer_[i];
				signals_buffer_[i] = 0;
			}
		}*/
	
	//we're out of the array	
	} else { 
		current_index_ = current_index_+t-size_of_buffer_;
		
		//this part never occurs in our case, can be uncommented if needed
		/*if (t>1) {
			for (unsigned int i(current_index_-t+size_of_buffer_); i<size_of_buffer_ ; ++i) {	//end of the array
				signals_buffer_[current_index_] += signals_buffer_[i];
				signals_buffer_[i] = 0;
			}
			for (unsigned int i(0); i<current_index_ ; ++i) {	//we go back to the begining of the array
				signals_buffer_[current_index_] += signals_buffer_[i];
				signals_buffer_[i] = 0;
			}
		}*/
	}
}

void Neuron::membrane_update(unsigned int t, unsigned int random_input)
{
	if (not refractory_) {
		membrane_potential_ = equation(t) + J_*signals_buffer_[current_index_] + J_*random_input;
	} else {
		if ((t+time_ - spike_times_.back()) >= Refractory_Time_Steps_) {
			refractory_ = false;
			membrane_potential_ = equation(t) + J_*signals_buffer_[current_index_] + J_*random_input;
		}
	}
	signals_buffer_[current_index_] = 0;
}

void Neuron::spike_update(unsigned long T)
{
	nb_of_spikes_ += 1;
	spike_times_.push_back(T);
	refractory_ = true;
	membrane_potential_ = Vreset_;
}

//--------------------------OTHER-METHODS-----------------------------//

void Neuron::receive_signal(unsigned long T, bool excitatory)
{
	unsigned int delay(Delay_Steps_ + T-time_);
	
		//we're still in the array
	if (current_index_+delay<size_of_buffer_) {
		if (excitatory) {
			signals_buffer_[current_index_+delay] += JE_;
		} else {
			signals_buffer_[current_index_+delay] += JI_;
		}
		
		//we're out of the array
	} else {
		if (excitatory) {
			signals_buffer_[current_index_+delay-size_of_buffer_] += JE_;
		} else {
			signals_buffer_[current_index_+delay-size_of_buffer_] += JI_;
		}
	}
}

double Neuron::equation(unsigned int t) const
{
	double exponential(exp(-(t*dt_)/TAU_));
	return exponential * membrane_potential_ + Iext_*R_*(1-exponential);
}

void Neuron::printSpikes() const
{
	std::cout << nb_of_spikes_ << " spikes : ";
	for (unsigned int i(0); i < nb_of_spikes_ ; ++i) {
		std::cout << spike_times_[i] * dt_ << '\t';
	}
	std::cout << std::endl;
}

//---------------------------DESTRUCTOR-------------------------------//
Neuron::~Neuron()
{}
