#! /bin/bash
# killall roslaunch
# source /opt/ros/noetic/setup.zsh
source /opt/ros/noetic/setup.bash
source devel/setup.bash
# cp armorboxContours.yml ~/.ros
# cp svm2.xml ~/.ros
# catkin_make && roslaunch src/roslaunch.launch
# catkin_make && roslaunch src/robot_use_gazebo/launch/my_robot_xacro_first.launch
roslaunch robot_use_gazebo save_map.launch 