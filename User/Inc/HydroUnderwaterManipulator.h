/*
 *
 *  Created on: May 12, 2018
 *      Author: 402072495
 */

#ifndef USERINC_SOFTARM_H_
#define USERINC_SOFTARM_H_

#include "CHAMBER.h"
#include "PRESSURESOURCE.h"
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



#define ActInValveBtn_seg_0    		21
#define ActInValveBtn_seg_1    		1344
#define ActInValveBtn_seg_2    		86016
#define ActOutValveBtn_seg_0    		42
#define ActOutValveBtn_seg_1    		2688
#define ActOutValveBtn_seg_2    	172032
#define PSinkBtn    				12582912
#define PSourceBtn    				3145728
#define actInValveBtn_seg_0_act_0    1
#define actInValveBtn_seg_0_act_1    4
#define actInValveBtn_seg_0_act_2    16
#define actInValveBtn_seg_1_act_0    64
#define actInValveBtn_seg_1_act_1    256
#define actInValveBtn_seg_1_act_2    1024
#define actInValveBtn_seg_2_act_0    4096
#define actInValveBtn_seg_2_act_1    16384
#define actInValveBtn_seg_2_act_2    65536
#define actOutValveBtn_seg_0_act_0    2
#define actOutValveBtn_seg_0_act_1    8
#define actOutValveBtn_seg_0_act_2    32
#define actOutValveBtn_seg_1_act_0    128
#define actOutValveBtn_seg_1_act_1    512
#define actOutValveBtn_seg_1_act_2    2048
#define actOutValveBtn_seg_2_act_0    8192
#define actOutValveBtn_seg_2_act_1    32768
#define actOutValveBtn_seg_2_act_2    131072
#define gripperInValveBtn    			262144
#define gripperOutValveBtn   			 524288
#define joystick3DBtn   				 4
#define joystickBtn   					 2
#define manualControlBtn  				1
#define pSinkPumpBtn   				 8388608
#define pSinkValveBtn  				  4194304
#define pSourcePumpBtn   				 2097152
#define pSourceValveBtn    				1048576
#define radioBtn_autoControl  		  	32
#define radioBtn_feedbackControl  	  8
#define radioBtn_pressureControl   	 16






#define __MY_SET_BIT(__VALUE__, __BITMASK__)     			 ((__VALUE__) |= (__BITMASK__))
#define __MY_RESET_BIT(__VALUE__, __BITMASK__)   			 ((__VALUE__) &= ~(__BITMASK__))
#define __MY_TOGGLE_BIT(__VALUE__, __BITMASK__)   		 	((__VALUE__) ^= (__BITMASK__))
#define __MY_GET_BIT(__VALUE__, __BITMASK__)         		(((__VALUE__) & (__BITMASK__)) != 0)

#define __MY_SET_BIT_VAL(__VALUE__, __BITMASK__,__VAL__)    do{                                              \
																if(__VAL__!=0)							\
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
//	void setupGripperPorts(uint8_t (&ports)[2]);
	void setupPsourcePorts(uint8_t pumpPort);
	void setupPsinkPorts(uint8_t pumpPort);

	void control();
	void encodeStatus();
	void controlTest();

	HydroManipulatorStatus manipulatorStatus;
	HydroManipulatorCommand hostCommand;
};

#endif /* USERINC_SOFTARM_H_ */
