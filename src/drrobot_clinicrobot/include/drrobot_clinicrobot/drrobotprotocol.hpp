/*
 * drrobotprotocol.h
 *
 *  Created on: Sep 17, 2008
 *      Author: bwei
 */

#ifndef DRROBOTPROTOCOL_H_
#define DRROBOTPROTOCOL_H_
#define RID			2
#define DID			4
#define LENGTHPOS	5
#define DATAPOS    	5		//please note the first data position is at 6,
#define LENGTHOFDATAPACKAGE 9

#define MOTORPWMCTRL	5
#define MOTORPWMCTRLALL	6
#define SETOUTPUTPORT	22

#define MOTORVELCTRL	26
#define MOTORVELCTRLALL	27
#define MOTORPOSCTRL	3
#define MOTORPOSCTRLALL	4

#define SERVOCTRL		28
#define SERVOCTRLALL	29

#define MOTORENABLE		0x1e
#define GENERALSENSOR	125
#define SPECIALSENSOR	124
#define MOTORSENSOR		123

#define STX0		94
#define STX1		2
#define ETX0		94
#define ETX1		13
#define FLAG		6
#define TIME_FLAG   28
static const QByteArray MOTION_PING = QByteArray::fromHex("5e020100ff0101855e0d");
static const QByteArray STX = QByteArray::fromHex("5e02");
static const QByteArray ETX = QByteArray::fromHex("5e0d");
//some robot setting

#define PWM0	16384
#define NOCONTROL	-32768
#define FULLCNT	32767

#endif /* DRROBOTPROTOCOL_H_ */
