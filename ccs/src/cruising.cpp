#include "../include/ccs/cruising.h"

namespace Algorithm
{
float Cruising::get_cruise(float desired_velocity,float current_velocity)
{ 
     current_velocity=desired_velocity;
     std::cout<<"Cruising the current velocity to "<<current_velocity<<std::endl; 
     return current_velocity;
}
}

