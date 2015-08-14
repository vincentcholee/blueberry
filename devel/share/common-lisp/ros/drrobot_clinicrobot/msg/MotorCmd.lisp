; Auto-generated. Do not edit!


(cl:in-package drrobot_clinicrobot-msg)


;//! \htmlinclude MotorCmd.msg.html

(cl:defclass <MotorCmd> (roslisp-msg-protocol:ros-message)
  ((motorcmd1
    :reader motorcmd1
    :initarg :motorcmd1
    :type cl:integer
    :initform 0)
   (motorCmd2
    :reader motorCmd2
    :initarg :motorCmd2
    :type cl:integer
    :initform 0)
   (motorCtrl
    :reader motorCtrl
    :initarg :motorCtrl
    :type cl:integer
    :initform 0))
)

(cl:defclass MotorCmd (<MotorCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MotorCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MotorCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name drrobot_clinicrobot-msg:<MotorCmd> is deprecated: use drrobot_clinicrobot-msg:MotorCmd instead.")))

(cl:ensure-generic-function 'motorcmd1-val :lambda-list '(m))
(cl:defmethod motorcmd1-val ((m <MotorCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:motorcmd1-val is deprecated.  Use drrobot_clinicrobot-msg:motorcmd1 instead.")
  (motorcmd1 m))

(cl:ensure-generic-function 'motorCmd2-val :lambda-list '(m))
(cl:defmethod motorCmd2-val ((m <MotorCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:motorCmd2-val is deprecated.  Use drrobot_clinicrobot-msg:motorCmd2 instead.")
  (motorCmd2 m))

(cl:ensure-generic-function 'motorCtrl-val :lambda-list '(m))
(cl:defmethod motorCtrl-val ((m <MotorCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:motorCtrl-val is deprecated.  Use drrobot_clinicrobot-msg:motorCtrl instead.")
  (motorCtrl m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MotorCmd>) ostream)
  "Serializes a message object of type '<MotorCmd>"
  (cl:let* ((signed (cl:slot-value msg 'motorcmd1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'motorCmd2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'motorCtrl)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MotorCmd>) istream)
  "Deserializes a message object of type '<MotorCmd>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motorcmd1) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motorCmd2) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'motorCtrl) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MotorCmd>)))
  "Returns string type for a message object of type '<MotorCmd>"
  "drrobot_clinicrobot/MotorCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MotorCmd)))
  "Returns string type for a message object of type 'MotorCmd"
  "drrobot_clinicrobot/MotorCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MotorCmd>)))
  "Returns md5sum for a message object of type '<MotorCmd>"
  "83414dfe9e393966fab06f8909c63052")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MotorCmd)))
  "Returns md5sum for a message object of type 'MotorCmd"
  "83414dfe9e393966fab06f8909c63052")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MotorCmd>)))
  "Returns full string definition for message of type '<MotorCmd>"
  (cl:format cl:nil "# wheel motor command message from DrRobot Robot.~%int32 motorcmd1		# left motor encoder command value~%int32 motorCmd2	        # right motor encoder Comamnd value~%int32 motorCtrl		# motor ctrl method , 0-- PWM, 1-- velocity  2-- position~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MotorCmd)))
  "Returns full string definition for message of type 'MotorCmd"
  (cl:format cl:nil "# wheel motor command message from DrRobot Robot.~%int32 motorcmd1		# left motor encoder command value~%int32 motorCmd2	        # right motor encoder Comamnd value~%int32 motorCtrl		# motor ctrl method , 0-- PWM, 1-- velocity  2-- position~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MotorCmd>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MotorCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'MotorCmd
    (cl:cons ':motorcmd1 (motorcmd1 msg))
    (cl:cons ':motorCmd2 (motorCmd2 msg))
    (cl:cons ':motorCtrl (motorCtrl msg))
))
