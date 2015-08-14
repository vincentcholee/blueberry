; Auto-generated. Do not edit!


(cl:in-package drrobot_clinicrobot-msg)


;//! \htmlinclude RobotSystemData.msg.html

(cl:defclass <RobotSystemData> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (system_vol
    :reader system_vol
    :initarg :system_vol
    :type cl:float
    :initform 0.0)
   (chargestation_flag
    :reader chargestation_flag
    :initarg :chargestation_flag
    :type cl:fixnum
    :initform 0)
   (charge_flag
    :reader charge_flag
    :initarg :charge_flag
    :type cl:fixnum
    :initform 0)
   (motionboard_vol
    :reader motionboard_vol
    :initarg :motionboard_vol
    :type cl:float
    :initform 0.0)
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
    :initform 0.0)
   (head_tiltangle
    :reader head_tiltangle
    :initarg :head_tiltangle
    :type cl:float
    :initform 0.0)
   (head_panangle
    :reader head_panangle
    :initarg :head_panangle
    :type cl:float
    :initform 0.0)
   (laser_tiltangle
    :reader laser_tiltangle
    :initarg :laser_tiltangle
    :type cl:float
    :initform 0.0)
   (bumpsensor
    :reader bumpsensor
    :initarg :bumpsensor
    :type cl:fixnum
    :initform 0)
   (faceimage_num
    :reader faceimage_num
    :initarg :faceimage_num
    :type cl:fixnum
    :initform 0)
   (power_source
    :reader power_source
    :initarg :power_source
    :type cl:fixnum
    :initform 0))
)

(cl:defclass RobotSystemData (<RobotSystemData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RobotSystemData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RobotSystemData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name drrobot_clinicrobot-msg:<RobotSystemData> is deprecated: use drrobot_clinicrobot-msg:RobotSystemData instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:header-val is deprecated.  Use drrobot_clinicrobot-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'system_vol-val :lambda-list '(m))
(cl:defmethod system_vol-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:system_vol-val is deprecated.  Use drrobot_clinicrobot-msg:system_vol instead.")
  (system_vol m))

(cl:ensure-generic-function 'chargestation_flag-val :lambda-list '(m))
(cl:defmethod chargestation_flag-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:chargestation_flag-val is deprecated.  Use drrobot_clinicrobot-msg:chargestation_flag instead.")
  (chargestation_flag m))

(cl:ensure-generic-function 'charge_flag-val :lambda-list '(m))
(cl:defmethod charge_flag-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:charge_flag-val is deprecated.  Use drrobot_clinicrobot-msg:charge_flag instead.")
  (charge_flag m))

(cl:ensure-generic-function 'motionboard_vol-val :lambda-list '(m))
(cl:defmethod motionboard_vol-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:motionboard_vol-val is deprecated.  Use drrobot_clinicrobot-msg:motionboard_vol instead.")
  (motionboard_vol m))

(cl:ensure-generic-function 'robot_x-val :lambda-list '(m))
(cl:defmethod robot_x-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:robot_x-val is deprecated.  Use drrobot_clinicrobot-msg:robot_x instead.")
  (robot_x m))

(cl:ensure-generic-function 'robot_y-val :lambda-list '(m))
(cl:defmethod robot_y-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:robot_y-val is deprecated.  Use drrobot_clinicrobot-msg:robot_y instead.")
  (robot_y m))

(cl:ensure-generic-function 'robot_heading-val :lambda-list '(m))
(cl:defmethod robot_heading-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:robot_heading-val is deprecated.  Use drrobot_clinicrobot-msg:robot_heading instead.")
  (robot_heading m))

(cl:ensure-generic-function 'head_tiltangle-val :lambda-list '(m))
(cl:defmethod head_tiltangle-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:head_tiltangle-val is deprecated.  Use drrobot_clinicrobot-msg:head_tiltangle instead.")
  (head_tiltangle m))

(cl:ensure-generic-function 'head_panangle-val :lambda-list '(m))
(cl:defmethod head_panangle-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:head_panangle-val is deprecated.  Use drrobot_clinicrobot-msg:head_panangle instead.")
  (head_panangle m))

(cl:ensure-generic-function 'laser_tiltangle-val :lambda-list '(m))
(cl:defmethod laser_tiltangle-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:laser_tiltangle-val is deprecated.  Use drrobot_clinicrobot-msg:laser_tiltangle instead.")
  (laser_tiltangle m))

(cl:ensure-generic-function 'bumpsensor-val :lambda-list '(m))
(cl:defmethod bumpsensor-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:bumpsensor-val is deprecated.  Use drrobot_clinicrobot-msg:bumpsensor instead.")
  (bumpsensor m))

(cl:ensure-generic-function 'faceimage_num-val :lambda-list '(m))
(cl:defmethod faceimage_num-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:faceimage_num-val is deprecated.  Use drrobot_clinicrobot-msg:faceimage_num instead.")
  (faceimage_num m))

(cl:ensure-generic-function 'power_source-val :lambda-list '(m))
(cl:defmethod power_source-val ((m <RobotSystemData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:power_source-val is deprecated.  Use drrobot_clinicrobot-msg:power_source instead.")
  (power_source m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RobotSystemData>) ostream)
  "Serializes a message object of type '<RobotSystemData>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'system_vol))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'chargestation_flag)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_flag)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'motionboard_vol))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
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
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'head_tiltangle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'head_panangle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'laser_tiltangle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bumpsensor)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'faceimage_num)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'power_source)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RobotSystemData>) istream)
  "Deserializes a message object of type '<RobotSystemData>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'system_vol) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'chargestation_flag)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_flag)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'motionboard_vol) (roslisp-utils:decode-single-float-bits bits)))
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
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'head_tiltangle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'head_panangle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'laser_tiltangle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bumpsensor)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'faceimage_num)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'power_source)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RobotSystemData>)))
  "Returns string type for a message object of type '<RobotSystemData>"
  "drrobot_clinicrobot/RobotSystemData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RobotSystemData)))
  "Returns string type for a message object of type 'RobotSystemData"
  "drrobot_clinicrobot/RobotSystemData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RobotSystemData>)))
  "Returns md5sum for a message object of type '<RobotSystemData>"
  "25a427223be51fd4f54e7fa38fa41527")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RobotSystemData)))
  "Returns md5sum for a message object of type 'RobotSystemData"
  "25a427223be51fd4f54e7fa38fa41527")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RobotSystemData>)))
  "Returns full string definition for message of type '<RobotSystemData>"
  (cl:format cl:nil "# system Sensor information message from DrRobot Robot.~%~%Header header    	# timestamp in the header is the time~%float32 system_vol	# system voltage, normally is battery vol, in charge station, it is DC power voltage~%uint8 chargestation_flag	#1-in hcarge station, 0-not~%uint8 charge_flag	# 1- charging, 0- not~%float32 motionboard_vol	# 5V~%float32 robot_x		# robot position X~%float32 robot_y		# robot position Y~%float32 robot_heading	# robot heading unit:radian~%float32 head_tiltangle	# head tile angle, unit: radian~%float32 head_panangle	# head pan angle, unit: radian~%float32 laser_tiltangle	# laser tilting angle, unit:radian~%uint8 bumpsensor	# bump sensor, bit0~bit3~%uint8 faceimage_num		# face image number~%uint8 power_source	# power source, 0- battery, 1 - dc power~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RobotSystemData)))
  "Returns full string definition for message of type 'RobotSystemData"
  (cl:format cl:nil "# system Sensor information message from DrRobot Robot.~%~%Header header    	# timestamp in the header is the time~%float32 system_vol	# system voltage, normally is battery vol, in charge station, it is DC power voltage~%uint8 chargestation_flag	#1-in hcarge station, 0-not~%uint8 charge_flag	# 1- charging, 0- not~%float32 motionboard_vol	# 5V~%float32 robot_x		# robot position X~%float32 robot_y		# robot position Y~%float32 robot_heading	# robot heading unit:radian~%float32 head_tiltangle	# head tile angle, unit: radian~%float32 head_panangle	# head pan angle, unit: radian~%float32 laser_tiltangle	# laser tilting angle, unit:radian~%uint8 bumpsensor	# bump sensor, bit0~bit3~%uint8 faceimage_num		# face image number~%uint8 power_source	# power source, 0- battery, 1 - dc power~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RobotSystemData>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     1
     1
     4
     4
     4
     4
     4
     4
     4
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RobotSystemData>))
  "Converts a ROS message object to a list"
  (cl:list 'RobotSystemData
    (cl:cons ':header (header msg))
    (cl:cons ':system_vol (system_vol msg))
    (cl:cons ':chargestation_flag (chargestation_flag msg))
    (cl:cons ':charge_flag (charge_flag msg))
    (cl:cons ':motionboard_vol (motionboard_vol msg))
    (cl:cons ':robot_x (robot_x msg))
    (cl:cons ':robot_y (robot_y msg))
    (cl:cons ':robot_heading (robot_heading msg))
    (cl:cons ':head_tiltangle (head_tiltangle msg))
    (cl:cons ':head_panangle (head_panangle msg))
    (cl:cons ':laser_tiltangle (laser_tiltangle msg))
    (cl:cons ':bumpsensor (bumpsensor msg))
    (cl:cons ':faceimage_num (faceimage_num msg))
    (cl:cons ':power_source (power_source msg))
))
