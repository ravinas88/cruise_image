#include "../include/ccs/accelerator.h"

namespace Algorithm
{
float Accelerator::get_accelerate(float previous_velocity,float current_velocity, float des_velocity)
{
   current_velocity=des_velocity;
   std::cout<<"Accelerating till des_velocity is given, current_velocity is  "<<current_velocity<<std::endl;
   return current_velocity;
}
}
