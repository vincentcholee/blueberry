#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "qmath.h"
#include <QtXml>
#include "../include/drrobot_clinicrobot/mainwindow.hpp"
#include "../include/drrobot_clinicrobot/drrobotprotocol.hpp"
#include "../include/drrobot_clinicrobot/ui_mainwindow.hpp"
#include "../include/drrobot_clinicrobot/drrobotsensordata.hpp"
#include "../include/drrobot_clinicrobot/drrobotp2pspeeddrive.hpp"

namespace drrobot_clinicrobot {

using namespace Qt;

MainWindow::MainWindow(int argc, char** argv, QMainWindow *parent)
    : QMainWindow(parent)
    , qnode(argc,argv),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixma (":/images/icon1.png");
    ui->labelMotionPortState->setPixmap(pixma);
    ui->labelChargerPortState->setPixmap(pixma);
    ui->labelLaserPortState->setPixmap(pixma);
    ui->labelIndoorGPSPortState->setPixmap(pixma);

    ui->lineEditNetworkIP1->setInputMask("000.000.000.000;");
    ui->lineEditNetworkIP2->setInputMask("000.000.000.000;");
    IP4Validator *ip4Validator = new IP4Validator();
    ui->lineEditNetworkIP2->setValidator(ip4Validator);
    ui->lineEditNetworkIP1->setValidator(ip4Validator);


    QRegExp rx1("^\\d\\d?\\d?\\d?\\d?$");
    ui->lineEditMotionPort->setValidator(new QRegExpValidator(rx1, this));
    ui->lineEditChargerPort->setValidator(new QRegExpValidator(rx1, this));
    ui->lineEditIndoorGPSPort->setValidator(new QRegExpValidator(rx1, this));
    ui->lineEditLaserPort->setValidator(new QRegExpValidator(rx1, this));
    ui->lineEditHeadCtrlTime->setValidator(new QRegExpValidator(rx1,this));

    ui->groupBoxMotorSensors->setEnabled(false);
    ui->groupBoxLaserScan->setEnabled(false);
    ui->groupBoxChargeControl->setEnabled(false);
    //motion control
    connect (ui->pushButtonMotionConnect, SIGNAL(clicked()),this,SLOT (connectToMotionController()));

    connect (ui->pushButtonGoForward, SIGNAL(clicked()),this,SLOT (sendForwardCmd()));
    connect (ui->pushButtonGoBackward, SIGNAL(clicked()),this,SLOT (sendBackwardCmd()));
    connect (ui->pushButtonTurnLeft, SIGNAL(clicked()),this,SLOT (sendLeftTurnCmd()));
    connect (ui->pushButtonTurnRight, SIGNAL(clicked()),this,SLOT (sendRightTurnCmd()));
    connect (ui->pushButtonStop, SIGNAL(clicked()),this,SLOT (sendStopCmd()));
    connect (ui->pushButtonStopHeadMotor, SIGNAL(clicked()),this,SLOT (sendHeadStopCmd()));
    connect (ui->horizontalSliderHeadPan,SIGNAL(sliderReleased()),SLOT (sendHeadPanCmd()));
    connect (ui->verticalSliderHeadTilt,SIGNAL(sliderReleased()),SLOT(sendHeadTiltCmd()));
    connect (ui->pushButtonLaserAutoScan,SIGNAL(clicked()),this,SLOT(setLaserAutoScan()));

    //calvin's keyboard control starts here
    connect (ui->checkBoxKeyboardCtr, SIGNAL(clicked(bool)),this,SLOT(keyboardMotionCtrl(bool)));

    connect (ui->checkBoxInChargeStation,SIGNAL(stateChanged(int)),this,SLOT(setChargeEn()));
    connect (ui->pushButtonHeadPanHome, SIGNAL(clicked()),this,SLOT(resetHeadPan()));
    connect (ui->pushButtonHeadTiltHome,SIGNAL(clicked()),this,SLOT(resetHeadTilt()));
    //laser scan drive
    connect (ui->pushButtonLaserConnect,SIGNAL(clicked()),this,SLOT(connectToLaserDrive()));
    connect (ui->verticalSliderLaserDrive,SIGNAL(sliderReleased()),this,SLOT(sendLaserDriveCmd()));
    connect (ui->pushButtonLaserHome,SIGNAL(clicked()),this,SLOT(laserResetDrive()));

    // charger controller
    connect (ui->pushButtonChargerConnect,SIGNAL(clicked()),this,SLOT(connectToChargerController()));
    connect (ui->pushButtonChargeCtrl,SIGNAL(clicked()),this,SLOT(sendChargeCmd()));
    connect (ui->pushButtonSwitchPower,SIGNAL(clicked()),this,SLOT(sendSwitchPowerCmd()));
    connect (ui->checkBoxStartROSReceive, SIGNAL(stateChanged(int)),this,SLOT(setROSReceive()));

    // indoor GPS
    connect (ui->pushButtonIndoorGPSConnect,SIGNAL(clicked()),this,SLOT(connectToIndoorGPS()));

// for patrol, go charger contorl
    connect (ui->pushButtonExitCharger,SIGNAL(clicked()),this,SLOT(exitCharger()));
    connect (ui->pushButtonPatrol,SIGNAL(clicked()),this,SLOT(patrolStart()));
    connect (ui->pushButtonGoCharger,SIGNAL(clicked()),this,SLOT(goChargerStart()));
    pathControlTimer.setInterval(100);
    pathControlTimer.stop();
    connect (&pathControlTimer,SIGNAL(timeout()),this,SLOT(pathControl()));


    iniSystemData();
    ui->lineEditNetworkIP1->setFocus();

serverFace = new QTcpServer(this);

    connect (serverFace,SIGNAL(newConnection()),this,SLOT(newConnectionFace()));

    if (!serverFace->listen(QHostAddress::Any,FACE_SERVER_PORT)){
        ui->labelServerState->setText("Face Server could not start");
    }else{
        faceConnectFlag = 0;
        faceConnectTimeOutCnt = 0;
        ui->labelServerState->setText("Face Server started at " + serverFace->serverAddress().toString() + ":"
                                      + QString::number(FACE_SERVER_PORT));
    }

    ui->spinBoxFileName->setEnabled(false);

    connect (ui->spinBoxFileName,SIGNAL(valueChanged(int)),this,SLOT(setFile(int)));


//for P2P drive and sensor map builder
    connect (ui->pushButtonP2PGo,SIGNAL(clicked()),this,SLOT(p2pStart()));
    connect (ui->pushButtonP2PStop,SIGNAL(clicked()),this,SLOT(p2pStop()));

    robotInfo.setRobotInfo();
    motorCmd.setMotorControlCmd();
    QObject::connect(&drrobotp2pSpeedDrive,SIGNAL(p2pDriveCmdCallback(MotorControlCmd)),this,SLOT(p2pUpdateMotorCmd(MotorControlCmd)));
    drrobotp2pSpeedDrive.SetRobotInfo(robotInfo);
    drrobotp2pSpeedDrive.setDrRobotP2PSpeedDrive();
    drrobotSensorMapBuilder.setDrRobotSensorMapBuilder();
    sensorMapData.setSensorMapData();
    robotPosition.setRobotPosition();

    //calvin added these for robot velocity
    robotvelocity.setRobotVelocity();
    //calvin ends

    drrobotSensorMapBuilder.ConfigSensor(sensorMapConfig);
    drrobotSensorMapBuilder.PreSetPosition(robotPosition);
    sensorData.setSensorData();
    QObject::connect (&drrobotSensorMapBuilder,SIGNAL(mapBuilderServiceCallback(SensorMapData)),this,SLOT(updateSensorMap(SensorMapData)));


    if ( !qnode.init()){
        showNoMasterMessage();
    }else{
        ui->textEditROSMsg->setText("ROS Start ....");
    }


    //timer
    ctrlTimer.setInterval(100);
    connect(&ctrlTimer,SIGNAL(timeout()),this,SLOT(ctrlFunc()));
    ctrlTimer.start();

    disTimer.setInterval(200);
    connect(&disTimer,SIGNAL(timeout()),this,SLOT(disData()));
    disTimer.start();



   ReadSettings();
   setWindowIcon(QIcon(":/images/icon.png"));

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

}

MainWindow::~MainWindow()
{

    if (udpMotion != NULL) delete udpMotion;      // motion control communication
    if (tcpCharge != NULL) delete tcpCharge;      // charger control communication
    if (tcpIndoorGPS != NULL) delete tcpIndoorGPS;   //indoor GPS communication
    if (tcpLaserDrive != NULL) delete tcpLaserDrive;  // laser drive communication
    if (socketFace != NULL) delete socketFace;
    if (serverFace != NULL) {
        serverFace->close();
        delete serverFace;
    }
    delete ui;
}




void MainWindow::setROSReceive()
{
    if (ui->checkBoxStartROSReceive->isChecked()){
        QObject::connect(&qnode, SIGNAL(wheelCmdUpdated(int,int,int)), this, SLOT(wheelCmdSend(int,int,int)));
        QObject::connect(&qnode, SIGNAL(headCmdUpdated(double,int,int,double,int,int)), this, SLOT(headCmdSend(double,int,int,double,int,int)));
        QObject::connect(&qnode, SIGNAL(laserCmdUpdated(double,int)), this, SLOT(laserCmdSend(double,int)));
        //calvin added this       
        QObject::connect(&qnode, SIGNAL(laserScanUpdated(double)),this, SLOT(laserScanEffected(double)));
        //calvin end
    }
    else{
        QObject::disconnect(&qnode, SIGNAL(wheelCmdUpdated(int,int,int)), this, SLOT(wheelCmdSend(int,int,int)));
        QObject::disconnect(&qnode, SIGNAL(headCmdUpdated(double,int,int,double,int,int)), this, SLOT(headCmdSend(double,int,int,double,int,int)));
        QObject::disconnect(&qnode, SIGNAL(laserCmdUpdated(double,int)), this, SLOT(laserCmdSend(double,int)));
        //calvin added this
        QObject::disconnect(&qnode, SIGNAL(laserScanUpdated(double)), this, SLOT(laserScanEffected(double)));
        //calvin end
    }

}


void MainWindow::p2pStart()
{
    double temp = (ui->lineEditTargetX->text()).toDouble();
    setPoint.TargetX = temp;
    temp = (ui->lineEditTargetY->text()).toDouble();
    setPoint.TargetY = temp;
    temp = (ui->lineEditTargetDir->text()).toDouble();
    setPoint.TargetDir = temp /180 * M_PI;
    setPoint.StopTime = 2;
    temp = (ui->lineEditTargetSpeed->text()).toDouble();
    if (temp > MAXSPEED) temp = MAXSPEED;
    setPoint.ForwardSpeed = temp;
    setPoint.Forgetable = false;
    setPoint.NonStop = false;
    setPoint.FinalPosture = true;
    setPoint.TargetTime = 200;
    setPoint.TargetTolerance = 0.05;
    setPoint.MaxTurnSpeed = 1;

    if (ui->checkBoxCAEn->isChecked()){
        setPoint.CAEnable = true;
    }else{
        setPoint.CAEnable = false;
    }
    if (ui->checkBoxReverseDrive->isChecked()){
        setPoint.ReverseDrive = true;
    }else{
        setPoint.ReverseDrive = false;
    }
    setPoint.TargetDirTolerance = 3 * M_PI/180;
    drrobotp2pSpeedDrive.SetTargetPosition(setPoint);
    drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdP2PGo);
    p2pStatus = P2PGo;
}

void MainWindow::p2pStop()
{
    drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdStopP2P);
    robotMotorNoTimeControlAll(MOTORPWMCTRLALL,INIPWM,INIPWM,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL);
    pathControlTimer.stop();
}

void MainWindow:: updateSensorMap(SensorMapData mapData)
{
    sensorMapData = mapData;
    //calvin added this to update the sensormap
    drrobotp2pSpeedDrive.UpdateSensorMap_Position(robotPosition,sensorMapData);
    //calvin ends
}

void MainWindow::p2pUpdateMotorCmd(MotorControlCmd cmd)
{
    motorCmd = cmd;
    ui->labelLeftCmd->setText(QString::number(motorCmd.LeftWheelCmd));
    ui->labelRightCmd->setText(QString::number(motorCmd.RightWheelCmd));
    p2pStatus = motorCmd.p2pDriveStatus;
    displayP2PStatus();
    displayP2PCtrlMethod();
    if ((motorCmd.p2pDriveStatus == P2POver) || (motorCmd.p2pDriveStatus == P2PSuspend)){
        //stop robot
        robotMotorNoTimeControlAll(MOTORVELCTRLALL,0,0,0,NOCONTROL,NOCONTROL,0);
    }
    else{
        if (motorCmd.p2pDriveMethod == SpeedControl){
            if (fabs(motorCmd.LeftWheelCmd) > ENCODERMAXSPEED) motorCmd.LeftWheelCmd = sign(motorCmd.LeftWheelCmd) * ENCODERMAXSPEED;
            if (fabs(motorCmd.RightWheelCmd) > ENCODERMAXSPEED) motorCmd.RightWheelCmd = sign(motorCmd.RightWheelCmd) * ENCODERMAXSPEED;
            robotMotorNoTimeControlAll(MOTORVELCTRLALL,motorCmd.LeftWheelCmd,motorCmd.RightWheelCmd,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL);

        }else if(motorCmd.p2pDriveMethod == PositionControl){
            robotMotorTimeControlAll(MOTORPOSCTRLALL,motorCmd.LeftWheelCmd,motorCmd.RightWheelCmd,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL,motorCmd.RunTime);
        }

    }
}

void MainWindow::newConnectionFace()
{
    if (faceConnectFlag == 0){
        // only allow one client
        faceConnectFlag = 1;
        faceConnectTimeOutCnt = 0;
        socketFace = serverFace->nextPendingConnection();
        socketFace->write("Hello face\r\n");
        socketFace->flush();

        connect (socketFace,SIGNAL(readyRead()),this,SLOT(processFaceData()));
        ui->labelServerState->setText("Client IP:" + socketFace->peerAddress().toString());
        ui->spinBoxFileName->setEnabled(true);

    }


}

void MainWindow::processFaceData()
{
    faceConnectTimeOutCnt = 0;
}

void MainWindow::setFile(int index)
{
    QString cmd = "FILE" + QString::number(index) + "\r\n";
    if (socketFace->isWritable()){
        socketFace->write(cmd.toStdString().c_str());
        socketFace->flush();

    }
}


// initialize all the sensor data
void MainWindow::iniSystemData()
{
    double angle = 0;
    firstCal = true;
    gpsCheckCnt = 0;
    // initialize all the data structure here
    sensorMapConfig.setConfigData();
    inChargeCnt = 0;
    exitChargeFlag = false;
    exitChargeStep = 0;

    for (int i = 0; i < IR_NUM; i++){
        irData[i].detectDis = 0;
        irData[i].detectZ = 0.16;
        irData[i].offsetZ = 0.16;
        if (i < 11){
            angle = (90 - SENSOR_ANGLE_STEP * (i + 1) );        //number ]0] is at the left front side
        }else{
            angle = (180 - SENSOR_ANGLE_STEP * (i - 11));
        }
        irData[i].angle = angle / 180 * M_PI;
        irData[i].disTag = 1;
        irData[i].weight = 1;
        irData[i].rawDis = 0.81;
        irData[i].offsetX = SENSOR_R * qCos(irData[i].angle);
        irData[i].offsetY = SENSOR_R * qSin(irData[i].angle);
        sensorMapConfig.IrConfigData[i].Angle = angle;
        sensorMapConfig.IrConfigData[i].DisTag = 1;
        sensorMapConfig.IrConfigData[i].OffsetX =  irData[i].offsetX;
        sensorMapConfig.IrConfigData[i].OffsetY = irData[i].offsetY;
        sensorMapConfig.IrConfigData[i].Weight = 1;

    }

    for (int i = 0; i < US_NUM; i++){
        usData[i].detectDis = 0;
        usData[i].detectZ = 0.16;
        usData[i].disTag = 1;
        usData[i].weight = 1;
        usData[i].rawDis = 0.81;

    }
        usData[0].offsetX = 0.05;
        usData[0].offsetY = 0;
        usData[0].offsetZ = 0.7;
        usData[0].detectZ = 0.7;
        usData[0].angle = 0;
        sensorMapConfig.UsConfigData[0].Angle = 0;
        sensorMapConfig.UsConfigData[0].DisTag = 1;
        sensorMapConfig.UsConfigData[0].OffsetX = 0.05;
        sensorMapConfig.UsConfigData[0].OffsetY = 0;
        sensorMapConfig.UsConfigData[0].Weight = 1;

        usData[1].offsetX = 0.05;
        usData[1].offsetY = 0;
        usData[1].offsetZ = 1.0;
        usData[1].detectZ = 1.0;
        usData[1].angle = 0;
        sensorMapConfig.UsConfigData[1].Angle = 0;
        sensorMapConfig.UsConfigData[1].DisTag = 1;
        sensorMapConfig.UsConfigData[1].OffsetX = 0.05;
        sensorMapConfig.UsConfigData[1].OffsetY = 0;
        sensorMapConfig.UsConfigData[1].Weight = 1;

        usData[2].offsetX = 0.05;
        usData[2].offsetY = 0;
        usData[2].offsetZ = 1.4;
        usData[2].detectZ = 1.4;
        usData[2].angle = 0;
        sensorMapConfig.UsConfigData[2].Angle = 0;
        sensorMapConfig.UsConfigData[2].DisTag = 1;
        sensorMapConfig.UsConfigData[2].OffsetX = 0.05;
        sensorMapConfig.UsConfigData[2].OffsetY = 0;
        sensorMapConfig.UsConfigData[2].Weight = 1;

        usData[3].offsetX = 0.0;
        usData[3].offsetY = 0.165;
        usData[3].offsetZ = 1.3;
        usData[3].detectZ = 1.3;
        usData[3].angle = M_PI/2;
        sensorMapConfig.UsConfigData[3].Angle = 90;
        sensorMapConfig.UsConfigData[3].DisTag = 1;
        sensorMapConfig.UsConfigData[3].OffsetX = 0;
        sensorMapConfig.UsConfigData[3].OffsetY = 0.165;
        sensorMapConfig.UsConfigData[3].Weight = 1;

        usData[4].offsetX = 0.0;
        usData[4].offsetY = -0.165;
        usData[4].offsetZ = 1.3;
        usData[4].detectZ = 1.3;
        usData[4].angle = -M_PI/2;
        sensorMapConfig.UsConfigData[4].Angle = -90;
        sensorMapConfig.UsConfigData[4].DisTag = 1;
        sensorMapConfig.UsConfigData[4].OffsetX = 0;
        sensorMapConfig.UsConfigData[4].OffsetY = -0.165;
        sensorMapConfig.UsConfigData[4].Weight = 1;
        usData[5].offsetX = -0.05;
        usData[5].offsetY = 0;

        // calvin changed it from 1.3 to 0.7
        usData[5].offsetZ = 0.7;
        usData[5].detectZ = 0.7;
        // calvin ends
        usData[5].angle = -M_PI;
        sensorMapConfig.UsConfigData[5].Angle = -180;
        sensorMapConfig.UsConfigData[5].DisTag = 1;
        sensorMapConfig.UsConfigData[5].OffsetX = -0.05;
        sensorMapConfig.UsConfigData[5].OffsetY = 0;
        sensorMapConfig.UsConfigData[5].Weight = 1;

        robotPos.robotX = 0;
        robotPos.robotY = 0;
        robotPos.robotHeading = 0;
        robotPos.robotHeading_En = 0;
        robotPos.robotX_En = 0;
        robotPos.robotY_En = 0;

        laserData.offsetX = 0.18;
        laserData.offsetY = 0;
        laserData.offsetZ = 0.35;
        laserData.tilt_Angle = 0;
        laserData.stopFlag = 1;

        indoorGPS.validFlag = 0; // invalid

        chargeData.chargeFlag = 0;
        chargeData.inChargeStation = 0;

        bumpData.bumpSW1 = 0;
        bumpData.bumpSW2 = 0;
        bumpData.bumpSW3 = 0;
        bumpData.bumpSW4 = 0;

        systemData.chargeControllerFlag = 0;
        systemData.chargeControlTimeoutCnt = 0;
        systemData.chargeFlag = 0;
        systemData.chargeStationFlag = 0;
        systemData.indoorGPSFlag = 0;
        systemData.indoorGPSTimeOutCnt = 0;
        systemData.laserDriveFlag = 0;
        systemData.laserDriveTimeOutCnt = 0;
        systemData.motionControlFlag = 0;
        systemData.motionControlTimeOutCnt = 0;

        motDir = -1;
        for (int i = 0; i < MOTOR_NUM; i++){
            motorData[i].encoderPos = 0;
            motorData[i].encoderVel = 0;
            motorData[i].encoderDir = 0;
            motorData[i].anglePos = 0;
            motorData[i].pwmValue = 0;

        }

        laserMotor.encoderPos = 0;
        laserMotor.anglePos = 0;
        laserMotor.encoderVel = 0;
        laserMotor.encoderDir = 0;
        laserMotor.pwmValue = 0;

        chargeData.batteryVol = 0;
        chargeData.batteryFuel = 0;
        chargeData.chargeCurrent = 0;
        chargeData.chargeErrorCode = 0;
        chargeData.chargeFlag = 0;
        chargeData.chargeMode = 0;
        chargeData.chargeRxStatus = 0;
        chargeData.powerReduceReason = 0;
        chargeData.setCurrent = 0;
        chargeData.chargeStatus = 0;
        for (int i = 0; i < 6; i++){
            chargeData.cellRes[i] = 0;
            chargeData.cellVol[i] = 0;
        }
        chargeData.chargeTimeMin = 0;
        chargeData.chargeTimeSec = 0;
        chargePingCnt = 0;

        indoorGPS.indoorGPSMsg.clear();
        indoorGPS.markHeight = 0;
        indoorGPS.markID = 0;
        indoorGPS.robotHeading_GPS = 0;
        indoorGPS.robotX_GPS = 0;
        indoorGPS.robotY_GPS = 0;
        indoorGPS.gpsOffsetX = GPS_OFFSETX;
        indoorGPS.gpsOffsetY = GPS_OFFSETY;

        faceConnectFlag = 0;
        faceConnectTimeOutCnt = 0;

}

// main control timer here, to check the communicaiton
// period 100ms
void MainWindow::ctrlFunc()
{
    char textData[80];
    if (systemData.motionControlFlag){

        // setup the communication with motion controlller
        systemData.motionControlTimeOutCnt ++;      //this count will be cleared in receive process
        if (systemData.motionControlTimeOutCnt > MOTION_TIMEOUT){
            // lost communication
            systemData.motionControlTimeOutCnt = 0;
            systemData.motionControlFlag = 0;

            ui->pushButtonMotionConnect ->setText(tr("Connect"));
            udpMotion->close();

            ui->groupBoxMotorSensors->setEnabled(false);
            QPixmap pixma (":/images/icon1.png");
            ui->labelMotionPortState->setPixmap(pixma);
        }
        if (udpMotion->isWritable()){
            //keep send ping package
            pingCnt++;
            if (pingCnt > 3){
                udpMotion->write(MOTION_PING);
                pingCnt = 0;
            }
        }

    }

    if (systemData.laserDriveFlag){
        systemData.laserDriveTimeOutCnt++;
        if (systemData.laserDriveTimeOutCnt > LASERDRIVE_TIMEOUT){
            ui->pushButtonLaserConnect ->setText(tr("Connect"));
            tcpLaserDrive->close();
            systemData.laserDriveTimeOutCnt = 0;
            systemData.laserDriveFlag = 0;
            ui->groupBoxLaserScan->setEnabled(false);
            QPixmap pixma (":/images/icon1.png");
            ui->labelLaserPortState->setPixmap(pixma);
            laserDriveFlag = 0;
        }
        if (laserDriveFlag == 1){
            laserDriveFlag = 2;
            if (tcpLaserDrive->isOpen()){
                tcpLaserDrive->write("# c\r");
            }
        }else if(laserDriveFlag == 2){
            laserDriveFlag= 3;
            if (tcpLaserDrive->isOpen()){
                tcpLaserDrive->write("?A_?C_?FF_?P_?S_?V_# 30\r");
            }
        }
    }

    if (systemData.chargeControllerFlag){
       // systemData.chargeControlTimeoutCnt++;
        if(systemData.chargeControlTimeoutCnt > CHARGE_TIMEOUT){

            ui->pushButtonChargerConnect->setText(tr("Connect"));
            tcpCharge->close();
            systemData.chargeControlTimeoutCnt = 0;
            systemData.chargeControllerFlag = 0;
            ui->groupBoxChargeControl->setEnabled(false);
            QPixmap pixma (":/images/icon1.png");
            ui->labelChargerPortState->setPixmap(pixma);
        }
        chargePingCnt ++;
        if (chargePingCnt > 10){
            chargePingCnt = 0;
            if (ui->checkBoxInChargeStation->isChecked()){
                //in charge Station, do nothing, send ping package
                if (tcpCharge->isWritable()){
                    tcpCharge->write("PING\r\n");
                }
            }
            else{
                //send battery voltage to charge for display
                if (tcpCharge->isWritable()){
                    sprintf(textData,"BAT%2.1f\r\n",systemData.systemVol);
                    tcpCharge->write(textData);
                }
            }
        }
    }

    if (systemData.indoorGPSFlag){
        systemData.indoorGPSTimeOutCnt++;
        if(systemData.indoorGPSTimeOutCnt > INDOORGPS_TIMEOUT){
            ui->pushButtonIndoorGPSConnect->setText(tr("Connect"));
            tcpIndoorGPS->close();
            systemData.indoorGPSFlag = 0;
            systemData.indoorGPSTimeOutCnt = 0;
            QPixmap pixma (":/images/icon1.png");
            ui->labelIndoorGPSPortState->setPixmap(pixma);
            ui->checkBoxEnIndoorGPS->setChecked(false);
        }
    }

    if (faceConnectFlag == 1){
        faceConnectTimeOutCnt ++;
        if (faceConnectTimeOutCnt > 100){
            faceConnectTimeOutCnt = 0;
            faceConnectFlag = 0;
            if (socketFace != NULL){
                socketFace->close();
            }
            ui->labelServerState->setText("Server started, listening....");
            ui->spinBoxFileName->setEnabled(false);


        }
    }

    drrobotSensorMapBuilder.UpdateSensorInfo(sensorData,robotPosition);

    if (exitChargeFlag){
        if (exitChargeStep == 0){
            //check the charge stop or not
            if (chargeData.chargeMode == 0){
                exitChargeStep = 1;
                ui->pushButtonSwitchPower->setText("DCPower");
                if (tcpCharge != NULL){
                    if (tcpCharge->isWritable()){
                        tcpCharge->write("CHG0\r\n");   //using battery, need stop charge first?
                    }
                }
            }else{
                exitChargeDelayCnt++;
                if (exitChargeDelayCnt == EXIT_CHARGE_DELAY_TH){
                    if (tcpCharge != NULL){
                        if (tcpCharge->isWritable()){
                            tcpCharge->write("StopC\r\n");   //stop charge
                        }
                    }
                    exitChargeDelayCnt = 0;
                }
            }
        }else if(exitChargeStep == 1){
            exitChargeStep = 2;
            exitChargeDelayCnt = 0;
        }else if(exitChargeStep == 2){
            exitChargeDelayCnt++;
            if (exitChargeDelayCnt > 30){       //around 3s
                exitChargeStep = 3;
            }
        }else if(exitChargeStep == 3){
            //after delay, drive robot out
            drvRobotDis(0.4,3000);
            exitChargeStep = 4;
            exitChargeDelayCnt = 0;
        }else if(exitChargeStep == 4){
            exitChargeDelayCnt++;
            if(exitChargeDelayCnt > 30){
                exitChargeDelayCnt = 0;
                exitChargeFlag = false;
            }
        }

    }

//publish sensor data here, rate = 10Hz
    if (ui->checkBoxStartROSPublish->isChecked()){
         qnode.publisherMotorData(motorData,MOTOR_NUM);
         qnode.publisherRangeArray(irData,usData,IR_NUM,US_NUM);
         qnode.publisherRobotSystemData(systemData);

        //uncommenting from here.. calvin
        qnode.publisherRobotPosition(robotPos);
        qnode.publisherBumpSensor(bumpData);
        qnode.publisherIndoorGPS(indoorGPS);
        qnode.publisherLaserDriveData(laserData);
        qnode.publisherPowerInfo(chargeData);
        //uncommenting stops here calvin

        //calvin added this for odometry
        qnode.publisherOdometry(robotPos,robotvelocity);
        //calvin ends here
        if (ui->checkBoxDisROSMsg->isChecked()){
            ui->textEditROSMsg->append("Publish sensor data..");
            rosLineCnt++;
            if (rosLineCnt > MAX_LINE){
                rosLineCnt = 0;
                ui->textEditROSMsg->setText(""); //here is simple clear all
            }
        }

    }
}


//main display data here
void MainWindow::disData()
{
    //display IR/US/Bump,Motor sensor
    ui->labelIR1_1->setText(QString::number(irData[0].detectDis,'f',2));
    ui->labelIR1_2->setText(QString::number(irData[1].detectDis,'f',2));
    ui->labelIR1_3->setText(QString::number(irData[2].detectDis,'f',2));
    ui->labelIR1_4->setText(QString::number(irData[3].detectDis,'f',2));
    ui->labelIR1_5->setText(QString::number(irData[4].detectDis,'f',2));
    ui->labelIR1_6->setText(QString::number(irData[5].detectDis,'f',2));
    ui->labelIR1_7->setText(QString::number(irData[6].detectDis,'f',2));
    ui->labelIR1_8->setText(QString::number(irData[7].detectDis,'f',2));
    ui->labelIR1_9->setText(QString::number(irData[8].detectDis,'f',2));
    ui->labelIR1_10->setText(QString::number(irData[9].detectDis,'f',2));
    ui->labelIR1_11->setText(QString::number(irData[10].detectDis,'f',2));
    ui->labelIR1_12->setText(QString::number(irData[11].detectDis,'f',2));
    ui->labelIR1_13->setText(QString::number(irData[12].detectDis,'f',2));
    ui->labelIR1_14->setText(QString::number(irData[13].detectDis,'f',2));
    ui->labelIR1_15->setText(QString::number(irData[14].detectDis,'f',2));
    ui->labelIR1_16->setText(QString::number(irData[15].detectDis,'f',2));
    ui->labelUS_1->setText(QString::number(usData[0].detectDis,'f',2));
    ui->labelUS_2->setText(QString::number(usData[1].detectDis,'f',2));
    ui->labelUS_3->setText(QString::number(usData[2].detectDis,'f',2));
    ui->labelUS_4->setText(QString::number(usData[3].detectDis,'f',2));
    ui->labelUS_5->setText(QString::number(usData[4].detectDis,'f',2));
    ui->labelUS_6->setText(QString::number(usData[5].detectDis,'f',2));
    ui->labelBump_R->setText(QString::number(bumpData.bumpSW1) + "+" +  QString::number(bumpData.bumpSW2));
    ui->labelBump_L->setText(QString::number(bumpData.bumpSW3) + "+" +  QString::number(bumpData.bumpSW4));

    ui->labelLeftEncPos->setText(QString::number(motorData[0].encoderPos));
    ui->labelLeftEncVel->setText(QString::number(motorData[0].encoderVel * motorData[0].encoderDir));
    ui->labelLeftPWM->setText(QString::number(motorData[0].pwmValue));
    ui->labelRightEncPos->setText(QString::number(motorData[1].encoderPos));
    ui->labelRightEncVel->setText(QString::number(motorData[1].encoderVel * motorData[1].encoderDir));
    ui->labelRightPWM->setText(QString::number(motorData[1].pwmValue));

    ui->labelHeadTiltEncPos->setText(QString::number(motorData[2].encoderPos));
    ui->labelHeadTiltEncVel->setText(QString::number(motorData[2].encoderVel * motorData[2].encoderDir));
    ui->labelHeadTiltPWM->setText(QString::number(motorData[2].pwmValue));

    ui->labelHeadPanEncPos->setText(QString::number(motorData[3].encoderPos));
    ui->labelHeadPanEncVel->setText(QString::number(motorData[3].encoderVel * motorData[3].encoderDir));
    ui->labelHeadPanPWM->setText(QString::number(motorData[3].pwmValue));

    ui->labelHeadTilt->setText(QString::number(motorData[2].anglePos * 180 / M_PI,'f',1));
    ui->labelHeadPan->setText(QString::number(motorData[3].anglePos * 180 / M_PI,'f',1));

    if (chargeData.inChargeStation == 1){
        ui->checkBoxInChargeStation->setChecked(true);
        ui->labelBatteryVol->setText(QString::number(chargeData.batteryVol,'f',2));
    }
    else{
        ui->checkBoxInChargeStation->setChecked(false);
        ui->labelBatteryVol->setText(QString::number(systemData.systemVol,'f',2));
    }

    //laser drive control
    ui->labelLaserEncPos->setText(QString::number(laserMotor.encoderPos));
    ui->labelLaserEncVel->setText(QString::number(laserMotor.encoderVel));
    ui->labelLaserMotorCurrent->setText(QString::number(laserMotor.current,'f',2));
    ui->labelLaserMotorPWM->setText(QString::number(laserMotor.pwmValue));
    ui->labelLaserAngle->setText(QString::number(laserMotor.anglePos * 180 /M_PI,'f',1));

    //charge
    ui->labelSystemVol->setText(QString::number(systemData.systemVol,'f',2));
    ui->labelBatteryVol->setText(QString::number(chargeData.batteryVol,'f',2));
    ui->lineEditBatteryFuel->setText(QString::number(chargeData.batteryFuel,'f',2));
    ui->lineEditChargeCurrent->setText(QString::number(chargeData.chargeCurrent,'f',2));
    ui->lineEditChargeErrorCode->setText(QString::number(chargeData.chargeErrorCode));
    if (chargeData.chargeMode == 0){
        ui->lineEditChargeMode->setText(QString::number(chargeData.chargeMode) + ":Ready To Start");
        ui->lineEditChargeTime->setText("00:00");
    }

    else if(chargeData.chargeMode == 1){
        ui->lineEditChargeMode->setText(QString::number(chargeData.chargeMode) + ":Detect Pack");
    }
    else if(chargeData.chargeMode == 6){
        ui->lineEditChargeMode->setText(QString::number(chargeData.chargeMode) + ":Charging");
        ui->lineEditChargeTime->setText(QString::number(chargeData.chargeTimeMin) + ":"
                                        + QString::number(chargeData.chargeTimeSec - chargeData.chargeTimeMin * 60));
        ui->pushButtonChargeCtrl->setText("StopCharge");
        ui->pushButtonSwitchPower->setText("BatteryPower");

    }
    else if(chargeData.chargeMode == 10){
        ui->lineEditChargeMode->setText(QString::number(chargeData.chargeMode) + ":Halt for Safety Screen");
    }
    else if(chargeData.chargeMode == 99){
        ui->lineEditChargeMode->setText(QString::number(chargeData.chargeMode) + ":Stop for Error");
    }
    else{
        ui->lineEditChargeMode->setText(QString::number(chargeData.chargeMode));
    }

    if (chargeData.powerReduceReason == 0){
        ui->lineEditChargePPR->setText(QString::number(chargeData.powerReduceReason) + ":Full Power Allowed");
    }
    else if (chargeData.powerReduceReason == 1){
        ui->lineEditChargePPR->setText(QString::number(chargeData.powerReduceReason) + ":Input Current Limit");
    }
    else if (chargeData.powerReduceReason == 2){
        ui->lineEditChargePPR->setText(QString::number(chargeData.powerReduceReason) + ":60A Current Limit");
    }
    else if (chargeData.powerReduceReason == 3){
        ui->lineEditChargePPR->setText(QString::number(chargeData.powerReduceReason) + ":Cell Sum Error");
    }
    else if (chargeData.powerReduceReason == 4){
        ui->lineEditChargePPR->setText(QString::number(chargeData.powerReduceReason) + ":Supply Noise");
    }
    else if (chargeData.powerReduceReason == 5){
        ui->lineEditChargePPR->setText(QString::number(chargeData.powerReduceReason) + ":High Temperature");
    }
    else if (chargeData.powerReduceReason == 6){
        ui->lineEditChargePPR->setText(QString::number(chargeData.powerReduceReason) + ":Low Input Noise");
    }
    else if (chargeData.powerReduceReason == 1){
        ui->lineEditChargePPR->setText(QString::number(chargeData.powerReduceReason) + ":Input Current Limit");
    }
    else{
        ui->lineEditChargePPR->setText(QString::number(chargeData.powerReduceReason));
    }

    ui->lineEditDCCurrent->setText(QString::number(chargeData.dcPowerCurrent,'f',2));
    ui->lineEditDCPower->setText(QString::number(chargeData.dcPowerVol,'f',2));

    ui->labelIndoorGPSMarkID->setText(QString::number(indoorGPS.markID));
    ui->labelRobotX_GPS->setText(QString::number(robotPosition.robotX,'f',2));
    ui->labelRobotY_GPS->setText(QString::number(robotPosition.robotY,'f',2));
    ui->labelRobotheading_GPS->setText(QString::number(robotPosition.robotDir * 180 /M_PI, 'f',2));
    ui->labelIndoorGPSMsg->setText(indoorGPS.indoorGPSMsg);
    ui->labelMarkHeight->setText(QString::number(indoorGPS.markHeight,'f',2));

}

//motion control communication here

void MainWindow::connectToMotionController()
{

    bool ok = false;
    QString temp = ui->pushButtonMotionConnect->text();

    if (temp == tr("Connect"))
    {

        QString addr = ui->lineEditNetworkIP1->text().trimmed();
        int port = ui->lineEditMotionPort->text().toInt(&ok,10);
        ui->pushButtonMotionConnect ->setText(tr("Disconnect"));
        udpMotion = new QUdpSocket(this);

        udpMotion->connectToHost(QHostAddress(addr),port);

        connect(udpMotion,SIGNAL(readyRead()), this, SLOT(processMotionData()));

        udpMotion->write(MOTION_PING);
        systemData.motionControlTimeOutCnt = 0;
        systemData.motionControlFlag = 1;
        ui->groupBoxMotorSensors->setEnabled(true);
        QPixmap pixma (":/images/icon2.png");
        ui->labelMotionPortState->setPixmap(pixma);
        pingCnt = 0;
    }
    else
    {
        disconnect(udpMotion,SIGNAL(readyRead()), this, SLOT(processMotionData()));
        systemData.motionControlTimeOutCnt = 0;
        systemData.motionControlFlag = 0;

        ui->pushButtonMotionConnect ->setText(tr("Connect"));
        udpMotion->close();

        ui->groupBoxMotorSensors->setEnabled(false);
        QPixmap pixma (":/images/icon1.png");
        ui->labelMotionPortState->setPixmap(pixma);
    }
}


void MainWindow::processMotionData()
{
    QByteArray datagram;
    QString received = "";
    qint64 count = 0;
    int headPos = -1;
    int tailPos = -1;
    bool keepSearch = false;
    do {
        systemData.motionControlTimeOutCnt = 0;
        count = udpMotion->pendingDatagramSize();
        datagram.resize(count);
        udpMotion->readDatagram(datagram.data(), datagram.size());
        if (count > 200 )
        {
            break;
        }
        else
        {
            receivedData.append(datagram);
            count = receivedData.size();

            keepSearch = true;
            while(keepSearch)
            {


                headPos = receivedData.indexOf(STX);

                if (headPos < 0)
                {
                    //do nothing , wait for more data
                    keepSearch = false;
                    //discard all data
                    receivedData = receivedData.remove(0,receivedData.size() );
                }
                else
                {
                    if (receivedData.size()> LENGTHOFDATAPACKAGE)
                    {
                        int c1 = (receivedData.at(headPos + LENGTHPOS));

                        tailPos = headPos + c1 + LENGTHOFDATAPACKAGE;
                        if(receivedData.mid(tailPos -2,2) != ETX)
                        {
                            //wrong, discard these data
                            receivedData = receivedData.remove(headPos,tailPos);
                        }
                        else
                        {
                            //here is the package
                            QByteArray data = receivedData.mid(headPos,tailPos - headPos);
                            dealWithPackage(data.constData(), data.size());
                            //cut the package
                            receivedData = receivedData.remove(headPos,tailPos - headPos);
                        }
                    }else{
                        keepSearch = false;
                    }
                }
            }
        }
    } while (udpMotion->hasPendingDatagrams());
}


void MainWindow::dealWithPackage(const char *dataPoint, int len)
{
    QString received;
    int value,adValue;
    double dis, vol;

    //protocol data package
    //STX(0,1) + RID(2) + Reserved(3) + DID(4)+ LENGTH(5) + DATA(...) + CHECKSUM + ETX
    //first check the checksum and the length
    if ( ((unsigned char)*(dataPoint + LENGTHPOS) + LENGTHOFDATAPACKAGE) != len)
    {
        return;	//wrong package length
    }
    else if((unsigned char)*(dataPoint + len - 3) != checkSum(dataPoint, len))
    {
        return;	//wrong checksum
    }
    else if ((unsigned char)*(dataPoint + RID) != 0)
    {

        return;//wrong RID
    }
    else
    {
        //here is the data package, please refer the protocol document
        if ((unsigned char)*(dataPoint + DID) == GENERALSENSOR)
        {
            //here is the general sensor data package
            value = (int)((unsigned char)*(dataPoint + DATAPOS + 1));
            dis = (double)value/100;
            usData[0].detectDis = dis;
            sensorData.UsDis[0] = dis;
            value = (int)((unsigned char)*(dataPoint + DATAPOS + 2));
            dis = (double)value/100;
            usData[1].detectDis = dis;
            sensorData.UsDis[1] = dis;

            value = (int)((unsigned char)*(dataPoint + DATAPOS + 3));
            dis = (double)value/100;
            usData[2].detectDis = dis;
            sensorData.UsDis[2] = dis;

            value = (int)((unsigned char)*(dataPoint + DATAPOS + 4));
            dis = (double)value/100;
            usData[3].detectDis = dis;
            sensorData.UsDis[3] = dis;

            value = (int)((unsigned char)*(dataPoint + DATAPOS + 5));
            dis = (double)value/100;
            usData[4].detectDis = dis;
            sensorData.UsDis[4] = dis;

            value = (int)((unsigned char)*(dataPoint + DATAPOS + 6));
            dis = (double)value/100;
            usData[5].detectDis = dis;
            sensorData.UsDis[5] = dis;


            //human sensor , not used now
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 8))* 256 + (unsigned char)*(dataPoint + DATAPOS + 7);
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 10))* 256 + (unsigned char)*(dataPoint + DATAPOS + 9);
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 12))* 256 + (unsigned char)*(dataPoint + DATAPOS + 11);
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 14))* 256 + (unsigned char)*(dataPoint + DATAPOS + 13);
            //ir 8 sensor tilt-x
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 16))* 256 + (unsigned char)*(dataPoint + DATAPOS + 15);
            dis = ad2Distance(adValue);
            irData[8].detectDis = dis;
            sensorData.IrDis[8] = dis;

            //ir 9 sensor tilt-y
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 18))* 256 + (unsigned char)*(dataPoint + DATAPOS + 17);
            dis = ad2Distance(adValue);
            irData[9].detectDis = dis;
            sensorData.IrDis[9] = dis;
            //ir 1 temperature
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 24))* 256 + (unsigned char)*(dataPoint + DATAPOS + 23);
            dis = ad2Distance(adValue);
            irData[1].detectDis = dis;
            sensorData.IrDis[1] = dis;


            //ir sensor 0
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 26))* 256 + (unsigned char)*(dataPoint + DATAPOS + 25);
            dis = ad2Distance(adValue);
            irData[0].detectDis = dis;
            sensorData.IrDis[0] = dis;

            //motion board voltage
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 32))* 256 + (unsigned char)*(dataPoint + DATAPOS + 31);
            vol = (double)adValue /4096 * 9 ;
            systemData.motionBoardVol = vol;


        }
        else if((unsigned char)*(dataPoint + DID) == SPECIALSENSOR)
        {
            //here is the expanded ad sensor or power sensor info for charge board
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 6))* 256 + (unsigned char)*(dataPoint + DATAPOS + 5);
            dis = ad2Distance(adValue);
            irData[2].detectDis = dis;
            sensorData.IrDis[2] = dis;
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 8))* 256 + (unsigned char)*(dataPoint + DATAPOS + 7);
            dis = ad2Distance(adValue);
            irData[3].detectDis = dis;
            sensorData.IrDis[3] = dis;

            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 10))* 256 + (unsigned char)*(dataPoint + DATAPOS + 9);
            dis = ad2Distance(adValue);
            irData[4].detectDis = dis;
            sensorData.IrDis[4] = dis;


            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 12))* 256 + (unsigned char)*(dataPoint + DATAPOS + 11);
            dis = ad2Distance(adValue);
            irData[5].detectDis = dis;
            sensorData.IrDis[5] = dis;

            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 14))* 256 + (unsigned char)*(dataPoint + DATAPOS + 13);
            dis = ad2Distance(adValue);
            irData[6].detectDis = dis;
            sensorData.IrDis[6] = dis;

            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 16))* 256 + (unsigned char)*(dataPoint + DATAPOS + 15);
            dis = ad2Distance(adValue);
            irData[7].detectDis = dis;
            sensorData.IrDis[7] = dis;
            //io input
            // d0-SW1, d1-Sw2,d2-SW3,d3-SW4, d7-inchargestation or not
            value = (unsigned char)*(dataPoint + DATAPOS + 17);
            systemData.bumpSensor = value & 0xf;
            if ((value & 0x1) == 0){
                bumpData.bumpSW1 = 1;
            }
            else{
                bumpData.bumpSW1 = 0;
            }
            if ((value & 0x2) == 0){
                bumpData.bumpSW2 = 1;
            }
            else{
                bumpData.bumpSW2 = 0;
            }
            if ((value & 0x4) == 0){
                bumpData.bumpSW3 = 1;
            }
            else{
                bumpData.bumpSW3 = 0;
            }
            if ((value & 0x8) == 0){
                bumpData.bumpSW4 = 1;
            }
            else{
                bumpData.bumpSW4 = 0;
            }
            if ((value & 0x80) == 0){
                if (!exitChargeFlag){
                    if (systemData.chargeStationFlag != 1){
                        inChargeCnt++;
                        if (inChargeCnt > DETECT_CHARGER_TH){
                            systemData.chargeStationFlag = 1;
                            chargeData.inChargeStation = 1;
                            //stop robot
                            robotMotorNoTimeControlAll(MOTORPWMCTRLALL,PWM0,PWM0,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL);
                            drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdStopP2P);
                            pathControlTimer.stop();
                        }
                    }
                }
            }
            else{
                inChargeCnt = 0;
                systemData.chargeStationFlag = 0;
                chargeData.inChargeStation = 0;
            }

            //expand encoder here
            value = (int)((unsigned char)*(dataPoint + DATAPOS + 19))* 256 + (unsigned char)*(dataPoint + DATAPOS + 18);
            motorData[2].encoderPos = value;
            value = (int)((unsigned char)*(dataPoint + DATAPOS + 21))* 256 + (unsigned char)*(dataPoint + DATAPOS + 20);
            motorData[2].encoderVel = value;
            value = (int)((unsigned char)*(dataPoint + DATAPOS + 23))* 256 + (unsigned char)*(dataPoint + DATAPOS + 22);
            if ((value & 0x1) == 0x1){
                motorData[2].encoderDir = 1;
            }
            else{
                motorData[2].encoderDir = 0;
            }

            value = (int)((unsigned char)*(dataPoint + DATAPOS + 25))* 256 + (unsigned char)*(dataPoint + DATAPOS + 24);
            motorData[3].encoderPos = value;
            value = (int)((unsigned char)*(dataPoint + DATAPOS + 27))* 256 + (unsigned char)*(dataPoint + DATAPOS + 26);
            motorData[3].encoderVel = value;
            value = (int)((unsigned char)*(dataPoint + DATAPOS + 29))* 256 + (unsigned char)*(dataPoint + DATAPOS + 28);
            if ((value & 0x1) == 0x1){
                motorData[3].encoderDir = 1;
            }
            else{
                motorData[3].encoderDir = -1;
            }

            if (motorData[2].encoderPos > 16384){

                value = motorData[2].encoderPos - 32767;
            }
            else{
                value = motorData[2].encoderPos;
            }

            motorData[2].anglePos = ((double)value)/HEAD_TILT_CIRCLE_CNT * M_PI * 2;
            systemData.headTiltAngle = motorData[2].anglePos;
            if (motorData[3].encoderPos > 16384){

                value = motorData[3].encoderPos - 32767;
            }
            else{
                value = motorData[3].encoderPos;
            }
            motorData[3].anglePos = ((double)value)/HEAD_PAN_CIRCLE_CNT * M_PI * 2;
            systemData.headPanAngle = motorData[3].anglePos;

        }
        else if((unsigned char)*(dataPoint + DID) == MOTORSENSOR)
        {
            //here is the motor sensor information
            //position
            int temp = (int)((unsigned char)*(dataPoint + DATAPOS + 26))* 256 + (unsigned char)*(dataPoint + DATAPOS + 25);
            motorData[0].encoderPos = temp;
            temp = (int)((unsigned char)*(dataPoint + DATAPOS + 30))* 256 + (unsigned char)*(dataPoint + DATAPOS + 29);
            motorData[1].encoderPos = temp;
            robotPosition.LeftWheelEncoderCnt = motorData[0].encoderPos;
            robotPosition.RightWheelEncoderCnt = motorData[1].encoderPos;
            encoderEstPos();
            drrobotp2pSpeedDrive.UpdateSensorMap_Position(robotPosition,sensorMapData);

            //speed
            temp = (int)((unsigned char)*(dataPoint + DATAPOS + 28))* 256 + (unsigned char)*(dataPoint + DATAPOS + 27);
            motorData[0].encoderVel = temp;
            temp = (int)((unsigned char)*(dataPoint + DATAPOS + 32))* 256 + (unsigned char)*(dataPoint + DATAPOS + 31);
            motorData[1].encoderVel = temp;

            temp = (int)((unsigned char)*(dataPoint + DATAPOS + 33));
            if( (temp & 0x1) == 1){
                motorData[0].encoderDir = 1;
            }
            else{
                motorData[0].encoderDir = -1;
            }
            if( (temp & 0x2) == 0x2){
                motorData[1].encoderDir = 1;
            }
            else{
                motorData[1].encoderDir = -1;
            }
            //calvin codes here, estimate velocity
            robotEstVel();
            //calvin end


            // now current feedback, we used it as IR range input
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 14))* 256 + (unsigned char)*(dataPoint + DATAPOS + 13);
            dis = ad2Distance(adValue);
            irData[10].detectDis = dis;
            sensorData.IrDis[10] = dis;
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 16))* 256 + (unsigned char)*(dataPoint + DATAPOS + 15);
            dis = ad2Distance(adValue);
            irData[11].detectDis = dis;
            sensorData.IrDis[11] = dis;
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 18))* 256 + (unsigned char)*(dataPoint + DATAPOS + 17);
            dis = ad2Distance(adValue);
            irData[12].detectDis = dis;
            sensorData.IrDis[12] = dis;
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 20))* 256 + (unsigned char)*(dataPoint + DATAPOS + 19);
            dis = ad2Distance(adValue);
            irData[13].detectDis = dis;
            sensorData.IrDis[13] = dis;
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 22))* 256 + (unsigned char)*(dataPoint + DATAPOS + 21);
            dis = ad2Distance(adValue);
            irData[14].detectDis = dis;
            sensorData.IrDis[14] = dis;
            adValue = (int)((unsigned char)*(dataPoint + DATAPOS + 24))* 256 + (unsigned char)*(dataPoint + DATAPOS + 23);
            dis = ad2Distance(adValue);
            irData[15].detectDis = dis;
            sensorData.IrDis[15] = dis;

            // no potentiometer sensor, we used as output PWM value
            value = (int)((unsigned char)*(dataPoint + DATAPOS + 2))* 256 + (unsigned char)*(dataPoint + DATAPOS + 1);
            motorData[0].pwmValue = value - INIPWM;
            value = (int)((unsigned char)*(dataPoint + DATAPOS + 4))* 256 + (unsigned char)*(dataPoint + DATAPOS + 3);
            motorData[1].pwmValue = value - INIPWM;

            //channel 3,4
            value = (int)((unsigned char)*(dataPoint + DATAPOS + 8))* 256 + (unsigned char)*(dataPoint + DATAPOS + 7);
            motorData[2].pwmValue = value - INIPWM;
            value = (int)((unsigned char)*(dataPoint + DATAPOS + 10))* 256 + (unsigned char)*(dataPoint + DATAPOS + 9);
            motorData[3].pwmValue = value - INIPWM;
        }
    }
}

double MainWindow::ad2Distance(int value)
{
    double temp = 0;
    double IRAD2Distance = 0;
    temp = 21.6 / ((double)value * 3 / 4028 - 0.17);

    // IR range 10-80cm
    if ((temp > 80) || (temp < 0))
        IRAD2Distance = 0.81;
    else if ((temp < 10) && (temp > 0))
        IRAD2Distance = 0.09;
    else
        IRAD2Distance = temp / 100;

    return IRAD2Distance;
}

unsigned char MainWindow::checkSum(const char *packPoint, int len)
{
    unsigned char shift_reg,sr_lsb,data_bit,v, fb_bit;
    int i,j;
    shift_reg = 0;//initialize the shift register
    for(i = 2; i < len - 3; ++i)		//from RID to checksum - 1
    {
        v = (unsigned char)(*(packPoint + i));
        for (j = 0; j < 8; ++j)
        {
            data_bit = v & 0x01;	//isolate least bit
            sr_lsb = shift_reg & 0x01;
            fb_bit = (data_bit ^ sr_lsb) & 0x01;	//calculate the feed back bit
            shift_reg = shift_reg >> 1;
            if (fb_bit == 1)
            {
                shift_reg = shift_reg ^ 0x8c;
            }
            v = v >> 1;
        }
    }
    return shift_reg;
}

void MainWindow::sendForwardCmd()
{

    int cmd1 = ui->horizontalSliderWheelCmd->value();
    int cmd2 = cmd1;

    ctrlMode = MOTORVELCTRLALL;
    cmd1 = -motDir * cmd1;
    cmd2 = motDir * cmd2;
    //here we use no time control all command
    robotMotorNoTimeControlAll(ctrlMode,cmd1,cmd2,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL);
    //int time = ui->lineEditHeadCtrlTime->text().toInt();
    //robotMotorTimeControlAll(ctrlMode,cmd1,cmd2,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL,time);

}
void MainWindow::sendStopCmd()
{
    int cmd1,cmd2;

    ctrlMode = MOTORPWMCTRLALL;
    cmd1 = INIPWM ;
    cmd2 = INIPWM ;

    //here we use no time control all command
    robotMotorNoTimeControlAll(ctrlMode,cmd1,cmd2,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL);
    pathControlTimer.stop();
    drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdStopP2P);

}
void MainWindow::sendBackwardCmd()
{
    int cmd1 = ui->horizontalSliderWheelCmd->value();
    int cmd2 = cmd1;

    ctrlMode = MOTORVELCTRLALL;
    cmd1 = motDir * cmd1;
    cmd2 = -motDir * cmd2;
    //here we use no time control all command
    robotMotorNoTimeControlAll(ctrlMode,cmd1,cmd2,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL);
}
void MainWindow::sendLeftTurnCmd()
{
    int cmd1 = ui->horizontalSliderWheelCmd->value();
    int cmd2 = cmd1;
    ctrlMode = MOTORVELCTRLALL;
    cmd1 = motDir * cmd1;
    cmd2 = motDir * cmd2;

    //here we use no time control all command
    robotMotorNoTimeControlAll(ctrlMode,cmd1,cmd2,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL);
}
void MainWindow::sendRightTurnCmd()
{
    int cmd1 = ui->horizontalSliderWheelCmd->value();
    int cmd2 = cmd1;
    ctrlMode = MOTORVELCTRLALL;
    cmd1 = motDir * cmd1;
    cmd2 = motDir * cmd2;

    //here we use no time control all command
    robotMotorNoTimeControlAll(ctrlMode,-cmd1,-cmd2,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL);
}

void MainWindow::sendHeadStopCmd()
{
    int cmd1,cmd2;

        ctrlMode = MOTORPWMCTRLALL;
        cmd1 = INIPWM ;
        cmd2 = INIPWM ;

        //here we use no time control all command
        robotMotorNoTimeControlAll(ctrlMode,NOCONTROL,NOCONTROL,NOCONTROL,cmd1,cmd2,NOCONTROL);
}

void MainWindow::sendHeadTiltCmd()
{
    double anglePos = ui->verticalSliderHeadTilt->value();
    int cmd = anglePos * HEAD_TILT_CIRCLE_CNT /360;
    if (cmd < 0) cmd = 32767 + cmd;
    int time = ui->lineEditHeadCtrlTime->text().toInt();
    ctrlMode = MOTORPOSCTRL;
    // here we use position time control
    robotMotorTimeControl(ctrlMode,3,cmd,time);
}
void MainWindow::sendHeadPanCmd()
{
    double anglePos = ui->horizontalSliderHeadPan->value();
    int cmd = anglePos * HEAD_PAN_CIRCLE_CNT /360;
    if (cmd < 0) cmd = 32767 + cmd;
    int time = ui->lineEditHeadCtrlTime->text().toInt();
    ctrlMode = MOTORPOSCTRL;
    // here we use position time control
    robotMotorTimeControl(ctrlMode,4,cmd,time);
}


void MainWindow::resetHeadPan()
{

    int time = ui->lineEditHeadCtrlTime->text().toInt();
    ctrlMode = MOTORPOSCTRL;
    // here we use position time control
    robotMotorTimeControl(ctrlMode,4,0,time);
    ui->horizontalSliderHeadPan->setValue(0);
}

void MainWindow::resetHeadTilt()
{

    int time = ui->lineEditHeadCtrlTime->text().toInt();
    ctrlMode = MOTORPOSCTRL;
    // here we use position time control
    robotMotorTimeControl(ctrlMode,3,0,time);

    ui->verticalSliderHeadTilt->setValue(0);
}

void MainWindow::robotMotorTimeControl(int ctrlMode,int channel, int value, int time )
{
    QByteArray sendData;
    sendData.resize(15);
    sendData[0] = STX0;
    sendData[1] = STX1;
    sendData[2] = 1;
    sendData[3] = 0;
    sendData[4] = (unsigned char)(ctrlMode & 0xff);	//DID
    sendData[5] = 6;			//length
    sendData[6] = (unsigned char)(channel & 0xff);			//channel

    sendData[7] = (unsigned char)(value & 0xff);
    sendData[8] = (unsigned char)((value >> 8) & 0xff);
    sendData[9] = TIME_FLAG;			//TIME_FLAG = 28
    sendData[10] = (unsigned char)(time & 0xff);
    sendData[11] = (unsigned char)((time >> 8) & 0xff);
    sendData[12] = 0;
    sendData[13] = ETX0;
    sendData[14] = ETX1;

    sendData[12] = checkSum(sendData.data(), sendData.size());
    if (udpMotion != NULL){
        if (udpMotion->isWritable()){
            udpMotion->write(sendData);
        }
    }
}

void MainWindow::robotMotorNoTimeControl(int ctrlMode,int channel, int value)
{
    QByteArray sendData;
    sendData.resize(12);
    sendData[0] = STX0;
    sendData[1] = STX1;
    sendData[2] = 1;
    sendData[3] = 0;
    sendData[4] = (unsigned char)ctrlMode;	//DID
    sendData[5] = 3;			//length
    sendData[6] = (unsigned char)(channel & 0xff);			//channel

    sendData[7] = (unsigned char)(value & 0xff);
    sendData[8] = (unsigned char)((value >> 8) & 0xff);
    sendData[9] = 0;
    sendData[10] = ETX0;
    sendData[11] = ETX1;

    sendData[9] = checkSum(sendData.data(), sendData.size());
    if (udpMotion != NULL){
        if (udpMotion->isWritable()){
            udpMotion->write(sendData);
        }
    }

}
void MainWindow::robotMotorTimeControlAll(int ctrlMode,int value1, int value2, int value3,int value4,int value5,int value6, int time)
{
    QByteArray sendData;
    sendData.resize(23);
    sendData[0] = STX0;
    sendData[1] = STX1;
    sendData[2] = 1;
    sendData[3] = 0;
    sendData[4] = (unsigned char)(ctrlMode & 0xff);	//DID
    sendData[5] = 14;			//length
    sendData[6] = (unsigned char)(value1 & 0xff);
    sendData[7] = (unsigned char)((value1 >> 8) & 0xff);
    sendData[8] = (unsigned char)(value2 & 0xff);
    sendData[9] = (unsigned char)((value2 >> 8) & 0xff);
    sendData[10] = (unsigned char)(value3 & 0xff);
    sendData[11] = (unsigned char)((value3 >> 8) & 0xff);
    sendData[12] = (unsigned char)(value4 & 0xff);
    sendData[13] = (unsigned char)((value4 >> 8) & 0xff);
    sendData[14] = (unsigned char)(value5 & 0xff);
    sendData[15] = (unsigned char)((value5 >> 8) & 0xff);
    sendData[16] = (unsigned char)(value6 & 0xff);
    sendData[17] = (unsigned char)((value6 >> 8) & 0xff);
    sendData[18] = (unsigned char)(time & 0xff);
    sendData[19] = (unsigned char)((time >> 8) & 0xff);
    sendData[20] = 0;
    sendData[21] = ETX0;
    sendData[22] = ETX1;

    sendData[20] = checkSum(sendData.data(), sendData.size());
    if (udpMotion != NULL){
        if (udpMotion->isWritable()){
            udpMotion->write(sendData);
        }
    }

}
void MainWindow::robotMotorNoTimeControlAll(int ctrlMode,int value1, int value2, int value3,int value4,int value5,int value6)
{
    QByteArray sendData;
    sendData.resize(21);
    sendData[0] = STX0;
    sendData[1] = STX1;
    sendData[2] = 1;
    sendData[3] = 0;
    sendData[4] = (unsigned char)(ctrlMode & 0xff);	//DID
    sendData[5] = 12;			//length
    sendData[6] = (unsigned char)(value1 & 0xff);
    sendData[7] = (unsigned char)((value1 >> 8) & 0xff);
    sendData[8] = (unsigned char)(value2 & 0xff);
    sendData[9] = (unsigned char)((value2 >> 8) & 0xff);
    sendData[10] = (unsigned char)(value3 & 0xff);
    sendData[11] = (unsigned char)((value3 >> 8) & 0xff);
    sendData[12] = (unsigned char)(value4 & 0xff);
    sendData[13] = (unsigned char)((value4 >> 8) & 0xff);
    sendData[14] = (unsigned char)(value5 & 0xff);
    sendData[15] = (unsigned char)((value5 >> 8) & 0xff);
    sendData[16] = (unsigned char)(value6 & 0xff);
    sendData[17] = (unsigned char)((value6 >> 8) & 0xff);
    sendData[18] = 0;
    sendData[19] = ETX0;
    sendData[20] = ETX1;

    sendData[18] = checkSum(sendData.data(), sendData.size());
    if (udpMotion != NULL){
        if (udpMotion->isWritable()){
            udpMotion->write(sendData);
        }
    }
}

void MainWindow::connectToLaserDrive()
{
    bool ok = false;
    QString temp = ui->pushButtonLaserConnect->text();

    if (temp == tr("Connect"))
    {

        QString addr = ui->lineEditNetworkIP2->text().trimmed();
        int port = ui->lineEditLaserPort->text().toInt(&ok,10);
        ui->pushButtonLaserConnect ->setText(tr("Disconnect"));
        tcpLaserDrive = new QTcpSocket(this);

        connect(tcpLaserDrive,SIGNAL(readyRead()), this, SLOT(processLaserDriveData()));
        tcpLaserDrive->connectToHost(QHostAddress(addr),port);
        tcpLaserDrive->write("?A \r");
        systemData.laserDriveTimeOutCnt = 0;
        systemData.laserDriveFlag = 1;
        ui->groupBoxLaserScan->setEnabled(true);
        QPixmap pixma (":/images/icon2.png");
        ui->labelLaserPortState->setPixmap(pixma);
        laserDriveFlag = 0;
    }
    else
    {
        disconnect(tcpLaserDrive,SIGNAL(readyRead()), this, SLOT(processLaserDriveData()));
        laserDriveFlag = 0;
        ui->pushButtonLaserConnect ->setText(tr("Connect"));
        tcpLaserDrive->close();
        systemData.laserDriveTimeOutCnt = 0;
        systemData.laserDriveFlag = 0;
        ui->groupBoxLaserScan->setEnabled(false);
        QPixmap pixma (":/images/icon1.png");
        ui->labelLaserPortState->setPixmap(pixma);
    }
}

void MainWindow::processLaserDriveData()
{

    char revData[MAX_BUFFER_SIZE];
    systemData.laserDriveTimeOutCnt  = 0;
    do{
        tcpLaserDrive->readLine(revData,MAX_BUFFER_SIZE);
        dealWithLaserDrivePackage(QString::fromUtf8(revData));
    }while(tcpLaserDrive->canReadLine());
}

void MainWindow::dealWithLaserDrivePackage(QString revData)
{
    if (laserDriveFlag == 0) laserDriveFlag = 1;
    if (revData.length() > 25){
        //discard all, to wait for next receive
        revData.clear();
    }
    else{

        if (revData.startsWith("A=")){
            //current data
            revData = revData.remove(0,2);
            QStringList data = revData.split(":");
            if (data.length()> 1) laserMotor.current = data[0].toDouble()/10;

        }
        else if(revData.startsWith("AI=")){
            // A/D data, here 3,4 will be motor temperature sensor
            revData = revData.remove(0,3);
            QStringList data = revData.split(":");

        }
        else if(revData.startsWith("C=")){
            // encoder position data
            revData = revData.remove(0,2);
            QStringList data = revData.split(":");
            if (data.length()> 1)       laserMotor.encoderPos = data[0].toInt();
            laserMotor.anglePos = -((double)laserMotor.encoderPos - 0) / LASER_SCAN_RESOLUTION /180 * M_PI;
            laserData.tilt_Angle = laserMotor.anglePos;
            systemData.laserTiltAngle = laserData.tilt_Angle;

        }
        else if(revData.startsWith("P=")){
            // output PWM value, 0 ~ 1000
            revData = revData.remove(0,2);

            QStringList data = revData.split(":");
            if (data.length()> 1)  laserMotor.pwmValue = data[0].toInt();

        }
        else if(revData.startsWith("S=")){
            // encoder velocity data RPM
            revData = revData.remove(0,2);
             QStringList data = revData.split(":");
             if (data.length()> 1) laserMotor.encoderVel = data[0].toInt();


        }
        else if(revData.startsWith("T=")){
            // motor driver board temperature
            revData = revData.remove(0,2);
             QStringList data = revData.split(":");
             //if (data.length()> 1) ch1Temp[index] = data[0].toDouble();

        }
        else if(revData.startsWith("V=")){
            // voltage data
            revData = revData.remove(0,2);
            QStringList data = revData.split(":");
            if (data.length()> 2){
                //drvVoltage[index] = data[0].toDouble()/10;      //12v
                 systemData.systemVol= data[1].toDouble()/10;      //battery vol or system vol
                 chargeData.systemVol = systemData.systemVol;

                //reg5Voltage[index] = data[2].toDouble() /1000;
            }

        }
        else if(revData.startsWith("CR=")){
            // here is the encoder relative difference reading,
            // very useful to estimate the encoder/motor traveling distance
        }
        else if(revData.startsWith("FF=")){
            // driver board state
            revData = revData.remove(0,3);
            laserData.driveState = revData.toInt();
        }
    }

}

void MainWindow::setLaserPosition(double angle)
{
    int cmd = 0;
    QString send;
    if ( angle <= LASER_SCAN_UP_TH && angle >= LASER_SCAN_DOWN_TH){
        cmd = (int)(angle * LASER_SCAN_RESOLUTION);
        send = "!P 1 " + QString::number(cmd) + "\r";
        if (tcpLaserDrive->isWritable()){
            tcpLaserDrive->write(send.toStdString().c_str());
        }
    }
}

void MainWindow::laserResetDrive()
{
    setLaserPosition(0);
    laserScanTimer.stop();
    disconnect(&laserScanTimer,SIGNAL(timeout()),this,SLOT(laserAutoScan()));
    ui->pushButtonLaserAutoScan->setText("AutoScan");
    ui->verticalSliderLaserDrive->setValue(0);
}

void MainWindow::sendLaserDriveCmd()
{
    double angle = -ui->verticalSliderLaserDrive->value();
    setLaserPosition(angle);

}

void MainWindow::setLaserAutoScan()
{

    QString temp = ui->pushButtonLaserAutoScan->text();

    if (temp == tr("AutoScan"))
    {
        ui->pushButtonLaserAutoScan->setText("StopScan");
        laserAutoScanFlag = 1;
        laserAutoScanDelayCnt = 0;
        laserAutoScanStep = 0;
        connect(&laserScanTimer,SIGNAL(timeout()),this,SLOT(laserAutoScan()));
        laserScanTimer.setInterval(500);
        laserScanTimer.start();
        laserData.stopFlag = 0;
        laserScanDir = 1;

    }
    else
    {
        setLaserPosition(0);
        laserData.stopFlag = 1;
        laserScanTimer.stop();
        disconnect(&laserScanTimer,SIGNAL(timeout()),this,SLOT(laserAutoScan()));
        laserAutoScanFlag = 0;
        ui->pushButtonLaserAutoScan->setText("AutoScan");
    }
}


void MainWindow::laserAutoScan()
{
    double angle = 0;
    if (laserAutoScanFlag > 0){
        if (laserAutoScanDelayCnt == 0){
            laserAutoScanDelayCnt = 1;
        }
        else{
            laserAutoScanDelayCnt = 0;
            //start  drive laser
               angle = laserAutoScanStep * LASER_SCAN_STEP;
               if (angle == LASER_SCAN_UP_TH){
                   laserScanDir = -1;
               }
               if (angle == LASER_SCAN_DOWN_TH ){
                   laserScanDir = 1;
               }
               //send motor command here
               setLaserPosition(angle);
               laserAutoScanDelayCnt = 0;
               if (laserScanDir > 0) laserAutoScanStep++;
               if (laserScanDir < 0) laserAutoScanStep--;

        }
    }

}

void MainWindow::connectToChargerController()
{
    bool ok = false;
    QString temp = ui->pushButtonChargerConnect->text();

    if (temp == tr("Connect"))
    {

        QString addr = ui->lineEditNetworkIP1->text().trimmed();
        int port = ui->lineEditChargerPort->text().toInt(&ok,10);
        ui->pushButtonChargerConnect ->setText(tr("Disconnect"));
        processedChargeData.clear();
        tcpCharge = new QTcpSocket(this);

        connect(tcpCharge,SIGNAL(readyRead()), this, SLOT(processChargeData()));
        tcpCharge->connectToHost(QHostAddress(addr),port);

        systemData.chargeControlTimeoutCnt = 0;
        systemData.chargeControllerFlag = 1;
        ui->groupBoxChargeControl->setEnabled(true);
        QPixmap pixma (":/images/icon2.png");
        ui->labelChargerPortState->setPixmap(pixma);

    }
    else
    {
        disconnect(tcpCharge,SIGNAL(readyRead()), this, SLOT(processChargeData()));
        ui->pushButtonChargerConnect ->setText(tr("Connect"));
        tcpCharge->close();
        systemData.chargeControllerFlag = 0;
        systemData.chargeControlTimeoutCnt = 0;
        ui->groupBoxChargeControl->setEnabled(false);
        QPixmap pixma (":/images/icon1.png");
        ui->labelChargerPortState->setPixmap(pixma);
    }
}

void MainWindow::processChargeData()
{

   // char revData[MAX_BUFFER_SIZE];
    QByteArray revData;
    systemData.chargeControlTimeoutCnt  = 0;
    do{
        revData.resize(tcpCharge->bytesAvailable());
        revData = tcpCharge->readAll();
        dealWithChargeControllerData(revData);
    }while(tcpCharge->bytesAvailable() > 0);
}

void MainWindow::dealWithChargeControllerData(QByteArray rcvData)
{
    int dataLen = 0;
    processedChargeData.append(rcvData);
    dataLen = processedChargeData.length();
    if (dataLen == CHARGE_DATA_PACK_LEN + 4)
    {
        if ((processedChargeData[0] == (char) 'R') && (processedChargeData[1] == (char) 'a')\
                && (processedChargeData[2] == (char) 'm') && ((int)processedChargeData[3] == 0)){
            //received Ram0 package here
            revCRC = crc16Byte(processedChargeData,RXCRC16,4,CHARGE_DATA_PACK_LEN + 4-2);
            int temp = static_cast<quint8>(processedChargeData[151]) * 256 + static_cast<quint8>(processedChargeData[152]);
            if (temp == revCRC){
                // right data package received
                for (int i = 0; i < 6; i++){
                    chargeData.cellVol[i] = (double)(static_cast<quint8>(processedChargeData[6 + 2 * i]) * 256 + static_cast<quint8>(processedChargeData[6 + 2 * i + 1]) )* 5.12/65536;

                }
                double vrAmp = (double)(static_cast<quint8>(processedChargeData[72]) * 256 + static_cast<quint8>(processedChargeData[73])) /600;
                for (int i = 0; i < 6 ; i++){
                    if (vrAmp > 0){

                        chargeData.cellRes[i] = (double)(static_cast<quint8>(processedChargeData[56 + 2 * i])* 256 + static_cast<quint8>(processedChargeData[56 + 2 * i + 1]))/6.3984/vrAmp;

                    }
                    else{
                        chargeData.cellRes[i] = 0;
                    }

                }

                chargeData.dcPowerVol = (double)(static_cast<quint8>(processedChargeData[28]) * 256 + static_cast<quint8>(processedChargeData[29]))* 46.96/4095;
                double value = (double)(static_cast<quint8>(processedChargeData[84])* 256 + static_cast<quint8>(processedChargeData[85]))/150;
                if (value < 100){
                    chargeData.dcPowerCurrent = value;
                }
                chargeData.batteryFuel = (double)(static_cast<quint8>(processedChargeData[42]) * 256 + static_cast<quint8>(processedChargeData[43]))/10;
                chargeData.batteryVol = (double)(static_cast<quint8>(processedChargeData[36]) * 256 + static_cast<quint8>(processedChargeData[37]))/4095 * 46.96;
                value = (double)(static_cast<quint8>(processedChargeData[46]) * 256 + static_cast<quint8>(processedChargeData[47]))/600;
                if (value < 100) chargeData.chargeCurrent = value;
                chargeData.setCurrent = (double)(static_cast<quint8>(processedChargeData[122]) * 256 + static_cast<quint8>(processedChargeData[123]))/600;
                chargeData.chargeMode = static_cast<quint8>(processedChargeData[137]);
                chargeData.chargeErrorCode = static_cast<quint8>(processedChargeData[138]);
                chargeData.chargeStatus = (int)(static_cast<quint8>(processedChargeData[48]) * 256 + static_cast<quint8>(processedChargeData[49]));
                chargeData.chargeRxStatus = (int)(static_cast<quint8>(processedChargeData[46]) * 256 + static_cast<quint8>(processedChargeData[47]));
                chargeData.chargeTimeMin = (int)(static_cast<quint8>(processedChargeData[82]) * 256 + static_cast<quint8>(processedChargeData[83]));
                chargeData.chargeTimeSec = (int)(static_cast<quint8>(processedChargeData[32]) * 256 + static_cast<quint8>(processedChargeData[33]));
                chargeData.chargerCPUTemperature = ((double)(static_cast<quint8>(processedChargeData[30]) * 256 + static_cast<quint8>(processedChargeData[31])) * 2.5/4095 - 0.986)/0.00355;
                chargeData.powerReduceReason = static_cast<quint8>((processedChargeData[147]));
                systemData.batteryVol = chargeData.batteryVol;
                if (chargeData.chargeMode == 6){
                    systemData.chargeFlag = 1;
                }
                else{
                    systemData.chargeFlag = 0;
                }

            }
        }
        processedChargeData.resize(0);
    }
    else if(dataLen > (CHARGE_DATA_PACK_LEN + 4)){
        processedChargeData.resize(0);
    }
}

int MainWindow::crc16Byte(QByteArray data, int crc16, int startPos, int len)
{
    int result = 0;
    int32_t temp = 0;
    int16_t c = 0;
    int32_t tempData = 0;
  //  int32_t crc16 = RXCRC16;
    if (startPos > len)
    {
        return result;

    }
    else{
        for (int i = startPos; i < len;i++){
            tempData = (int32_t)data[i];
            if (tempData < 0){
                tempData = tempData + 256;
            }
            for (c = 1; c < 9; c++){
                temp = tempData ^ crc16;
                if ((int)(temp/2) == (int)((temp - 1)/2)){
                    crc16 = (int)crc16/2;
                    crc16 = 33800 ^ crc16;
                }
                else{
                    crc16 = (int)(crc16/2);

                }
                tempData = (int)(tempData /2);
            }
        }
        result = crc16;
        return result;
    }

}

void MainWindow::sendChargeCmd()
{
    QString temp = ui->pushButtonChargeCtrl->text();
    if (ui->checkBoxInChargeStation->isChecked()){
        if (temp == tr("StopCharge")){
            ui->pushButtonChargeCtrl->setText("StartCharge");
            if (tcpCharge->isWritable()){
                tcpCharge->write("StopC\r\n");   //stop charge
            }
        }
        else{
            ui->pushButtonChargeCtrl->setText("StopCharge");
            if (tcpCharge->isWritable()){
                tcpCharge->write("StartC\r\n");   //startcharge
            }
        }
    }

}

void MainWindow::sendSwitchPowerCmd()
{
    QString temp = ui->pushButtonSwitchPower->text();
    if (ui->checkBoxInChargeStation->isChecked()){
        if (temp == tr("DCPower")){
            ui->pushButtonSwitchPower->setText("BatteryPower");
            if (tcpCharge->isWritable()){
                tcpCharge->write("CHG1\r\n");   //using DC power
            }
        }
        else{
            ui->pushButtonSwitchPower->setText("DCPower");
            if (tcpCharge->isWritable()){
                tcpCharge->write("CHG0\r\n");   //using battery, need stop charge first?
            }
        }
    }
}

void MainWindow::setChargeEn()
{
    if (ui->checkBoxInChargeStation->isChecked()){
        ui->groupBoxChargeControl->setEnabled(true);
    }
    else{
        ui->groupBoxChargeControl->setEnabled(false);
        chargeData.batteryFuel = 0;
        chargeData.chargeFlag = 0;
        chargeData.chargeMode = 0;
        chargeData.chargeRxStatus = 0;
        chargeData.chargeStatus = 0;
        chargeData.dcPowerVol = 0;
        chargeData.chargeCurrent = 0;
        chargeData.chargeErrorCode = 0;
        chargeData.chargerCPUTemperature = 0;
       // chargeData.chargeTimeMin = 0;
       // chargeData.chargeTimeSec = 0;
        chargeData.dcPowerCurrent = 0;

    }
}

void MainWindow::connectToIndoorGPS()
{
    bool ok = false;
    QString temp = ui->pushButtonIndoorGPSConnect->text();

    if (temp == tr("Connect"))
    {

        QString addr = ui->lineEditNetworkIP2->text().trimmed();
        int port = ui->lineEditIndoorGPSPort->text().toInt(&ok,10);
        ui->pushButtonIndoorGPSConnect ->setText(tr("Disconnect"));
        tcpIndoorGPS = new QTcpSocket(this);

        connect(tcpIndoorGPS,SIGNAL(readyRead()), this, SLOT(processIndoorGPSData()));
        tcpIndoorGPS->connectToHost(QHostAddress(addr),port);
        systemData.indoorGPSTimeOutCnt = 0;
        systemData.indoorGPSFlag = 1;

        QPixmap pixma (":/images/icon2.png");
        ui->labelIndoorGPSPortState->setPixmap(pixma);
        ui->checkBoxEnIndoorGPS->setChecked(true);
    }
    else
    {
        disconnect(tcpIndoorGPS,SIGNAL(readyRead()), this, SLOT(processIndoorGPSData()));
        ui->pushButtonIndoorGPSConnect ->setText(tr("Connect"));
        tcpIndoorGPS->close();
        systemData.indoorGPSTimeOutCnt = 0;
        systemData.indoorGPSFlag = 0;

        QPixmap pixma (":/images/icon1.png");
        ui->labelIndoorGPSPortState->setPixmap(pixma);
        ui->checkBoxEnIndoorGPS->setChecked(false);
    }
}

void MainWindow::processIndoorGPSData()
{
    qint64 count = 0;
    QByteArray revData;
    systemData.indoorGPSTimeOutCnt  = 0;
    do{
        revData.resize(tcpIndoorGPS->bytesAvailable());
        revData = tcpIndoorGPS->readAll();
        dealWithIndoorGPSData(QString::fromUtf8(revData),count);
    }while(tcpIndoorGPS->bytesAvailable() > 0);
}

void MainWindow::dealWithIndoorGPSData(QString rcvData, int len)
{
    bool keepDecode = true;
    int iSTX = -1;
    int iETX = -1;
    int iPos = 0;
    QString dataMsg;
    QString strCmd;
    QString strData;
    QString checkStr;
    int dataLen = 0;
    double tempDir;
    double tempX;
    double tempY;
    processGPSStr +=rcvData;
    if (processGPSStr.length() > 50){
        processGPSStr.clear();
    }

    if (len < 5){
        len = 0;
    }
    while(keepDecode){
        iETX = processGPSStr.indexOf("`");
        if (iETX == -1){
            keepDecode = false;
        }
        else{
            iSTX=processGPSStr.indexOf("~");
            if (iSTX == -1){
                //lost the head, discard the package
                if ( (iETX + 1 ) < processGPSStr.length()){
                    processGPSStr = processGPSStr.mid(iETX + 1,processGPSStr.length() - iETX - 1);
                }
                else{
                    keepDecode = false;
                    processGPSStr.clear();
                }
            }
            else{
                //message here
                processGPSStr = processGPSStr.mid(iSTX,processGPSStr.length() - iSTX);
                dataMsg = processGPSStr.mid(iSTX,iETX - iSTX + 1);
                indoorGPS.indoorGPSMsg = dataMsg;
                dataLen = dataMsg.length();
                if (dataMsg.mid(0,2) == "~!"){
                    //here is the acknowledge package
                }
                else if(dataMsg.mid(0,2) == "~$"){
                    iPos = dataMsg.indexOf("|");
                    if ((iPos > 3) && (iPos < dataMsg.length() - 2)){
                        strCmd = dataMsg.mid(2,iPos - 2);
                        strData = dataMsg.mid(iPos + 1,dataLen - iPos - 2);
                        //process command here
                    }

                }
                else if(dataMsg.mid(0,2) == "~^"){
                    checkStr = dataMsg.mid(1,2);
                    if ( (checkStr == "^I") || (checkStr == "^F") || (checkStr == "^Z")){

                            iPos = dataMsg.indexOf("|");
                            indoorGPS.markID = dataMsg.mid(3,iPos - 3).toInt();
                            if (indoorGPS.markID == 0){
                                indoorGPS.markID = 0;
                            }
                            dataMsg = dataMsg.mid(iPos + 1,dataMsg.length() - iPos -1);
                            iPos = dataMsg.indexOf("|");
                            indoorGPS.robotHeading_GPS = dataMsg.mid(0,iPos).toDouble();
                            dataMsg = dataMsg.mid(iPos + 1,dataMsg.length() - iPos -1);
                            iPos = dataMsg.indexOf("|");
                            indoorGPS.robotX_GPS = dataMsg.mid(0,iPos).toDouble()/100;

                            dataMsg = dataMsg.mid(iPos + 1,dataMsg.length() - iPos -1);
                            iPos = dataMsg.indexOf("|");
                            indoorGPS.robotY_GPS = dataMsg.mid(0,iPos).toDouble()/100;
                            dataMsg = dataMsg.mid(iPos + 1,dataMsg.length() - iPos -1);
                            if (dataMsg.length() > 1){
                                dataMsg = dataMsg.left(dataMsg.length() -1);
                                indoorGPS.markHeight = dataMsg.toDouble()/100;
                            }
                            if (ui->checkBoxEnIndoorGPS->isChecked()){
                                //transform now
                                if (indoorGPS.robotHeading_GPS > 0){
                                    tempDir = (180 - indoorGPS.robotHeading_GPS) /180 * M_PI;

                                }else{
                                    tempDir = -(180 + indoorGPS.robotHeading_GPS) /180 * M_PI;
                                }
                                tempX = indoorGPS.gpsOffsetX *qCos(tempDir)
                                            - indoorGPS.gpsOffsetY * qSin(tempDir) + indoorGPS.robotX_GPS ;
                                tempY = indoorGPS.gpsOffsetX *qSin(tempDir)
                                        + indoorGPS.gpsOffsetY * qCos(tempDir) + indoorGPS.robotY_GPS;
                                //here is the reliability check, compare with deadreckoning(encoder)
                                if (((tempX - robotPosition.robotX) * (tempX - robotPosition.robotX)
                                                    + (tempY - robotPosition.robotY) * (tempY - robotPosition.robotY)) < 0.5 * 0.5) //0.5m distance between GPS data and Deadreckoning data
                                {
                                    gpsCheckCnt = 0;
                                    robotPosition.robotX = tempX;
                                    robotPosition.robotY = tempY;
                                    robotPosition.robotDir = tempDir;

                                }
                                else{
                                    gpsCheckCnt++;
                                    if (gpsCheckCnt > GPSCHECKCNTLM){
                                        gpsCheckCnt = 0;
                                        robotPosition.robotX = tempX;
                                        robotPosition.robotY = tempY;
                                        robotPosition.robotDir = tempDir;
                                    }
                                }
                                systemData.robotX = robotPosition.robotX;
                                systemData.robotY = robotPosition.robotY;
                                systemData.robotHeading = robotPosition.robotDir;
                                drrobotp2pSpeedDrive.UpdateSensorMap_Position(robotPosition,sensorMapData);
                                //calvin added these codes to add publish robot position data
                                robotPos.robotHeading = robotPosition.robotDir;
                                robotPos.robotX = robotPosition.robotX;
                                robotPos.robotY = robotPosition.robotY;
                                // ends here calvin

                            }


                    }

                }

                if ( (dataLen + 1) < processGPSStr.length()){
                    //still some string need to be decode
                    processGPSStr = processGPSStr.mid(iETX + 1,processGPSStr.length() - iETX -1);
                }
                else{
                    processGPSStr.clear();
                    keepDecode = false;
                }
            }
        }
    }

}

void MainWindow::encoderEstPos()
{
    int leftWheelPos = robotPosition.LeftWheelEncoderCnt;
    int rightWheelPos = robotPosition.RightWheelEncoderCnt;
    double deltaLeft = 0;
    double deltaRight = 0;
    double deltaAngle = 0;

    if (firstCal == false)
    {
        //assuming no motion over 1/2 wheel cycle in every interval
        //Left Wheel travel distnace
        deltaLeft = (leftWheelPos - preLeftWheelPos);
        if (fabs(deltaLeft) > ENCODERHALFRANGE)
        {
            if (leftWheelPos < preLeftWheelPos)
                deltaLeft = ENCODERFULLRANGE - preLeftWheelPos + leftWheelPos; //
            else
                deltaLeft = leftWheelPos - preLeftWheelPos - ENCODERFULLRANGE;

        }

        preLeftWheelPos = leftWheelPos;
        //change to distance
        deltaLeft = deltaLeft / robotInfo.OneCircleCount * 2 * M_PI;   //angle,unit radian
        deltaLeft = -robotInfo.MotorDir * deltaLeft * robotInfo.WheelRadius;

        //Right Wheel travel distnace
        deltaRight = rightWheelPos - preRightWheelPos;
        if (fabs(deltaRight) > ENCODERHALFRANGE)
        {
            if (rightWheelPos < preRightWheelPos)
                deltaRight = ENCODERFULLRANGE - preRightWheelPos + rightWheelPos;
            else
                deltaRight = rightWheelPos - preRightWheelPos - ENCODERFULLRANGE;

        }

        preRightWheelPos = rightWheelPos;
        //change to distance
        deltaRight = deltaRight / robotInfo.OneCircleCount * 2 * M_PI;  //angle,unit radian
        deltaRight = robotInfo.MotorDir * deltaRight * robotInfo.WheelRadius;

        //Update the Estimated Robot Position

        deltaAngle = (deltaRight - deltaLeft) / robotInfo.WheelDis;
        //to -2PI ~ +2Pi
        double tempAngle = angle2PI(robotPosition.robotDir + deltaAngle);
        //calvin added from here for robotHeading_En
        double tempAngle1 = angle2PI(robotPos.robotHeading_En + deltaAngle);
        //calvin codes ends here
        // to -PI ~ +PI
        tempAngle = anglePI(tempAngle);
        //calvin added code from here for robotHeading_En
        tempAngle1 = anglePI(tempAngle1);
        //calvin ends here

        //output estimate here
        robotPosition.robotDir = tempAngle;
        robotPosition.robotX = robotPosition.robotX + 0.5 * (deltaRight + deltaLeft) * qCos(robotPosition.robotDir);
        robotPosition.robotY = robotPosition.robotY + 0.5 * (deltaRight + deltaLeft) * qSin(robotPosition.robotDir);
        //calvin starts here for encoder values only
        robotPos.robotHeading_En = tempAngle1;
        robotPos.robotX_En = robotPos.robotX_En + 0.5 * (deltaRight + deltaLeft) * qCos(robotPos.robotHeading_En);
        robotPos.robotY_En = robotPos.robotY_En + 0.5 * (deltaRight + deltaLeft) * qSin(robotPos.robotHeading_En);
        //calvin ends

        systemData.robotX = robotPosition.robotX;
        systemData.robotY = robotPosition.robotY;
        systemData.robotHeading = robotPosition.robotDir;
        // calvin codes starts here to help robot position publishing
        robotPos.robotX = robotPosition.robotX;
        robotPos.robotY = robotPosition.robotY;
        robotPos.robotHeading = robotPosition.robotDir;
        //calvin codes to help robot position publishing ends here

    }
    else
    {
        preLeftWheelPos = leftWheelPos;
        preRightWheelPos = rightWheelPos;
        firstCal = false;

    }
}
double MainWindow::angle2PI(double tempAngle)
{
    int numberPI;
    numberPI = (int)(fabs(tempAngle) / (M_PI * 2));
    numberPI = ((fabs(tempAngle) - numberPI * (M_PI * 2)) >= 0 ? numberPI : numberPI - 1);
    tempAngle = sign(tempAngle) * (fabs(tempAngle) - numberPI * (M_PI * 2));
    return tempAngle;
}

double MainWindow::anglePI(double tempAngle)
{
    if (tempAngle > M_PI)
        tempAngle = tempAngle - (M_PI * 2);

    if (tempAngle < -M_PI)
        tempAngle = tempAngle + (M_PI * 2);

    return tempAngle;
}

void MainWindow::patrolStart()
{
    if (ui->pushButtonPatrol->text() == "Patrol-Go"){
        ui->pushButtonPatrol->setText("Patrol-Stop");

        pathPointSet.clear();
        //The QDomDocument class represents an XML document.
        QDomDocument xmlBOM;
        // Load xml file as raw data
        QString homePath = QDir::homePath();

        QFile f(homePath + "/DrRobotClinicPathFile/patrol.xml");
        if (!f.open(QIODevice::ReadOnly ))
        {
            return;
        }
        // Set data into the QDomDocument before processing
        xmlBOM.setContent(&f);
        f.close();
        // Extract the root markup
        QDomElement root=xmlBOM.documentElement();

        // Get root names and attributes
      //  QString Type=root.tagName();

        // Get the first child of the root (Markup COMPONENT is expected)
        QDomElement Component=root.firstChild().toElement();

        // Loop while there is a child
        while(!Component.isNull())
        {
            // Check if the child tag name is COMPONENT
            if (Component.tagName()=="PointConfigTable")
            {
                // Get the first child of the component
                QDomElement Child=Component.firstChild().toElement();
                // Read each child of the component node
                while (!Child.isNull())
                {
                    // Read Name and value
                    if (Child.tagName()=="TargetX") setPoint.TargetX = Child.firstChild().toText().data().toDouble();
                    if (Child.tagName()=="TargetY") setPoint.TargetY = Child.firstChild().toText().data().toDouble();
                    if (Child.tagName()=="TargetDir") setPoint.TargetDir = Child.firstChild().toText().data().toDouble() * M_PI/180;
                    if (Child.tagName()=="StopTime") setPoint.StopTime = Child.firstChild().toText().data().toInt();
                    if (Child.tagName()=="ForwardSpeed") setPoint.ForwardSpeed = Child.firstChild().toText().data().toDouble();
                    if (Child.tagName()=="Forgetable"){
                        if (Child.firstChild().toText().data() == "true"){
                            setPoint.Forgetable = true;
                        }else{
                            setPoint.Forgetable = false;
                        }
                    }
                    if (Child.tagName()=="NonStop"){
                        if (Child.firstChild().toText().data() == "true"){
                            setPoint.NonStop = true;
                        }else{
                            setPoint.NonStop = false;
                        }
                    }
                    if (Child.tagName()=="FinalPosture"){
                        if(Child.firstChild().toText().data() == "true"){
                            setPoint.FinalPosture = true;
                        }else{
                            setPoint.FinalPosture = false;
                        }
                    }
                    if (Child.tagName()=="TargetTime") setPoint.TargetTime = Child.firstChild().toText().data().toInt();
                    if (Child.tagName()=="TargetTolerance") setPoint.TargetTolerance = Child.firstChild().toText().data().toDouble();
                    if (Child.tagName()=="MaxTurnSpeed") setPoint.MaxTurnSpeed = Child.firstChild().toText().data().toDouble() * M_PI / 180;
                    if (Child.tagName()=="CAEnable"){
                        if(Child.firstChild().toText().data() == "true"){
                            setPoint.CAEnable = true;
                        }else{
                            setPoint.CAEnable = false;
                        }
                    }

                    if (Child.tagName()=="ReverseDrive"){
                        if (Child.firstChild().toText().data() == "true"){
                            setPoint.ReverseDrive = true;
                        }else{
                            setPoint.ReverseDrive = false;
                        }
                    }
                    if (Child.tagName()=="TargetDirTolerance") setPoint.TargetDirTolerance=Child.firstChild().toText().data().toDouble() * M_PI / 180;

                    // Next child
                    Child = Child.nextSibling().toElement();
                }

            }
            pathPointSet.append(setPoint);
            // Next component
            Component = Component.nextSibling().toElement();
        }
        pathPointNum = pathPointSet.count();
        pathPointCnt = 0;
        setPoint = pathPointSet.at(pathPointCnt);
        blnAutoRun = true;
        blnGoCharger = false;
        drrobotp2pSpeedDrive.SetTargetPosition(setPoint);
        drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdP2PGo);
        p2pStatus = P2PGo;

        pathControlTimer.start();

    }else{
        ui->pushButtonPatrol->setText("Patrol-Go");
        pathControlTimer.stop();
        drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdStopP2P);
        blnAutoRun = false;
    }
}

void MainWindow::pathControl()
{
    // path control timer slot
    if (blnAutoRun){
        //patrol task
        // check the p2p status
        if (p2pStatus == P2POver){
            //go next point
            pathPointCnt ++;
            if (pathPointCnt >= pathPointNum) pathPointCnt = 0;
            setPoint = pathPointSet.at(pathPointCnt);
            drrobotp2pSpeedDrive.SetTargetPosition(setPoint);
            drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdP2PGo);
            p2pStatus = P2PGo;

        }
    }else if (blnGoCharger){
        if (systemData.chargeStationFlag == 1){
            //stop all
            drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdStopP2P);
            pathControlTimer.stop();
            blnGoCharger = false;
        }else if (p2pStatus == P2POver){
            //go next point
            pathPointCnt ++;
            if (pathPointCnt >= pathPointNum) {
                //since last point is forgetable, if robot not in charge station, try again
                pathPointCnt = 0;
            }
            setPoint = pathPointSet.at(pathPointCnt);
            drrobotp2pSpeedDrive.SetTargetPosition(setPoint);
            drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdP2PGo);
            p2pStatus = P2PGo;
        }
    }
}

void MainWindow::goChargerStart()
{

    if (ui->pushButtonGoCharger->text() == "GoCharger"){
        ui->pushButtonGoCharger->setText("StopGoCharger");
        if (blnAutoRun){
            //stop first
            robotMotorNoTimeControlAll(MOTORVELCTRLALL,0,0,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL);
            blnAutoRun = false;
            pathControlTimer.stop();
        }
        drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdStopP2P);
        pathPointSet.clear();
        //The QDomDocument class represents an XML document.
        QDomDocument xmlBOM;
        // Load xml file as raw data
        QString homePath = QDir::homePath();

        QFile f(homePath + "/DrRobotClinicPathFile/Charge.xml");
        if (!f.open(QIODevice::ReadOnly ))
        {
            return;
        }
        // Set data into the QDomDocument before processing
        xmlBOM.setContent(&f);
        f.close();
        // Extract the root markup
        QDomElement root=xmlBOM.documentElement();

        // Get root names and attributes
      //  QString Type=root.tagName();

        // Get the first child of the root (Markup COMPONENT is expected)
        QDomElement Component=root.firstChild().toElement();

        // Loop while there is a child
        while(!Component.isNull())
        {
            // Check if the child tag name is COMPONENT
            if (Component.tagName()=="PointConfigTable")
            {
                // Get the first child of the component
                QDomElement Child=Component.firstChild().toElement();
                // Read each child of the component node
                while (!Child.isNull())
                {
                    // Read Name and value
                    if (Child.tagName()=="TargetX") setPoint.TargetX = Child.firstChild().toText().data().toDouble();
                    if (Child.tagName()=="TargetY") setPoint.TargetY = Child.firstChild().toText().data().toDouble();
                    if (Child.tagName()=="TargetDir") setPoint.TargetDir = Child.firstChild().toText().data().toDouble() * M_PI/180;
                    if (Child.tagName()=="StopTime") setPoint.StopTime = Child.firstChild().toText().data().toInt();
                    if (Child.tagName()=="ForwardSpeed") setPoint.ForwardSpeed = Child.firstChild().toText().data().toDouble();
                    if (Child.tagName()=="Forgetable"){
                        if (Child.firstChild().toText().data() == "true"){
                            setPoint.Forgetable = true;
                        }else{
                            setPoint.Forgetable = false;
                        }
                    }
                    if (Child.tagName()=="NonStop"){
                        if (Child.firstChild().toText().data() == "true"){
                            setPoint.NonStop = true;
                        }else{
                            setPoint.NonStop = false;
                        }
                    }
                    if (Child.tagName()=="FinalPosture"){
                        if(Child.firstChild().toText().data() == "true"){
                            setPoint.FinalPosture = true;
                        }else{
                            setPoint.FinalPosture = false;
                        }
                    }
                    if (Child.tagName()=="TargetTime") setPoint.TargetTime = Child.firstChild().toText().data().toInt();
                    if (Child.tagName()=="TargetTolerance") setPoint.TargetTolerance = Child.firstChild().toText().data().toDouble();
                    if (Child.tagName()=="MaxTurnSpeed") setPoint.MaxTurnSpeed = Child.firstChild().toText().data().toDouble() * M_PI / 180;
                    if (Child.tagName()=="CAEnable"){
                        if(Child.firstChild().toText().data() == "true"){
                            setPoint.CAEnable = true;
                        }else{
                            setPoint.CAEnable = false;
                        }
                    }

                    if (Child.tagName()=="ReverseDrive"){
                        if (Child.firstChild().toText().data() == "true"){
                            setPoint.ReverseDrive = true;
                        }else{
                            setPoint.ReverseDrive = false;
                        }
                    }
                    if (Child.tagName()=="TargetDirTolerance") setPoint.TargetDirTolerance=Child.firstChild().toText().data().toDouble() * M_PI / 180;

                    // Next child
                    Child = Child.nextSibling().toElement();
                }

            }
            pathPointSet.append(setPoint);
            // Next component
            Component = Component.nextSibling().toElement();
        }
        pathPointNum = pathPointSet.count();
        pathPointCnt = 0;
        setPoint = pathPointSet.at(pathPointCnt);
        blnAutoRun = false;
        blnGoCharger = true;
        drrobotp2pSpeedDrive.SetTargetPosition(setPoint);
        drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdP2PGo);
        p2pStatus = P2PGo;

        pathControlTimer.start();

    }else{
        drrobotp2pSpeedDrive.SendP2PCmd(P2PCtrlCmdStopP2P);
        pathControlTimer.stop();
        ui->pushButtonGoCharger->setText("GoCharger");
        blnGoCharger = false;
    }
}

void MainWindow::drvRobotDis(double dis, int time)
{
    int diffEncoder = (int)(dis / (2 * M_PI * robotInfo.WheelRadius) * robotInfo.OneCircleCount);

    int leftCmd = motorData[0].encoderPos - robotInfo.MotorDir * diffEncoder;
    if (leftCmd < 0)
    {
        leftCmd = 32767 + leftCmd;
    }
    else if (leftCmd > 32767)
    {
        leftCmd = leftCmd - 32767;
    }

    int rightCmd = motorData[1].encoderPos + robotInfo.MotorDir * diffEncoder;
    if (rightCmd < 0)
    {
        rightCmd = 32767 + rightCmd;
    }
    else if (rightCmd > 32767)
    {
        rightCmd = rightCmd - 32767;
    }
    if (time < 10) time = 10;
    robotMotorTimeControlAll(MOTORPOSCTRLALL,leftCmd,rightCmd,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL,time);

}

void MainWindow::exitCharger()
{
    pathControlTimer.stop();

    ui->pushButtonChargeCtrl->setText("StartCharge");
    if (tcpCharge != NULL){
        if (tcpCharge->isWritable()){
            tcpCharge->write("StopC\r\n");   //stop charge
        }
    }
    exitChargeFlag = true;
    exitChargeStep = 0;
    exitChargeDelayCnt = 0;
}

void MainWindow::displayP2PStatus()
{
    switch(p2pStatus)
    {
        case P2PGo:
            ui->labelP2PStatus->setText("P2PGo");
            break;
        case P2POver:
            ui->labelP2PStatus->setText("P2POver");
            break;
        case P2PCAStuck:
            ui->labelP2PStatus->setText("P2PCAStuck");
            break;
        case P2PWait:
            ui->labelP2PStatus->setText("P2PWait");
            break;
        case P2PTurn:
            ui->labelP2PStatus->setText("P2PTurn");
            break;
        case P2PSuspend:
            ui->labelP2PStatus->setText("P2PSuspend");
            break;
        case P2PAntiStuck:
            ui->labelP2PStatus->setText("P2PAntiStuck");
            break;
        case P2PMotorHeatUp:
            ui->labelP2PStatus->setText("P2PMotorHeatUp");
            break;
    }
}

void MainWindow::displayP2PCtrlMethod()
{
    switch(motorCmd.p2pDriveMethod)
    {
        case SpeedControl:
            ui->labelP2PCtrlMode->setText("SpeedControl");
            break;
        case PositionControl:
            ui->labelP2PCtrlMode->setText("PositionControl");
            break;
    }
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {

    QSettings settings("Qt-Ros Package", "drrobot_clinicrobot");
    QString robot_url1 = settings.value("robot_url1",QString("http://192.168.0.65")).toString();
    QString robot_port1 = settings.value("robot_port1", QString("10001")).toString();
    QString robot_port2 = settings.value("robot_port2", QString("10002")).toString();
    QString robot_url2 = settings.value("robot_url2",QString("http://192.168.0.66")).toString();
    QString robot_port3 = settings.value("robot_port3", QString("10001")).toString();
    QString robot_port4 = settings.value("robot_port4", QString("10002")).toString();
    ui->lineEditNetworkIP1->setText(robot_url1);
    ui->lineEditNetworkIP2->setText(robot_url2);
    ui->lineEditMotionPort->setText(robot_port1);
    ui->lineEditChargerPort->setText(robot_port2);
    ui->lineEditLaserPort->setText(robot_port3);
    ui->lineEditIndoorGPSPort->setText(robot_port4);


}

void MainWindow::WriteSettings() {

    QSettings settings("Qt-Ros Package", "drrobot_clinicrobot");
    settings.setValue("robot_url1",ui->lineEditNetworkIP1->text());
    settings.setValue("robot_port1",ui->lineEditMotionPort->text());
    settings.setValue("robot_port2",ui->lineEditChargerPort->text());
    settings.setValue("robot_url2",ui->lineEditNetworkIP2->text());
    settings.setValue("robot_port3",ui->lineEditLaserPort->text());
    settings.setValue("robot_port4",ui->lineEditIndoorGPSPort->text());

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	if (udpMotion->isOpen()) udpMotion->close();
	if (tcpCharge->isOpen()) tcpCharge->close();
	if (tcpIndoorGPS->isOpen()) tcpIndoorGPS->close();
	if (tcpLaserDrive->isOpen()) tcpLaserDrive->close();
	ctrlTimer.stop();
	disTimer.stop();
	laserScanTimer.stop();
	QWidget::closeEvent(event);
}

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

//for qnode
void MainWindow::wheelCmdSend(int cmdValue1,int cmdValue2,int motorCtrl)
{
    // here is the wheel control, now we force it to velocity control
    // motorCtrl, 0- pwm, 1- velocity, 2 -psoiton
    //command value is encoder command value
    if (cmdValue1 > MAX_SPEED) cmdValue1 = MAX_SPEED;
    if (cmdValue1 < -MAX_SPEED) cmdValue1 = -MAX_SPEED;
    if (cmdValue2 > MAX_SPEED) cmdValue2 = MAX_SPEED;
    if (cmdValue2 < -MAX_SPEED) cmdValue2 = -MAX_SPEED;
    ctrlMode = MOTORVELCTRLALL;
    //here we use no time control all command
    robotMotorNoTimeControlAll(ctrlMode,cmdValue1,cmdValue2,NOCONTROL,NOCONTROL,NOCONTROL,NOCONTROL);
    if (ui->checkBoxDisROSMsg->isChecked()){
        ui->textEditROSMsg->append("WheelCmd:" +  QString::number(cmdValue1) + ":" + QString::number(cmdValue2));
        rosLineCnt++;
        if (rosLineCnt > MAX_LINE){
            rosLineCnt = 0;
            ui->textEditROSMsg->setText(""); //here is simple clear all
        }

    }
}


void MainWindow::headCmdSend (double headTiltPos, int headTiltFlag,int headTiltTime,double headPanPos,int headPanFlag,int headPanTime)
{
    int cmd1 = NOCONTROL;
    int cmd2 = NOCONTROL;
    ctrlMode = MOTORPOSCTRL;
    if (headTiltFlag == 1){
        // tilt position contorl
        if (headTiltTime < 100) headTiltTime = 100; //time control, at least 100ms
        if (headTiltPos > HEAD_TILT_LM_TH) headTiltPos = HEAD_TILT_LM_TH;
        if (headTiltPos < -HEAD_TILT_LM_TH) headTiltPos = -HEAD_TILT_LM_TH;
        cmd1 = headTiltPos * HEAD_TILT_CIRCLE_CNT /360;
        if (cmd1 < 0) cmd1 = 32767 + cmd1;


        // here we use position time control
        robotMotorTimeControl(ctrlMode,3,cmd1,headTiltTime);


    }
    if (headPanFlag == 1){
        // pan position contorl
        if (headPanTime < 100) headPanTime = 100; //time control, at least 100ms
        if (headPanPos > HEAD_PAN_LM_TH) headPanPos = HEAD_PAN_LM_TH;
        if (headPanPos < -HEAD_PAN_LM_TH) headPanPos = -HEAD_PAN_LM_TH;
        cmd2 = headPanPos * HEAD_PAN_CIRCLE_CNT /360;
        if (cmd2 < 0) cmd2 = 32767 + cmd2;

        ctrlMode = MOTORPOSCTRL;
        // here we use position time control
        robotMotorTimeControl(ctrlMode,4,cmd2,headPanTime);

    }

    if (ui->checkBoxDisROSMsg->isChecked()){
        ui->textEditROSMsg->append("HeadCmd:" +  QString::number(headTiltPos,'f',2) + ":"
                                   + QString::number(headTiltFlag) + ":"
                                   + QString::number(headTiltTime) + ":"
                                   + QString::number(headPanPos,'f',2) + ":"
                                   + QString::number(headPanFlag) + ":"
                                   + QString::number(headPanTime));
        rosLineCnt++;
        if (rosLineCnt > MAX_LINE){
            rosLineCnt = 0;
            ui->textEditROSMsg->setText(""); //here is simple clear all
        }

    }

}

void MainWindow::laserCmdSend(double laserPos,int scanFlag)
{
    if (scanFlag < 0){
        // go to set position
        if (laserPos < LASER_SCAN_DOWN_TH) laserPos = LASER_SCAN_DOWN_TH;
        if (laserPos > LASER_SCAN_UP_TH) laserPos = LASER_SCAN_UP_TH;
        setLaserPosition(laserPos);
    }
    else{
        if (scanFlag == 1){
            // auto scan start
            ui->pushButtonLaserAutoScan->setText("StopScan");
            laserAutoScanFlag = 1;
            laserAutoScanDelayCnt = 0;
            laserAutoScanStep = 0;
            connect(&laserScanTimer,SIGNAL(timeout()),this,SLOT(laserAutoScan()));
            laserScanTimer.setInterval(500);
            laserScanTimer.start();
            laserData.stopFlag = 0;
            laserScanDir = 1;

        }else if(scanFlag == 0){
            //stop auto scan
            setLaserPosition(0);
            laserData.stopFlag = 1;
            laserScanTimer.stop();
            disconnect(&laserScanTimer,SIGNAL(timeout()),this,SLOT(laserAutoScan()));
            laserAutoScanFlag = 0;
            ui->pushButtonLaserAutoScan->setText("AutoScan");
        }
    }

    if (ui->checkBoxDisROSMsg->isChecked()){
        ui->textEditROSMsg->append("LaserCmd:" +  QString::number(laserPos,'f',2) + ":"
                                   + QString::number(scanFlag));
        rosLineCnt++;
        if (rosLineCnt > MAX_LINE){
            rosLineCnt = 0;
            ui->textEditROSMsg->setText(""); //here is simple clear all
        }

    }
}

//calvin keyboard control starts here

void MainWindow::keyboardMotionCtrl(bool checked)
{
   if (checked == true)
   {
       ui->pushButtonGoForward->setEnabled(false);
       ui->pushButtonGoBackward->setEnabled(false);
       ui->pushButtonTurnLeft->setEnabled(false);
       ui->pushButtonTurnRight->setEnabled(false);
       ui->pushButtonStop->setEnabled(false);
       ui->pushButtonHeadPanHome->setEnabled(false);
       ui->pushButtonHeadTiltHome->setEnabled(false);
       ui->pushButtonStopHeadMotor->setEnabled(false);
       ui->horizontalSliderHeadPan->setEnabled(false);
       ui->verticalSliderHeadTilt->setEnabled(false);

       grabKeyboard();
   }
   else
   {
       ui->pushButtonGoForward->setEnabled(true);
       ui->pushButtonGoBackward->setEnabled(true);
       ui->pushButtonTurnLeft->setEnabled(true);
       ui->pushButtonTurnRight->setEnabled(true);
       ui->pushButtonStop->setEnabled(true);
       ui->pushButtonHeadPanHome->setEnabled(true);
       ui->pushButtonHeadTiltHome->setEnabled(true);
       ui->pushButtonStopHeadMotor->setEnabled(true);
       ui->horizontalSliderHeadPan->setEnabled(true);
       ui->verticalSliderHeadTilt->setEnabled(true);

       releaseKeyboard();

   }

}

bool MainWindow::event(QEvent *event)
{
   if (event->type() == QEvent::KeyPress)
   {
       QKeyEvent *ke = static_cast<QKeyEvent*>(event);
       int a = ke->key();
       if (ke->key() == Qt::Key_T)
       {
           double anglePos = 0;
           while (anglePos <= 40)
           {
               int cmd = anglePos * HEAD_TILT_CIRCLE_CNT /360;
               int time = ui->lineEditHeadCtrlTime->text().toInt();
               ctrlMode = MOTORPOSCTRL;
               // here we use position time control
               robotMotorTimeControl(ctrlMode,3,cmd,time);
               anglePos += 1;
               a = ke->key();
           }
           return true;
       }
       else if (ke->key() == Qt::Key_V)
       {
           double anglePos = 0;
           while (anglePos <= 40)
           {
               int cmd = anglePos * HEAD_TILT_CIRCLE_CNT /360;
               int time = ui->lineEditHeadCtrlTime->text().toInt();
               ctrlMode = MOTORPOSCTRL;
               // here we use position time control
               robotMotorTimeControl(ctrlMode,3,-cmd,time);
               anglePos += 1;
               a = ke->key();
           }
           return true;
       }
       else if (ke->key() == Qt::Key_H)
       {
           double anglePos = 0;
           while(anglePos <= 90)
           {
               int cmd = anglePos * HEAD_PAN_CIRCLE_CNT /360;
               int time = ui->lineEditHeadCtrlTime->text().toInt();
               ctrlMode = MOTORPOSCTRL;
               // here we use position time control
               robotMotorTimeControl(ctrlMode,4,cmd,time);
               anglePos  += 1;
           }
           return true;

       }
       else if (ke->key() == Qt::Key_D)
       {
           double anglePos = 0;
           while(anglePos <= 90)
           {
               int cmd = anglePos * HEAD_PAN_CIRCLE_CNT /360;
               int time = ui->lineEditHeadCtrlTime->text().toInt();
               ctrlMode = MOTORPOSCTRL;
               // here we use position time control
               robotMotorTimeControl(ctrlMode,4,-cmd,time);
               anglePos  += 1;
           }
           return true;
       }
       else if (ke->key() == Qt::Key_Left)
       {
           sendLeftTurnCmd();
           return true;
       }
       else if (ke->key() == Qt::Key_Right)
       {
           sendRightTurnCmd();
           return true;
       }
       else if (ke->key() == Qt::Key_Up)
       {
           sendForwardCmd();
           return true;
       }
       else if (ke->key() == Qt::Key_Down)
       {
           sendBackwardCmd();
           return true;
       }
       else if (ke->key() == Qt::Key_Enter)
       {
           sendStopCmd();
           return true;
       }
       else
           return QMainWindow::event(event);
   }
   else
   return QMainWindow::event(event);
}

void MainWindow::robotEstVel()
{
    if(-motorData[0].encoderDir + motorData[1].encoderDir == 1)
        robotvelocity.velocityAng = 0;
    else
        robotvelocity.velocityAng = M_PI;

    robotvelocity.velocityX = -motorData[0].encoderDir*motorData[0].encoderVel+ motorData[1].encoderDir*motorData[1].encoderVel;
}

void MainWindow::laserScanEffected(double a)
{

   // LaserConfigData laserConfigData = b;
    //LaserSensorData laserSensorData = a;
    drrobotSensorMapBuilder.SetLaserUse(true);
   // drrobotSensorMapBuilder.ConfigLaserSensor(laserConfigData);
   // drrobotSensorMapBuilder.UpdateLaserSensorInfo(laserSensorData);

}

//calvin ends


}	//namespace- drrobot_clinicrobot
