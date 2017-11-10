#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>

class Neuron {
	public:
	///CONSTRUCTOR
	/**
      \param excitatory is a boolean which says if the neuron is excitatory or not.
      \param dt is the time step for each update in ms.
      \param Delay_Steps is the delay to receive a signal in number of time steps.
      \param Refractory_Time_Steps is the refractrory time for the neurons (they don't have any activity during this time after spiking) in number of time steps.
      \param Vthr is the potential (mV) to exceed for a spike to appear.
      \param Vreset is the initial and refractory potential (mV).
      \param JE is the potential transmited when an excitatory neuron has a spike in number of J.
      \param JI is the potential transmited when an inhibitory neuron has a spike in number of J.
      \param J is the "potential step" transmitted between neurons in mV.
      \param TAU is the membrane time constant (ms).
      \param R is the neuron membrane resistance.
      \param Iext is the external current received by the neuron.
    */
	Neuron(bool excitatory, double dt = 0.1, unsigned int Delay_Steps = 15, unsigned int Refractory_Time_Steps = 20, double Vthr = 20.0, double Vreset = 0.0, double JE = 1.0, double JI = -5.0, double J = 0.1, double TAU = 20, double R = 20.0, double Iext = 0);
	
		//getters
	///getter for the membrane potential.
	/**
      \return the membrane potential in mV.
    */
	double get_membrane_potential() const;
	
	///getter for the number of spikes.
	/**
      \return the number of spikes that the neuron had since the begining of the simulation.
    */
	int get_nb_of_spikes() const;
	
	///getter for the number of signals at a certain index in the signals_buffer.
	/**
	  \param buffer_index is the index of the signals_buffer where we will look for the number of signals received.
	  \return the number of signals received at this index.
	*/
	unsigned int get_nb_of_signals(unsigned int buffer_index) const;
	
		//setters
	///setter for the external current received.
	/**
	  \param Iext is the external current in A.
	*/
	void set_Iext(double Iext);
	
		//update
	///updates the neuron with time T, calculate a new membrane potential and see if there is a spike.
	/**
      \param T is the new time (in numer of steps).
      \param random_input is a random number of excitatory signals received from "outside" the brain.
      \return a boolean which says if the neurons has spikes during the update.
    */
	bool update(unsigned long T, unsigned int random_input);
	
	///take the number of signals received for the current time into account to calculate the new membrane potential.
	/**
      \return a boolean which says if the neurons has spikes because of received signals.
    */
	bool add_signals();
	
	///updates the current index for the signals_buffer and if some time steps have been skiped, add the signals received for the current time.
	/**
      \param t is the number of time steps since the last update (usually 1).
    */
	void signals_update(unsigned int t);
	
	///updates the membrane potential.
	/**
      \param t is the number of time steps since the last update (usually 1).
      \param random_input is a random number of excitatory signals received from "outside" the brain.
    */
	void membrane_update(unsigned int t, unsigned int random_input);
	
	///upates the neuron as a result of a spike.
	/**
      \param T is the new time (in numer of steps).
    */
	void spike_update(unsigned long T);
	
		//other methods
	///add in the appropriate index in the signals_ vector the signal received (JE or JI).
	/**
      \param T is the time of the transmitter neuron when it had the spike.
      \param excitatory is a boolean which says if the transmitter neuron is excitatory or not.
    */
	void receive_signal(unsigned long T, bool excitatory);
	
	///calculate the equation : exp(-(t*dt_)/TAU_) * membrane_potential_ + Iext_*R_*(1- exp(-(t*dt_)/TAU_))
	/**
	  \param t is the number of time steps since the last update (usually 1).
	  \return the result of the calculation.
	*/
	double equation(unsigned int t) const;
	
	///print the number of spikes.
	void printSpikes() const; 
	
	///DESTRUCTOR
	~Neuron();
	
	private:
		//Parameters
	const double dt_; /**< time step */
	const unsigned int Delay_Steps_; /**< delay to receive a signal in number of time steps */
	const unsigned int Refractory_Time_Steps_; /**< time (in number of time steps) after a spike during which the neuron won't have any activity */
	
	const double Vthr_; /**< potential (mV) to exceed for a spike	to appear */
	const double Vreset_; /**< initial and refractory potential (mV) */
	
	const double JE_; /**< potential transmited when an excitatory neuron has a spike in number of J_ */ 
	const double JI_; /**< potential transmited when an inhibitory neuron has a spike in number of J_ */ 
	const double J_; /**< (mV) */

	const double TAU_; /**< constant (ms) */
	const double R_; /**< resistance of the membrane */
	
		//Basic attributs
	const bool excitatory_; /**< a boolean saying if the neuron is excitatory or not */
	double membrane_potential_; /**< the membrane potential in mV */
	bool refractory_; /**< a boolean saying if the neuron is currently refractory which means that it doesn't have any activity (membrane potential = 0) */	
	double Iext_; /**< the external current received by the neuron */
	
		//Time
	unsigned long time_; /**< clock */
	
		//Spikes
	unsigned int nb_of_spikes_; /**< the number of spikes that the neuron had since the begining of the simulation */
	std::vector<unsigned long> spike_times_; /**< vector containing the times of every spike since the beginning of the simulation */
		
		//Signals received
	std::vector<double> signals_buffer_; /**< array containing the number of JE received from other neurons for a specific time step */
	const unsigned int size_of_buffer_; /**< size of the vector signals_ */
	unsigned int current_index_; /**< indicate the index in signals_ corresponding to the current time step */
};

#endif
