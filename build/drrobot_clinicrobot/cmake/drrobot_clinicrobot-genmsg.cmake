# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "drrobot_clinicrobot: 13 messages, 0 services")

set(MSG_I_FLAGS "-Idrrobot_clinicrobot:/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(drrobot_clinicrobot_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveCmd.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveCmd.msg" ""
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/PowerInfo.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/PowerInfo.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotSystemData.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotSystemData.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RangeArray.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RangeArray.msg" "drrobot_clinicrobot/Range:std_msgs/Header"
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/HeadCmd.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/HeadCmd.msg" ""
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveData.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveData.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/BumpSensor.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/BumpSensor.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfoArray.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfoArray.msg" "drrobot_clinicrobot/MotorInfo:std_msgs/Header"
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/IndoorGPS.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/IndoorGPS.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorCmd.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorCmd.msg" ""
)

get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotPosition.msg" NAME_WE)
add_custom_target(_drrobot_clinicrobot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "drrobot_clinicrobot" "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotPosition.msg" "std_msgs/Header"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/PowerInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RangeArray.msg"
  "${MSG_I_FLAGS}"
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotSystemData.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/HeadCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveData.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/BumpSensor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfoArray.msg"
  "${MSG_I_FLAGS}"
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/IndoorGPS.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_cpp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotPosition.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
)

### Generating Services

### Generating Module File
_generate_module_cpp(drrobot_clinicrobot
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(drrobot_clinicrobot_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(drrobot_clinicrobot_generate_messages drrobot_clinicrobot_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveCmd.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/PowerInfo.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotSystemData.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RangeArray.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/HeadCmd.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveData.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/BumpSensor.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfoArray.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/IndoorGPS.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorCmd.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotPosition.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_cpp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(drrobot_clinicrobot_gencpp)
add_dependencies(drrobot_clinicrobot_gencpp drrobot_clinicrobot_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS drrobot_clinicrobot_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/PowerInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RangeArray.msg"
  "${MSG_I_FLAGS}"
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotSystemData.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/HeadCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveData.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/BumpSensor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfoArray.msg"
  "${MSG_I_FLAGS}"
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/IndoorGPS.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_lisp(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotPosition.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
)

### Generating Services

### Generating Module File
_generate_module_lisp(drrobot_clinicrobot
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(drrobot_clinicrobot_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(drrobot_clinicrobot_generate_messages drrobot_clinicrobot_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveCmd.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/PowerInfo.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotSystemData.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RangeArray.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/HeadCmd.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveData.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/BumpSensor.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfoArray.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/IndoorGPS.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorCmd.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotPosition.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_lisp _drrobot_clinicrobot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(drrobot_clinicrobot_genlisp)
add_dependencies(drrobot_clinicrobot_genlisp drrobot_clinicrobot_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS drrobot_clinicrobot_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/PowerInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RangeArray.msg"
  "${MSG_I_FLAGS}"
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotSystemData.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/HeadCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveData.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/BumpSensor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfoArray.msg"
  "${MSG_I_FLAGS}"
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/IndoorGPS.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorCmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)
_generate_msg_py(drrobot_clinicrobot
  "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotPosition.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
)

### Generating Services

### Generating Module File
_generate_module_py(drrobot_clinicrobot
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(drrobot_clinicrobot_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(drrobot_clinicrobot_generate_messages drrobot_clinicrobot_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveCmd.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/PowerInfo.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotSystemData.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RangeArray.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/HeadCmd.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveData.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/BumpSensor.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfoArray.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/IndoorGPS.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorCmd.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotPosition.msg" NAME_WE)
add_dependencies(drrobot_clinicrobot_generate_messages_py _drrobot_clinicrobot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(drrobot_clinicrobot_genpy)
add_dependencies(drrobot_clinicrobot_genpy drrobot_clinicrobot_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS drrobot_clinicrobot_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/drrobot_clinicrobot
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(drrobot_clinicrobot_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/drrobot_clinicrobot
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(drrobot_clinicrobot_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/drrobot_clinicrobot
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(drrobot_clinicrobot_generate_messages_py std_msgs_generate_messages_py)
