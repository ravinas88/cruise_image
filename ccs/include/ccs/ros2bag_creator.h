#ifndef ROS2BAG_CREATOR_H
#define ROS2BAG_CREATOR_H

#include <chrono>
#include <memory>
#include <fstream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "message_pkg/msg/custommsg.hpp"
#include "../include/ccs/Constants.h"

using namespace std::chrono_literals;
namespace Rosbag_player
{
class ros2bag_creator : public rclcpp::Node
{
public:
  ros2bag_creator()
  : Node(ros2bag_creator_node)
  {
    publisher_ = this->create_publisher<message_pkg::msg::Custommsg>(rosbag_topic,publisher_rate);
    write_radar_data();
  }
  void write_radar_data();

private:
  rclcpp::Publisher<message_pkg::msg::Custommsg>::SharedPtr publisher_;
  std::ifstream myfile;
  std::string line,time,acceleration,brakestatus;
};
}

#endif
