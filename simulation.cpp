#include "simulation.h"

//-----------------------------CONSTRUCTOR----------------------------//
Simulation::Simulation(unsigned long NE, unsigned long NI, double dt, double t_stop, double g, double ETA)
: NE_(NE), NI_(NI), CE_(NE/10), CI_(NI/10), dt_(dt), g_(g), ETA_(ETA), clock_(0), Tstop_( static_cast<int>(t_stop*10) / static_cast<int>(dt*10)), brain_(Brain(NE_, NI_, CE_, CI_, dt_, v_ext_, Delay_Steps_, Refractory_Time_Steps_, Vthr_, Vreset_, JE_, JI_, J_, TAU_, R_))
{}

//-------------------------------GETTERS------------------------------//
unsigned long Simulation::get_CE() const
{
	return CE_;
}

unsigned long Simulation::get_CI() const
{
	return CI_;
}

unsigned int Simulation::get_Delay_Steps() const
{
	return Delay_Steps_;
}

unsigned int Simulation::get_Refractory_Time_Steps() const
{
	return Refractory_Time_Steps_;
}

double Simulation::get_JI() const
{
	return JI_;
}

double Simulation::get_R() const
{
	return R_;
}

double Simulation::get_v_ext() const
{
	return v_ext_;
}

//---------------------------------RUN--------------------------------//
void Simulation::run(std::ofstream& file)
{
	while (clock_ < Tstop_) {
		clock_ += 1;
		brain_.update(clock_, file);
	}
}

//------------------------------DESTRUCTOR----------------------------//	
Simulation::~Simulation()
{}
