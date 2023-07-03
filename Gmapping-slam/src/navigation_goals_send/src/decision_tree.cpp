#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <navigation_goals.h>
#include <iostream>

void Goals::decision_tree(int tree_sign, int tree_num)
{
    std::cout<<"=========decision tree begin!========="<<std::endl;
    int sign;
    sign = tree_sign;
    //读取决策树的点
    cv::Point3f point_1 = this->point_1_1;
    cv::Point3f point_2 = this->point_1_2;
    cv::Point3f point_3 = this->point_1_3;
    cv::Point3f point_4 = this->point_1_4; 
    cv::Point3f point_5 = this->point_1_5; 
    cv::Point3f point_6 = this->point_1_6;  
    switch (sign)
    {
    //决策树1
    case 1:
        // std::cout<<"decision_tree_sign_2 :"<<std::endl;
        // this->send_goals_sign = 1;
        //参数传入
        if(tree_num == 0)
        {
            std::cout<<"    decision_tree_sign_1 to 1"<<std::endl;
            this->line_x = point_1.x;
            this->line_y = point_1.y;
            this->orientation_w = point_1.z;
        }
        if(tree_num == 1)
        {
            std::cout<<"    decision_tree_sign_1 to 2"<<std::endl;
            this->line_x = point_2.x;
            this->line_y = point_2.y;
            this->orientation_w = point_2.z;
        }
        if(tree_num == 2)
        {
            std::cout<<"    decision_tree_sign_1 to 3"<<std::endl;
            this->line_x = point_3.x;
            this->line_y = point_3.y;
            this->orientation_w = point_3.z;
        }
        if(tree_num == 3)
        {
            std::cout<<"    decision_tree_sign_1 to 4"<<std::endl;
            this->line_x = point_4.x;
            this->line_y = point_4.y;
            this->orientation_w = point_4.z;
        }
        if(tree_num == 4)
        {
            std::cout<<"    decision_tree_sign_1 to 5"<<std::endl;
            this->line_x = point_5.x;
            this->line_y = point_5.y;
            this->orientation_w = point_5.z;
        }
        if(tree_num == 5)
        {
            std::cout<<"    decision_tree_sign_1 to 6"<<std::endl;
            this->line_x = point_6.x;
            this->line_y = point_6.y;
            this->orientation_w = point_6.z;
        }
        if(tree_num == 6)
        {
            std::cout<<"    decision_tree_sign_1 successful"<<std::endl;
            this->send_goals_sign = 0;
            this->tree_1 = 0;
            // break;
        }
        break;

    //决策树2
    case 2:
        std::cout<<"    decision_tree_sign_2"<<std::endl;
        break;
    
    default:
        std::cout<<"    no thing"<<std::endl;
        break;
    }
}