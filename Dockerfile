FROM ros:eloquent-ros-base

# install ros build tools
RUN apt-get update && apt-get install -y \
      python3-colcon-common-extensions && \
    rm -rf /var/lib/apt/lists/*

# clone ros package repo
ENV ROS_WS /opt/ros_ws
RUN mkdir -p $ROS_WS/src
WORKDIR $ROS_WS
RUN git -C src clone \
      -b cruise_branch \
      https://github.com/ravinas88/cruise_image.git

# install ros package dependencies
RUN apt-get update && \
    rosdep update && \
    rosdep install -y \
      --from-paths \
        src/cruise_image/ccs \
        src/cruise_image/message_pkg \
      --ignore-src && \
    rm -rf /var/lib/apt/lists/*

# build ros package source
RUN . /opt/ros/$ROS_DISTRO/setup.sh && \
    colcon build \
      --packages-select \
        ccs \
        message_pkg \
      --cmake-args \
        -DCMAKE_BUILD_TYPE=Release

# copy ros package install via multi-stage
FROM ros:eloquent-ros-core
ENV ROS_WS /opt/ros_ws
COPY --from=0  $ROS_WS/install $ROS_WS/install

# source ros package from entrypoint
RUN sed --in-place --expression \
      '$isource "$ROS_WS/install/setup.bash"' \
      /ros_entrypoint.sh

# run ros package launch file
CMD ["ros2", "launch", "ccs", "ccs.launch.py"]
