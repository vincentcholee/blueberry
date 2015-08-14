#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include <drrobot_clinicrobot/LaserDriveData.h>
#include <drrobot_clinicrobot/RobotPosition.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/TransformStamped.h>
//#include  "/home/drrobot1/github/BlueBerry/src/drrobot_clinicrobot/include/drrobot_clinicrobot/drrobotprotocol.hpp"
//#include "/home/drrobot1/github/BlueBerry/src/drrobot_clinicrobot/include/drrobot_clinicrobot/drrobotsensordata.hpp"

#define IR_NUM  16      // 16 IR range sensor
#define US_NUM  6       // 6 US sensor
#define SENSOR_R    0.25
#define SENSOR_ANGLE_STEP 22.5      // 16 sensor one circle(360)

void setlasertf(const drrobot_clinicrobot::LaserDriveDataConstPtr laserData)
{

    tf::TransformBroadcaster broadcaster_IRsensor[IR_NUM];
    tf::TransformBroadcaster broadcaster_USsensor[US_NUM];

    static tf::TransformBroadcaster broadcaster_laser;
    tf::Transform transform;
    transform.setOrigin( tf::Vector3(laserData->offset_x, laserData->offset_y, laserData->offset_z) );
    tf::Quaternion q;
    q.setRPY(0, laserData->tilt_angle, 0);
    transform.setRotation(q);

    tf::StampedTransform a(transform, ros::Time::now(), "base_link", "laser");

    broadcaster_laser.sendTransform(a);

    double angle;
    for (int i = 0; i < IR_NUM; i++){
        if (i < 11){
            angle = (90 - SENSOR_ANGLE_STEP * (i + 1) ) / 180 * M_PI;        //number ]0] is at the left front side
        }else{
            angle = (180 - SENSOR_ANGLE_STEP * (i - 11)) / 180 * M_PI;
        }

        std_msgs::String frame;
        std::stringstream ss;
        ss << "base_IRsensor" << i;
        frame.data = ss.str();
        broadcaster_IRsensor[i].sendTransform(
                    tf::StampedTransform(
                        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(SENSOR_R * cos(angle), SENSOR_R * sin(angle), 0.16)),
                        ros::Time::now(),"base_link", frame.data.c_str()));
    }
    broadcaster_USsensor[0].sendTransform(
                tf::StampedTransform(
                    tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.05, 0.0, 0.7)),
                    ros::Time::now(),"base_link", "base_USsensor0"));
    broadcaster_USsensor[1].sendTransform(
                tf::StampedTransform(
                    tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.05, 0.0, 1.0)),
                    ros::Time::now(),"base_link", "base_USsensor1"));
    broadcaster_USsensor[2].sendTransform(
                tf::StampedTransform(
                    tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.05, 0.0, 1.4)),
                    ros::Time::now(),"base_link", "base_USsensor2"));
    broadcaster_USsensor[3].sendTransform(
                tf::StampedTransform(
                    tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, 0.165, 1.3)),
                    ros::Time::now(),"base_link", "base_USsensor3"));
    broadcaster_USsensor[4].sendTransform(
                tf::StampedTransform(
                    tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.0, -0.165, 1.3)),
                    ros::Time::now(),"base_link", "base_USsensor4"));
    broadcaster_USsensor[5].sendTransform(
                tf::StampedTransform(
                    tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(-0.05, 0.0, 0.7)),
                    ros::Time::now(),"base_link", "base_USsensor5"));

}
void setOdomtf(const drrobot_clinicrobot::RobotPositionConstPtr robotPositionData)
{

    tf::TransformBroadcaster odom_broadcaster;
//    tf::StampedTransform odom_trans;

    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(robotPositionData->robot_heading);
//    tf::Quaternion odom_quat = tf::createQuaternionFromYaw(robotPositionData->robot_heading);


    //first, we'll publish the transform over tf
    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = ros::Time::now();
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";

//    odom_trans.stamp_ = ros::Time::now();
//    odom_trans.frame_id_ = "odom";
//    odom_trans.child_frame_id_ = "base_link";

    odom_trans.transform.translation.x = robotPositionData->robot_x;
    odom_trans.transform.translation.y = robotPositionData->robot_y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;

//    odom_trans.setOrigin(tf::Vector3(robotPositionData->robot_x,robotPositionData->robot_y, 0));
//    odom_trans.setRotation(odom_quat);

   tf::StampedTransform transform;
   tf::transformStampedMsgToTF(odom_trans, transform);

    //send the transform
    //odom_broadcaster.sendTransform(odom_trans);

     odom_broadcaster.sendTransform(transform);
}

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle n;

  ros::Rate r(100);




  while(n.ok()){

      ros::Subscriber laser_tf = n.subscribe("drrobot_clinicrobot_laserdrivedata",1000, setlasertf);
      ros::Subscriber Odom = n.subscribe("drrobot_clinicrobot_robotposition",1000, setOdomtf);


      ros::spin();

      r.sleep();

  }
}
