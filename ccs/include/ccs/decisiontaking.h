#ifndef DECISIONTAKING_H
#define DECISIONTAKING_H

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "message_pkg/msg/custommsg.hpp"

#include "../include/ccs/cruising.h"
#include "../include/ccs/braker.h"
#include "../include/ccs/accelerator.h"
#include "../include/ccs/getting_output.h"
#include "../include/ccs/Constants.h"

namespace Algorithm
{
class Decisiontaking
{
  public:
    Decisiontaking(){};
    message_pkg::msg::Custommsg get_action(float,float,int,float);
};
}

#endif
