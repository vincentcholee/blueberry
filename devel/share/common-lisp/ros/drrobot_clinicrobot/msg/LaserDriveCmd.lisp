; Auto-generated. Do not edit!


(cl:in-package drrobot_clinicrobot-msg)


;//! \htmlinclude LaserDriveCmd.msg.html

(cl:defclass <LaserDriveCmd> (roslisp-msg-protocol:ros-message)
  ((tilt_pos
    :reader tilt_pos
    :initarg :tilt_pos
    :type cl:float
    :initform 0.0)
   (auto_scan_flag
    :reader auto_scan_flag
    :initarg :auto_scan_flag
    :type cl:integer
    :initform 0))
)

(cl:defclass LaserDriveCmd (<LaserDriveCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LaserDriveCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LaserDriveCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name drrobot_clinicrobot-msg:<LaserDriveCmd> is deprecated: use drrobot_clinicrobot-msg:LaserDriveCmd instead.")))

(cl:ensure-generic-function 'tilt_pos-val :lambda-list '(m))
(cl:defmethod tilt_pos-val ((m <LaserDriveCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:tilt_pos-val is deprecated.  Use drrobot_clinicrobot-msg:tilt_pos instead.")
  (tilt_pos m))

(cl:ensure-generic-function 'auto_scan_flag-val :lambda-list '(m))
(cl:defmethod auto_scan_flag-val ((m <LaserDriveCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:auto_scan_flag-val is deprecated.  Use drrobot_clinicrobot-msg:auto_scan_flag instead.")
  (auto_scan_flag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LaserDriveCmd>) ostream)
  "Serializes a message object of type '<LaserDriveCmd>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'tilt_pos))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'auto_scan_flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LaserDriveCmd>) istream)
  "Deserializes a message object of type '<LaserDriveCmd>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'tilt_pos) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'auto_scan_flag) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LaserDriveCmd>)))
  "Returns string type for a message object of type '<LaserDriveCmd>"
  "drrobot_clinicrobot/LaserDriveCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LaserDriveCmd)))
  "Returns string type for a message object of type 'LaserDriveCmd"
  "drrobot_clinicrobot/LaserDriveCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LaserDriveCmd>)))
  "Returns md5sum for a message object of type '<LaserDriveCmd>"
  "4014e77e6d883222bc1b69ceb9b011b5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LaserDriveCmd)))
  "Returns md5sum for a message object of type 'LaserDriveCmd"
  "4014e77e6d883222bc1b69ceb9b011b5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LaserDriveCmd>)))
  "Returns full string definition for message of type '<LaserDriveCmd>"
  (cl:format cl:nil "# laser motor command message from DrRobot Robot.~%float32 tilt_pos		# laser tilt angle(-20~20), unit:degree~%int32 auto_scan_flag	# 1- auto scan, 0 -stop ,-1, just position contorl~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LaserDriveCmd)))
  "Returns full string definition for message of type 'LaserDriveCmd"
  (cl:format cl:nil "# laser motor command message from DrRobot Robot.~%float32 tilt_pos		# laser tilt angle(-20~20), unit:degree~%int32 auto_scan_flag	# 1- auto scan, 0 -stop ,-1, just position contorl~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LaserDriveCmd>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LaserDriveCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'LaserDriveCmd
    (cl:cons ':tilt_pos (tilt_pos msg))
    (cl:cons ':auto_scan_flag (auto_scan_flag msg))
))
