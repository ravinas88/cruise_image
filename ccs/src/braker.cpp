#include "../include/ccs/braker.h"

namespace Algorithm
{
float Braker::get_brake(float previous_velocity,float current_velocity)
{
    if((previous_velocity-current_velocity)>= 0)
    {
       current_velocity=previous_velocity-current_velocity;
       std::cout<<"Brake is applied, so the current velocity changes to "<<current_velocity<<std::endl;
    }
    else 
    { 
       current_velocity=current_velocity-braking_limit;
       std::cout<<"Brake is applied, so the current velocity changes to "<<current_velocity<<std::endl;
    }
   return current_velocity;
}
}
