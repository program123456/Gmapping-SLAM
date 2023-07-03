#! /bin/bash
killall roslaunch
# source /opt/ros/noetic/setup.zsh
source /opt/ros/noetic/setup.bash
source devel/setup.bash
# cp armorboxContours.yml ~/.ros
# cp svm2.xml ~/.ros
# catkin_make && roslaunch src/roslaunch.launch
catkin_make && roslaunch src/robot_use_gazebo/launch/base_move.launch
# gnome-terminal -t "gmapping" -x bash -c "./gmapping.bash;exec bash;"
# sleep 2
# gnome-terminal -t "teleop_twist_keyboard" -x bash -c "./teleop_twist_keyboard.bash;exec bash;"
# sleep 2
# gmapping