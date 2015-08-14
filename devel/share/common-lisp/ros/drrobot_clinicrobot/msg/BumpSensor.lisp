; Auto-generated. Do not edit!


(cl:in-package drrobot_clinicrobot-msg)


;//! \htmlinclude BumpSensor.msg.html

(cl:defclass <BumpSensor> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (bump_sw1
    :reader bump_sw1
    :initarg :bump_sw1
    :type cl:fixnum
    :initform 0)
   (bump_sw2
    :reader bump_sw2
    :initarg :bump_sw2
    :type cl:fixnum
    :initform 0)
   (bump_sw3
    :reader bump_sw3
    :initarg :bump_sw3
    :type cl:fixnum
    :initform 0)
   (bump_sw4
    :reader bump_sw4
    :initarg :bump_sw4
    :type cl:fixnum
    :initform 0))
)

(cl:defclass BumpSensor (<BumpSensor>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BumpSensor>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BumpSensor)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name drrobot_clinicrobot-msg:<BumpSensor> is deprecated: use drrobot_clinicrobot-msg:BumpSensor instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <BumpSensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:header-val is deprecated.  Use drrobot_clinicrobot-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'bump_sw1-val :lambda-list '(m))
(cl:defmethod bump_sw1-val ((m <BumpSensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:bump_sw1-val is deprecated.  Use drrobot_clinicrobot-msg:bump_sw1 instead.")
  (bump_sw1 m))

(cl:ensure-generic-function 'bump_sw2-val :lambda-list '(m))
(cl:defmethod bump_sw2-val ((m <BumpSensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:bump_sw2-val is deprecated.  Use drrobot_clinicrobot-msg:bump_sw2 instead.")
  (bump_sw2 m))

(cl:ensure-generic-function 'bump_sw3-val :lambda-list '(m))
(cl:defmethod bump_sw3-val ((m <BumpSensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:bump_sw3-val is deprecated.  Use drrobot_clinicrobot-msg:bump_sw3 instead.")
  (bump_sw3 m))

(cl:ensure-generic-function 'bump_sw4-val :lambda-list '(m))
(cl:defmethod bump_sw4-val ((m <BumpSensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:bump_sw4-val is deprecated.  Use drrobot_clinicrobot-msg:bump_sw4 instead.")
  (bump_sw4 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BumpSensor>) ostream)
  "Serializes a message object of type '<BumpSensor>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bump_sw1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bump_sw2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bump_sw3)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bump_sw4)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BumpSensor>) istream)
  "Deserializes a message object of type '<BumpSensor>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bump_sw1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bump_sw2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bump_sw3)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bump_sw4)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BumpSensor>)))
  "Returns string type for a message object of type '<BumpSensor>"
  "drrobot_clinicrobot/BumpSensor")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BumpSensor)))
  "Returns string type for a message object of type 'BumpSensor"
  "drrobot_clinicrobot/BumpSensor")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BumpSensor>)))
  "Returns md5sum for a message object of type '<BumpSensor>"
  "555b7e3f76b2263507508b9011bd9a1a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BumpSensor)))
  "Returns md5sum for a message object of type 'BumpSensor"
  "555b7e3f76b2263507508b9011bd9a1a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BumpSensor>)))
  "Returns full string definition for message of type '<BumpSensor>"
  (cl:format cl:nil "# Bump Sensor information message from DrRobot Robot.~%~%Header header    	# timestamp in the header is the time~%uint8 bump_sw1		# middle_right~%uint8 bump_sw2		# right~%uint8 bump_sw3		# middle_left~%uint8 bump_sw4		# left~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BumpSensor)))
  "Returns full string definition for message of type 'BumpSensor"
  (cl:format cl:nil "# Bump Sensor information message from DrRobot Robot.~%~%Header header    	# timestamp in the header is the time~%uint8 bump_sw1		# middle_right~%uint8 bump_sw2		# right~%uint8 bump_sw3		# middle_left~%uint8 bump_sw4		# left~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BumpSensor>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BumpSensor>))
  "Converts a ROS message object to a list"
  (cl:list 'BumpSensor
    (cl:cons ':header (header msg))
    (cl:cons ':bump_sw1 (bump_sw1 msg))
    (cl:cons ':bump_sw2 (bump_sw2 msg))
    (cl:cons ':bump_sw3 (bump_sw3 msg))
    (cl:cons ':bump_sw4 (bump_sw4 msg))
))
