/*
 * SoftArm.c
 *
 *  Created on: May 12, 2018
 *      Author: 402072495
 */
#include "HydroUnderwaterManipulator.h"
#include "myUsartFunction.h"
#include "main.h"

#include "stdio.h"
#include "string.h"
/*************************SOFT ARM**************************
 *
 ***********************************************************/

uint32_t maskPumpPSource = pSourcePumpBtn;
uint32_t maskPumpPSink = pSinkPumpBtn;
uint32_t maskGripperIn = gripperInValveBtn;
uint32_t maskGripperOut = gripperOutValveBtn;
uint32_t maskValve[SEGNUM][ACTNUM][2] = {
		{	{actInValveBtn_seg_0_act_0,actOutValveBtn_seg_0_act_0},
			{actInValveBtn_seg_0_act_1,actOutValveBtn_seg_0_act_1},
			{actInValveBtn_seg_0_act_2,actOutValveBtn_seg_0_act_2}
		},
		{
			{actInValveBtn_seg_1_act_0,actOutValveBtn_seg_1_act_0},
			{actInValveBtn_seg_1_act_1,actOutValveBtn_seg_1_act_1},
			{actInValveBtn_seg_1_act_2,actOutValveBtn_seg_1_act_2}
		},
		{
			{actInValveBtn_seg_2_act_0,actOutValveBtn_seg_2_act_0},
			{actInValveBtn_seg_2_act_1,actOutValveBtn_seg_2_act_1},
			{actInValveBtn_seg_2_act_2,actOutValveBtn_seg_2_act_2}
		}
};



HydroUnderwaterManipulator::HydroUnderwaterManipulator() :
		pSource(0, 0, HIGH_PRESSURE_SOURCE), pSink(0, 0, LOW_PRESSURE_SINK) {
	manipulatorStatus.header[0] = 0x5a;
	manipulatorStatus.header[1] = 0x5a;
	manipulatorStatus.tail[0] = '\n';

	hostCommand.header[0] = 0x5a;
	hostCommand.header[1] = 0x5a;
	hostCommand.tail[0] = '\n';
}

void HydroUnderwaterManipulator::setupActuatorPorts(
		uint8_t (&ports)[SEGNUM][ACTNUM][2]) {
	/*Every actuator is refered to with two numbers, segNum(0-3) and bellowNum(0-3)*/

	for (int i = 0; i < SEGNUM; i++) {
		for (int j = 0; j < ACTNUM; j++) {
			actuators[i][j].attachPWM(ports[i][j][0], ports[i][j][1]);
			actuators[i][j].writeOpening(0);
		}
	}

}
//void HydroUnderwaterManipulator::setupGripperPorts(uint8_t (&ports)[2]) {
//	gripper.attachPWM(ports[0], ports[1]);
//	gripper.writeOpening(0);
//
//}
//void HydroUnderwaterManipulator::setupPsourcePorts(uint8_t pumpPort,
//		uint8_t valvePort, uint8_t sensorPort) {
//	pSource.attach(pumpPort, valvePort, sensorPort);
//}
//void HydroUnderwaterManipulator::setupPsinkPorts(uint8_t pumpPort,
//		uint8_t valvePort, uint8_t sensorPort) {
//	pSink.attach(pumpPort, valvePort, sensorPort);
//}

void HydroUnderwaterManipulator::setupPsourcePorts(uint8_t pumpPort) {
	pSource.attachPump(pumpPort);
}
void HydroUnderwaterManipulator::setupPsinkPorts(uint8_t pumpPort) {
	pSink.attachPump(pumpPort);
}
void HydroUnderwaterManipulator::control() {
	int8_t inPumpcmd=__MY_GET_BIT(hostCommand.armCmd, maskPumpPSource);
	pSource.setPump(inPumpcmd);

	pSink.setPump(__MY_GET_BIT(hostCommand.armCmd, maskPumpPSink));

//	gripper.valves[0].writeDuty(
//			__MY_GET_BIT(hostCommand.armCmd, maskGripperIn));
//	gripper.valves[1].writeDuty(
//			__MY_GET_BIT(hostCommand.armCmd,
//					maskGripperOut));

	for (int i = 0; i < SEGNUM; i++) {
		for (int j = 0; j < ACTNUM; j++) {
			for(int k=0;k<2;k++){
				actuators[i][j].valves[k].writeDuty(__MY_GET_BIT(hostCommand.armCmd, maskValve[i][j][k]));
			}
		}
	}
}

void HydroUnderwaterManipulator::encodeStatus() {
	for (int i = 0; i < SEGNUM; i++) {
		for (int j = 0; j < ACTNUM; j++) {
			for(int k=0;k<2;k++){
				__MY_SET_BIT_VAL(manipulatorStatus.armStatus,maskValve[i][j][k],(actuators[i][j].valves[k].getDuty()));
			}
		}
	}
//	__MY_SET_BIT_VAL(manipulatorStatus.armStatus,
//			maskGripperIn, (gripper.valves[0].getDuty()));
//	__MY_SET_BIT_VAL(manipulatorStatus.armStatus,
//			maskGripperOut, (gripper.valves[1].getDuty()));

	__MY_SET_BIT_VAL(manipulatorStatus.armStatus, maskPumpPSource,
			(pSource.pump.status));

	__MY_SET_BIT_VAL(manipulatorStatus.armStatus, maskPumpPSink,
			(pSink.pump.status));

}

void HydroUnderwaterManipulator::controlTest() {

	pSource.setPump(1);
	pSink.setPump(1);


	for (int i = 0; i < SEGNUM; i++) {
		for (int j = 0; j < ACTNUM; j++) {

			actuators[i][j].valves[0].writeDuty(
					0);
			actuators[i][j].valves[1].writeDuty(
					0);
		}
	}

}

