#ifndef ACCELERATOR_H
#define ACCELERATOR_H

#include "rclcpp/rclcpp.hpp"

namespace Algorithm
{
class Accelerator
{
  public:
    Accelerator(){};
    float get_accelerate(float,float,float);
};
}

#endif
