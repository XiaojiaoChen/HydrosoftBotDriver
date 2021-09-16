/*
 *
 *  Created on: May 12, 2018
 *      Author: 402072495
 */

#ifndef USERINC_SOFTARM_H_
#define USERINC_SOFTARM_H_

#include "CHAMBER.h"
#include "PRESSURESOURCE.h"
#include "messages.h"
#define SEGNUM 3
#define ACTNUM 3
#define P_ATM 101000
#include "HydroDriveLL.h"
typedef enum{
	OpeningControlMode,
	PressureControlMode
}CONTROLMODE;


typedef struct __attribute__((packed)) HydroManipulatorCommandTag{
	uint8_t header[2];
	uint8_t modeCmd;
	uint32_t armCmd;
	int16_t pSourceCmd;
	int16_t pSinkCmd;
	uint8_t tail[1];
}HydroManipulatorCommand;

typedef struct __attribute__((packed)) HydroManipulatorStatusTag{
	uint8_t header[2];
	uint8_t modeStatus;
	uint32_t armStatus;
	int16_t pSourcePressure;
	int16_t pSinkPressure;
	int16_t quaternions[(SEGNUM+1)][4];
	uint8_t tail[1];
}HydroManipulatorStatus;


//
//class HydroManipulatorStatus : public hydrosoft_ros::Sensor_Arm
//{
//	public:
//		HydroManipulatorStatus()
//		{
//			actuatorStatus = (int16_t *)actuatorStatusBuf;
//			actuatorStatus_length = SEGNUM*ACTNUM;
//			quaternions = (int16_t *)quaternionsBuf;
//			quaternions_length = (SEGNUM+1)*4;
//		}
//		int16_t actuatorStatusBuf[SEGNUM][ACTNUM];
//		int16_t quaternionsBuf[(SEGNUM+1)][4];
//};
//
//class HydroManipulatorCommand : public hydrosoft_ros::Command_Arm
//{
//	public:
//		HydroManipulatorCommand()
//		{
//			actuatorCommand = (int16_t *)actuatorCommandBuf;
//			actuatorCommand_length = SEGNUM*ACTNUM;
//		}
//		int16_t actuatorCommandBuf[SEGNUM][ACTNUM];
//
//		int16_t controlMode;
//
//		int16_t openingCmd_actuators[SEGNUM][ACTNUM][2];
//		int16_t openingCmd_gripper[2];
//		int16_t openingCmd_pSource_pump;
//		int16_t openingCmd_pSource_valve;
//		int16_t openingCmd_pSink_pump;
//		int16_t openingCmd_pSink_valve;
//
//		int16_t pressureCmd_actuators[SEGNUM][ACTNUM];
//		int16_t pressureCmd_gripper;
//		int16_t pressureCmd_pSource;
//		int16_t pressureCmd_pSink;
//};



#define __MY_SET_BIT(__VALUE__, __BITMASK__)     			 ((__VALUE__) |= (__BITMASK__))
#define __MY_RESET_BIT(__VALUE__, __BITMASK__)   			 ((__VALUE__) &= ~(__BITMASK__))
#define __MY_TOGGLE_BIT(__VALUE__, __BITMASK__)   		 	((__VALUE__) ^= (__BITMASK__))
#define __MY_GET_BIT(__VALUE__, __BITMASK__)         		(((__VALUE__) & (__BITMASK__)) != 0)

#define __MY_SET_BIT_VAL(__VALUE__, __BITMASK__,__VAL__)    do{                                              \
																if(__VAL__)							\
																	{(__VALUE__) |= (__BITMASK__);}   \
																else\
																	{(__VALUE__) &= ~(__BITMASK__);};        \
																       \
															  } while(0)



class HydroUnderwaterManipulator
{
public:
	HydroUnderwaterManipulator();

	CHAMBER actuators[SEGNUM][ACTNUM];
	CHAMBER gripper;
	PRESSURE_SOURCE pSource;
	PRESSURE_SOURCE pSink;

	void setupActuatorPorts(uint8_t (&ports)[SEGNUM][ACTNUM][2]);
	void setupGripperPorts(uint8_t (&ports)[2]);
	void setupPsourcePorts(uint8_t pumpPort, uint8_t valvePort, uint8_t sensorPort);
	void setupPsinkPorts(uint8_t pumpPort, uint8_t valvePort, uint8_t sensorPort);

	void control();
	void encodeStatus();


	HydroManipulatorStatus manipulatorStatus;
	HydroManipulatorCommand hostCommand;
};

#endif /* USERINC_SOFTARM_H_ */
