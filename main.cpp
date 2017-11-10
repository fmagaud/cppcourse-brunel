#include "simulation.h"
#include <iostream>
#include <fstream>

int main()
{
	double t_stop;
	std::cout << "How long is the simulation (ms)? ";
	std::cin >> t_stop;
	while (t_stop < 0.0) {
		std::cout << "The simulation length can not be negative." << std::endl << "How long is the simulation (ms)? ";
		std::cin >> t_stop;
	}
	
	double dt;
	std::cout << "What is the simulation step (ms)? ";
	std::cin >> dt;
	while (dt <= 0.0) {
		std::cout << "The simulation step has to be strictly positive." << std::endl << "What is the simulation step (ms)? ";
		std::cin >> dt;
	}
	
	double g;
	std::cout << "What is the g parameter? ";
	std::cin >> g;
	while (g <= 0.0) {
		std::cout << "The g parameter has to be strictly positive." << std::endl << "What is the g parameter? ";
		std::cin >> g;
	}
	
	double ETA;
	std::cout << "What is the ETA parameter? ";
	std::cin >> ETA;
	while (ETA < 0.0) {
		std::cout << "The ETA parameter has to be positive." << std::endl << "What is the ETA parameter? ";
		std::cin >> ETA;
	}
	
	//creation of the simulation
	Simulation sim(10000, 2500, dt, t_stop, g, ETA);
	
	std::cout << "GO!!!" << std::endl;
	
	//running the simulation and saving the data in the file "spikes.txt"
	std::ofstream file;
	file.open("spikes.txt");
	
	sim.run(file);
	
	file.close();
	
	std::cout << "Done" << std::endl;
	
	return 0;
}
