#include "../include/ccs/getting_output.h"

namespace Algorithm
{
message_pkg::msg::Custommsg Getting_output::get_outputacc(float previous_velocity,float current_velocity, float timestamp)
{
      	auto outputacc=message_pkg::msg::Custommsg();
        if (timestamp>0)
	{
	   prev_time=curr_time;
           curr_time=timestamp;       
	}
        if(timestamp==0)
	{
           prev_time=previous_time;
           curr_time=timestamp;    
	}
        time_diff=curr_time-prev_time;
        curr_acc = (current_velocity-previous_velocity)/time_diff;
        jerk_ = (curr_acc-prev_acc)/time_diff;
	if(Jerk<=(abs(jerk_)))
	{
	    std::cout<<"Jerk is present"<<std::endl; 
	}
        else
        {
            std::cout<<"Jerk is not present..........."<<std::endl; 
        }
        prev_acc=curr_acc;
        prev_time=curr_time;
	outputacc.acc=std::to_string(curr_acc);
	outputacc.timestamp=std::to_string(timestamp);
      	return outputacc;
}
}
