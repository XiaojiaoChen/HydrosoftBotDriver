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
#define ACTNUM 4
#define P_ATM 101000
#include "ros.h"
#include "hydrosoft_ros/Command_Arm.h"
#include "hydrosoft_ros/Sensor_Arm.h"
#include "HydroDriveLL.h"
typedef enum{
	OpeningControlMode,
	PressureControlMode
}CONTROLMODE;

class HydroManipulatorStatus : public hydrosoft_ros::Sensor_Arm
{
	public:
		HydroManipulatorStatus()
		{
			actuatorStatus = (int16_t *)actuatorStatusBuf;
			actuatorStatus_length = SEGNUM*ACTNUM;
			quaternions = (int16_t *)quaternionsBuf;
			quaternions_length = (SEGNUM+1)*4;
		}
		int16_t actuatorStatusBuf[SEGNUM][ACTNUM];
		int16_t quaternionsBuf[(SEGNUM+1)][4];
};

class HydroManipulatorCommand : public hydrosoft_ros::Command_Arm
{
	public:
		HydroManipulatorCommand()
		{
			actuatorCommand = (int16_t *)actuatorCommandBuf;
			actuatorCommand_length = SEGNUM*ACTNUM;
		}
		int16_t actuatorCommandBuf[SEGNUM][ACTNUM];

		int16_t controlMode;

		int16_t openingCmd_actuators[SEGNUM][ACTNUM][2];
		int16_t openingCmd_gripper[2];
		int16_t openingCmd_pSource_pump;
		int16_t openingCmd_pSource_valve;
		int16_t openingCmd_pSink_pump;
		int16_t openingCmd_pSink_valve;

		int16_t pressureCmd_actuators[SEGNUM][ACTNUM];
		int16_t pressureCmd_gripper;
		int16_t pressureCmd_pSource;
		int16_t pressureCmd_pSink;
};


#define PRESSURE_CONTROL_MASK (0x0001)

#define ACTUATOR_IN_VALVE_MASK  (0x0001)
#define ACTUATOR_OUT_VALVE_MASK  (0x0002)

#define GRIPPER_IN_VALVE_MASK  (0x0001)
#define GRIPPER_OUT_VALVE_MASK  (0x0002)

#define PSOURCE_IN_VALVE_MASK  (0x0001)
#define PSOURCE_IN_PUMP_MASK  (0x0002)

#define PSINK_OUT_VALVE_MASK  (0x0001)
#define PSINK_OUT_PUMP_MASK  (0x0002)

#define __SET_BIT(__VALUE__, __BITMASK__) ((__VALUE__) |= (__BITMASK__))
#define __RESET_BIT(__VALUE__, __BITMASK__) ((__VALUE__) &= ~(__BITMASK__))
#define __TOGGLE_BIT(__VALUE__, __BITMASK__) ((__VALUE__) ^= (__BITMASK__))
#define __GET_BIT(__VALUE__, __BITMASK__) (((__VALUE__) & (__BITMASK__)) != 0)




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
