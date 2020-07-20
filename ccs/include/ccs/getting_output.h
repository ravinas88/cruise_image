#ifndef GETTING_OUTPUT_H
#define GETTING_OUTPUT_H

#include "rclcpp/rclcpp.hpp"
#include "message_pkg/msg/custommsg.hpp"
#include "../include/ccs/Constants.h"
#include <string.h>

static float prev_acc,prev_time,curr_time;

namespace Algorithm
{
using namespace std;

class Getting_output
{
  public:
    Getting_output(){};
    message_pkg::msg::Custommsg get_outputacc(float,float,float);

  private:
   float jerk_,curr_acc,time_diff;
};
}

#endif
