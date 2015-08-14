; Auto-generated. Do not edit!


(cl:in-package drrobot_clinicrobot-msg)


;//! \htmlinclude RobotPosition.msg.html

(cl:defclass <RobotPosition> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (robot_x
    :reader robot_x
    :initarg :robot_x
    :type cl:float
    :initform 0.0)
   (robot_y
    :reader robot_y
    :initarg :robot_y
    :type cl:float
    :initform 0.0)
   (robot_heading
    :reader robot_heading
    :initarg :robot_heading
    :type cl:float
    :initform 0.0))
)

(cl:defclass RobotPosition (<RobotPosition>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RobotPosition>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RobotPosition)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name drrobot_clinicrobot-msg:<RobotPosition> is deprecated: use drrobot_clinicrobot-msg:RobotPosition instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <RobotPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:header-val is deprecated.  Use drrobot_clinicrobot-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'robot_x-val :lambda-list '(m))
(cl:defmethod robot_x-val ((m <RobotPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:robot_x-val is deprecated.  Use drrobot_clinicrobot-msg:robot_x instead.")
  (robot_x m))

(cl:ensure-generic-function 'robot_y-val :lambda-list '(m))
(cl:defmethod robot_y-val ((m <RobotPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:robot_y-val is deprecated.  Use drrobot_clinicrobot-msg:robot_y instead.")
  (robot_y m))

(cl:ensure-generic-function 'robot_heading-val :lambda-list '(m))
(cl:defmethod robot_heading-val ((m <RobotPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:robot_heading-val is deprecated.  Use drrobot_clinicrobot-msg:robot_heading instead.")
  (robot_heading m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RobotPosition>) ostream)
  "Serializes a message object of type '<RobotPosition>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'robot_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'robot_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'robot_heading))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RobotPosition>) istream)
  "Deserializes a message object of type '<RobotPosition>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'robot_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'robot_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'robot_heading) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RobotPosition>)))
  "Returns string type for a message object of type '<RobotPosition>"
  "drrobot_clinicrobot/RobotPosition")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RobotPosition)))
  "Returns string type for a message object of type 'RobotPosition"
  "drrobot_clinicrobot/RobotPosition")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RobotPosition>)))
  "Returns md5sum for a message object of type '<RobotPosition>"
  "0ac379ad435e9dde0e291abbdaeea644")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RobotPosition)))
  "Returns md5sum for a message object of type 'RobotPosition"
  "0ac379ad435e9dde0e291abbdaeea644")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RobotPosition>)))
  "Returns full string definition for message of type '<RobotPosition>"
  (cl:format cl:nil "# robot position information message from DrRobot Robot.~%# it could be from encoder dead reckoning, or from Indoor GPS~%Header header    	# timestamp in the header is the time the ~%~%#make sure below sensors on your robot or not~%float32 robot_x	# robot x position reading~%float32 robot_y	#robot y position reading~%float32 robot_heading	# robot heading reading~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RobotPosition)))
  "Returns full string definition for message of type 'RobotPosition"
  (cl:format cl:nil "# robot position information message from DrRobot Robot.~%# it could be from encoder dead reckoning, or from Indoor GPS~%Header header    	# timestamp in the header is the time the ~%~%#make sure below sensors on your robot or not~%float32 robot_x	# robot x position reading~%float32 robot_y	#robot y position reading~%float32 robot_heading	# robot heading reading~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RobotPosition>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RobotPosition>))
  "Converts a ROS message object to a list"
  (cl:list 'RobotPosition
    (cl:cons ':header (header msg))
    (cl:cons ':robot_x (robot_x msg))
    (cl:cons ':robot_y (robot_y msg))
    (cl:cons ':robot_heading (robot_heading msg))
))
