from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ccs',
            node_executable='Stub_node',
            node_name='stub_node',
            output = 'screen'
        ),
        Node(
            package='ccs',
            node_executable='Algorithm_node',
            node_name='algorithm_node',
            output = 'screen'
        )
    ])
