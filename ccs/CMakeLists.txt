cmake_minimum_required(VERSION 3.5)
project(ccs)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(message_pkg REQUIRED)
find_package(builtin_interfaces REQUIRED)

include_directories(include)
set(dependencies
    src/ros2bag_creator.cpp
    src/stub_nodecallback.cpp
    src/stub_operation.cpp
    src/algorithm_nodecallback.cpp 
    src/collecting_input.cpp 
    src/decisiontaking.cpp 
    src/cruising.cpp 
    src/braker.cpp 
    src/accelerator.cpp 
    src/getting_output.cpp)

add_executable(ros2bag_player ${dependencies} src/ros2bag_player.cpp )
ament_target_dependencies(ros2bag_player rclcpp message_pkg)

add_executable(Stub_node ${dependencies} src/stub_node.cpp )
ament_target_dependencies(Stub_node rclcpp message_pkg)

add_executable(Algorithm_node ${dependencies} src/algorithm_node.cpp )
ament_target_dependencies(Algorithm_node rclcpp message_pkg)
  
install(TARGETS
  ros2bag_player
  Stub_node
  Algorithm_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
 launch   
 DESTINATION share/${PROJECT_NAME}/
)
  
ament_export_include_directories(include)
ament_export_dependencies(rosidl_default_runtime)
ament_export_dependencies(std_msgs)
ament_package()
