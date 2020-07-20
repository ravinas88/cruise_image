#ifndef STUB_OPERATION_H
#define STUB_OPERATION_H

#include <memory>
#include <string.h>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "message_pkg/msg/custommsg.hpp"
#include "../include/ccs/Constants.h"

static float start_velocity, stubout_velocity;
namespace Stub_operation
{
using namespace std;
class Stub_operation 
{
  public:
    Stub_operation(){};
    message_pkg::msg::Custommsg stub_operation(const message_pkg::msg::Custommsg) const;
};
}

#endif
