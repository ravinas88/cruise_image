#include "../include/ccs/algorithm_node.h"

namespace Algorithm
{
void Algorithm_node::algorithm_callback(const message_pkg::msg::Custommsg::SharedPtr stuboutput) const
{
      message_pkg::msg::Custommsg::SharedPtr algorithminput;
      algorithminput=stuboutput;
      Collecting_input obj;
      auto output=message_pkg::msg::Custommsg();
      output=obj.collectinput(*algorithminput);
      std::cout<<"Publishing desired acceleartion is        "<<output.acc<<std::endl; 
      algorithm_node_publisher->publish(output);
}
}
