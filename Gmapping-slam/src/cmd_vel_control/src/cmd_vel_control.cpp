// #include <iostream>
// #include <geometry_msgs/Twist.h>
// #include <ros/ros.h>
// #include <ros/console.h>
// #include <unistd.h>
// #include <opencv2/opencv.hpp>

// using namespace cv;
// using namespace std;

// int main(int argc,char** argv)
// {
//     ros::init(argc, argv, "cmdveltest");
//      ros::NodeHandle cmdh;
//     ros::Publisher cmdpub= cmdh.advertise<geometry_msgs::Twist>("cmd_vel", 1, true);
//     ros::Rate r(60);
    
//     int l_x = 0;
//     int l_y = 0;
//     int l_z = 0;

//     int a_x = 0;
//     int a_y = 0;
//     int a_z = 0;

//     int ahead = 0;
//     int turn_left = 0;
//     int turn_right = 0;
    
//     namedWindow("cmd_vel_control_window");
//     createTrackbar("l_x", "cmd_vel_control_window", &l_x, 100, 0);
//     createTrackbar("l_y", "cmd_vel_control_window", &l_y, 100, 0);
//     createTrackbar("l_z", "cmd_vel_control_window", &l_z, 100, 0);
//     createTrackbar("a_x", "cmd_vel_control_window", &a_x, 100, 0);
//     createTrackbar("a_y", "cmd_vel_control_window", &a_y, 100, 0);
//     createTrackbar("a_z", "cmd_vel_control_window", &a_z, 100, 0);
//     createTrackbar("ahead", "cmd_vel_control_window", &ahead, 1, 0);
//     createTrackbar("turn_left", "cmd_vel_control_window", &turn_left, 1, 0);
//     createTrackbar("turn_right", "cmd_vel_control_window", &turn_right, 1, 0);
    
//     while(1){
//         float Lx = (float)l_x; 
//         float Ly = (float)l_x; 
//         float Lz = (float)l_x; 
//         float Ax = (float)l_x; 
//         float Lx = (float)l_x; 
//         float Lx = (float)l_x; 
//         float Lx = (float)l_x; 
//         float Lx = (float)l_x;
//         float Lx = (float)l_x; 


//         geometry_msgs::Twist twist;
//         geometry_msgs::Vector3 linear;
//         linear.x=0.1;
//         linear.y=0;
//         linear.z=0;
//         geometry_msgs::Vector3 angular;
//         angular.x=0;
//         angular.y=0;
//         angular.z=-0.5;
//         twist.linear=linear;
//         twist.angular=angular;

//         cmdpub.publish(twist);
//         cout<<"hello"<<endl;
//        // ros::spinOnce();
//         //r.sleep();
//         sleep(1);
//     }
//     return 0;
// }
