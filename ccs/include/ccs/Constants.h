#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>
#include <functional>

namespace Rosbag_player
{
    static constexpr char csvpath[]{"/home/ravinas/cruise_control/src/ccs/data/data.csv"};
    static constexpr char ros2bag_creator_node[]{"ros2bag_creator"};
    static constexpr char rosbag_topic[]{"bagtopic"};
    static constexpr unsigned publisher_rate{10};
    static constexpr unsigned sleep{300};
}

namespace Stub_operation
{
    static constexpr char stub_node[]{"stub_node_operation"};
    static constexpr char rosbag_topic[]{"bagtopic"};
    static constexpr char stub_publisher_topic[]{"stubnodetopic"};
    static constexpr unsigned publisher_rate{10};
    static constexpr unsigned subscriber_rate{10};
    static constexpr float initial_velocity{80};
}

namespace Algorithm
{
    static constexpr char algorithm_node[]{"algorithm_node_operation"};
    static constexpr char algorithm_subscriber_topic[]{"stubnodetopic"};
    static constexpr char algorithm_publisher_topic[]{"algorithmnodetopic"};
    static constexpr unsigned publisher_rate{10};
    static constexpr unsigned subscriber_rate{10};
    static constexpr float desired_velocity{85};
    static constexpr char previous_velocity_value[]{"80"};
    static constexpr float braking_limit{15};
    static constexpr float Jerk{400};
    static constexpr double previous_time{-0.01};
}

#endif
