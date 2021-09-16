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

#include <map>
std::map<std::string, uint32_t> bitMaskDict = { { "actInValveBtn_seg_0", 85 }, {
		"actInValveBtn_seg_0_act_0", 1 }, { "actInValveBtn_seg_0_act_1", 4 }, {
		"actInValveBtn_seg_0_act_2", 16 }, { "actInValveBtn_seg_0_act_3", 64 },
		{ "actInValveBtn_seg_1", 21760 }, { "actInValveBtn_seg_1_act_0", 256 },
		{ "actInValveBtn_seg_1_act_1", 1024 }, { "actInValveBtn_seg_1_act_2",
				4096 }, { "actInValveBtn_seg_1_act_3", 16384 }, {
				"actInValveBtn_seg_2", 5570560 }, { "actInValveBtn_seg_2_act_0",
				65536 }, { "actInValveBtn_seg_2_act_1", 262144 }, {
				"actInValveBtn_seg_2_act_2", 1048576 }, {
				"actInValveBtn_seg_2_act_3", 4194304 }, {
				"actOutValveBtn_seg_0", 170 },
		{ "actOutValveBtn_seg_0_act_0", 2 },
		{ "actOutValveBtn_seg_0_act_1", 8 },
		{ "actOutValveBtn_seg_0_act_2", 32 }, { "actOutValveBtn_seg_0_act_3",
				128 }, { "actOutValveBtn_seg_1", 43520 }, {
				"actOutValveBtn_seg_1_act_0", 512 }, {
				"actOutValveBtn_seg_1_act_1", 2048 }, {
				"actOutValveBtn_seg_1_act_2", 8192 }, {
				"actOutValveBtn_seg_1_act_3", 32768 }, { "actOutValveBtn_seg_2",
				11141120 }, { "actOutValveBtn_seg_2_act_0", 131072 }, {
				"actOutValveBtn_seg_2_act_1", 524288 }, {
				"actOutValveBtn_seg_2_act_2", 2097152 }, {
				"actOutValveBtn_seg_2_act_3", 8388608 }, { "gripperInValveBtn",
				16777216 }, { "gripperOutValveBtn", 33554432 }, {
				"joystick3DBtn", 4 }, { "joystickBtn", 2 }, {
				"manualControlBtn", 1 }, { "PSinkBtn", 805306368 }, {
				"pSinkPumpBtn", 536870912 }, { "pSinkValveBtn", 268435456 }, {
				"PSourceBtn", 201326592 }, { "pSourcePumpBtn", 134217728 }, {
				"pSourceValveBtn", 67108864 },
		{ "radioBtn_feedbackControl", 8 }, { "radioBtn_pressureControl", 16 }

};


/*************************SOFT ARM**************************
 *
 ***********************************************************/
HydroUnderwaterManipulator::HydroUnderwaterManipulator() :
		pSource(0, 0, HIGH_PRESSURE_SOURCE), pSink(0, 0, LOW_PRESSURE_SINK) {
	manipulatorStatus.header[0]=0x5a;
	manipulatorStatus.header[1]=0x5a;
	manipulatorStatus.tail[0]='\n';

	hostCommand.header[0]=0x5a;
	hostCommand.header[1]=0x5a;
	hostCommand.tail[0]='\n';
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
void HydroUnderwaterManipulator::setupGripperPorts(uint8_t (&ports)[2]) {
	gripper.attachPWM(ports[0], ports[1]);
	gripper.writeOpening(0);

}
void HydroUnderwaterManipulator::setupPsourcePorts(uint8_t pumpPort,
		uint8_t valvePort, uint8_t sensorPort) {
	pSource.attach(pumpPort, valvePort, sensorPort);
}
void HydroUnderwaterManipulator::setupPsinkPorts(uint8_t pumpPort,
		uint8_t valvePort, uint8_t sensorPort) {
	pSink.attach(pumpPort, valvePort, sensorPort);
}

void HydroUnderwaterManipulator::control() {
			pSource.setPump(
					__MY_GET_BIT(hostCommand.armCmd,
							bitMaskDict["pSourcePumpBtn"]));
			pSource.setValve(
					__MY_GET_BIT(hostCommand.armCmd,
							bitMaskDict["pSourceValveBtn"]));

			pSink.setPump(
					__MY_GET_BIT(hostCommand.armCmd, bitMaskDict["pSinkPumpBtn"]));
			pSink.setValve(
					__MY_GET_BIT(hostCommand.armCmd, bitMaskDict["pSinkValveBtn"]));

			gripper.valves[0].writeDuty(
					__MY_GET_BIT(hostCommand.armCmd,
							bitMaskDict["gripperInValveBtn"]));
			gripper.valves[1].writeDuty(
					__MY_GET_BIT(hostCommand.armCmd,
							bitMaskDict["gripperOutValveBtn"]));

			for (int i = 0; i < SEGNUM; i++) {
				for (int j = 0; j < ACTNUM; j++) {
					std::string targetActIn, targetActOut;
					targetActIn = std::string("actInValveBtn_seg_") + std::to_string(i)
							+ std::string("_act_") + std::to_string(j);
					targetActOut = std::string("actOutValveBtn_seg_")
							+ std::to_string(i) + std::string("_act_")
							+ std::to_string(j);

		//			actuators[i][j].valves[0].writeDuty(armCmd & (1<<((i*ACTNUM+j)*2)));
		//			actuators[i][j].valves[1].writeDuty(armCmd & (1<<((i*ACTNUM+j)*2+1)));
					actuators[i][j].valves[0].writeDuty(
							__MY_GET_BIT(hostCommand.armCmd, bitMaskDict[targetActIn]));
					actuators[i][j].valves[1].writeDuty(
							__MY_GET_BIT(hostCommand.armCmd, bitMaskDict[targetActOut]));
				}
			}
}

void HydroUnderwaterManipulator::encodeStatus() {
	for (int i = 0; i < SEGNUM; i++) {
		for (int j = 0; j < ACTNUM; j++) {
			std::string targetActIn, targetActOut;
			targetActIn = std::string("actInValveBtn_seg_") + std::to_string(i)
					+ std::string("_act_") + std::to_string(j);
			targetActOut = std::string("actOutValveBtn_seg_")
					+ std::to_string(i) + std::string("_act_")
					+ std::to_string(j);

			__MY_SET_BIT_VAL(manipulatorStatus.armStatus,
					bitMaskDict[targetActIn],
					(actuators[i][j].valves[0].getDuty()));
			__MY_SET_BIT_VAL(manipulatorStatus.armStatus,
					bitMaskDict[targetActOut],
					(actuators[i][j].valves[1].getDuty()));

		}
	}
	__MY_SET_BIT_VAL(manipulatorStatus.armStatus,
			bitMaskDict["gripperInValveBtn"], (gripper.valves[0].getDuty()));
	__MY_SET_BIT_VAL(manipulatorStatus.armStatus,
			bitMaskDict["gripperOutValveBtn"], (gripper.valves[1].getDuty()));
	__MY_SET_BIT_VAL(manipulatorStatus.armStatus, bitMaskDict["pSourcePumpBtn"],
			(pSource.pump.status));
	__MY_SET_BIT_VAL(manipulatorStatus.armStatus, bitMaskDict["pSourceValveBtn"],
			(pSource.valve.getDuty()));
	__MY_SET_BIT_VAL(manipulatorStatus.armStatus, bitMaskDict["pSinkPumpBtn"],
			(pSink.pump.status));
	__MY_SET_BIT_VAL(manipulatorStatus.armStatus, bitMaskDict["pSinkValveBtn"],
			(pSink.valve.getDuty()));

	manipulatorStatus.pSourcePressure = pSource.pressure;
	manipulatorStatus.pSinkPressure= pSink.pressure;
}

