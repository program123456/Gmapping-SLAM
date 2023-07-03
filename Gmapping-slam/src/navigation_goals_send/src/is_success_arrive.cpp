#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <navigation_goals.h>
#include <iostream>

void Goals::is_success_arrive(double x1, double y1, double x2, double y2, double specifi_distance)
{
    double distance = this->get_2P_distance(x1, y1, x2, y2);
    if(distance <= specifi_distance)
    {
        std::cout<<"    mobile state:"<<std::endl;
        std::cout<<"        move successful"<<std::endl;
        std::cout<<"        distance"<<distance<<std::endl;
        std::cout<<"        tree_1 :"<<this->tree_1<<std::endl;
        this->successful_sign = 1;
        this->success_sign_update();
    }
    else
    {
        std::cout<<"    mobile state:"<<std::endl;
        std::cout<<"        move failure"<<std::endl;
        std::cout<<"        distance"<<distance<<std::endl;
        std::cout<<"        tree_1 :"<<this->tree_1<<std::endl;
        this->successful_sign = 0;
        this->success_sign_update();
        this->send_goals_sign = 1;
    }
}