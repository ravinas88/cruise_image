#ifndef ALGORITHM_NODE_H
#define ALGORITHM_NODE_H

#include "rclcpp/rclcpp.hpp"
#include "../include/ccs/collecting_input.h"
#include "../include/ccs/Constants.h"

namespace Algorithm
{
using std::placeholders::_1;
class Algorithm_node : public rclcpp::Node
{
  public:
    Algorithm_node()
    : Node(algorithm_node)
    {
      algorithm_node_subscriber = this->create_subscription<message_pkg::msg::Custommsg>(algorithm_subscriber_topic,subscriber_rate,
std::bind(&Algorithm_node::algorithm_callback,this,_1));
      algorithm_node_publisher = this->create_publisher<message_pkg::msg::Custommsg>(algorithm_publisher_topic,publisher_rate);  
    }
  private:
    void algorithm_callback(const message_pkg::msg::Custommsg::SharedPtr) const;
    rclcpp::Subscription<message_pkg::msg::Custommsg>::SharedPtr algorithm_node_subscriber; 
    rclcpp::Publisher<message_pkg::msg::Custommsg>::SharedPtr algorithm_node_publisher;
};
}

#endif
