#include <opencv2/opencv.hpp>
#ifndef H_RECTANGLE
#define H_RECTANGLE

class Goals {
    public:
        double goal_to_acmlPose_distance;  //目标点到当前点的距离
        double specified_distance = 1;  //指定距离
        //发布的目标坐标
        float line_x = 5.0;
        float line_y = -1.0;
        float line_z = 0.0;
        float orientation_w = 1.0;
        float orientation_x = 0.0;
        float orientation_y = 0.0;
        float orientation_z = 0.0;
        //接收的目前坐标
        double acml_x = 0;
        double acml_y = 0;
        double acml_z = 0;
        //标志
        int successful_sign;  //到达目标点的标志（1成功/0失败）
        int send_goals_sign = 0;  //是否发送目标点
        int decision_tree_sign = 1;  //决策树标志
        //========决策树1=========//
        Goals():point_1_1(5.0, -1.0, 1.0),
        point_1_2(6.0, -2.0, 1.0),
        point_1_3(6.0, -5.0, 1.0),
        point_1_4(0.0, -5.0, 1.0),
        point_1_5(-5.0, 0.0, 1.0),
        point_1_6(0.0, 0.0, 1.0) {}
        cv::Point3f point_1_1;
        cv::Point3f point_1_2;
        cv::Point3f point_1_3;
        cv::Point3f point_1_4;
        cv::Point3f point_1_5;
        cv::Point3f point_1_6;
        int tree_1 = 0;
        //======================//

        void success_sign_update();  //成功标志更新，串口发送
        void decision_tree(int tree_sign, int tree_num);  //决策树
        double get_2P_distance(double x1, double y1, double x2, double y2);
        void is_success_arrive(double x1, double y1, double x2, double y2, double specifi_distance);
};

#endif