#include <iostream>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <ros/console.h>
#include <unistd.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc,char** argv)
{
    ros::init(argc, argv, "cmdveltest");
     ros::NodeHandle cmdh;
    ros::Publisher cmdpub= cmdh.advertise<geometry_msgs::Twist>("cmd_vel", 1, true);
    ros::Rate r(60);
    
    int l_x = 0;
    int l_y = 0;
    int l_z = 0;

    int a_x = 0;
    int a_y = 0;
    int a_z = 1;

    int ahead = 0;
    int turn_left = 0;
    int turn_right = 0;
    
    namedWindow("cmd_vel_control_window");
    createTrackbar("l_x", "cmd_vel_control_window", &l_x, 100, 0);
    createTrackbar("l_y", "cmd_vel_control_window", &l_y, 100, 0);
    createTrackbar("l_z", "cmd_vel_control_window", &l_z, 100, 0);
    createTrackbar("a_x", "cmd_vel_control_window", &a_x, 100, 0);
    createTrackbar("a_y", "cmd_vel_control_window", &a_y, 100, 0);
    createTrackbar("a_z", "cmd_vel_control_window", &a_z, 100, 0);
    createTrackbar("ahead", "cmd_vel_control_window", &ahead, 1, 0);
    createTrackbar("turn_left", "cmd_vel_control_window", &turn_left, 1, 0);
    createTrackbar("turn_right", "cmd_vel_control_window", &turn_right, 1, 0);
    
    while(1){
        float Lx = (float)l_x; 
        float Ly = (float)l_y; 
        float Lz = (float)l_z; 
        float Ax = (float)a_x; 
        float Ay = (float)a_y; 
        float Az = (float)a_z; 
        float W = (float)ahead; 
        float A = (float)turn_left;
        float D = (float)turn_right; 

        geometry_msgs::Twist twist;
        geometry_msgs::Vector3 linear;
        linear.x=Lx;
        linear.y=Ly;
        linear.z=Lz;
        geometry_msgs::Vector3 angular;
        angular.x=Ax;
        angular.y=Ay;
        angular.z=Az;

        twist.linear=linear;
        twist.angular=angular;
        cmdpub.publish(twist);
        cout<<"hello"<<endl;
        ros::spinOnce();
        //r.sleep();
        // sleep(1);
    }
    return 0;
}










































// #include <ros/ros.h>
// #include <geometry_msgs/Twist.h>
// #include <opencv2/highgui/highgui.hpp>

// ros::Publisher cmd_vel_pub;
// int slider_value = 0;

// void on_trackbar(int, void*)
// {
//     ros::NodeHandle nh;
//     nh.setParam("cmd_vel/linear/x", slider_value / 100.0);
// }

// int main(int argc, char** argv)
// {
//     ros::init(argc, argv, "slider_cmd_vel");
//     ros::NodeHandle nh;

//     cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1);

//     cv::namedWindow("Control");
//     cv::createTrackbar("Speed", "Control", &slider_value, 100, on_trackbar);

//     ros::spin();

//     return 0;
// }
