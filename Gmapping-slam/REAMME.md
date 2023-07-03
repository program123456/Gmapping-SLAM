# Gmapping-SLAM

此项目在gmapping导航的基础上，通过向/move_base/goal话题发布消息实现了定点巡航功能，同时通过订阅/amcl_pose获取当前点，来判断是否到达目的地。

## 该项目需要的依赖
```
1.navigation
2.gazebo
3.gmapping
4.map-server
5.ros-noetic-teleop-twist-keyboard
```

## 代码目录说明
smcl_read用于读取当前位置

cmd_vel_control用于控制机器人运动（运动位置无法动态修改，目前使用ros自带的teleop_twist_keyboard teleop_twist_keyboard.py进行实时控制）

cmd_vel_read用于读取机器人的运动状态（包括线速度和角速度）

navigation_goals_send用于按照预期的点实现定点巡航

robot_mod为测试的机器人模型

robot_use_gazebo是实现gmapping-slam的核心代码（已近包括robot_mod机器人模型）

rmus_map_2和rmus_map_gazebo为RobotMaster2023年的地图生成文件


# 1 下载&编译&权限赋予
### 1.1 下载
```
 mkdir catkin_ws_2
```
将下载的文件移动到该文件夹下

### 1.2编译
```
 cd catkin_ws/src

 catkin_init_workspace

 cd ~/catkin_ws

 catkin_make
```

### 1.3赋予bash文件执行权限

```
 sudo chmod 777 start_navigation.bash 

 sudo chmod 777 start_navigation_no_map.bash

 sudo chmod 777 start_keyboard_control.bash

 sudo chmod 777 save_map.bash

 sudo chmod 777 read_map.bash

 sudo chmod 777 keyboard_control.bash

 sudo chmod 777 1_gazebo.bash
 
 sudo chmod 777 2_gmapping.bash
```

start_navigation.bash - - - 启动全局地图导航

start_navigation_no_map.bash - - - 启动无全局地图导航

start_keyboard_control.bash - - - 启动手动建图（1_gazebo.bash和2_gmapping.bash的结合体）

keyboard_control.bash - - - 启动键盘控制

save_map.bash - - - 保存地图

read_map.bash - - - 读取地图

1_gazebo.bash - - - 启动gazebo仿真

2_gmapping.bash - - - 启动gmapping建图

# 2 运行

### 2.1 启动全局地图导航
```
 cd catkin_ws

 ./start_navigation.bash
```
![image](git-img\全局地图导航.png)

### 2.2 启动无全局地图导航
```
 cd catkin_ws

 ./start_navigation_no_map.bash
```
![image](git-img\无全局地图导航.png)

### 2.3启动手动建图
```
 cd catkin_ws

 ./start_keyboard_control.bash
```
新建终端
```
 cd catkin_ws

 ./keyboard_control.bash
```
![image](git-img\手动建图.png)


### 2.4保存地图
```
 cd catkin_ws

 ./save_map.bash
```

### 2.5读取地图
```
 cd catkin_ws

 ./read_map.bash
```

### 2.6启动gazebo仿真
```
 cd catkin_ws

 ./1_gazebo.bash
```
![image](git-img\gazebo仿真.png)

### 2.7启动gmapping建图
```
 cd catkin_ws

 ./2_gmapping.bash
```

### 2.8启动定点巡航
```
 cd catkin_ws

 ./start_navigation.bash
```
新建终端
```
 cd catkin_ws

 source devel/setup.bash

 rosrun navigation_goals_sendnavigation_goals_send_node 
```
![image](git-img\定点巡航.png)

catkin_ws\src\navigation_goals_send\include\navigation_goals.h里储存着要巡航的点，目前有六个，分别为
```
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
```
每个点的x，y，z分别代表着x轴坐标，y轴坐标，w旋转反向4
