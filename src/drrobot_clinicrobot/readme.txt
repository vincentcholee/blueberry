In Terminal-1 window
roscore

In terminal-2 window
cd catkin_ws
source ./devel/setup.bash

catkin_make
rosrun drrobot_clinicrobot drrobot_clinicrobot_node

In Terminal-3 window
cd catkin_ws
source ./devel/setup.bash

rostopic list

#test published sensor message
rostopic echo drrobot_clinicrobot_motor_sensor
rostopic echo drrobot_clinicrobot_range_sensor
rostopic echo drrobot_clinicrobot_systemdata

#test receive control command
rostopic pub /drrobot_clinicrobot_laserdrive_cmd drrobot_clinicrobot/LaserDriveCmd -- -15 -1
rostopic pub /drrobot_clinicrobot_head_cmd drrobot_clinicrobot/HeadCmd -- 0.6 1 2000 -0.3 1 1500
rostopic pub /drrobot_clinicrobot_motor_cmd drrobot_clinicrobot/MotorCmd -- 200 -200 1



