#include "../include/ccs/stub_node.h"

namespace Stub_operation
{
void Stub_node::stub_callback(const message_pkg::msg::Custommsg::SharedPtr inputdata) const
{
      std::cout<<"\n \ntimestamp = "<<inputdata->timestamp<<"      acc = "<<inputdata->acc<<"      Brake status = "<<inputdata->brake_status<<std::endl;
      message_pkg::msg::Custommsg::SharedPtr inputparameters;
      inputparameters=inputdata;
      Stub_operation obj;
      auto output_velocity=message_pkg::msg::Custommsg();
      output_velocity=obj.stub_operation(*inputparameters);
      stub_node_publisher->publish(output_velocity);
}
}
