	A. Presentation of the program:

This program can simulate a cortical activity following N. BRUNEL’s model and produce a file which contains the time and the neuron’s number of each spike that occurred during the simulation. This data can be used to create a graph.

The cortex contains 10000 excitatory neurons and 2500 inhibitory neurons.
Each neuron has a membrane potential and when they reach a certain value they spike and send a potential JE or JI (whether they’re excitatory or inhibitory) to the neurons they’re connected to. A random background noise is produced: each neuron receives a random number of JE.

The user can choose:
 - the time of simulation (in ms)
 - the time step (in ms)
 - 2 parameters of the model: g which is the JI/JE ratio and ETA which is the rate of the background noise (it is used to produce the random numbers of JE received)

To modifiy the other parameters, they can be changed through the attributes of the class Simulation in the file "simulation.h”.

	B. Compilation:
	
The program is compiled with cMake. To do so, the command:
	“cmake ..” and then "make"
must be thrown from the repertory “build”.

	C. Utilisation:

To run the program, the command:
	“./simulation”
must be thrown from the repertory “build”.
   
Once the program has started, the user will be asked to give:
 - the time of simulation (in ms)
 - the time step (in ms)
 - the g parameter
 - the ETA parameter

To obtain the 4 graphs present in the BRUNEL paper, the values for g and ETA are:
 - figure A: g=3, ETA=2
 - figure B: g=6, ETA=4
 - figure C: g=5, ETA=2
 - figure D: g=4.5, ETA=0.9

When the program is done, the data can be found in the “spikes.txt” file, located in the “build” repertory.
A graph can be drawn using python with the command:
	"python graphic.py"
thrown from the repertory "build".


To run the tests, the command:
	“./unit_test”
must be thrown from the repertory “build”.

The terminal will display the result of the tests (PASSED or FAILED).


To see the doxygen documentation on line, the user can double click on a random “.html” file in the repertory “html”.
# cppcourse-brunel
