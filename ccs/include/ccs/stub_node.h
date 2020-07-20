#ifndef STUB_NODE_H
#define STUB_NODE_H

#include "../include/ccs/stub_operation.h"
#include "../include/ccs/Constants.h"

namespace Stub_operation
{
using std::placeholders::_1;
class Stub_node : public rclcpp::Node
{
  public:
    Stub_node()
    : Node(stub_node)
    {
      stub_node_subscriber = this->create_subscription<message_pkg::msg::Custommsg>
(rosbag_topic,subscriber_rate,std::bind(&Stub_node::stub_callback,this,_1));
      stub_node_publisher = this->create_publisher<message_pkg::msg::Custommsg>(stub_publisher_topic,publisher_rate);  
    }

  private:
    void stub_callback(const message_pkg::msg::Custommsg::SharedPtr) const;
    rclcpp::Subscription<message_pkg::msg::Custommsg>::SharedPtr stub_node_subscriber; 
    rclcpp::Publisher<message_pkg::msg::Custommsg>::SharedPtr stub_node_publisher;
};
}

#endif
