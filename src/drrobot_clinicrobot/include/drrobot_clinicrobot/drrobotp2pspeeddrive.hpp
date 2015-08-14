#ifndef DRROBOTP2PSPEEDDRIVE_H
#define DRROBOTP2PSPEEDDRIVE_H
#include "drrobotp2pdrive.hpp"
#include "qtimer.h"
#include "drrobotconst.hpp"
#include "qmath.h"
#include "math.h"
class DrRobotP2PSpeedDrive:public QObject
    {
        Q_OBJECT
        private:
            int _p2pWaitCnt;
            int waitTurnCnt;
            int setTurnTime;
            bool blnTurnFinish;

            P2PServiceStatus p2pServiceStatus;//= P2PServiceStatus::P2POver;
            RobotPosition robotPosition;// = new RobotPosition();

            SensorMapData sensorMapData ;//= new SensorMapData();
            P2PDriveParameter p2pDriveParameter;// = new P2PDriveParameter();
            P2PCAParameter p2pCAParameter;//= new P2PCAParameter();
            RobotInfo robotInfo ;//= new RobotInfo();


            QTimer mainTimer;
            int p2pTimeCnt;
            bool taskOver;
            MotorControlCmd motorCmd;//= new MotorControlCmd();
            SetTargetPointRequest _pointSet;// = new SetTargetPointRequest();


            double calP2PAngle(double X1, double Y1, double  X2,double Y2);
            int cycleindex(int Index);
            double AnglePI(double  adeltaAngle);
        public:
            void setDrRobotP2PSpeedDrive();
            //region get robot information function
            bool SetRobotInfo(RobotInfo data);
            bool UpdateSensorMap_Position(RobotPosition posData, SensorMapData sensorMap);
            bool SetTargetPosition(SetTargetPointRequest request);
            bool SetP2PDriveParameter(P2PDriveParameter request);
            bool SetP2PCAParameter(P2PCAParameter request);
            bool SendP2PCmd(P2PCtrlCmd cmd);
    signals:
            void p2pDriveCmdCallback(MotorControlCmd cmd);

    private slots:
            //region main function here
            void ctrlTimeEvent();
    };

#endif // DRROBOTP2PSPEEDDRIVE_H
