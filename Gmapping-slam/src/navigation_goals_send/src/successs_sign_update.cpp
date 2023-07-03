#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <navigation_goals.h>
#include <iostream>

void Goals::success_sign_update()
{
    int success_sign;
    success_sign = this->successful_sign;
    std::cout<<"        successful sign :"<<success_sign<<std::endl;
    std::cout<<"        send goals sign :"<<this->send_goals_sign<<std::endl;
    if(success_sign == 1)
    {
        this->tree_1++;
        // std::cout<<"        tree_1 :"<<this->tree_1<<std::endl;
    }
}