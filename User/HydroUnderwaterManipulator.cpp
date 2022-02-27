/*
 * SoftArm.c
 *
 *  Created on: May 12, 2018
 *      Author: 402072495
 */
#include "HydroUnderwaterManipulator.h"

#include "main.h"

#include "stdio.h"
#include "string.h"

#include "buttonMaps.h"
#include "myUsartFunction.h"

HydroUnderwaterManipulator uwManipulator;

/*************************SOFT ARM**************************
 *
 ***********************************************************/
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
			__MY_GET_BIT(hostCommand.armCmd, bitMaskDict["pSourcePumpBtn"]));
	pSource.setValve(
			__MY_GET_BIT(hostCommand.armCmd, bitMaskDict["pSourceValveBtn"]));

	pSink.setPump(
			__MY_GET_BIT(hostCommand.armCmd, bitMaskDict["pSinkPumpBtn"]));
	pSink.setValve(
			__MY_GET_BIT(hostCommand.armCmd, bitMaskDict["pSinkValveBtn"]));

	gripper.valves[0].writeDuty(
			__MY_GET_BIT(hostCommand.armCmd, bitMaskDict["gripperInValveBtn"]));
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
					__MY_GET_BIT(hostCommand.armCmd,
							bitMaskDict[targetActOut]));
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
	__MY_SET_BIT_VAL(manipulatorStatus.armStatus,
			bitMaskDict["pSourceValveBtn"], (pSource.valve.getDuty()));
	__MY_SET_BIT_VAL(manipulatorStatus.armStatus, bitMaskDict["pSinkPumpBtn"],
			(pSink.pump.status));
	__MY_SET_BIT_VAL(manipulatorStatus.armStatus, bitMaskDict["pSinkValveBtn"],
			(pSink.valve.getDuty()));

	manipulatorStatus.pSourcePressure = pSource.pressure;
	manipulatorStatus.pSinkPressure = pSink.pressure;
}

