; Auto-generated. Do not edit!


(cl:in-package drrobot_clinicrobot-msg)


;//! \htmlinclude LaserDriveData.msg.html

(cl:defclass <LaserDriveData> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (offset_x
    :reader offset_x
    :initarg :offset_x
    :type cl:float
    :initform 0.0)
   (offset_y
    :reader offset_y
    :initarg :offset_y
    :type cl:float
    :initform 0.0)
   (offset_z
    :reader offset_z
    :initarg :offset_z
    :type cl:float
    :initform 0.0)
   (tilt_angle
    :reader tilt_angle
    :initarg :tilt_angle
    :type cl:float
    :initform 0.0)
   (stop_flag
    :reader stop_flag
    :initarg :stop_flag
    :type cl:fixnum
    :initform 0)
   (drive_state
    :reader drive_state
    :initarg :drive_state
    :type cl:fixnum
    :initform 0))
)

(cl:defclass LaserDriveData (<LaserDriveData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LaserDriveData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LaserDriveData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name drrobot_clinicrobot-msg:<LaserDriveData> is deprecated: use drrobot_clinicrobot-msg:LaserDriveData instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LaserDriveData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:header-val is deprecated.  Use drrobot_clinicrobot-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'offset_x-val :lambda-list '(m))
(cl:defmethod offset_x-val ((m <LaserDriveData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:offset_x-val is deprecated.  Use drrobot_clinicrobot-msg:offset_x instead.")
  (offset_x m))

(cl:ensure-generic-function 'offset_y-val :lambda-list '(m))
(cl:defmethod offset_y-val ((m <LaserDriveData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:offset_y-val is deprecated.  Use drrobot_clinicrobot-msg:offset_y instead.")
  (offset_y m))

(cl:ensure-generic-function 'offset_z-val :lambda-list '(m))
(cl:defmethod offset_z-val ((m <LaserDriveData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:offset_z-val is deprecated.  Use drrobot_clinicrobot-msg:offset_z instead.")
  (offset_z m))

(cl:ensure-generic-function 'tilt_angle-val :lambda-list '(m))
(cl:defmethod tilt_angle-val ((m <LaserDriveData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:tilt_angle-val is deprecated.  Use drrobot_clinicrobot-msg:tilt_angle instead.")
  (tilt_angle m))

(cl:ensure-generic-function 'stop_flag-val :lambda-list '(m))
(cl:defmethod stop_flag-val ((m <LaserDriveData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:stop_flag-val is deprecated.  Use drrobot_clinicrobot-msg:stop_flag instead.")
  (stop_flag m))

(cl:ensure-generic-function 'drive_state-val :lambda-list '(m))
(cl:defmethod drive_state-val ((m <LaserDriveData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:drive_state-val is deprecated.  Use drrobot_clinicrobot-msg:drive_state instead.")
  (drive_state m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LaserDriveData>) ostream)
  "Serializes a message object of type '<LaserDriveData>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'offset_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'offset_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'offset_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'tilt_angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'stop_flag)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'drive_state)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LaserDriveData>) istream)
  "Deserializes a message object of type '<LaserDriveData>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'offset_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'offset_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'offset_z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'tilt_angle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'stop_flag)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'drive_state)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LaserDriveData>)))
  "Returns string type for a message object of type '<LaserDriveData>"
  "drrobot_clinicrobot/LaserDriveData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LaserDriveData)))
  "Returns string type for a message object of type 'LaserDriveData"
  "drrobot_clinicrobot/LaserDriveData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LaserDriveData>)))
  "Returns md5sum for a message object of type '<LaserDriveData>"
  "cd9fa55f9b4bc78c1d63654d78099ba1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LaserDriveData)))
  "Returns md5sum for a message object of type 'LaserDriveData"
  "cd9fa55f9b4bc78c1d63654d78099ba1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LaserDriveData>)))
  "Returns full string definition for message of type '<LaserDriveData>"
  (cl:format cl:nil "# laser tilting driving module information message from DrRobot Robot.~%~%Header header    	# timestamp in the header is the time the ~%~%float32 offset_x	# link with robot base~%float32 offset_y	# base link~%float32 offset_z	# base link~%float32 tilt_angle	# base link~%uint8 stop_flag		# move or not, 0-stop~%uint8 drive_state	# drive board state~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LaserDriveData)))
  "Returns full string definition for message of type 'LaserDriveData"
  (cl:format cl:nil "# laser tilting driving module information message from DrRobot Robot.~%~%Header header    	# timestamp in the header is the time the ~%~%float32 offset_x	# link with robot base~%float32 offset_y	# base link~%float32 offset_z	# base link~%float32 tilt_angle	# base link~%uint8 stop_flag		# move or not, 0-stop~%uint8 drive_state	# drive board state~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LaserDriveData>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LaserDriveData>))
  "Converts a ROS message object to a list"
  (cl:list 'LaserDriveData
    (cl:cons ':header (header msg))
    (cl:cons ':offset_x (offset_x msg))
    (cl:cons ':offset_y (offset_y msg))
    (cl:cons ':offset_z (offset_z msg))
    (cl:cons ':tilt_angle (tilt_angle msg))
    (cl:cons ':stop_flag (stop_flag msg))
    (cl:cons ':drive_state (drive_state msg))
))
