#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

void amclPoseCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
  double x = msg->pose.pose.position.x;
  double y = msg->pose.pose.position.y;
  double z = msg->pose.pose.position.z;
  std::cout << "Robot position: (" << x << ", " << y << ", " << z << ")" << std::endl;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "amcl_pose_listener");
  ros::NodeHandle node;
  ros::Subscriber sub = node.subscribe("amcl_pose", 10, amclPoseCallback);
  ros::spin();
  return 0;
}

