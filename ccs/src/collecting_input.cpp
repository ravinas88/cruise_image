#include "../include/ccs/collecting_input.h"

namespace Algorithm
{
message_pkg::msg::Custommsg Collecting_input::collectinput(const message_pkg::msg::Custommsg parameters) 
{
   //std::cout<<"The input parameters for algorithm nodes are -    "<<parameters.final_velocity<<"        "<<des_velocity<<"        "<<parameters.timestamp<<"          "<<parameters.brake_status<<std::endl;
      auto output_acc=message_pkg::msg::Custommsg();
      brakestatus = stof(parameters.brake_status);
      time = stof(parameters.timestamp);      
      if (time > 0)
      {
        previous_velocity=current_velocity;
        current_velocity = parameters.final_velocity;        
      }
      if (time==0)
      {
        previous_velocity= stof(previous_velocity_value); 
        current_velocity = previous_velocity;
      }
      std::cout<<"\nprevious_velocity = "<<previous_velocity<<"         current_velocity = "<<current_velocity<<"         time = "<<time<<std::endl;    
      Decisiontaking obj;              
      output_acc=obj.get_action(previous_velocity,current_velocity,brakestatus,time); 
      return output_acc;
}
}
