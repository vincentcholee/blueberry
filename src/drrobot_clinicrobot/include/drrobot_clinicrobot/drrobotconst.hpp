#ifndef DRROBOTCONST_H
#define DRROBOTCONST_H
#define EXIT_CHARGE_DELAY_TH    15     //around 1.5s
#define DETECT_CHARGER_TH 5     //around 500ms
#define ENCODERMAXSPEED 300
#define MAXSPEED    0.4
#define GPSCHECKCNTLM   4
#define MAPSECTIONNUM   36
#define cSectionRange    36

#define MAXIRNUM  16
#define MAXUSNUM  6


#define COMTIMEOUT  2
#define MAPSIZE  800
#define MAPCENT  399
#define MAPRATIO  100        //1 cm one block
#define cEmptyStep  1
#define cOccupiedStep  5
#define cMAx_Occupied  15
#define cWinSize  160       //max is 1.5m

#define cSmoothWinSize  4 //polar map the connected 4 section
#define IrDisLLM  0.05
#define IrDisHLM  0.6
#define USDisLLM  0.1
#define USDisHLM  2.0

#define MAX_LASER_DIS  4     // the occ_map is (8m*8m), so the max front dis = 4m, we set little less than 4m to 3.5m;
#define MIN_LASER_DIS  0.01
#define MAX_LASER_DATA_LEN  2048

enum  P2PServiceStatus
{

    P2PServicesStatusNull = 0x0,
    P2PGo = 0x01,               //P2P Drive running
    P2POver = 0x02,             // P2P Task over
    P2PCAStuck = 0x03,          // With Collision Avoidance, it can not find a open direction
    P2PWait = 0x04,             // If you set stop time for a point, it will wait setting time after achiving the point
    P2PTurn = 0x05,             // if you set final direction, the robot will turn to settting direction after achiveing the point
    P2PSuspend = 0x06,          // you can send command to suspend the P2P task
    P2PAntiStuck = 0x07,        // with motor protection, it means robot detect stuck, it will auto backwards
    P2PMotorHeatUp = 0x08,      // it means robot detect motor heat up, the task has to wait some time
};


enum P2PCtrlCmd
{
    P2PCtrlCmdNull = 0x9,
    P2PCtrlCmdStopP2P = 0xa,
    P2PCtrlCmdSuspendP2P = 0xb,
    P2PCtrlCmdResumeP2P = 0xc,
    P2PCtrlCmdP2PGo = 0xd,
    P2PCtrlCmdP2PSkip = 0xe,
};

enum P2PDriveMethod
{
    SpeedControl = 0xf,
    PositionControl = 0x10,
};

template <typename T> int sign(T val){
    return (T(0) < val) - (val < T(0));
}

#endif // DRROBOTCONST_H
