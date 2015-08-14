# Install script for directory: /home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/drrobot2/hokuyo_exp/install")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/drrobot_clinicrobot/msg" TYPE FILE FILES
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/BumpSensor.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/IndoorGPS.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveData.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfo.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorInfoArray.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/PowerInfo.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/Range.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RangeArray.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotPosition.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/MotorCmd.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/RobotSystemData.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/LaserDriveCmd.msg"
    "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/msg/HeadCmd.msg"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/drrobot_clinicrobot/cmake" TYPE FILE FILES "/home/drrobot2/hokuyo_exp/build/drrobot_clinicrobot/catkin_generated/installspace/drrobot_clinicrobot-msg-paths.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/drrobot2/hokuyo_exp/devel/include/drrobot_clinicrobot")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/drrobot2/hokuyo_exp/devel/share/common-lisp/ros/drrobot_clinicrobot")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/drrobot2/hokuyo_exp/devel/lib/python2.7/dist-packages/drrobot_clinicrobot")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/drrobot2/hokuyo_exp/devel/lib/python2.7/dist-packages/drrobot_clinicrobot")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/drrobot2/hokuyo_exp/build/drrobot_clinicrobot/catkin_generated/installspace/drrobot_clinicrobot.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/drrobot_clinicrobot/cmake" TYPE FILE FILES "/home/drrobot2/hokuyo_exp/build/drrobot_clinicrobot/catkin_generated/installspace/drrobot_clinicrobot-msg-extras.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/drrobot_clinicrobot/cmake" TYPE FILE FILES
    "/home/drrobot2/hokuyo_exp/build/drrobot_clinicrobot/catkin_generated/installspace/drrobot_clinicrobotConfig.cmake"
    "/home/drrobot2/hokuyo_exp/build/drrobot_clinicrobot/catkin_generated/installspace/drrobot_clinicrobotConfig-version.cmake"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/drrobot_clinicrobot" TYPE FILE FILES "/home/drrobot2/hokuyo_exp/src/drrobot_clinicrobot/package.xml")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

