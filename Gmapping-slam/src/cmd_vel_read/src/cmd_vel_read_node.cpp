#include <iostream>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <ros/console.h>
#include <unistd.h>
 
void callback(const geometry_msgs::Twist& cmd_vel)
{
	ROS_INFO("Received a /cmd_vel message!");
	ROS_INFO("Linear Components:[%f,%f,%f]",cmd_vel.linear.x,cmd_vel.linear.y,cmd_vel.linear.z);
	ROS_INFO("Angular Components:[%f,%f,%f]",cmd_vel.angular.x,cmd_vel.angular.y,cmd_vel.angular.z);
}
 
int main(int argc, char** argv)
{
	ros::init(argc, argv, "cmd_vel_listener");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("cmd_vel", 1000, callback);
	ros::spin();
	ros::Rate loop_rate(10);
	while( n.ok() ) 
	{
   		 ros::spin();
	}

	return 1;
}