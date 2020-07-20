#ifndef CRUISING_H
#define CRUISING_H

#include "rclcpp/rclcpp.hpp"
#include "../include/ccs/Constants.h"

namespace Algorithm
{
class Cruising
{
  public:
    Cruising(){};
    float get_cruise(float,float);
};
}

#endif
