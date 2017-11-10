#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>
#include <vector>
#include "neuron.h"

class Brain {
	public:
	///CONSTRUCTOR
	/**
      \param NE is the number of excitatory neurons wanted.
      \param NI is the number of inhibitory neurons wanted.
      \param CE is the number of excitatory connections received by each neuron.
      \param CI is the number of inhibitory connections received by each neuron.
      \param dt is the time step for each update in ms.
      \param v_ext is the frequency of the external input needed to reach Vthr.
      \param Delay_Steps is the delay for a neuron to transmit a signal in number of time steps.
      \param Refractory_Time_Steps is the refractrory time for the neurons (they don't have any activity during this time after spiking) in number of time steps.
      \param Vthr is the potential (mV) to exceed for a spike to appear.
      \param Vreset is the initial and refractory potential (mV).
      \param JE is the potential transmited when an excitatory neuron has a spike in number of J.
      \param JI is the potential transmited when an inhibitory neuron has a spike in number of J.
      \param J is the "potential step" transmitted between neurons in mV.
      \param TAU is the membrane time constant (ms).
      \param R is the neuron membrane resistance.
    */
	Brain(unsigned long NE, unsigned long NI, unsigned long CE = 0, unsigned long CI = 0, double dt = 0.1, double v_ext = 2.0, unsigned int Delay_Steps = 15, unsigned int Refractory_Time_Steps = 20, double Vthr = 20.0, double Vreset = 0.0, double JE = 1.0, double JI = -5.0, double J = 0.1, double TAU = 20, double R = 20.0);
	
		//getters
	///getter for the number of neurons.
	/**
	  \return the number of neurons in the brain.
	*/
	unsigned long get_nb_neurons() const;
	
	///getter for the number of excitatory neurons.
	/**
	  \return the number of excitatory neurons in the brain.
	*/
	unsigned long get_nb_excitatory() const;
	
	///getter for the number of inhibitory neurons.
	/**
	  \return the number of inhibitory neurons in the brain.
	*/
	unsigned long get_nb_inhibitory() const;
	
	///getter for a precise neuron.
	/**
	  \param neuron_index is the index of the neuron wanted.
	  \return the neuron with the index given.
	*/
	const Neuron& get_neuron(unsigned long neuron_index);
	
		//update
	///updates every neurons with time T and handles the signals sent
	/**
      \param T is the new time (in numer of steps).
      \param file is the file in which the data will be save if there are somme spikes.
    */
	void update(unsigned long T, std::ostream& file);
	
		//other methods
	///send signals to the receiver neurons of the transmitter neuron given.
	/**
	  \param transmitter_neuron is the index of the neuron that send signals.
	  \param T is the sending time.
	*/
	void send_signals(unsigned long transmitter_neuron, unsigned long T);
	
	///create a connection between 2 given neurons.
	/**
	  \param transmitter_neuron is the index of the transmitter neuron.
	  \param receiver_neuron is the index of the receiver neuron.
	*/
	void add_connection(unsigned long transmitter_neuron, unsigned long receiver_neuron);
	
	///returns the number of connections from a given transmitter neuron to a given receiver neuron.
	/**
	  \param transmitter_neuron is the index of the transmitter neuron.
	  \param receiver_neuron is the index of the receiver neuron.
	  \return the number of connections.
	*/
	unsigned int is_connected(unsigned long transmitter_neuron, unsigned long receiver_neuron) const;
	
	///print on the terminal the time and for each neuron its number, its membrane potential and its number of spikes.
	void print() const;
	
	///DESTRUCTOR
	~Brain();
	
	private:
		//Parameters
	const unsigned long nb_neurons_; /**< number of neurons */
	const unsigned long NE_; /**< number of excitatory neurons */
	
	const double dt_; /**< time step */
	const unsigned int Delay_Steps_; /**< delay to receive a signal in number of time steps */
	
	const double v_ext_; /**< the frequency of the external input needed to reach Vthr */
	
		//Time
	unsigned long time_; /**< clock */
	
		//Neurons
	std::vector<Neuron> neurons_; /**< a vector containing every neurons: first the excitatory and second the inhibitory */
	
		//Connections
	std::vector<std::vector<unsigned long>> network_; /**< a vector containing for each neuron a vector with the index of the neurons they send signals to */
};

#endif
