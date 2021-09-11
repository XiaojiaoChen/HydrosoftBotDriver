/*
 * SoftArm.c
 *
 *  Created on: May 12, 2018
 *      Author: 402072495
 */
#include "HydroUnderwaterManipulator.h"

#include "main.h"

/*************************SOFT ARM**************************
 *
 ***********************************************************/
HydroUnderwaterManipulator::HydroUnderwaterManipulator() : pSource(0, 0, HIGH_PRESSURE_SOURCE),
														   pSink(0, 0, LOW_PRESSURE_SINK)
{
}

void HydroUnderwaterManipulator::setupActuatorPorts(uint8_t (&ports)[SEGNUM][ACTNUM][2])
{
	/*Every actuator is refered to with two numbers, segNum(0-3) and bellowNum(0-3)*/

	for (int i = 0; i < SEGNUM; i++)
	{
		for (int j = 0; j < ACTNUM; j++)
		{
			actuators[i][j].attachPWM(ports[i][j][0], ports[i][j][1]);
			actuators[i][j].writeOpening(0);
		}
	}

}
void HydroUnderwaterManipulator::setupGripperPorts(uint8_t (&ports)[2])
{
	gripper.attachPWM(ports[0], ports[1]);
	gripper.writeOpening(0);

}
void HydroUnderwaterManipulator::setupPsourcePorts(uint8_t pumpPort, uint8_t valvePort, uint8_t sensorPort)
{
	pSource.attach(pumpPort, valvePort, sensorPort);
}
void HydroUnderwaterManipulator::setupPsinkPorts(uint8_t pumpPort, uint8_t valvePort, uint8_t sensorPort)
{
	pSink.attach(pumpPort, valvePort, sensorPort);
}



void HydroUnderwaterManipulator::control(){

	pSource.setPump(__GET_BIT(hostCommand.pSourceCommand, PSOURCE_IN_PUMP_MASK));
	pSource.setValve(__GET_BIT(hostCommand.pSourceCommand, PSOURCE_IN_VALVE_MASK));

	pSink.setPump(__GET_BIT(hostCommand.pSinkCommand, PSINK_OUT_PUMP_MASK));
	pSink.setValve(__GET_BIT(hostCommand.pSinkCommand, PSINK_OUT_VALVE_MASK));

	gripper.valves[0].writeDuty(__GET_BIT(hostCommand.gripperCommand, GRIPPER_IN_VALVE_MASK));
	gripper.valves[1].writeDuty(__GET_BIT(hostCommand.gripperCommand, GRIPPER_OUT_VALVE_MASK));

	for (int i = 0; i < SEGNUM; i++)
	{
		for (int j = 0; j < ACTNUM; j++)
		{
			actuators[i][j].valves[0].writeDuty(__GET_BIT(hostCommand.actuatorCommand[i * ACTNUM + j], ACTUATOR_IN_VALVE_MASK));
			actuators[i][j].valves[1].writeDuty(__GET_BIT(hostCommand.actuatorCommand[i * ACTNUM + j], ACTUATOR_OUT_VALVE_MASK));
		}
	}
}


void HydroUnderwaterManipulator::encodeStatus()
{
	for (int i = 0; i < SEGNUM; i++)
	{
		for (int j = 0; j < ACTNUM; j++)
		{
			manipulatorStatus.actuatorStatusBuf[i][j] = (((actuators[i][j].valves[0].getDuty() != 0) << 1) | (actuators[i][j].valves[1].getDuty() != 0));
		}
	}
	manipulatorStatus.gripperStatus = (((gripper.valves[0].getDuty() != 0) << 1) | (gripper.valves[1].getDuty() != 0));
	manipulatorStatus.pSourceStatus =pSource.pressure;
	manipulatorStatus.pSinkStatus = pSink.pressure;

}
