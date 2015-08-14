; Auto-generated. Do not edit!


(cl:in-package drrobot_clinicrobot-msg)


;//! \htmlinclude PowerInfo.msg.html

(cl:defclass <PowerInfo> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (battery_vol
    :reader battery_vol
    :initarg :battery_vol
    :type cl:float
    :initform 0.0)
   (system_vol
    :reader system_vol
    :initarg :system_vol
    :type cl:float
    :initform 0.0)
   (battery_fuel
    :reader battery_fuel
    :initarg :battery_fuel
    :type cl:float
    :initform 0.0)
   (dcin_vol
    :reader dcin_vol
    :initarg :dcin_vol
    :type cl:float
    :initform 0.0)
   (dcin_current
    :reader dcin_current
    :initarg :dcin_current
    :type cl:float
    :initform 0.0)
   (charge_time_min
    :reader charge_time_min
    :initarg :charge_time_min
    :type cl:integer
    :initform 0)
   (charge_time_sec
    :reader charge_time_sec
    :initarg :charge_time_sec
    :type cl:integer
    :initform 0)
   (charge_error_code
    :reader charge_error_code
    :initarg :charge_error_code
    :type cl:fixnum
    :initform 0)
   (charge_mode
    :reader charge_mode
    :initarg :charge_mode
    :type cl:fixnum
    :initform 0)
   (charge_status
    :reader charge_status
    :initarg :charge_status
    :type cl:fixnum
    :initform 0)
   (charge_rx_status
    :reader charge_rx_status
    :initarg :charge_rx_status
    :type cl:fixnum
    :initform 0)
   (charger_temperature
    :reader charger_temperature
    :initarg :charger_temperature
    :type cl:float
    :initform 0.0)
   (set_charge_current
    :reader set_charge_current
    :initarg :set_charge_current
    :type cl:float
    :initform 0.0)
   (charge_flag
    :reader charge_flag
    :initarg :charge_flag
    :type cl:fixnum
    :initform 0)
   (in_chargestation_flag
    :reader in_chargestation_flag
    :initarg :in_chargestation_flag
    :type cl:fixnum
    :initform 0)
   (cell_vol
    :reader cell_vol
    :initarg :cell_vol
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0))
   (cell_res
    :reader cell_res
    :initarg :cell_res
    :type (cl:vector cl:float)
   :initform (cl:make-array 6 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass PowerInfo (<PowerInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PowerInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PowerInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name drrobot_clinicrobot-msg:<PowerInfo> is deprecated: use drrobot_clinicrobot-msg:PowerInfo instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:header-val is deprecated.  Use drrobot_clinicrobot-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'battery_vol-val :lambda-list '(m))
(cl:defmethod battery_vol-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:battery_vol-val is deprecated.  Use drrobot_clinicrobot-msg:battery_vol instead.")
  (battery_vol m))

(cl:ensure-generic-function 'system_vol-val :lambda-list '(m))
(cl:defmethod system_vol-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:system_vol-val is deprecated.  Use drrobot_clinicrobot-msg:system_vol instead.")
  (system_vol m))

(cl:ensure-generic-function 'battery_fuel-val :lambda-list '(m))
(cl:defmethod battery_fuel-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:battery_fuel-val is deprecated.  Use drrobot_clinicrobot-msg:battery_fuel instead.")
  (battery_fuel m))

(cl:ensure-generic-function 'dcin_vol-val :lambda-list '(m))
(cl:defmethod dcin_vol-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:dcin_vol-val is deprecated.  Use drrobot_clinicrobot-msg:dcin_vol instead.")
  (dcin_vol m))

(cl:ensure-generic-function 'dcin_current-val :lambda-list '(m))
(cl:defmethod dcin_current-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:dcin_current-val is deprecated.  Use drrobot_clinicrobot-msg:dcin_current instead.")
  (dcin_current m))

(cl:ensure-generic-function 'charge_time_min-val :lambda-list '(m))
(cl:defmethod charge_time_min-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:charge_time_min-val is deprecated.  Use drrobot_clinicrobot-msg:charge_time_min instead.")
  (charge_time_min m))

(cl:ensure-generic-function 'charge_time_sec-val :lambda-list '(m))
(cl:defmethod charge_time_sec-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:charge_time_sec-val is deprecated.  Use drrobot_clinicrobot-msg:charge_time_sec instead.")
  (charge_time_sec m))

(cl:ensure-generic-function 'charge_error_code-val :lambda-list '(m))
(cl:defmethod charge_error_code-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:charge_error_code-val is deprecated.  Use drrobot_clinicrobot-msg:charge_error_code instead.")
  (charge_error_code m))

(cl:ensure-generic-function 'charge_mode-val :lambda-list '(m))
(cl:defmethod charge_mode-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:charge_mode-val is deprecated.  Use drrobot_clinicrobot-msg:charge_mode instead.")
  (charge_mode m))

(cl:ensure-generic-function 'charge_status-val :lambda-list '(m))
(cl:defmethod charge_status-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:charge_status-val is deprecated.  Use drrobot_clinicrobot-msg:charge_status instead.")
  (charge_status m))

(cl:ensure-generic-function 'charge_rx_status-val :lambda-list '(m))
(cl:defmethod charge_rx_status-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:charge_rx_status-val is deprecated.  Use drrobot_clinicrobot-msg:charge_rx_status instead.")
  (charge_rx_status m))

(cl:ensure-generic-function 'charger_temperature-val :lambda-list '(m))
(cl:defmethod charger_temperature-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:charger_temperature-val is deprecated.  Use drrobot_clinicrobot-msg:charger_temperature instead.")
  (charger_temperature m))

(cl:ensure-generic-function 'set_charge_current-val :lambda-list '(m))
(cl:defmethod set_charge_current-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:set_charge_current-val is deprecated.  Use drrobot_clinicrobot-msg:set_charge_current instead.")
  (set_charge_current m))

(cl:ensure-generic-function 'charge_flag-val :lambda-list '(m))
(cl:defmethod charge_flag-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:charge_flag-val is deprecated.  Use drrobot_clinicrobot-msg:charge_flag instead.")
  (charge_flag m))

(cl:ensure-generic-function 'in_chargestation_flag-val :lambda-list '(m))
(cl:defmethod in_chargestation_flag-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:in_chargestation_flag-val is deprecated.  Use drrobot_clinicrobot-msg:in_chargestation_flag instead.")
  (in_chargestation_flag m))

(cl:ensure-generic-function 'cell_vol-val :lambda-list '(m))
(cl:defmethod cell_vol-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:cell_vol-val is deprecated.  Use drrobot_clinicrobot-msg:cell_vol instead.")
  (cell_vol m))

(cl:ensure-generic-function 'cell_res-val :lambda-list '(m))
(cl:defmethod cell_res-val ((m <PowerInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader drrobot_clinicrobot-msg:cell_res-val is deprecated.  Use drrobot_clinicrobot-msg:cell_res instead.")
  (cell_res m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PowerInfo>) ostream)
  "Serializes a message object of type '<PowerInfo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'battery_vol))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'system_vol))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'battery_fuel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'dcin_vol))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'dcin_current))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_time_min)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'charge_time_min)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'charge_time_min)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'charge_time_min)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_time_sec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'charge_time_sec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'charge_time_sec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'charge_time_sec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_error_code)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_status)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_rx_status)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'charger_temperature))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'set_charge_current))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_flag)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'in_chargestation_flag)) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'cell_vol))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'cell_res))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PowerInfo>) istream)
  "Deserializes a message object of type '<PowerInfo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'battery_vol) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'system_vol) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'battery_fuel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dcin_vol) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dcin_current) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_time_min)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'charge_time_min)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'charge_time_min)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'charge_time_min)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_time_sec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'charge_time_sec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'charge_time_sec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'charge_time_sec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_error_code)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_status)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_rx_status)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'charger_temperature) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'set_charge_current) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'charge_flag)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'in_chargestation_flag)) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'cell_vol) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'cell_vol)))
    (cl:dotimes (i 6)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'cell_res) (cl:make-array 6))
  (cl:let ((vals (cl:slot-value msg 'cell_res)))
    (cl:dotimes (i 6)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PowerInfo>)))
  "Returns string type for a message object of type '<PowerInfo>"
  "drrobot_clinicrobot/PowerInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PowerInfo)))
  "Returns string type for a message object of type 'PowerInfo"
  "drrobot_clinicrobot/PowerInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PowerInfo>)))
  "Returns md5sum for a message object of type '<PowerInfo>"
  "c19e8d592d8f15bf9ff68a439be7b96c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PowerInfo)))
  "Returns md5sum for a message object of type 'PowerInfo"
  "c19e8d592d8f15bf9ff68a439be7b96c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PowerInfo>)))
  "Returns full string definition for message of type '<PowerInfo>"
  (cl:format cl:nil "# battery /power information message from DrRobot Robot.~%~%Header header    	# timestamp in the header is the time the driver~%~%float32 battery_vol		# battery voltage, if not in charge station, it also would be system voltage~%float32 system_vol	# system power voltage, in charge station, it would be 24V DC power~%float32 battery_fuel	# battery fuel, estimate by fuel table~%float32 dcin_vol	# dcin power voltage reading, only avaiable in chage state~%float32 dcin_current	#  for charger~%uint32 charge_time_min	# charging minute~%uint32 charge_time_sec	# charging second~%uint8 charge_error_code	# charging error code~%uint8 charge_mode	# charge mode~%uint8 charge_status	# charging state, finish or not~%uint8 charge_rx_status	# charging state~%float32 charger_temperature	# charger CPU temperature~%float32 set_charge_current	# set charge current~%uint8 charge_flag	# charging or not, 1- charing, 0- not~%uint8 in_chargestation_flag	# in charge station or not, 1-in, 0-not~%float32[6] cell_vol	# cell voltage~%float32[6] cell_res	# cell resistor~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PowerInfo)))
  "Returns full string definition for message of type 'PowerInfo"
  (cl:format cl:nil "# battery /power information message from DrRobot Robot.~%~%Header header    	# timestamp in the header is the time the driver~%~%float32 battery_vol		# battery voltage, if not in charge station, it also would be system voltage~%float32 system_vol	# system power voltage, in charge station, it would be 24V DC power~%float32 battery_fuel	# battery fuel, estimate by fuel table~%float32 dcin_vol	# dcin power voltage reading, only avaiable in chage state~%float32 dcin_current	#  for charger~%uint32 charge_time_min	# charging minute~%uint32 charge_time_sec	# charging second~%uint8 charge_error_code	# charging error code~%uint8 charge_mode	# charge mode~%uint8 charge_status	# charging state, finish or not~%uint8 charge_rx_status	# charging state~%float32 charger_temperature	# charger CPU temperature~%float32 set_charge_current	# set charge current~%uint8 charge_flag	# charging or not, 1- charing, 0- not~%uint8 in_chargestation_flag	# in charge station or not, 1-in, 0-not~%float32[6] cell_vol	# cell voltage~%float32[6] cell_res	# cell resistor~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PowerInfo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
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
     1
     4
     4
     1
     1
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'cell_vol) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'cell_res) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PowerInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'PowerInfo
    (cl:cons ':header (header msg))
    (cl:cons ':battery_vol (battery_vol msg))
    (cl:cons ':system_vol (system_vol msg))
    (cl:cons ':battery_fuel (battery_fuel msg))
    (cl:cons ':dcin_vol (dcin_vol msg))
    (cl:cons ':dcin_current (dcin_current msg))
    (cl:cons ':charge_time_min (charge_time_min msg))
    (cl:cons ':charge_time_sec (charge_time_sec msg))
    (cl:cons ':charge_error_code (charge_error_code msg))
    (cl:cons ':charge_mode (charge_mode msg))
    (cl:cons ':charge_status (charge_status msg))
    (cl:cons ':charge_rx_status (charge_rx_status msg))
    (cl:cons ':charger_temperature (charger_temperature msg))
    (cl:cons ':set_charge_current (set_charge_current msg))
    (cl:cons ':charge_flag (charge_flag msg))
    (cl:cons ':in_chargestation_flag (in_chargestation_flag msg))
    (cl:cons ':cell_vol (cell_vol msg))
    (cl:cons ':cell_res (cell_res msg))
))
