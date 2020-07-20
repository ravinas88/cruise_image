#include "../include/ccs/ros2bag_creator.h"

namespace Rosbag_player
{
void ros2bag_creator:: write_radar_data()
{ 
    myfile.open(csvpath,std::ios::in);    
    getline (myfile,line,'\n');
    auto data=message_pkg::msg::Custommsg();
    while (rclcpp::ok() and myfile.good())
    {
      getline (myfile,time,',');
      data.timestamp = time;

      getline (myfile,acceleration,',');
      data.acc = acceleration;

      getline (myfile,brakestatus,'\n');
      data.brake_status = brakestatus;

      std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
      std::cout<<"timestamp="<<data.timestamp<<"       acc="<<data.acc<<"       brake_status="<<data.brake_status<<"\n"<<std::endl;
      publisher_->publish(data);  
   }
myfile.close();
}
}
