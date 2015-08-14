; Auto-generated. Do not edit!


(cl:in-package drrobot_clinicrobot-msg)


;//! \htmlinclude IndoorGPS.msg.html

(cl:defclass <IndoorGPS> (roslisp-msg-protocol:ros-message)
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
    :initform 0.0)
   (markid_height
    :reader markid_height
    :initarg :markid_height
    :type cl:float
    :initform 0.0)
   (mark_id
    :reader mark_id
    :initarg :mark_id
    :type cl:integer
    :initform 0)
   (valid_flag
    :reader valid_flag
    :initarg :valid_flag
    :type cl:fixnum
    :initform 0))
)

(cl:defclass IndoorGPS (<IndoorGPS>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <IndoorGPS>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'IndoorGPS)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name drrobot_clinicrobot-msg:<IndoorGPS> is deprecated: use drrobot_clinicrobot-msg:IndoorGPS instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <IndoorGPS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:header-val is deprecated.  Use drrobot_clinicrobot-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'robot_x-val :lambda-list '(m))
(cl:defmethod robot_x-val ((m <IndoorGPS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:robot_x-val is deprecated.  Use drrobot_clinicrobot-msg:robot_x instead.")
  (robot_x m))

(cl:ensure-generic-function 'robot_y-val :lambda-list '(m))
(cl:defmethod robot_y-val ((m <IndoorGPS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:robot_y-val is deprecated.  Use drrobot_clinicrobot-msg:robot_y instead.")
  (robot_y m))

(cl:ensure-generic-function 'robot_heading-val :lambda-list '(m))
(cl:defmethod robot_heading-val ((m <IndoorGPS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:robot_heading-val is deprecated.  Use drrobot_clinicrobot-msg:robot_heading instead.")
  (robot_heading m))

(cl:ensure-generic-function 'markid_height-val :lambda-list '(m))
(cl:defmethod markid_height-val ((m <IndoorGPS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:markid_height-val is deprecated.  Use drrobot_clinicrobot-msg:markid_height instead.")
  (markid_height m))

(cl:ensure-generic-function 'mark_id-val :lambda-list '(m))
(cl:defmethod mark_id-val ((m <IndoorGPS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:mark_id-val is deprecated.  Use drrobot_clinicrobot-msg:mark_id instead.")
  (mark_id m))

(cl:ensure-generic-function 'valid_flag-val :lambda-list '(m))
(cl:defmethod valid_flag-val ((m <IndoorGPS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:valid_flag-val is deprecated.  Use drrobot_clinicrobot-msg:valid_flag instead.")
  (valid_flag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <IndoorGPS>) ostream)
  "Serializes a message object of type '<IndoorGPS>"
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
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'markid_height))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mark_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mark_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mark_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mark_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'valid_flag)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <IndoorGPS>) istream)
  "Deserializes a message object of type '<IndoorGPS>"
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
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'markid_height) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mark_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'mark_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'mark_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'mark_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'valid_flag)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<IndoorGPS>)))
  "Returns string type for a message object of type '<IndoorGPS>"
  "drrobot_clinicrobot/IndoorGPS")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IndoorGPS)))
  "Returns string type for a message object of type 'IndoorGPS"
  "drrobot_clinicrobot/IndoorGPS")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<IndoorGPS>)))
  "Returns md5sum for a message object of type '<IndoorGPS>"
  "28c7106d8f3f5a0bd38a8f7719376e0a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'IndoorGPS)))
  "Returns md5sum for a message object of type 'IndoorGPS"
  "28c7106d8f3f5a0bd38a8f7719376e0a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<IndoorGPS>)))
  "Returns full string definition for message of type '<IndoorGPS>"
  (cl:format cl:nil "# InDoor GPS Sensor information message from DrRobot Robot.~%~%Header header    	# timestamp in the header is the time the ~%~%#make sure below sensors on your robot or not~%float32 robot_x	# robot x position reading~%float32 robot_y	#robot y position reading~%float32 robot_heading	# robot heading reading~%float32 markid_height	# mark height~%uint32 mark_id		# mark ID~%uint8 valid_flag	# valid or not, 0- in dead zone, no reading~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'IndoorGPS)))
  "Returns full string definition for message of type 'IndoorGPS"
  (cl:format cl:nil "# InDoor GPS Sensor information message from DrRobot Robot.~%~%Header header    	# timestamp in the header is the time the ~%~%#make sure below sensors on your robot or not~%float32 robot_x	# robot x position reading~%float32 robot_y	#robot y position reading~%float32 robot_heading	# robot heading reading~%float32 markid_height	# mark height~%uint32 mark_id		# mark ID~%uint8 valid_flag	# valid or not, 0- in dead zone, no reading~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <IndoorGPS>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <IndoorGPS>))
  "Converts a ROS message object to a list"
  (cl:list 'IndoorGPS
    (cl:cons ':header (header msg))
    (cl:cons ':robot_x (robot_x msg))
    (cl:cons ':robot_y (robot_y msg))
    (cl:cons ':robot_heading (robot_heading msg))
    (cl:cons ':markid_height (markid_height msg))
    (cl:cons ':mark_id (mark_id msg))
    (cl:cons ':valid_flag (valid_flag msg))
))
