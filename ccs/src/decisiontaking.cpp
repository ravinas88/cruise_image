#include "../include/ccs/decisiontaking.h"

namespace Algorithm
{
message_pkg::msg::Custommsg Decisiontaking::get_action(float prev_velocity,float current_velocity,int brake_status,float time) 
{
      auto func_out=message_pkg::msg::Custommsg();
      if(current_velocity>desired_velocity)
      {
        Cruising cruise;
        current_velocity=cruise.get_cruise(desired_velocity,current_velocity); 
      }
      else
      {
        Accelerator accelerate;
        current_velocity=accelerate.get_accelerate(prev_velocity,current_velocity,desired_velocity);
      }
      
      if(brake_status != 0)
      {
        Braker brake;
        current_velocity=brake.get_brake(prev_velocity,current_velocity);
      }
      Getting_output getting_output;
      func_out=getting_output.get_outputacc(prev_velocity,current_velocity,time);    
      return func_out;
}
}
