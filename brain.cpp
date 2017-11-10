#include "brain.h"
#include <cmath>
#include <random>

//----------------------------CONSTRUCTOR-----------------------------//
Brain::Brain(unsigned long NE, unsigned long NI, unsigned long CE, unsigned long CI, double dt, double v_ext, unsigned int Delay_Steps, unsigned int Refractory_Time_Steps, double Vthr, double Vreset, double JE, double JI, double J, double TAU, double R)
: nb_neurons_(NE + NI), NE_(NE), dt_(dt), Delay_Steps_(Delay_Steps), v_ext_(v_ext), time_(0)
{
	//creation of neurons and connections between them
	static std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_int_distribution<> random_excitatory(0, NE_-1);
	std::uniform_int_distribution<> random_inhibitory(NE_, nb_neurons_-1);
	
	for(unsigned int j(0); j<nb_neurons_ ; ++j) {
		std::vector<unsigned long> transmitter_neuron;
		network_.push_back(transmitter_neuron);
	}
	
	for (unsigned int i(0) ; i < nb_neurons_ ; ++i) {
		 //NEURONS
		if (i<NE_) {
			//creation of nb_excitatory neurons (from 0 to nb_excitatory-1 )
			neurons_.push_back(Neuron(true, dt_, Delay_Steps_, Refractory_Time_Steps, Vthr, Vreset, JE, JI, J, TAU, R));
		} else {
			//creation of nb_inhibitory neurons (from nb_excitatory to nb_neurons )
			neurons_.push_back(Neuron(false, dt, Delay_Steps_, Refractory_Time_Steps, Vthr, Vreset, JE, JI, J, TAU, R));
		}
		
		//CONNECTIONS
		//creation of CE random connections between the receiver neurons (i) and excitatory neurons (random)
		for(unsigned int k(0) ; k<CE ; ++k) {
			network_[random_excitatory(generator)].push_back(i);
		}
		//creation of CI random connections between the receiver neurons (i) and inhibitory neurons (random)
		for(unsigned int k(0) ; k<CI ; ++k) {
			network_[random_inhibitory(generator)].push_back(i);
		}
	}
}

//------------------------------GETTERS-------------------------------//
unsigned long Brain::get_nb_neurons() const
{
	return nb_neurons_;
}

unsigned long Brain::get_nb_excitatory() const
{
	return NE_;
}

unsigned long Brain::get_nb_inhibitory() const
{
	return nb_neurons_ - NE_;
}

const Neuron& Brain::get_neuron(unsigned long neuron_index)
{
	return neurons_[neuron_index];
}

//--------------------------------UPDATE------------------------------//
void Brain::update(unsigned long T, std::ostream& file)
{
	//poisson distribution
	static std::random_device rd;
	static std::mt19937 generator(rd());
	std::poisson_distribution<> random_input(v_ext_);
	
	//update(T) de chaque neurone //stockage des spikes dans un vector de taille nb_neurones
	for (unsigned long i(0) ; i<nb_neurons_ ; ++i) {
		bool spike = neurons_[i].update(T, random_input(generator));
		
		//send signals and save the data if there is a spike
		if (spike) {
			send_signals(i, T);
			file << T*dt_ << '\t' << i << '\n';
		}
	}
	
	//this part never occurs because or delay_steps=15 : in one step time no neuron will receive a signal from "this" update for "this" time
	if (Delay_Steps_<1) {
		bool s;
		do {
			s = false;
			//check for each neuron if they received new signals after they updated
			for (unsigned int i(0) ; i<nb_neurons_ ; ++i) {
				bool spike = neurons_[i].add_signals();
				if (spike) {
					s = true;
					if (i<NE_) {
						for (auto receiver_neuron : network_[i]) {
							neurons_[receiver_neuron].receive_signal(T, true);
						}
					} else {
						for (auto receiver_neuron : network_[i]) {
							neurons_[receiver_neuron].receive_signal(T, false);
						}
					}
				}
			}
		} while (s);
	}
	
	//update du time
	time_ = T;
}

//---------------------------OTHER-METHODS----------------------------//
void Brain::send_signals(unsigned long transmitter_neuron, unsigned long T)
{
	if (transmitter_neuron<NE_) {
		for (auto receiver_neuron : network_[transmitter_neuron]) {
			neurons_[receiver_neuron].receive_signal(T, true);
		}
	} else {
		for (auto receiver_neuron : network_[transmitter_neuron]) {
			neurons_[receiver_neuron].receive_signal(T, false);
		}
	}
}

void Brain::add_connection(unsigned long transmitter_neuron, unsigned long receiver_neuron)
{
	if (transmitter_neuron<nb_neurons_ and receiver_neuron<nb_neurons_) {
		network_[transmitter_neuron].push_back(receiver_neuron);
	}
}

unsigned int Brain::is_connected(unsigned long transmitter_neuron, unsigned long receiver_neuron) const
{
	unsigned int nb_connections(0);
	
	for (auto n : network_[transmitter_neuron]) {
		if (n == receiver_neuron) {
			++nb_connections;
		}
	}
	
	return nb_connections;
}

void Brain::print() const
{	
	for (unsigned int i(0); i<nb_neurons_ ; ++i) {
		std::cout << "Neuron " << i+1 << " : V(" << time_*dt_ << ") = " << neurons_[i].get_membrane_potential() << "	Spikes = " << neurons_[i].get_nb_of_spikes() << '\n';
	}
}	

//---------------------------DESTRUCTOR-------------------------------//
Brain::~Brain()
{}
