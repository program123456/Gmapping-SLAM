#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <navigation_goals.h>
#include <iostream>

double Goals::get_2P_distance(double x1, double y1, double x2, double y2)
{
    return sqrt((pow(fabs(x1 - x2),2) + pow(fabs(y1 - y2),2)));
}