/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
//calvin included this
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Twist.h>
#include <drrobot_clinicrobot/P2pCmd.h>
//calvin end
#include "../include/drrobot_clinicrobot/qnode.hpp"
#include "../include/drrobot_clinicrobot/drrobotsensordata.hpp"
#include <drrobot_clinicrobot/MotorInfo.h>
#include <drrobot_clinicrobot/MotorInfoArray.h>
#include <drrobot_clinicrobot/MotorCmd.h>
#include <drrobot_clinicrobot/IndoorGPS.h>
#include <drrobot_clinicrobot/BumpSensor.h>
#include <drrobot_clinicrobot/LaserDriveData.h>
#include <drrobot_clinicrobot/PowerInfo.h>
#include <drrobot_clinicrobot/Range.h>
#include <drrobot_clinicrobot/RangeArray.h>
#include <drrobot_clinicrobot/RobotPosition.h>
#include <drrobot_clinicrobot/RobotSystemData.h>
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace drrobot_clinicrobot {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
    ros::init(init_argc,init_argv,"drrobot_clinicrobot");
	if ( ! ros::master::check() ) {
		return false;
	}
	msgCnt = 0;
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
    motorInfo_pub_ = n.advertise<drrobot_clinicrobot::MotorInfoArray>("drrobot_clinicrobot_motor_sensor", 1);
    rangeArray_pub_= n.advertise<drrobot_clinicrobot::RangeArray>("drrobot_clinicrobot_range_sensor",1);
    robotSystemData_pub_ = n.advertise<drrobot_clinicrobot::RobotSystemData>("drrobot_clinicrobot_systemdata",1);
    //uncommenting from here
    indoorGPS_pub_ = n.advertise<drrobot_clinicrobot::IndoorGPS>("drrobot_clinicrobot_indoorgps_sensor", 1);
    laserDriveData_pub_= n.advertise<drrobot_clinicrobot::LaserDriveData>("drrobot_clinicrobot_laserdrivedata",1);
    powerInfo_pub_ = n.advertise<drrobot_clinicrobot::PowerInfo>("drrobot_clinicrobot_powerinfo",1);
    robotPosition_pub_= n.advertise<drrobot_clinicrobot::RobotPosition>("drrobot_clinicrobot_robotposition",1);
    bumpSensor_pub_ = n.advertise<drrobot_clinicrobot::BumpSensor>("drrobot_clinicrobot_bump_sensor",1);
    // uncommenting stops here
    motor_cmd_sub_ = n.subscribe<drrobot_clinicrobot::MotorCmd>("drrobot_clinicrobot_motor_cmd", 1, boost::bind(&QNode::wheelCmdReceived, this, _1));
    head_cmd_sub_ = n.subscribe<drrobot_clinicrobot::HeadCmd>("drrobot_clinicrobot_head_cmd", 1, boost::bind(&QNode::headCmdReceived, this, _1));
    laser_cmd_sub_ = n.subscribe<drrobot_clinicrobot::LaserDriveCmd>("drrobot_clinicrobot_laserdrive_cmd", 1, boost::bind(&QNode::laserCmdReceived, this, _1));

    //calvin added these codes
    //laser_scan_sub_ = n.subscribe<sensor_msgs::LaserScan>("scan", 1000, &QNode::laserScanUpdated);
    laser_scan_sub_ = n.subscribe<sensor_msgs::LaserScan>("scan", 1, boost::bind(&QNode::lasersensorReceived, this, _1));
    odom_pub_ = n.advertise<nav_msgs::Odometry>("drrobot_clinicrobot_odometry", 1);
    geo_twist_sub_ = n.subscribe<geometry_msgs::Twist>("cmd_vel", 1, boost::bind(&QNode::navigationCmd, this, _1));
    p2p_go_sub_ = n.subscribe<drrobot_clinicrobot::P2pCmd>("P2PNavigation", 1, boost::bind(&QNode::p2pnavrecieved, this, _1));
    //calvin end


	start();
	return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
	
	return true;
}

void QNode::publisherMotorData(MotorData motorData[],int len)
{
    drrobot_clinicrobot::MotorInfoArray motorInfoArray;
	motorInfoArray.motorInfos.resize(len);
	for (uint32_t i = 0 ; i < len; ++i)
	{

	  motorInfoArray.motorInfos[i].header.stamp = ros::Time::now();
      motorInfoArray.motorInfos[i].header.frame_id = "/drrobot_clinicrobot_motor";
      motorInfoArray.motorInfos[i].encoder_pos = motorData[i].encoderPos;
      motorInfoArray.motorInfos[i].encoder_vel = motorData[i].encoderVel;
      motorInfoArray.motorInfos[i].motor_pwm = motorData[i].pwmValue;
	}

   // ROS_INFO("publish motor info array");
	motorInfo_pub_.publish(motorInfoArray);
}

void QNode::publisherRangeArray(IRRangeData irRangeData[],USRangeData usRangeData[],int irnum,int usnum)
{
    drrobot_clinicrobot::RangeArray rangeArray;
     rangeArray.ranges.resize(irnum + usnum);
    for (uint32_t i = 0; i < irnum; i++){

        rangeArray.ranges[i].header.stamp = ros::Time::now();
        rangeArray.ranges[i].header.frame_id = "/drrobot_clinicrobot_ir_range";
        rangeArray.ranges[i].radiation_type = 1; //infrared range sensor
        rangeArray.ranges[i].field_of_view = 0.087;  // around 5 degreee
        rangeArray.ranges[i].min_range = 0.2;
        rangeArray.ranges[i].max_range = 1.0;
        rangeArray.ranges[i].range = irRangeData[i].detectDis;
    }
    for (uint32_t i = irnum; i < irnum + usnum; i++){

        rangeArray.ranges[i].header.stamp = ros::Time::now();
        rangeArray.ranges[i].header.frame_id = "/drrobot_clinicrobot_us_range";
        rangeArray.ranges[i].radiation_type = 0; //ultrasonic range sensor
        rangeArray.ranges[i].field_of_view = 0.35;  // around 20 degreee
        rangeArray.ranges[i].min_range = 0.2;
        rangeArray.ranges[i].max_range = 2.7;
        rangeArray.ranges[i].range = usRangeData[i-irnum].detectDis;
    }
    rangeArray_pub_.publish(rangeArray);

}

void QNode::publisherRobotSystemData(SystemData systemData)
{
    drrobot_clinicrobot::RobotSystemData robotSystemData;
    robotSystemData.header.stamp = ros::Time::now();
    robotSystemData.header.frame_id = "/drrobot_clinicrobot_systemdata";
    robotSystemData.system_vol = systemData.systemVol;
    robotSystemData.chargestation_flag = systemData.chargeStationFlag;
    robotSystemData.charge_flag = systemData.chargeFlag;
    robotSystemData.motionboard_vol = systemData.motionBoardVol;
    robotSystemData.robot_x = systemData.robotX;
    robotSystemData.robot_y = systemData.robotY;
    robotSystemData.robot_heading = systemData.robotHeading;
    robotSystemData.head_tiltangle = systemData.headTiltAngle;
    robotSystemData.head_panangle = systemData.headPanAngle;
    robotSystemData.laser_tiltangle = systemData.laserTiltAngle;
    robotSystemData.bumpsensor = systemData.bumpSensor;
    robotSystemData.faceimage_num = systemData.faceImage;
    robotSystemData_pub_.publish(robotSystemData);
}

// calvin uncommented these codes from here

void QNode::publisherIndoorGPS(IndoorGPSData indoorGPSData)
{
    drrobot_clinicrobot::IndoorGPS indoorGPS;
    indoorGPS.header.stamp = ros::Time::now();
    indoorGPS.header.frame_id = "/drrobot_clinicrobot_indoorGPS";
    indoorGPS.robot_x = indoorGPSData.robotX_GPS;
    indoorGPS.robot_y = indoorGPSData.robotY_GPS;
    indoorGPS.robot_heading = indoorGPSData.robotHeading_GPS;
    indoorGPS.mark_id = indoorGPSData.markID;
    indoorGPS.markid_height = indoorGPSData.markHeight;
    indoorGPS.valid_flag = indoorGPSData.validFlag;
    indoorGPS_pub_.publish(indoorGPS);

}

void QNode::publisherBumpSensor(BumpData bumpData)
{
    drrobot_clinicrobot::BumpSensor bumpSensor;
    bumpSensor.header.stamp = ros::Time::now();
    bumpSensor.header.frame_id = "/drrobot_clinicrobot_bumpsensor";
    bumpSensor. bump_sw1= bumpData.bumpSW1;
    bumpSensor. bump_sw2= bumpData.bumpSW2;
    bumpSensor. bump_sw3= bumpData.bumpSW3;
    bumpSensor. bump_sw4= bumpData.bumpSW4;
    bumpSensor_pub_.publish(bumpSensor);
}

void QNode::publisherLaserDriveData(Laser_Data laserData)
{
    drrobot_clinicrobot::LaserDriveData laserDriveData;
    laserDriveData.header.stamp = ros::Time::now();
    laserDriveData.header.frame_id = "/drrobot_clinicrobot_laserdrivedata";
    laserDriveData.offset_x= laserData.offsetX;
    laserDriveData.offset_y= laserData.offsetY;
    laserDriveData.offset_z= laserData.offsetZ;
    laserDriveData.tilt_angle= laserData.tilt_Angle;
    laserDriveData.stop_flag= laserData.stopFlag;
    laserDriveData.drive_state= laserData.driveState;
    laserDriveData_pub_.publish(laserDriveData);
}

void QNode::publisherPowerInfo(ChargerData chargeData)
{
    drrobot_clinicrobot::PowerInfo powerInfo;
    powerInfo.header.stamp = ros::Time::now();
    powerInfo.header.frame_id = "/drrobot_clinicrobot_powerinfo";
    powerInfo.battery_vol = chargeData.batteryVol;
    powerInfo.system_vol = chargeData.systemVol;
    powerInfo.battery_fuel = chargeData.batteryFuel;
    powerInfo.dcin_vol = chargeData.dcPowerVol;
    powerInfo.dcin_current = chargeData.dcPowerCurrent;
    powerInfo.charge_time_min = chargeData.chargeTimeMin;
    powerInfo.charge_time_sec = chargeData.chargeTimeSec;
    powerInfo.charge_error_code = chargeData.chargeErrorCode;
    powerInfo.charge_mode = chargeData.chargeMode;
    powerInfo.charge_status = chargeData.chargeStatus;
    powerInfo.charge_rx_status = chargeData.chargeRxStatus;
    powerInfo.charger_temperature = chargeData.chargerCPUTemperature;
    powerInfo.set_charge_current = chargeData.setCurrent;
    powerInfo.charge_flag = chargeData.chargeFlag;
    powerInfo.in_chargestation_flag = chargeData.inChargeStation;
    for (uint32_t i = 0; i < 6; i ++){
        powerInfo.cell_vol[i] = chargeData.cellVol[i];
        powerInfo.cell_res[i] = chargeData.cellRes[i];
    }
    powerInfo_pub_.publish(powerInfo);
}

void QNode::publisherRobotPosition(RobotPositionData robotPositionData)
{

    drrobot_clinicrobot::RobotPosition robotPosition;
    robotPosition.header.stamp = ros::Time::now();
    robotPosition.header.frame_id = "/drrobot_clinicrobot_robotposition";
    robotPosition.robot_x = robotPositionData.robotX;
    robotPosition.robot_y = robotPositionData.robotY;
    robotPosition.robot_heading = robotPositionData.robotHeading;
    robotPosition_pub_.publish(robotPosition);


}


// calvin end of uncommented codes
void QNode::run() {
	ros::Rate loop_rate(1);
	int count = 0;
	while ( ros::ok() ) {
		ros::spinOnce();
        loop_rate.sleep();
		++count;
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	emit rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void QNode::wheelCmdReceived(const drrobot_clinicrobot::MotorCmd::ConstPtr& cmd)
{
    int cmdValue1 =  cmd->motorcmd1;
    int cmdValue2 = cmd->motorCmd2;
	int cmdCtrl = cmd->motorCtrl;
	std::cout << "Ros received motor command." << std::endl;
    emit wheelCmdUpdated(cmdValue1,cmdValue2,cmdCtrl);
}


void QNode::headCmdReceived(const drrobot_clinicrobot::HeadCmd::ConstPtr& cmd)
{
    double headTiltPos = cmd->head_tilt_pos;
    int headTiltFlag = cmd->head_tiltflag;
    int headTiltTime = cmd->head_tilt_time;
    double headPanPos = cmd->head_pan_pos;
    int headPanFlag = cmd->head_panflag;
    int headPanTime = cmd->head_pan_time;
    emit headCmdUpdated(headTiltPos,headTiltFlag,headTiltTime,headPanPos,headPanFlag,headPanTime);

}

void QNode::laserCmdReceived(const drrobot_clinicrobot::LaserDriveCmd::ConstPtr& cmd)
{
    double tiltPos = cmd->tilt_pos;
    int autoScanFlag = cmd->auto_scan_flag;
    emit laserCmdUpdated(tiltPos,autoScanFlag);

}

//calvin added this
void QNode::lasersensorReceived(const sensor_msgs::LaserScan::ConstPtr& scan)
{
    LaserSensorData laserSensorData;
    LaserConfigData laserConfigData;
    laserSensorData.setLaserSensorData();
    laserConfigData.setLaserConfigData();

    laserConfigData.EndStep = (scan->angle_max-scan->angle_min)/scan->angle_increment + 1;
    laserConfigData.LaserDataLen = (scan->angle_max-scan->angle_min)/scan->angle_increment + 1;
    laserConfigData.AngleStep = scan->angle_increment;
    laserConfigData.MaxDis = scan->range_max;
    laserConfigData.MinDis = scan->range_min;
    //laserconfigdata offset x and y will be provided in the mainwindow.
    laserConfigData.StartAngle = scan->angle_min;

    //using just arrays
    double laserconfig[6];
    laserconfig[0] = laserConfigData.EndStep;
    laserconfig[1] = laserConfigData.LaserDataLen;
    laserconfig[2] = laserConfigData.AngleStep;
    laserconfig[3] = laserConfigData.MaxDis;
    laserconfig[4] = laserConfigData.MinDis;
    laserconfig[5] = laserConfigData.StartAngle;

    double laserdata[laserConfigData.LaserDataLen];

    laserSensorData.TimeStamp = scan->header.stamp.toSec();
    double time = laserSensorData.TimeStamp;
    for (int i = laserConfigData.StartStep; i < laserConfigData.EndStep; i++)
    {
        laserSensorData.DisArrayData[i] = scan->ranges[i];
        laserdata[i] = laserSensorData.DisArrayData[i];
    }

    emit laserScanUpdated(time);
}

void QNode::publisherOdometry(RobotPositionData robotPositionData, RobotVelocity robotVelocity)
{
//    tf::TransformBroadcaster odom_broadcaster;

    //since all odometry is 6DOF we'll need a quaternion created from yaw
       geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(robotPositionData.robotHeading);

//       //first, we'll publish the transform over tf
//       geometry_msgs::TransformStamped odom_trans;
//       odom_trans.header.stamp = ros::Time::now();
//       odom_trans.header.frame_id = "odom";
//       odom_trans.child_frame_id = "base_link";

//       odom_trans.transform.translation.x = robotPositionData.robotX;
//       odom_trans.transform.translation.y = robotPositionData.robotY;
//       odom_trans.transform.translation.z = 0.0;
//       odom_trans.transform.rotation = odom_quat;

//       //send the transform
//       tf::StampedTransform transform;
//       tf::transformStampedMsgToTF(odom_trans, transform);
//       odom_broadcaster.sendTransform(transform);

       //next, we'll publish the odometry message over ROS
       nav_msgs::Odometry odom;
       odom.header.stamp = ros::Time::now();
       odom.header.frame_id = "odom";

       //set the position
       odom.pose.pose.position.x = robotPositionData.robotX;
       odom.pose.pose.position.y = robotPositionData.robotY;
       odom.pose.pose.position.z = 0.0;
       odom.pose.pose.orientation = odom_quat;

       //set the velocity
       odom.child_frame_id = "base_link";
       odom.twist.twist.linear.x = robotVelocity.velocityX;
       odom.twist.twist.linear.y = robotVelocity.velocityY;
       odom.twist.twist.angular.z = robotVelocity.velocityAng;

       //publish the message
       odom_pub_.publish(odom);

}

void QNode::navigationCmd(const geometry_msgs::Twist::ConstPtr &twist)
{
    int cmdValue1;
    int cmdValue2;
    int cmdCtrl;

    if (twist->angular.z != 0)
    {
        cmdValue1 = -twist->angular.z;
        cmdValue2 = -twist->angular.z;
        cmdCtrl = 1;
        std::cout << "Ros received motor command." << std::endl;
        emit wheelCmdUpdated(cmdValue1,cmdValue2,cmdCtrl);
    }

    if (twist->linear.x != 0)
    {
        cmdValue1 = twist->linear.x;
        cmdValue2 = -twist->linear.x;
        int cmdCtrl = 1;
        std::cout << "Ros received motor command." << std::endl;
        emit wheelCmdUpdated(cmdValue1,cmdValue2,cmdCtrl);
    }
}

void QNode::p2pnavrecieved(const drrobot_clinicrobot::P2pCmd::ConstPtr &cmd)
{
    emit p2pCmdUpdated(cmd->TargetX, cmd->TargetY, cmd->TargetDir, cmd->ForwardSpeed, cmd->CAEnable, cmd->ReverseDrive);
}

//calvin end

void QNode::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
        case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}
	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	emit loggingUpdated(); // used to readjust the scrollbar
}

}  // namespace drrobot_clinicrobot
