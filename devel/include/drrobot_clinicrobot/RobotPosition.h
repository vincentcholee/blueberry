// Generated by gencpp from file drrobot_clinicrobot/RobotPosition.msg
// DO NOT EDIT!


#ifndef DRROBOT_CLINICROBOT_MESSAGE_ROBOTPOSITION_H
#define DRROBOT_CLINICROBOT_MESSAGE_ROBOTPOSITION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace drrobot_clinicrobot
{
template <class ContainerAllocator>
struct RobotPosition_
{
  typedef RobotPosition_<ContainerAllocator> Type;

  RobotPosition_()
    : header()
    , robot_x(0.0)
    , robot_y(0.0)
    , robot_heading(0.0)  {
    }
  RobotPosition_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , robot_x(0.0)
    , robot_y(0.0)
    , robot_heading(0.0)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef float _robot_x_type;
  _robot_x_type robot_x;

   typedef float _robot_y_type;
  _robot_y_type robot_y;

   typedef float _robot_heading_type;
  _robot_heading_type robot_heading;




  typedef boost::shared_ptr< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> const> ConstPtr;

}; // struct RobotPosition_

typedef ::drrobot_clinicrobot::RobotPosition_<std::allocator<void> > RobotPosition;

typedef boost::shared_ptr< ::drrobot_clinicrobot::RobotPosition > RobotPositionPtr;
typedef boost::shared_ptr< ::drrobot_clinicrobot::RobotPosition const> RobotPositionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace drrobot_clinicrobot

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'drrobot_clinicrobot': ['/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0ac379ad435e9dde0e291abbdaeea644";
  }

  static const char* value(const ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0ac379ad435e9ddeULL;
  static const uint64_t static_value2 = 0x0e291abbdaeea644ULL;
};

template<class ContainerAllocator>
struct DataType< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "drrobot_clinicrobot/RobotPosition";
  }

  static const char* value(const ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# robot position information message from DrRobot Robot.\n\
# it could be from encoder dead reckoning, or from Indoor GPS\n\
Header header    	# timestamp in the header is the time the \n\
\n\
#make sure below sensors on your robot or not\n\
float32 robot_x	# robot x position reading\n\
float32 robot_y	#robot y position reading\n\
float32 robot_heading	# robot heading reading\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.robot_x);
      stream.next(m.robot_y);
      stream.next(m.robot_heading);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct RobotPosition_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::drrobot_clinicrobot::RobotPosition_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "robot_x: ";
    Printer<float>::stream(s, indent + "  ", v.robot_x);
    s << indent << "robot_y: ";
    Printer<float>::stream(s, indent + "  ", v.robot_y);
    s << indent << "robot_heading: ";
    Printer<float>::stream(s, indent + "  ", v.robot_heading);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DRROBOT_CLINICROBOT_MESSAGE_ROBOTPOSITION_H