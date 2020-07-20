#ifndef ROSBAG_CREATOR_INCLUDED
#define ROSBAG_CREATOR_INCLUDED

#include "../include/ccs/ros2bag_creator.h"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Rosbag_player::ros2bag_creator>();
  rclcpp::shutdown();
  return 0;
}

#endif
