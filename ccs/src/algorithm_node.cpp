#include "../include/ccs/algorithm_node.h"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Algorithm::Algorithm_node>());
  rclcpp::shutdown();
  return 0;
}
