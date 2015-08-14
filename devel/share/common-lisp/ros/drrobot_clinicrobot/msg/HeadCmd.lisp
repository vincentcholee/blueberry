; Auto-generated. Do not edit!


(cl:in-package drrobot_clinicrobot-msg)


;//! \htmlinclude HeadCmd.msg.html

(cl:defclass <HeadCmd> (roslisp-msg-protocol:ros-message)
  ((head_tilt_pos
    :reader head_tilt_pos
    :initarg :head_tilt_pos
    :type cl:float
    :initform 0.0)
   (head_tiltflag
    :reader head_tiltflag
    :initarg :head_tiltflag
    :type cl:fixnum
    :initform 0)
   (head_tilt_time
    :reader head_tilt_time
    :initarg :head_tilt_time
    :type cl:integer
    :initform 0)
   (head_pan_pos
    :reader head_pan_pos
    :initarg :head_pan_pos
    :type cl:float
    :initform 0.0)
   (head_panflag
    :reader head_panflag
    :initarg :head_panflag
    :type cl:fixnum
    :initform 0)
   (head_pan_time
    :reader head_pan_time
    :initarg :head_pan_time
    :type cl:integer
    :initform 0))
)

(cl:defclass HeadCmd (<HeadCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HeadCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HeadCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name drrobot_clinicrobot-msg:<HeadCmd> is deprecated: use drrobot_clinicrobot-msg:HeadCmd instead.")))

(cl:ensure-generic-function 'head_tilt_pos-val :lambda-list '(m))
(cl:defmethod head_tilt_pos-val ((m <HeadCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:head_tilt_pos-val is deprecated.  Use drrobot_clinicrobot-msg:head_tilt_pos instead.")
  (head_tilt_pos m))

(cl:ensure-generic-function 'head_tiltflag-val :lambda-list '(m))
(cl:defmethod head_tiltflag-val ((m <HeadCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:head_tiltflag-val is deprecated.  Use drrobot_clinicrobot-msg:head_tiltflag instead.")
  (head_tiltflag m))

(cl:ensure-generic-function 'head_tilt_time-val :lambda-list '(m))
(cl:defmethod head_tilt_time-val ((m <HeadCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:head_tilt_time-val is deprecated.  Use drrobot_clinicrobot-msg:head_tilt_time instead.")
  (head_tilt_time m))

(cl:ensure-generic-function 'head_pan_pos-val :lambda-list '(m))
(cl:defmethod head_pan_pos-val ((m <HeadCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:head_pan_pos-val is deprecated.  Use drrobot_clinicrobot-msg:head_pan_pos instead.")
  (head_pan_pos m))

(cl:ensure-generic-function 'head_panflag-val :lambda-list '(m))
(cl:defmethod head_panflag-val ((m <HeadCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:head_panflag-val is deprecated.  Use drrobot_clinicrobot-msg:head_panflag instead.")
  (head_panflag m))

(cl:ensure-generic-function 'head_pan_time-val :lambda-list '(m))
(cl:defmethod head_pan_time-val ((m <HeadCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:head_pan_time-val is deprecated.  Use drrobot_clinicrobot-msg:head_pan_time instead.")
  (head_pan_time m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HeadCmd>) ostream)
  "Serializes a message object of type '<HeadCmd>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'head_tilt_pos))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'head_tiltflag)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'head_tilt_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'head_tilt_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'head_tilt_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'head_tilt_time)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'head_pan_pos))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'head_panflag)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'head_pan_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'head_pan_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'head_pan_time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'head_pan_time)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HeadCmd>) istream)
  "Deserializes a message object of type '<HeadCmd>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'head_tilt_pos) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'head_tiltflag)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'head_tilt_time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'head_tilt_time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'head_tilt_time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'head_tilt_time)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'head_pan_pos) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'head_panflag)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'head_pan_time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'head_pan_time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'head_pan_time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'head_pan_time)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HeadCmd>)))
  "Returns string type for a message object of type '<HeadCmd>"
  "drrobot_clinicrobot/HeadCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HeadCmd)))
  "Returns string type for a message object of type 'HeadCmd"
  "drrobot_clinicrobot/HeadCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HeadCmd>)))
  "Returns md5sum for a message object of type '<HeadCmd>"
  "33b58503880791edf7de4962dc56195c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HeadCmd)))
  "Returns md5sum for a message object of type 'HeadCmd"
  "33b58503880791edf7de4962dc56195c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HeadCmd>)))
  "Returns full string definition for message of type '<HeadCmd>"
  (cl:format cl:nil "# head motor command message from DrRobot Robot.~%float32 head_tilt_pos		# head tilt angle(-40~40) unit:degree~%uint8 head_tiltflag	        # head tilt flag, 0- no control, 1- control~%uint32 head_tilt_time		# for head tilt position command time~% ~%float32 head_pan_pos		# head pan angle(-90~90), unit:degree~%uint8 head_panflag	        # head pan flag, 0- no control, 1- control~%uint32 head_pan_time		# for head pan position command time~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HeadCmd)))
  "Returns full string definition for message of type 'HeadCmd"
  (cl:format cl:nil "# head motor command message from DrRobot Robot.~%float32 head_tilt_pos		# head tilt angle(-40~40) unit:degree~%uint8 head_tiltflag	        # head tilt flag, 0- no control, 1- control~%uint32 head_tilt_time		# for head tilt position command time~% ~%float32 head_pan_pos		# head pan angle(-90~90), unit:degree~%uint8 head_panflag	        # head pan flag, 0- no control, 1- control~%uint32 head_pan_time		# for head pan position command time~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HeadCmd>))
  (cl:+ 0
     4
     1
     4
     4
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HeadCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'HeadCmd
    (cl:cons ':head_tilt_pos (head_tilt_pos msg))
    (cl:cons ':head_tiltflag (head_tiltflag msg))
    (cl:cons ':head_tilt_time (head_tilt_time msg))
    (cl:cons ':head_pan_pos (head_pan_pos msg))
    (cl:cons ':head_panflag (head_panflag msg))
    (cl:cons ':head_pan_time (head_pan_time msg))
))
