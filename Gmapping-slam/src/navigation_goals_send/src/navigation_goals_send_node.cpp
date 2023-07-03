#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <navigation_goals.h>
#include <iostream>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
Goals goals_;

void amclPoseCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
    double x = msg->pose.pose.position.x;
    double y = msg->pose.pose.position.y;
    double z = msg->pose.pose.position.z;
    goals_.acml_x = x;
    goals_.acml_y = y;
    goals_.acml_z = z;
    // std::cout << "Robot position: (" << x << ", " << y << ", " << z << ")" << std::endl;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "simple_navigation_goals");
    ros::init(argc, argv, "amcl_pose_listener");
    ros::NodeHandle n;
    //启动一个线程
    MoveBaseClient ac("move_base", true);
    //等待操作服务器启动
    while(!ac.waitForServer(ros::Duration(5.0)))
    {
        ROS_INFO("Waiting for the move_base action server to come up");
    }
    move_base_msgs::MoveBaseGoal goal;
    ros::Rate loop_rate(1);
    while (ros::ok())
    {
        goals_.successful_sign = 0;
        ros::Subscriber sub = n.subscribe("amcl_pose", 10, amclPoseCallback);  //当前点
        goals_.decision_tree(goals_.decision_tree_sign, goals_.tree_1);  //启动决策树  
        if(goals_.send_goals_sign == 1)
        {
            //向机器人发送一个目标
            goal.target_pose.header.frame_id = "map";
            goal.target_pose.header.stamp = ros::Time::now();
            //线坐标
            float line_x = goals_.line_x;
            float line_y = goals_.line_y;
            float line_z = goals_.line_z;
            //角坐标
            float orientation_w = goals_.orientation_w;
            float orientation_x = goals_.orientation_x;
            float orientation_y = goals_.orientation_y;
            float orientation_z = goals_.orientation_z;
            //参数传入
            goal.target_pose.pose.position.x = line_x;
            goal.target_pose.pose.position.y = line_y;
            goal.target_pose.pose.position.z = line_z;
            goal.target_pose.pose.orientation.w = orientation_w;
            goal.target_pose.pose.orientation.x = orientation_x;
            goal.target_pose.pose.orientation.y = orientation_y;
            goal.target_pose.pose.orientation.z = orientation_z;
            // ROS_INFO("Sending goal");
            std::cout<<"======Send a /move_base/goal message!======"<<std::endl;
            std::cout<<"    Line:"<<std::endl;
            std::cout<<"        line_x :"<<line_x<<std::endl;
            std::cout<<"        line_y :"<<line_y<<std::endl;
            std::cout<<"        line_z :"<<line_z<<std::endl;
            std::cout<<"    Orientation:"<<std::endl;
            std::cout<<"        orientation_w :"<<orientation_w<<std::endl;
            std::cout<<"        orientation_x :"<<orientation_x<<std::endl;
            std::cout<<"        orientation_y :"<<orientation_y<<std::endl;
            std::cout<<"        orientation_z :"<<orientation_z<<std::endl;
            //发送
            ac.sendGoal(goal);
            // ac.waitForResult();
            //判断是否到达预定位置
            // if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
            // {
            //     std::cout<<"    mobile state:"<<std::endl;
            //     std::cout<<"        move successful"<<std::endl;
            //     goals_.successful_sign = 1;
            //     goals_.success_sign_update();
            // }
            // else
            // {
            //     std::cout<<"    mobile state:"<<std::endl;
            //     std::cout<<"        move failure"<<std::endl;
            //     goals_.successful_sign = 0;
            //     goals_.success_sign_update();
            // }
            // goals_.is_success_arrive(goals_.acml_x, goals_.acml_y, goals_.line_x, goals_.line_y, goals_.specified_distance);
        }
        goals_.is_success_arrive(goals_.acml_x, goals_.acml_y, goals_.line_x, goals_.line_y, goals_.specified_distance);
        loop_rate.sleep();
        ros::spinOnce();
    }
    return 0;
}