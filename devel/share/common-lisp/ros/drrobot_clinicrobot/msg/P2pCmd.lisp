; Auto-generated. Do not edit!


(cl:in-package drrobot_clinicrobot-msg)


;//! \htmlinclude P2pCmd.msg.html

(cl:defclass <P2pCmd> (roslisp-msg-protocol:ros-message)
  ((TargetX
    :reader TargetX
    :initarg :TargetX
    :type cl:float
    :initform 0.0)
   (TargetY
    :reader TargetY
    :initarg :TargetY
    :type cl:float
    :initform 0.0)
   (TargetDir
    :reader TargetDir
    :initarg :TargetDir
    :type cl:float
    :initform 0.0)
   (ForwardSpeed
    :reader ForwardSpeed
    :initarg :ForwardSpeed
    :type cl:float
    :initform 0.0)
   (CAEnable
    :reader CAEnable
    :initarg :CAEnable
    :type cl:fixnum
    :initform 0)
   (ReverseDrive
    :reader ReverseDrive
    :initarg :ReverseDrive
    :type cl:fixnum
    :initform 0))
)

(cl:defclass P2pCmd (<P2pCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <P2pCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'P2pCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name drrobot_clinicrobot-msg:<P2pCmd> is deprecated: use drrobot_clinicrobot-msg:P2pCmd instead.")))

(cl:ensure-generic-function 'TargetX-val :lambda-list '(m))
(cl:defmethod TargetX-val ((m <P2pCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:TargetX-val is deprecated.  Use drrobot_clinicrobot-msg:TargetX instead.")
  (TargetX m))

(cl:ensure-generic-function 'TargetY-val :lambda-list '(m))
(cl:defmethod TargetY-val ((m <P2pCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:TargetY-val is deprecated.  Use drrobot_clinicrobot-msg:TargetY instead.")
  (TargetY m))

(cl:ensure-generic-function 'TargetDir-val :lambda-list '(m))
(cl:defmethod TargetDir-val ((m <P2pCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:TargetDir-val is deprecated.  Use drrobot_clinicrobot-msg:TargetDir instead.")
  (TargetDir m))

(cl:ensure-generic-function 'ForwardSpeed-val :lambda-list '(m))
(cl:defmethod ForwardSpeed-val ((m <P2pCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:ForwardSpeed-val is deprecated.  Use drrobot_clinicrobot-msg:ForwardSpeed instead.")
  (ForwardSpeed m))

(cl:ensure-generic-function 'CAEnable-val :lambda-list '(m))
(cl:defmethod CAEnable-val ((m <P2pCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:CAEnable-val is deprecated.  Use drrobot_clinicrobot-msg:CAEnable instead.")
  (CAEnable m))

(cl:ensure-generic-function 'ReverseDrive-val :lambda-list '(m))
(cl:defmethod ReverseDrive-val ((m <P2pCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:ReverseDrive-val is deprecated.  Use drrobot_clinicrobot-msg:ReverseDrive instead.")
  (ReverseDrive m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <P2pCmd>) ostream)
  "Serializes a message object of type '<P2pCmd>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'TargetX))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'TargetY))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'TargetDir))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'ForwardSpeed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'CAEnable)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ReverseDrive)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <P2pCmd>) istream)
  "Deserializes a message object of type '<P2pCmd>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'TargetX) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'TargetY) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'TargetDir) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ForwardSpeed) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'CAEnable)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ReverseDrive)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<P2pCmd>)))
  "Returns string type for a message object of type '<P2pCmd>"
  "drrobot_clinicrobot/P2pCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'P2pCmd)))
  "Returns string type for a message object of type 'P2pCmd"
  "drrobot_clinicrobot/P2pCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<P2pCmd>)))
  "Returns md5sum for a message object of type '<P2pCmd>"
  "1c12145f741c94dc887f31111234d185")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'P2pCmd)))
  "Returns md5sum for a message object of type 'P2pCmd"
  "1c12145f741c94dc887f31111234d185")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<P2pCmd>)))
  "Returns full string definition for message of type '<P2pCmd>"
  (cl:format cl:nil "# P2P go message~%~%float32 TargetX~%float32 TargetY~%float32 TargetDir     #in degrees~%float32 ForwardSpeed~%uint8 CAEnable        # 0 is collision avoidance disabled, 1 is enabled~%uint8 ReverseDrive    # 0 is reverse drive disabled, 1 is enabled~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'P2pCmd)))
  "Returns full string definition for message of type 'P2pCmd"
  (cl:format cl:nil "# P2P go message~%~%float32 TargetX~%float32 TargetY~%float32 TargetDir     #in degrees~%float32 ForwardSpeed~%uint8 CAEnable        # 0 is collision avoidance disabled, 1 is enabled~%uint8 ReverseDrive    # 0 is reverse drive disabled, 1 is enabled~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <P2pCmd>))
  (cl:+ 0
     4
     4
     4
     4
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <P2pCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'P2pCmd
    (cl:cons ':TargetX (TargetX msg))
    (cl:cons ':TargetY (TargetY msg))
    (cl:cons ':TargetDir (TargetDir msg))
    (cl:cons ':ForwardSpeed (ForwardSpeed msg))
    (cl:cons ':CAEnable (CAEnable msg))
    (cl:cons ':ReverseDrive (ReverseDrive msg))
))
