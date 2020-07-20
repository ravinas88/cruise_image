#include "../include/ccs/stub_node.h"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Stub_operation::Stub_node>());
  rclcpp::shutdown();
  return 0;
}
