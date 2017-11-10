#ifndef SIMULATION_H
#define SIMULATION_H
#include <iostream>
#include <fstream>
#include "brain.h"

class Simulation {
	public:
	///CONSTRUCTOR
	/**
      \param NE is the number of excitatory neurons wanted for the simulation.
      \param NI is the number of inhibitory neurons wanted for the simulation.
      \param dt is the time step for each update in ms.
      \param t_stop is the length of the simulation in ms (the simulation will end when it reaches t_stop).
      \param g is a conception parameter, it is the positive ratio of JI/JE.
      \param ETA is a conception parameter, it is the ratio for one connection and one second of v_ext/v_thr.
    */
	Simulation(unsigned long NE, unsigned long NI, double dt, double t_stop, double g, double ETA);
	
		//getters
	///getter for the CE constant (number of excitatory connections received by each neuron).
	/**
      \return CE_.
    */
	unsigned long get_CE() const;
	
	///getter for the CI constant (number of inhibitory connections received by each neuron).
	/**
      \return CI_.
    */
	unsigned long get_CI() const;
	
	///getter for the Delay_Step constant (delay for a neuron to transmit a signal in number of time steps).
	/**
      \return Delay_Steps_.
    */
	unsigned int get_Delay_Steps() const;
	
	///getter for the Refractory_Time_Steps constant (refractrory time for the neurons (they don't have any activity during this time after spiking) in number of time steps).
	/**
      \return Refractory_Time_Steps_.
    */
	unsigned int get_Refractory_Time_Steps() const;
	
	///getter for the JI constant (potential transmited when an inhibitory neuron has a spike in number of J_).
	/**
      \return JI_.
    */
	double get_JI() const;
	
	///getter for the R constant (resistance of the neuron membrane).
	/**
      \return R_.
    */
	double get_R() const;
	
	///getter for the v_ext constant (the frequency of the external input needed to reach Vthr).
	/**
      \return v_ext_.
    */
	double get_v_ext() const;
	
		//run
	///run the simulation from time = 0 to time = t_stop with a time step of dt_
	/**
      \param file is the file in which the data are printed
    */
	void run(std::ofstream& file);
	
	///DESTRUCTOR
	~Simulation();
	
	private:
		//Parameters
	const unsigned long NE_; /**< number of excitatory neurons */
	const unsigned long NI_; /**< number of inhibitory neurons */
	const unsigned long CE_; /**< number of excitatory connections received by each neuron */
	const unsigned long CI_; /**< number of inhibitory connections received by each neuron */

	const double dt_; /**< time step */	
	
	const double D_ = 1.5; /**< delay to transmit a signal in ms */	
	const unsigned int Delay_Steps_ = static_cast<int>(D_*10) / static_cast<int>(dt_*10); /**< delay in number of time steps */
	
	const double Refractory_Time_ = 2.0; /**< time (ms) after a spike during which the neuron won't have any activity */
	const unsigned int Refractory_Time_Steps_ = static_cast<int>(Refractory_Time_*10) / static_cast<int>(dt_*10); /**< refractrory time in number of time steps */
	
	const double Vthr_ = 20.0; /**< potential (mV) to exceed for a spike to appear */
	const double Vreset_ = 0.0; /**< initial and refractory potential (mV) */
	
	const double g_; /**< positive ratio of JI/JE */
	const double JE_ = 1.0; /**< potential transmited when an excitatory neuron has a spike in number of J_ */ 
	const double JI_ = -g_ * JE_; /**< potential transmited when an inhibitory neuron has a spike in number of J_ */ 
	const double J_ = 0.1; /**< (mV) */
	
	const double TAU_ = 20.0; /**< membrane time constant (ms) */
	const double C_ = 1.0; /**< constant */
	const double R_ = TAU_/C_; /**< resistance of the membrane */
	
	const double ETA_; /**< ratio for one connection and one second of v_ext/v_thr */
	const double v_ext_ = ETA_*Vthr_*dt_ / (J_*TAU_) ; /**< the frequency of the external input needed to reach Vthr */
	
		//Time
	unsigned long clock_; /**< clock */
	unsigned long Tstop_; /**< length of the simulation */
	
		//Brain
	Brain brain_; /**< brain of the simulation */
};

#endif
