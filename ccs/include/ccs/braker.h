#ifndef BRAKER_H
#define BRAKER_H

#include "rclcpp/rclcpp.hpp"
#include "../include/ccs/Constants.h"
#include <string.h>

namespace Algorithm
{
using namespace std;
class Braker
{
  public:
    Braker(){};
    float get_brake(float,float);
};
}

#endif
