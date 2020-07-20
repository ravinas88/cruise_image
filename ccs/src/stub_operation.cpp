#include "../include/ccs/stub_operation.h"

namespace Stub_operation
{
message_pkg::msg::Custommsg Stub_operation::stub_operation(const message_pkg::msg::Custommsg parameters) const
{
   auto data=message_pkg::msg::Custommsg();
   if (!parameters.timestamp.empty())
   {
     std::cout<<"The final velocity of vehicle from input acceleration -"<<std::endl;
     float acceleration,time;
     acceleration = stof(parameters.acc); 
     time = stof(parameters.timestamp); 
     data.timestamp=parameters.timestamp;
     data.brake_status=parameters.brake_status;
    if (time>0)
      {
        stubout_velocity = start_velocity + (acceleration*time);
        std::cout<<"stubout_velocity = "<<stubout_velocity<<"\n"<<std::endl;
        data.final_velocity=stubout_velocity;
      }
    if (time==0)
      {  
        start_velocity = initial_velocity + (acceleration*time);
        std::cout<<"start_velocity = "<<start_velocity<<"\n"<<std::endl;
        data.final_velocity=start_velocity;
      }
   }
   else 
   {
       std::cout<<"Parameters are not valid or rosbag may be at end"<<std::endl;
       exit(0);
   }
   return data;
}
}
