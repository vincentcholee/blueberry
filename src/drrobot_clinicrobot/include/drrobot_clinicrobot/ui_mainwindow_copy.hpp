/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBoxCommunication;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditNetworkIP1;
    QLabel *label_3;
    QLineEdit *lineEditMotionPort;
    QPushButton *pushButtonMotionConnect;
    QLabel *labelMotionPortState;
    QLabel *label_4;
    QLineEdit *lineEditChargerPort;
    QPushButton *pushButtonChargerConnect;
    QLabel *labelChargerPortState;
    QLabel *label_2;
    QLineEdit *lineEditNetworkIP2;
    QLabel *label_5;
    QLineEdit *lineEditLaserPort;
    QPushButton *pushButtonLaserConnect;
    QLabel *labelLaserPortState;
    QLabel *label_6;
    QLineEdit *lineEditIndoorGPSPort;
    QPushButton *pushButtonIndoorGPSConnect;
    QLabel *labelIndoorGPSPortState;
    QGroupBox *groupBoxRangeSensors;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLabel *labelIR1_1;
    QLabel *label_8;
    QLabel *labelIR1_2;
    QLabel *label_9;
    QLabel *labelIR1_3;
    QLabel *label_10;
    QLabel *labelIR1_4;
    QLabel *label_11;
    QLabel *labelIR1_5;
    QLabel *label_12;
    QLabel *labelIR1_6;
    QLabel *label_13;
    QLabel *labelIR1_7;
    QLabel *label_14;
    QLabel *labelIR1_8;
    QLabel *label_15;
    QLabel *labelIR1_9;
    QLabel *label_16;
    QLabel *labelIR1_10;
    QLabel *label_17;
    QLabel *labelIR1_11;
    QLabel *label_18;
    QLabel *labelIR1_12;
    QLabel *label_19;
    QLabel *labelIR1_13;
    QLabel *label_20;
    QLabel *labelIR1_14;
    QLabel *label_21;
    QLabel *labelIR1_15;
    QLabel *label_22;
    QLabel *labelIR1_16;
    QLabel *label_23;
    QLabel *labelUS_1;
    QLabel *label_24;
    QLabel *labelUS_2;
    QLabel *label_25;
    QLabel *labelUS_3;
    QLabel *label_26;
    QLabel *labelUS_4;
    QLabel *label_27;
    QLabel *labelUS_5;
    QLabel *label_28;
    QLabel *labelUS_6;
    QLabel *label_58;
    QLabel *labelBump_L;
    QLabel *label_59;
    QLabel *labelBump_R;
    QGroupBox *groupBoxMotorSensors;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *labelLeftEncPos;
    QLabel *label_31;
    QLabel *labelLeftEncVel;
    QLabel *label_32;
    QLabel *labelLeftPWM;
    QLabel *labelRightEncVel;
    QLabel *labelRightEncPos;
    QLabel *label_33;
    QLabel *labelRightPWM;
    QLabel *label_34;
    QLabel *labelHeadTiltEncPos;
    QLabel *labelHeadTiltPWM;
    QLabel *labelHeadTiltEncVel;
    QLabel *label_35;
    QLabel *labelHeadPanEncPos;
    QLabel *labelHeadPanPWM;
    QLabel *labelHeadPanEncVel;
    QPushButton *pushButtonGoForward;
    QPushButton *pushButtonTurnLeft;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonTurnRight;
    QPushButton *pushButtonGoBackward;
    QSlider *horizontalSliderWheelCmd;
    QSlider *verticalSliderHeadTilt;
    QSlider *horizontalSliderHeadPan;
    QLabel *label_36;
    QLabel *label_37;
    QPushButton *pushButtonStopHeadMotor;
    QLabel *labelHeadPan;
    QLabel *labelHeadTilt;
    QLabel *label_60;
    QLineEdit *lineEditHeadCtrlTime;
    QPushButton *pushButtonHeadTiltHome;
    QPushButton *pushButtonHeadPanHome;
    QGroupBox *groupBoxIndoorGPS;
    QLabel *label_43;
    QLabel *labelIndoorGPSMsg;
    QLabel *label_44;
    QLabel *labelRobotX_GPS;
    QLabel *label_45;
    QLabel *labelRobotY_GPS;
    QLabel *label_46;
    QLabel *labelRobotheading_GPS;
    QLabel *labelIndoorGPSMarkID;
    QLabel *label_47;
    QCheckBox *checkBoxEnIndoorGPS;
    QLabel *labelMarkHeight;
    QLabel *label_61;
    QGroupBox *groupBoxChargeControl;
    QLabel *labelBatteryVol;
    QLabel *label_48;
    QLabel *label_49;
    QLineEdit *lineEditBatteryFuel;
    QLabel *label_50;
    QLineEdit *lineEditChargeCurrent;
    QLineEdit *lineEditChargeTime;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *labelSystemVol;
    QCheckBox *checkBoxInChargeStation;
    QLabel *label_53;
    QLineEdit *lineEditDCCurrent;
    QLabel *label_54;
    QLabel *label_55;
    QLineEdit *lineEditChargeMode;
    QLineEdit *lineEditDCPower;
    QLabel *label_56;
    QLineEdit *lineEditChargePPR;
    QLabel *label_57;
    QLineEdit *lineEditChargeErrorCode;
    QPushButton *pushButtonChargeCtrl;
    QPushButton *pushButtonSwitchPower;
    QGroupBox *groupBoxLaserScan;
    QLabel *labelLaserAngle;
    QLabel *label_38;
    QSlider *verticalSliderLaserDrive;
    QPushButton *pushButtonLaserAutoScan;
    QLabel *labelLaserEncPos;
    QLabel *label_39;
    QLabel *labelLaserEncVel;
    QLabel *label_40;
    QLabel *labelLaserMotorPWM;
    QLabel *label_41;
    QLabel *labelLaserMotorCurrent;
    QLabel *label_42;
    QPushButton *pushButtonLaserHome;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 700);
        MainWindow->setMaximumSize(QSize(1200, 700));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBoxCommunication = new QGroupBox(centralWidget);
        groupBoxCommunication->setObjectName(QString::fromUtf8("groupBoxCommunication"));
        groupBoxCommunication->setGeometry(QRect(10, 10, 1181, 91));
        groupBoxCommunication->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	border:1px solid gray;\n"
"	border-radius: 9px;\n"
"	margin-top:0.5em;} \n"
" QGroupBox::title{\n"
"	subcontrol-origin:margin;\n"
"	left:10px;\n"
"	padding: 0 3 px 2 3px}"));

        widget = new QWidget(groupBoxCommunication);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(31, 21, 1121, 62));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditNetworkIP1 = new QLineEdit(widget);
        lineEditNetworkIP1->setObjectName(QString::fromUtf8("lineEditNetworkIP1"));
        lineEditNetworkIP1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditNetworkIP1, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        lineEditMotionPort = new QLineEdit(widget);
        lineEditMotionPort->setObjectName(QString::fromUtf8("lineEditMotionPort"));
        lineEditMotionPort->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditMotionPort, 0, 3, 1, 1);

        pushButtonMotionConnect = new QPushButton(widget);
        pushButtonMotionConnect->setObjectName(QString::fromUtf8("pushButtonMotionConnect"));

        gridLayout->addWidget(pushButtonMotionConnect, 0, 4, 1, 1);

        labelMotionPortState = new QLabel(widget);
        labelMotionPortState->setObjectName(QString::fromUtf8("labelMotionPortState"));

        gridLayout->addWidget(labelMotionPortState, 0, 5, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 0, 6, 1, 1);

        lineEditChargerPort = new QLineEdit(widget);
        lineEditChargerPort->setObjectName(QString::fromUtf8("lineEditChargerPort"));
        lineEditChargerPort->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditChargerPort, 0, 7, 1, 1);

        pushButtonChargerConnect = new QPushButton(widget);
        pushButtonChargerConnect->setObjectName(QString::fromUtf8("pushButtonChargerConnect"));

        gridLayout->addWidget(pushButtonChargerConnect, 0, 8, 1, 1);

        labelChargerPortState = new QLabel(widget);
        labelChargerPortState->setObjectName(QString::fromUtf8("labelChargerPortState"));

        gridLayout->addWidget(labelChargerPortState, 0, 9, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditNetworkIP2 = new QLineEdit(widget);
        lineEditNetworkIP2->setObjectName(QString::fromUtf8("lineEditNetworkIP2"));
        lineEditNetworkIP2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditNetworkIP2, 1, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        lineEditLaserPort = new QLineEdit(widget);
        lineEditLaserPort->setObjectName(QString::fromUtf8("lineEditLaserPort"));
        lineEditLaserPort->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditLaserPort, 1, 3, 1, 1);

        pushButtonLaserConnect = new QPushButton(widget);
        pushButtonLaserConnect->setObjectName(QString::fromUtf8("pushButtonLaserConnect"));

        gridLayout->addWidget(pushButtonLaserConnect, 1, 4, 1, 1);

        labelLaserPortState = new QLabel(widget);
        labelLaserPortState->setObjectName(QString::fromUtf8("labelLaserPortState"));

        gridLayout->addWidget(labelLaserPortState, 1, 5, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 1, 6, 1, 1);

        lineEditIndoorGPSPort = new QLineEdit(widget);
        lineEditIndoorGPSPort->setObjectName(QString::fromUtf8("lineEditIndoorGPSPort"));
        lineEditIndoorGPSPort->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditIndoorGPSPort, 1, 7, 1, 1);

        pushButtonIndoorGPSConnect = new QPushButton(widget);
        pushButtonIndoorGPSConnect->setObjectName(QString::fromUtf8("pushButtonIndoorGPSConnect"));

        gridLayout->addWidget(pushButtonIndoorGPSConnect, 1, 8, 1, 1);

        labelIndoorGPSPortState = new QLabel(widget);
        labelIndoorGPSPortState->setObjectName(QString::fromUtf8("labelIndoorGPSPortState"));

        gridLayout->addWidget(labelIndoorGPSPortState, 1, 9, 1, 1);

        groupBoxRangeSensors = new QGroupBox(centralWidget);
        groupBoxRangeSensors->setObjectName(QString::fromUtf8("groupBoxRangeSensors"));
        groupBoxRangeSensors->setGeometry(QRect(10, 100, 1181, 101));
        groupBoxRangeSensors->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	border:1px solid gray;\n"
"	border-radius: 9px;\n"
"	margin-top:0.5em;} \n"
" QGroupBox::title{\n"
"	subcontrol-origin:margin;\n"
"	left:10px;\n"
"	padding: 0 3 px 2 3px}"));
        widget1 = new QWidget(groupBoxRangeSensors);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(31, 21, 1121, 71));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        labelIR1_1 = new QLabel(widget1);
        labelIR1_1->setObjectName(QString::fromUtf8("labelIR1_1"));
        labelIR1_1->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_1->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_1, 0, 1, 1, 1);

        label_8 = new QLabel(widget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 0, 2, 1, 1);

        labelIR1_2 = new QLabel(widget1);
        labelIR1_2->setObjectName(QString::fromUtf8("labelIR1_2"));
        labelIR1_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_2, 0, 3, 1, 1);

        label_9 = new QLabel(widget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_9, 0, 4, 1, 1);

        labelIR1_3 = new QLabel(widget1);
        labelIR1_3->setObjectName(QString::fromUtf8("labelIR1_3"));
        labelIR1_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_3, 0, 5, 1, 1);

        label_10 = new QLabel(widget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_10, 0, 6, 1, 1);

        labelIR1_4 = new QLabel(widget1);
        labelIR1_4->setObjectName(QString::fromUtf8("labelIR1_4"));
        labelIR1_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_4, 0, 7, 1, 1);

        label_11 = new QLabel(widget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_11, 0, 8, 1, 1);

        labelIR1_5 = new QLabel(widget1);
        labelIR1_5->setObjectName(QString::fromUtf8("labelIR1_5"));
        labelIR1_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_5, 0, 9, 1, 1);

        label_12 = new QLabel(widget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_12, 0, 10, 1, 1);

        labelIR1_6 = new QLabel(widget1);
        labelIR1_6->setObjectName(QString::fromUtf8("labelIR1_6"));
        labelIR1_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_6, 0, 11, 1, 1);

        label_13 = new QLabel(widget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_13, 0, 12, 1, 1);

        labelIR1_7 = new QLabel(widget1);
        labelIR1_7->setObjectName(QString::fromUtf8("labelIR1_7"));
        labelIR1_7->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_7, 0, 13, 1, 1);

        label_14 = new QLabel(widget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_14, 0, 14, 1, 1);

        labelIR1_8 = new QLabel(widget1);
        labelIR1_8->setObjectName(QString::fromUtf8("labelIR1_8"));
        labelIR1_8->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_8, 0, 15, 1, 1);

        label_15 = new QLabel(widget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_15, 1, 0, 1, 1);

        labelIR1_9 = new QLabel(widget1);
        labelIR1_9->setObjectName(QString::fromUtf8("labelIR1_9"));
        labelIR1_9->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_9->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_9, 1, 1, 1, 1);

        label_16 = new QLabel(widget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_16, 1, 2, 1, 1);

        labelIR1_10 = new QLabel(widget1);
        labelIR1_10->setObjectName(QString::fromUtf8("labelIR1_10"));
        labelIR1_10->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_10, 1, 3, 1, 1);

        label_17 = new QLabel(widget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_17, 1, 4, 1, 1);

        labelIR1_11 = new QLabel(widget1);
        labelIR1_11->setObjectName(QString::fromUtf8("labelIR1_11"));
        labelIR1_11->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_11, 1, 5, 1, 1);

        label_18 = new QLabel(widget1);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_18, 1, 6, 1, 1);

        labelIR1_12 = new QLabel(widget1);
        labelIR1_12->setObjectName(QString::fromUtf8("labelIR1_12"));
        labelIR1_12->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_12, 1, 7, 1, 1);

        label_19 = new QLabel(widget1);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_19, 1, 8, 1, 1);

        labelIR1_13 = new QLabel(widget1);
        labelIR1_13->setObjectName(QString::fromUtf8("labelIR1_13"));
        labelIR1_13->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_13->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_13, 1, 9, 1, 1);

        label_20 = new QLabel(widget1);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_20, 1, 10, 1, 1);

        labelIR1_14 = new QLabel(widget1);
        labelIR1_14->setObjectName(QString::fromUtf8("labelIR1_14"));
        labelIR1_14->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_14->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_14, 1, 11, 1, 1);

        label_21 = new QLabel(widget1);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_21, 1, 12, 1, 1);

        labelIR1_15 = new QLabel(widget1);
        labelIR1_15->setObjectName(QString::fromUtf8("labelIR1_15"));
        labelIR1_15->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_15->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_15, 1, 13, 1, 1);

        label_22 = new QLabel(widget1);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_22, 1, 14, 1, 1);

        labelIR1_16 = new QLabel(widget1);
        labelIR1_16->setObjectName(QString::fromUtf8("labelIR1_16"));
        labelIR1_16->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIR1_16->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelIR1_16, 1, 15, 1, 1);

        label_23 = new QLabel(widget1);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_23, 2, 0, 1, 1);

        labelUS_1 = new QLabel(widget1);
        labelUS_1->setObjectName(QString::fromUtf8("labelUS_1"));
        labelUS_1->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelUS_1->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelUS_1, 2, 1, 1, 1);

        label_24 = new QLabel(widget1);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_24, 2, 2, 1, 1);

        labelUS_2 = new QLabel(widget1);
        labelUS_2->setObjectName(QString::fromUtf8("labelUS_2"));
        labelUS_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelUS_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelUS_2, 2, 3, 1, 1);

        label_25 = new QLabel(widget1);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_25, 2, 4, 1, 1);

        labelUS_3 = new QLabel(widget1);
        labelUS_3->setObjectName(QString::fromUtf8("labelUS_3"));
        labelUS_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelUS_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelUS_3, 2, 5, 1, 1);

        label_26 = new QLabel(widget1);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_26, 2, 6, 1, 1);

        labelUS_4 = new QLabel(widget1);
        labelUS_4->setObjectName(QString::fromUtf8("labelUS_4"));
        labelUS_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelUS_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelUS_4, 2, 7, 1, 1);

        label_27 = new QLabel(widget1);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_27, 2, 8, 1, 1);

        labelUS_5 = new QLabel(widget1);
        labelUS_5->setObjectName(QString::fromUtf8("labelUS_5"));
        labelUS_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelUS_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelUS_5, 2, 9, 1, 1);

        label_28 = new QLabel(widget1);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_28, 2, 10, 1, 1);

        labelUS_6 = new QLabel(widget1);
        labelUS_6->setObjectName(QString::fromUtf8("labelUS_6"));
        labelUS_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelUS_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelUS_6, 2, 11, 1, 1);

        label_58 = new QLabel(widget1);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_58, 2, 12, 1, 1);

        labelBump_L = new QLabel(widget1);
        labelBump_L->setObjectName(QString::fromUtf8("labelBump_L"));
        labelBump_L->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelBump_L->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelBump_L, 2, 13, 1, 1);

        label_59 = new QLabel(widget1);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_59, 2, 14, 1, 1);

        labelBump_R = new QLabel(widget1);
        labelBump_R->setObjectName(QString::fromUtf8("labelBump_R"));
        labelBump_R->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelBump_R->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelBump_R, 2, 15, 1, 1);

        groupBoxMotorSensors = new QGroupBox(centralWidget);
        groupBoxMotorSensors->setObjectName(QString::fromUtf8("groupBoxMotorSensors"));
        groupBoxMotorSensors->setGeometry(QRect(10, 200, 851, 161));
        groupBoxMotorSensors->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	border:1px solid gray;\n"
"	border-radius: 9px;\n"
"	margin-top:0.5em;} \n"
" QGroupBox::title{\n"
"	subcontrol-origin:margin;\n"
"	left:10px;\n"
"	padding: 0 3 px 2 3px}"));
        label_29 = new QLabel(groupBoxMotorSensors);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(30, 40, 91, 17));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_30 = new QLabel(groupBoxMotorSensors);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(140, 20, 91, 17));
        labelLeftEncPos = new QLabel(groupBoxMotorSensors);
        labelLeftEncPos->setObjectName(QString::fromUtf8("labelLeftEncPos"));
        labelLeftEncPos->setGeometry(QRect(150, 40, 63, 20));
        labelLeftEncPos->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelLeftEncPos->setAlignment(Qt::AlignCenter);
        label_31 = new QLabel(groupBoxMotorSensors);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(240, 20, 91, 17));
        labelLeftEncVel = new QLabel(groupBoxMotorSensors);
        labelLeftEncVel->setObjectName(QString::fromUtf8("labelLeftEncVel"));
        labelLeftEncVel->setGeometry(QRect(250, 40, 63, 20));
        labelLeftEncVel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelLeftEncVel->setAlignment(Qt::AlignCenter);
        label_32 = new QLabel(groupBoxMotorSensors);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(330, 20, 91, 17));
        labelLeftPWM = new QLabel(groupBoxMotorSensors);
        labelLeftPWM->setObjectName(QString::fromUtf8("labelLeftPWM"));
        labelLeftPWM->setGeometry(QRect(340, 40, 63, 20));
        labelLeftPWM->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelLeftPWM->setAlignment(Qt::AlignCenter);
        labelRightEncVel = new QLabel(groupBoxMotorSensors);
        labelRightEncVel->setObjectName(QString::fromUtf8("labelRightEncVel"));
        labelRightEncVel->setGeometry(QRect(250, 70, 63, 20));
        labelRightEncVel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelRightEncVel->setAlignment(Qt::AlignCenter);
        labelRightEncPos = new QLabel(groupBoxMotorSensors);
        labelRightEncPos->setObjectName(QString::fromUtf8("labelRightEncPos"));
        labelRightEncPos->setGeometry(QRect(150, 70, 63, 20));
        labelRightEncPos->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelRightEncPos->setAlignment(Qt::AlignCenter);
        label_33 = new QLabel(groupBoxMotorSensors);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(30, 70, 91, 17));
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelRightPWM = new QLabel(groupBoxMotorSensors);
        labelRightPWM->setObjectName(QString::fromUtf8("labelRightPWM"));
        labelRightPWM->setGeometry(QRect(340, 70, 63, 20));
        labelRightPWM->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelRightPWM->setAlignment(Qt::AlignCenter);
        label_34 = new QLabel(groupBoxMotorSensors);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(30, 100, 91, 17));
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelHeadTiltEncPos = new QLabel(groupBoxMotorSensors);
        labelHeadTiltEncPos->setObjectName(QString::fromUtf8("labelHeadTiltEncPos"));
        labelHeadTiltEncPos->setGeometry(QRect(150, 100, 63, 20));
        labelHeadTiltEncPos->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelHeadTiltEncPos->setAlignment(Qt::AlignCenter);
        labelHeadTiltPWM = new QLabel(groupBoxMotorSensors);
        labelHeadTiltPWM->setObjectName(QString::fromUtf8("labelHeadTiltPWM"));
        labelHeadTiltPWM->setGeometry(QRect(340, 100, 63, 20));
        labelHeadTiltPWM->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelHeadTiltPWM->setAlignment(Qt::AlignCenter);
        labelHeadTiltEncVel = new QLabel(groupBoxMotorSensors);
        labelHeadTiltEncVel->setObjectName(QString::fromUtf8("labelHeadTiltEncVel"));
        labelHeadTiltEncVel->setGeometry(QRect(250, 100, 63, 20));
        labelHeadTiltEncVel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelHeadTiltEncVel->setAlignment(Qt::AlignCenter);
        label_35 = new QLabel(groupBoxMotorSensors);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(30, 130, 91, 17));
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelHeadPanEncPos = new QLabel(groupBoxMotorSensors);
        labelHeadPanEncPos->setObjectName(QString::fromUtf8("labelHeadPanEncPos"));
        labelHeadPanEncPos->setGeometry(QRect(150, 130, 63, 20));
        labelHeadPanEncPos->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelHeadPanEncPos->setAlignment(Qt::AlignCenter);
        labelHeadPanPWM = new QLabel(groupBoxMotorSensors);
        labelHeadPanPWM->setObjectName(QString::fromUtf8("labelHeadPanPWM"));
        labelHeadPanPWM->setGeometry(QRect(340, 130, 63, 20));
        labelHeadPanPWM->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelHeadPanPWM->setAlignment(Qt::AlignCenter);
        labelHeadPanEncVel = new QLabel(groupBoxMotorSensors);
        labelHeadPanEncVel->setObjectName(QString::fromUtf8("labelHeadPanEncVel"));
        labelHeadPanEncVel->setGeometry(QRect(250, 130, 63, 20));
        labelHeadPanEncVel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelHeadPanEncVel->setAlignment(Qt::AlignCenter);
        pushButtonGoForward = new QPushButton(groupBoxMotorSensors);
        pushButtonGoForward->setObjectName(QString::fromUtf8("pushButtonGoForward"));
        pushButtonGoForward->setGeometry(QRect(480, 20, 51, 27));
        pushButtonTurnLeft = new QPushButton(groupBoxMotorSensors);
        pushButtonTurnLeft->setObjectName(QString::fromUtf8("pushButtonTurnLeft"));
        pushButtonTurnLeft->setGeometry(QRect(420, 50, 51, 27));
        pushButtonStop = new QPushButton(groupBoxMotorSensors);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(480, 50, 51, 27));
        pushButtonTurnRight = new QPushButton(groupBoxMotorSensors);
        pushButtonTurnRight->setObjectName(QString::fromUtf8("pushButtonTurnRight"));
        pushButtonTurnRight->setGeometry(QRect(540, 50, 51, 27));
        pushButtonGoBackward = new QPushButton(groupBoxMotorSensors);
        pushButtonGoBackward->setObjectName(QString::fromUtf8("pushButtonGoBackward"));
        pushButtonGoBackward->setGeometry(QRect(480, 80, 51, 27));
        horizontalSliderWheelCmd = new QSlider(groupBoxMotorSensors);
        horizontalSliderWheelCmd->setObjectName(QString::fromUtf8("horizontalSliderWheelCmd"));
        horizontalSliderWheelCmd->setGeometry(QRect(420, 120, 160, 29));
        horizontalSliderWheelCmd->setMinimum(50);
        horizontalSliderWheelCmd->setMaximum(300);
        horizontalSliderWheelCmd->setValue(100);
        horizontalSliderWheelCmd->setOrientation(Qt::Horizontal);
        horizontalSliderWheelCmd->setTickPosition(QSlider::TicksBothSides);
        horizontalSliderWheelCmd->setTickInterval(0);
        verticalSliderHeadTilt = new QSlider(groupBoxMotorSensors);
        verticalSliderHeadTilt->setObjectName(QString::fromUtf8("verticalSliderHeadTilt"));
        verticalSliderHeadTilt->setGeometry(QRect(670, 10, 29, 121));
        verticalSliderHeadTilt->setMinimum(-40);
        verticalSliderHeadTilt->setMaximum(40);
        verticalSliderHeadTilt->setOrientation(Qt::Vertical);
        verticalSliderHeadTilt->setTickPosition(QSlider::TicksBothSides);
        horizontalSliderHeadPan = new QSlider(groupBoxMotorSensors);
        horizontalSliderHeadPan->setObjectName(QString::fromUtf8("horizontalSliderHeadPan"));
        horizontalSliderHeadPan->setGeometry(QRect(710, 30, 121, 29));
        horizontalSliderHeadPan->setMinimum(-90);
        horizontalSliderHeadPan->setMaximum(90);
        horizontalSliderHeadPan->setOrientation(Qt::Horizontal);
        horizontalSliderHeadPan->setTickPosition(QSlider::TicksBothSides);
        label_36 = new QLabel(groupBoxMotorSensors);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(590, 30, 67, 17));
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_37 = new QLabel(groupBoxMotorSensors);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(740, 10, 67, 17));
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonStopHeadMotor = new QPushButton(groupBoxMotorSensors);
        pushButtonStopHeadMotor->setObjectName(QString::fromUtf8("pushButtonStopHeadMotor"));
        pushButtonStopHeadMotor->setGeometry(QRect(710, 130, 131, 27));
        labelHeadPan = new QLabel(groupBoxMotorSensors);
        labelHeadPan->setObjectName(QString::fromUtf8("labelHeadPan"));
        labelHeadPan->setGeometry(QRect(750, 60, 41, 20));
        labelHeadPan->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelHeadPan->setAlignment(Qt::AlignCenter);
        labelHeadTilt = new QLabel(groupBoxMotorSensors);
        labelHeadTilt->setObjectName(QString::fromUtf8("labelHeadTilt"));
        labelHeadTilt->setGeometry(QRect(662, 130, 41, 20));
        labelHeadTilt->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelHeadTilt->setAlignment(Qt::AlignCenter);
        label_60 = new QLabel(groupBoxMotorSensors);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(576, 80, 81, 20));
        label_60->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditHeadCtrlTime = new QLineEdit(groupBoxMotorSensors);
        lineEditHeadCtrlTime->setObjectName(QString::fromUtf8("lineEditHeadCtrlTime"));
        lineEditHeadCtrlTime->setGeometry(QRect(590, 100, 61, 27));
        lineEditHeadCtrlTime->setAlignment(Qt::AlignCenter);
        pushButtonHeadTiltHome = new QPushButton(groupBoxMotorSensors);
        pushButtonHeadTiltHome->setObjectName(QString::fromUtf8("pushButtonHeadTiltHome"));
        pushButtonHeadTiltHome->setGeometry(QRect(600, 50, 51, 27));
        pushButtonHeadPanHome = new QPushButton(groupBoxMotorSensors);
        pushButtonHeadPanHome->setObjectName(QString::fromUtf8("pushButtonHeadPanHome"));
        pushButtonHeadPanHome->setGeometry(QRect(750, 90, 51, 27));
        groupBoxIndoorGPS = new QGroupBox(centralWidget);
        groupBoxIndoorGPS->setObjectName(QString::fromUtf8("groupBoxIndoorGPS"));
        groupBoxIndoorGPS->setGeometry(QRect(10, 360, 401, 151));
        groupBoxIndoorGPS->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	border:1px solid gray;\n"
"	border-radius: 9px;\n"
"	margin-top:0.5em;} \n"
" QGroupBox::title{\n"
"	subcontrol-origin:margin;\n"
"	left:10px;\n"
"	padding: 0 3 px 2 3px}"));
        label_43 = new QLabel(groupBoxIndoorGPS);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(30, 20, 91, 17));
        label_43->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelIndoorGPSMsg = new QLabel(groupBoxIndoorGPS);
        labelIndoorGPSMsg->setObjectName(QString::fromUtf8("labelIndoorGPSMsg"));
        labelIndoorGPSMsg->setGeometry(QRect(130, 20, 261, 20));
        labelIndoorGPSMsg->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIndoorGPSMsg->setAlignment(Qt::AlignCenter);
        label_44 = new QLabel(groupBoxIndoorGPS);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(50, 50, 71, 20));
        label_44->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelRobotX_GPS = new QLabel(groupBoxIndoorGPS);
        labelRobotX_GPS->setObjectName(QString::fromUtf8("labelRobotX_GPS"));
        labelRobotX_GPS->setGeometry(QRect(130, 50, 63, 20));
        labelRobotX_GPS->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelRobotX_GPS->setAlignment(Qt::AlignCenter);
        label_45 = new QLabel(groupBoxIndoorGPS);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(30, 80, 91, 17));
        label_45->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelRobotY_GPS = new QLabel(groupBoxIndoorGPS);
        labelRobotY_GPS->setObjectName(QString::fromUtf8("labelRobotY_GPS"));
        labelRobotY_GPS->setGeometry(QRect(130, 80, 63, 20));
        labelRobotY_GPS->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelRobotY_GPS->setAlignment(Qt::AlignCenter);
        label_46 = new QLabel(groupBoxIndoorGPS);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(10, 110, 111, 17));
        label_46->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelRobotheading_GPS = new QLabel(groupBoxIndoorGPS);
        labelRobotheading_GPS->setObjectName(QString::fromUtf8("labelRobotheading_GPS"));
        labelRobotheading_GPS->setGeometry(QRect(130, 110, 63, 20));
        labelRobotheading_GPS->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelRobotheading_GPS->setAlignment(Qt::AlignCenter);
        labelIndoorGPSMarkID = new QLabel(groupBoxIndoorGPS);
        labelIndoorGPSMarkID->setObjectName(QString::fromUtf8("labelIndoorGPSMarkID"));
        labelIndoorGPSMarkID->setGeometry(QRect(320, 50, 63, 20));
        labelIndoorGPSMarkID->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelIndoorGPSMarkID->setAlignment(Qt::AlignCenter);
        label_47 = new QLabel(groupBoxIndoorGPS);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(240, 50, 71, 20));
        label_47->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        checkBoxEnIndoorGPS = new QCheckBox(groupBoxIndoorGPS);
        checkBoxEnIndoorGPS->setObjectName(QString::fromUtf8("checkBoxEnIndoorGPS"));
        checkBoxEnIndoorGPS->setGeometry(QRect(250, 120, 111, 22));
        labelMarkHeight = new QLabel(groupBoxIndoorGPS);
        labelMarkHeight->setObjectName(QString::fromUtf8("labelMarkHeight"));
        labelMarkHeight->setGeometry(QRect(320, 80, 63, 20));
        labelMarkHeight->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelMarkHeight->setAlignment(Qt::AlignCenter);
        label_61 = new QLabel(groupBoxIndoorGPS);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(200, 80, 111, 17));
        label_61->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBoxChargeControl = new QGroupBox(centralWidget);
        groupBoxChargeControl->setObjectName(QString::fromUtf8("groupBoxChargeControl"));
        groupBoxChargeControl->setGeometry(QRect(420, 360, 771, 151));
        groupBoxChargeControl->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	border:1px solid gray;\n"
"	border-radius: 9px;\n"
"	margin-top:0.5em;} \n"
" QGroupBox::title{\n"
"	subcontrol-origin:margin;\n"
"	left:10px;\n"
"	padding: 0 3 px 2 3px}"));
        labelBatteryVol = new QLabel(groupBoxChargeControl);
        labelBatteryVol->setObjectName(QString::fromUtf8("labelBatteryVol"));
        labelBatteryVol->setGeometry(QRect(110, 20, 63, 20));
        labelBatteryVol->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelBatteryVol->setAlignment(Qt::AlignCenter);
        label_48 = new QLabel(groupBoxChargeControl);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(10, 20, 91, 20));
        label_48->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_49 = new QLabel(groupBoxChargeControl);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(230, 20, 91, 20));
        label_49->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditBatteryFuel = new QLineEdit(groupBoxChargeControl);
        lineEditBatteryFuel->setObjectName(QString::fromUtf8("lineEditBatteryFuel"));
        lineEditBatteryFuel->setEnabled(true);
        lineEditBatteryFuel->setGeometry(QRect(330, 20, 71, 27));
        label_50 = new QLabel(groupBoxChargeControl);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(200, 50, 121, 20));
        label_50->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditChargeCurrent = new QLineEdit(groupBoxChargeControl);
        lineEditChargeCurrent->setObjectName(QString::fromUtf8("lineEditChargeCurrent"));
        lineEditChargeCurrent->setEnabled(true);
        lineEditChargeCurrent->setGeometry(QRect(330, 50, 71, 27));
        lineEditChargeTime = new QLineEdit(groupBoxChargeControl);
        lineEditChargeTime->setObjectName(QString::fromUtf8("lineEditChargeTime"));
        lineEditChargeTime->setEnabled(true);
        lineEditChargeTime->setGeometry(QRect(330, 80, 71, 27));
        label_51 = new QLabel(groupBoxChargeControl);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(200, 80, 121, 20));
        label_51->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_52 = new QLabel(groupBoxChargeControl);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(10, 50, 91, 20));
        label_52->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelSystemVol = new QLabel(groupBoxChargeControl);
        labelSystemVol->setObjectName(QString::fromUtf8("labelSystemVol"));
        labelSystemVol->setGeometry(QRect(110, 50, 63, 20));
        labelSystemVol->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelSystemVol->setAlignment(Qt::AlignCenter);
        checkBoxInChargeStation = new QCheckBox(groupBoxChargeControl);
        checkBoxInChargeStation->setObjectName(QString::fromUtf8("checkBoxInChargeStation"));
        checkBoxInChargeStation->setEnabled(false);
        checkBoxInChargeStation->setGeometry(QRect(20, 80, 151, 22));
        checkBoxInChargeStation->setChecked(true);
        label_53 = new QLabel(groupBoxChargeControl);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(420, 80, 121, 20));
        label_53->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDCCurrent = new QLineEdit(groupBoxChargeControl);
        lineEditDCCurrent->setObjectName(QString::fromUtf8("lineEditDCCurrent"));
        lineEditDCCurrent->setEnabled(true);
        lineEditDCCurrent->setGeometry(QRect(550, 50, 71, 27));
        label_54 = new QLabel(groupBoxChargeControl);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(450, 20, 91, 20));
        label_54->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_55 = new QLabel(groupBoxChargeControl);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(410, 50, 131, 20));
        label_55->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditChargeMode = new QLineEdit(groupBoxChargeControl);
        lineEditChargeMode->setObjectName(QString::fromUtf8("lineEditChargeMode"));
        lineEditChargeMode->setEnabled(true);
        lineEditChargeMode->setGeometry(QRect(550, 80, 211, 27));
        lineEditDCPower = new QLineEdit(groupBoxChargeControl);
        lineEditDCPower->setObjectName(QString::fromUtf8("lineEditDCPower"));
        lineEditDCPower->setEnabled(true);
        lineEditDCPower->setGeometry(QRect(550, 20, 71, 27));
        label_56 = new QLabel(groupBoxChargeControl);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(420, 110, 121, 20));
        label_56->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditChargePPR = new QLineEdit(groupBoxChargeControl);
        lineEditChargePPR->setObjectName(QString::fromUtf8("lineEditChargePPR"));
        lineEditChargePPR->setEnabled(true);
        lineEditChargePPR->setGeometry(QRect(550, 110, 211, 27));
        label_57 = new QLabel(groupBoxChargeControl);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(240, 110, 81, 20));
        label_57->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditChargeErrorCode = new QLineEdit(groupBoxChargeControl);
        lineEditChargeErrorCode->setObjectName(QString::fromUtf8("lineEditChargeErrorCode"));
        lineEditChargeErrorCode->setEnabled(true);
        lineEditChargeErrorCode->setGeometry(QRect(330, 110, 71, 27));
        pushButtonChargeCtrl = new QPushButton(groupBoxChargeControl);
        pushButtonChargeCtrl->setObjectName(QString::fromUtf8("pushButtonChargeCtrl"));
        pushButtonChargeCtrl->setGeometry(QRect(10, 110, 111, 27));
        pushButtonSwitchPower = new QPushButton(groupBoxChargeControl);
        pushButtonSwitchPower->setObjectName(QString::fromUtf8("pushButtonSwitchPower"));
        pushButtonSwitchPower->setGeometry(QRect(130, 110, 111, 27));
        groupBoxLaserScan = new QGroupBox(centralWidget);
        groupBoxLaserScan->setObjectName(QString::fromUtf8("groupBoxLaserScan"));
        groupBoxLaserScan->setGeometry(QRect(870, 200, 321, 161));
        groupBoxLaserScan->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	border:1px solid gray;\n"
"	border-radius: 9px;\n"
"	margin-top:0.5em;} \n"
" QGroupBox::title{\n"
"	subcontrol-origin:margin;\n"
"	left:10px;\n"
"	padding: 0 3 px 2 3px}"));
        labelLaserAngle = new QLabel(groupBoxLaserScan);
        labelLaserAngle->setObjectName(QString::fromUtf8("labelLaserAngle"));
        labelLaserAngle->setGeometry(QRect(90, 130, 41, 20));
        labelLaserAngle->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelLaserAngle->setAlignment(Qt::AlignCenter);
        label_38 = new QLabel(groupBoxLaserScan);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(16, 40, 71, 20));
        label_38->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        verticalSliderLaserDrive = new QSlider(groupBoxLaserScan);
        verticalSliderLaserDrive->setObjectName(QString::fromUtf8("verticalSliderLaserDrive"));
        verticalSliderLaserDrive->setGeometry(QRect(100, 20, 29, 111));
        verticalSliderLaserDrive->setMinimum(-20);
        verticalSliderLaserDrive->setMaximum(20);
        verticalSliderLaserDrive->setOrientation(Qt::Vertical);
        verticalSliderLaserDrive->setTickPosition(QSlider::TicksBothSides);
        pushButtonLaserAutoScan = new QPushButton(groupBoxLaserScan);
        pushButtonLaserAutoScan->setObjectName(QString::fromUtf8("pushButtonLaserAutoScan"));
        pushButtonLaserAutoScan->setGeometry(QRect(10, 60, 81, 27));
        labelLaserEncPos = new QLabel(groupBoxLaserScan);
        labelLaserEncPos->setObjectName(QString::fromUtf8("labelLaserEncPos"));
        labelLaserEncPos->setGeometry(QRect(250, 30, 63, 20));
        labelLaserEncPos->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelLaserEncPos->setAlignment(Qt::AlignCenter);
        label_39 = new QLabel(groupBoxLaserScan);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(150, 30, 91, 17));
        label_39->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelLaserEncVel = new QLabel(groupBoxLaserScan);
        labelLaserEncVel->setObjectName(QString::fromUtf8("labelLaserEncVel"));
        labelLaserEncVel->setGeometry(QRect(250, 60, 63, 20));
        labelLaserEncVel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelLaserEncVel->setAlignment(Qt::AlignCenter);
        label_40 = new QLabel(groupBoxLaserScan);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(150, 60, 91, 17));
        label_40->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelLaserMotorPWM = new QLabel(groupBoxLaserScan);
        labelLaserMotorPWM->setObjectName(QString::fromUtf8("labelLaserMotorPWM"));
        labelLaserMotorPWM->setGeometry(QRect(250, 90, 63, 20));
        labelLaserMotorPWM->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelLaserMotorPWM->setAlignment(Qt::AlignCenter);
        label_41 = new QLabel(groupBoxLaserScan);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(140, 90, 101, 17));
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelLaserMotorCurrent = new QLabel(groupBoxLaserScan);
        labelLaserMotorCurrent->setObjectName(QString::fromUtf8("labelLaserMotorCurrent"));
        labelLaserMotorCurrent->setGeometry(QRect(250, 120, 63, 20));
        labelLaserMotorCurrent->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border: 1px solid;\n"
"	background-color:#fff;\n"
"}"));
        labelLaserMotorCurrent->setAlignment(Qt::AlignCenter);
        label_42 = new QLabel(groupBoxLaserScan);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(140, 120, 101, 20));
        label_42->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonLaserHome = new QPushButton(groupBoxLaserScan);
        pushButtonLaserHome->setObjectName(QString::fromUtf8("pushButtonLaserHome"));
        pushButtonLaserHome->setGeometry(QRect(10, 90, 81, 27));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Clinic Robot Control Center", 0, QApplication::UnicodeUTF8));
        groupBoxCommunication->setTitle(QApplication::translate("MainWindow", "Communication Status", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Network-I:", 0, QApplication::UnicodeUTF8));
        lineEditNetworkIP1->setText(QApplication::translate("MainWindow", "192.168.0.60", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Motion Control Port:", 0, QApplication::UnicodeUTF8));
        lineEditMotionPort->setText(QApplication::translate("MainWindow", "10001", 0, QApplication::UnicodeUTF8));
        pushButtonMotionConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        labelMotionPortState->setText(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Charger Control Port:", 0, QApplication::UnicodeUTF8));
        lineEditChargerPort->setText(QApplication::translate("MainWindow", "10002", 0, QApplication::UnicodeUTF8));
        pushButtonChargerConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        labelChargerPortState->setText(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Network-II:", 0, QApplication::UnicodeUTF8));
        lineEditNetworkIP2->setText(QApplication::translate("MainWindow", "192.168.0.61", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Laser Control Port:", 0, QApplication::UnicodeUTF8));
        lineEditLaserPort->setText(QApplication::translate("MainWindow", "10001", 0, QApplication::UnicodeUTF8));
        pushButtonLaserConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        labelLaserPortState->setText(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Indoor GPS Port:", 0, QApplication::UnicodeUTF8));
        lineEditIndoorGPSPort->setText(QApplication::translate("MainWindow", "10002", 0, QApplication::UnicodeUTF8));
        pushButtonIndoorGPSConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        labelIndoorGPSPortState->setText(QApplication::translate("MainWindow", "T", 0, QApplication::UnicodeUTF8));
        groupBoxRangeSensors->setTitle(QApplication::translate("MainWindow", "Range Sensors && Bump Sensor", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "IR #1:", 0, QApplication::UnicodeUTF8));
        labelIR1_1->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "IR #2:", 0, QApplication::UnicodeUTF8));
        labelIR1_2->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "IR #3:", 0, QApplication::UnicodeUTF8));
        labelIR1_3->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "IR #4:", 0, QApplication::UnicodeUTF8));
        labelIR1_4->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "IR #5:", 0, QApplication::UnicodeUTF8));
        labelIR1_5->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "IR #6:", 0, QApplication::UnicodeUTF8));
        labelIR1_6->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "IR #7:", 0, QApplication::UnicodeUTF8));
        labelIR1_7->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "IR #8:", 0, QApplication::UnicodeUTF8));
        labelIR1_8->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "IR #9:", 0, QApplication::UnicodeUTF8));
        labelIR1_9->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "IR #10:", 0, QApplication::UnicodeUTF8));
        labelIR1_10->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "IR #11:", 0, QApplication::UnicodeUTF8));
        labelIR1_11->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "IR #12:", 0, QApplication::UnicodeUTF8));
        labelIR1_12->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "IR #13:", 0, QApplication::UnicodeUTF8));
        labelIR1_13->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "IR #14:", 0, QApplication::UnicodeUTF8));
        labelIR1_14->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "IR #15:", 0, QApplication::UnicodeUTF8));
        labelIR1_15->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "IR #16:", 0, QApplication::UnicodeUTF8));
        labelIR1_16->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "US #1:", 0, QApplication::UnicodeUTF8));
        labelUS_1->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "US #2:", 0, QApplication::UnicodeUTF8));
        labelUS_2->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "US #3:", 0, QApplication::UnicodeUTF8));
        labelUS_3->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "US #4:", 0, QApplication::UnicodeUTF8));
        labelUS_4->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "US #5:", 0, QApplication::UnicodeUTF8));
        labelUS_5->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "US #6:", 0, QApplication::UnicodeUTF8));
        labelUS_6->setText(QApplication::translate("MainWindow", "0.81", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("MainWindow", "Bump-L:", 0, QApplication::UnicodeUTF8));
        labelBump_L->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("MainWindow", "Bump_R:", 0, QApplication::UnicodeUTF8));
        labelBump_R->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        groupBoxMotorSensors->setTitle(QApplication::translate("MainWindow", "Motor Sensors && Control(Wheel && Head)", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "Left-Wheel:", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "Encoder Pos", 0, QApplication::UnicodeUTF8));
        labelLeftEncPos->setText(QString());
        label_31->setText(QApplication::translate("MainWindow", "Encoder Vel", 0, QApplication::UnicodeUTF8));
        labelLeftEncVel->setText(QString());
        label_32->setText(QApplication::translate("MainWindow", "Motor PWM", 0, QApplication::UnicodeUTF8));
        labelLeftPWM->setText(QString());
        labelRightEncVel->setText(QString());
        labelRightEncPos->setText(QString());
        label_33->setText(QApplication::translate("MainWindow", "Right-Wheel:", 0, QApplication::UnicodeUTF8));
        labelRightPWM->setText(QString());
        label_34->setText(QApplication::translate("MainWindow", "Head_Tilt:", 0, QApplication::UnicodeUTF8));
        labelHeadTiltEncPos->setText(QString());
        labelHeadTiltPWM->setText(QString());
        labelHeadTiltEncVel->setText(QString());
        label_35->setText(QApplication::translate("MainWindow", "Head-Pan:", 0, QApplication::UnicodeUTF8));
        labelHeadPanEncPos->setText(QString());
        labelHeadPanPWM->setText(QString());
        labelHeadPanEncVel->setText(QString());
        pushButtonGoForward->setText(QApplication::translate("MainWindow", "^", 0, QApplication::UnicodeUTF8));
        pushButtonTurnLeft->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        pushButtonStop->setText(QApplication::translate("MainWindow", "O", 0, QApplication::UnicodeUTF8));
        pushButtonTurnRight->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        pushButtonGoBackward->setText(QApplication::translate("MainWindow", "v", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "Head Tilt:", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MainWindow", "Head Pan:", 0, QApplication::UnicodeUTF8));
        pushButtonStopHeadMotor->setText(QApplication::translate("MainWindow", "StopHeadMotor", 0, QApplication::UnicodeUTF8));
        labelHeadPan->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        labelHeadTilt->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_60->setText(QApplication::translate("MainWindow", "Head Time:", 0, QApplication::UnicodeUTF8));
        lineEditHeadCtrlTime->setText(QApplication::translate("MainWindow", "1500", 0, QApplication::UnicodeUTF8));
        pushButtonHeadTiltHome->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        pushButtonHeadPanHome->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        groupBoxIndoorGPS->setTitle(QApplication::translate("MainWindow", "Indoor GPS", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("MainWindow", "Rev Message:", 0, QApplication::UnicodeUTF8));
        labelIndoorGPSMsg->setText(QString());
        label_44->setText(QApplication::translate("MainWindow", "RobotX:", 0, QApplication::UnicodeUTF8));
        labelRobotX_GPS->setText(QString());
        label_45->setText(QApplication::translate("MainWindow", "RobotY:", 0, QApplication::UnicodeUTF8));
        labelRobotY_GPS->setText(QString());
        label_46->setText(QApplication::translate("MainWindow", "Robot Heading:", 0, QApplication::UnicodeUTF8));
        labelRobotheading_GPS->setText(QString());
        labelIndoorGPSMarkID->setText(QString());
        label_47->setText(QApplication::translate("MainWindow", "Mark ID:", 0, QApplication::UnicodeUTF8));
        checkBoxEnIndoorGPS->setText(QApplication::translate("MainWindow", "Enable GPS", 0, QApplication::UnicodeUTF8));
        labelMarkHeight->setText(QString());
        label_61->setText(QApplication::translate("MainWindow", "Mark Height:", 0, QApplication::UnicodeUTF8));
        groupBoxChargeControl->setTitle(QApplication::translate("MainWindow", "Charger Control && Status", 0, QApplication::UnicodeUTF8));
        labelBatteryVol->setText(QString());
        label_48->setText(QApplication::translate("MainWindow", "Battery Vol:", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("MainWindow", "Battery Fuel:", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("MainWindow", "ChargeCurrent:", 0, QApplication::UnicodeUTF8));
        lineEditChargeTime->setText(QString());
        label_51->setText(QApplication::translate("MainWindow", "ChargeTime:", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("MainWindow", "System Vol:", 0, QApplication::UnicodeUTF8));
        labelSystemVol->setText(QString());
        checkBoxInChargeStation->setText(QApplication::translate("MainWindow", "In Charge Station", 0, QApplication::UnicodeUTF8));
        label_53->setText(QApplication::translate("MainWindow", "Charger Mode:", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("MainWindow", "<html><head/><body><p>DC Power:</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_55->setText(QApplication::translate("MainWindow", "DC Power Current:", 0, QApplication::UnicodeUTF8));
        lineEditChargeMode->setText(QString());
        label_56->setText(QApplication::translate("MainWindow", "Charger PPR:", 0, QApplication::UnicodeUTF8));
        lineEditChargePPR->setText(QString());
        label_57->setText(QApplication::translate("MainWindow", "Error Code:", 0, QApplication::UnicodeUTF8));
        lineEditChargeErrorCode->setText(QString());
        pushButtonChargeCtrl->setText(QApplication::translate("MainWindow", "StopCharge", 0, QApplication::UnicodeUTF8));
        pushButtonSwitchPower->setText(QApplication::translate("MainWindow", "DCPower", 0, QApplication::UnicodeUTF8));
        groupBoxLaserScan->setTitle(QApplication::translate("MainWindow", "Laser Scanner && Control", 0, QApplication::UnicodeUTF8));
        labelLaserAngle->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", "Tilt Angle:", 0, QApplication::UnicodeUTF8));
        pushButtonLaserAutoScan->setText(QApplication::translate("MainWindow", "AutoScan", 0, QApplication::UnicodeUTF8));
        labelLaserEncPos->setText(QString());
        label_39->setText(QApplication::translate("MainWindow", "Encoder Pos:", 0, QApplication::UnicodeUTF8));
        labelLaserEncVel->setText(QString());
        label_40->setText(QApplication::translate("MainWindow", "Encoder Vel:", 0, QApplication::UnicodeUTF8));
        labelLaserMotorPWM->setText(QString());
        label_41->setText(QApplication::translate("MainWindow", "Motor Power:", 0, QApplication::UnicodeUTF8));
        labelLaserMotorCurrent->setText(QString());
        label_42->setText(QApplication::translate("MainWindow", "Motor Current:", 0, QApplication::UnicodeUTF8));
        pushButtonLaserHome->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
