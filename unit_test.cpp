#include <iostream>
#include "neuron.h"
#include "brain.h"
#include "simulation.h"
#include "gtest/gtest.h"

TEST (NeuronTest, MembranePotential){
	Neuron neuron(true, 0.1);
	neuron.set_Iext(1);
	
	neuron.update(1, 0);
	EXPECT_EQ(1*20.0*(1.0-std::exp(-0.1/20.0)), neuron.get_membrane_potential());
}

TEST (NeuronTest, SpikeTimes) {
	Neuron neuron(true, 0.1);
	neuron.set_Iext(1.01);
	
	for (unsigned long i(1); i<924 ; ++i) {
		neuron.update(i, 0);
	}
	EXPECT_EQ(0, neuron.get_nb_of_spikes());
	
	neuron.update(924, 0);
	EXPECT_EQ(1, neuron.get_nb_of_spikes());
	EXPECT_EQ(0.0, neuron.get_membrane_potential());
	
	for (unsigned long i(925); i<(924+943) ; ++i) {
		neuron.update(i, 0);
	}
	EXPECT_EQ(1, neuron.get_nb_of_spikes());
	
	neuron.update(924+943, 0);
	EXPECT_EQ(2, neuron.get_nb_of_spikes());
}

TEST (BrainTest, NumberOfNeurons){
	Brain brain(1000, 250);
	EXPECT_EQ(1250, brain.get_nb_neurons());
}

TEST (BrainTest, NumberOfExcitatory){
	Brain brain(1000, 250);
	EXPECT_EQ(1000, brain.get_nb_excitatory());
}

TEST (BrainTest, NumberOfInhibitory){
	Brain brain(1000, 250);
	EXPECT_EQ(250, brain.get_nb_inhibitory());
}

TEST (BrainTest, ExcitatorySignal){
	Brain brain(1, 1);
	brain.add_connection(0, 1);
	brain.send_signals(0, 0);
	
	EXPECT_EQ(1, (brain.get_neuron(1)).get_nb_of_signals(15));
}

TEST (BrainTest, InhibitorySignal){
	Brain brain(1, 1);
	brain.add_connection(1, 0);
	brain.send_signals(1,0);
	
	EXPECT_EQ(-5, (brain.get_neuron(0)).get_nb_of_signals(15));
}

TEST (BrainTest, Connections){
	Brain brain(10000, 2500, 1000, 250);
	unsigned long CE(0);
	unsigned long CI(0);
	
	static std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_int_distribution<> random_neuron(0, 12499);
	
	unsigned long receiver_neuron(random_neuron(generator));
	
	for (unsigned long i(0) ; i<12500 ; ++i) {
		if (i<10000) {
			CE += brain.is_connected(i, receiver_neuron); 
		} else {
			CI += brain.is_connected(i, receiver_neuron);
		}
	}
	
	EXPECT_EQ(1000, CE);
	EXPECT_EQ(250, CI);
}

TEST (SimulationTest, ConstantValues){
	Simulation sim(10000, 2500, 0.1, 0, 4.5, 0.9);
	
	EXPECT_EQ(1000, sim.get_CE());
	EXPECT_EQ(250, sim.get_CI());
	
	EXPECT_EQ(15, sim.get_Delay_Steps());
	EXPECT_EQ(20, sim.get_Refractory_Time_Steps());
	
	EXPECT_EQ(-4.5, sim.get_JI());
	EXPECT_EQ(20.0, sim.get_R());
	
	EXPECT_EQ(0.9, sim.get_v_ext());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
} 
