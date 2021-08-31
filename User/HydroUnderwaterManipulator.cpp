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

void HydroUnderwaterManipulator::control_pSource()
{
	if (hostCommand.controlMode == OpeningControlMode)
	{
		//pumpIn = on and vavleIn = On, watch out the sequency
		if (hostCommand.openingCmd_pSource_pump && hostCommand.openingCmd_pSource_valve)
		{
			pSource.openValve();
			pSource.startPump();
		}

		//pumpIn = off and vavleIn = Off;
		else if ((!hostCommand.openingCmd_pSource_pump) && (!hostCommand.openingCmd_pSource_valve))
		{
			pSource.stopPump();
			pSource.closeValve();
		}
		else if ((hostCommand.openingCmd_pSource_pump) && (!hostCommand.openingCmd_pSource_valve))
		{
			pSource.startPump();
			pSource.closeValve();
		}
		else
		{
			pSource.openValve();
			pSource.stopPump();
		}
	}
	else if (hostCommand.controlMode == PressureControlMode)
	{
		pSource.maintainPressure(hostCommand.pressureCmd_pSource);
	}
}
void HydroUnderwaterManipulator::control_pSink()
{
	if (hostCommand.controlMode == OpeningControlMode)
	{
		//pumpIn = on and vavleIn = On, watch out the sequency
		if (hostCommand.openingCmd_pSink_pump && hostCommand.openingCmd_pSink_valve)
		{
			pSink.openValve();
			pSink.startPump();
		}

		//pumpIn = off and vavleIn = Off;
		else if ((!hostCommand.openingCmd_pSink_pump) && (!hostCommand.openingCmd_pSink_valve))
		{
			pSink.stopPump();
			pSink.closeValve();
		}
		else if ((hostCommand.openingCmd_pSink_pump) && (!hostCommand.openingCmd_pSink_valve))
		{
			pSink.startPump();
			pSink.closeValve();
		}
		else
		{
			pSink.openValve();
			pSink.stopPump();
		}
	}
	else if (hostCommand.controlMode == PressureControlMode)
	{
		pSink.maintainPressure(hostCommand.pressureCmd_pSink);
	}
}

void HydroUnderwaterManipulator::control_gripper()
{
	// if (hostCommand.controlMode == OpeningControlMode)
	// {
	gripper.valves[0].writeDuty(hostCommand.openingCmd_gripper[0]);
	gripper.valves[1].writeDuty(hostCommand.openingCmd_gripper[1]);
	// }
	// else if (hostCommand.controlMode == PressureControlMode)
	// {
	// }
}

void HydroUnderwaterManipulator::control_actuators()
{
	for (int i = 0; i < SEGNUM; i++)
	{
		for (int j = 0; j < ACTNUM; j++)
		{
			//if (hostCommand.controlMode == OpeningControlMode)
			//{
			actuators[i][j].valves[0].writeDuty(hostCommand.openingCmd_actuators[i][j][0]);
			actuators[i][j].valves[1].writeDuty(hostCommand.openingCmd_actuators[i][j][1]);
			//}
			// else
			// {
			// 	hostCommand.pressureCmd_actuators[SEGNUM][ACTNUM] = hostCommand.actuatorCommand[(i * ACTNUM + j)];
			// }
		}
	}
}

void HydroUnderwaterManipulator::decodeCommand()
{

	hostCommand.controlMode = __GET_BIT(hostCommand.controlModeCommand, PRESSURE_CONTROL_MASK);

	//decode actuator command, no implementation of pressure control yet
	for (int i = 0; i < SEGNUM; i++)
	{
		for (int j = 0; j < ACTNUM; j++)
		{
			//if (hostCommand.controlMode == OpeningControlMode)
			//{
			hostCommand.openingCmd_actuators[SEGNUM][ACTNUM][0] = __GET_BIT(hostCommand.actuatorCommand[i * ACTNUM + j], ACTUATOR_IN_VALVE_MASK);
			hostCommand.openingCmd_actuators[SEGNUM][ACTNUM][1] = __GET_BIT(hostCommand.actuatorCommand[i * ACTNUM + j], ACTUATOR_OUT_VALVE_MASK);
			//}
			// else
			// {
			// 	hostCommand.pressureCmd_actuators[SEGNUM][ACTNUM] = hostCommand.actuatorCommand[(i * ACTNUM + j)];
			// }
		}
	}

	//decode gripper command, no implementation of pressure control yet
	//if (hostCommand.controlMode == OpeningControlMode)
	//{
	hostCommand.openingCmd_gripper[0] = __GET_BIT(hostCommand.gripperCommand, GRIPPER_IN_VALVE_MASK);
	hostCommand.openingCmd_gripper[1] = __GET_BIT(hostCommand.gripperCommand, GRIPPER_OUT_VALVE_MASK);
	//}
	// else
	// {
	// 	hostCommand.pressureCmd_gripper = hostCommand.gripperCommand;
	// }

	//decode pSource command
	if (hostCommand.controlMode == OpeningControlMode)
	{
		hostCommand.openingCmd_pSource_pump = __GET_BIT(hostCommand.pSourceCommand, PSOURCE_IN_PUMP_MASK);
		hostCommand.openingCmd_pSource_valve = __GET_BIT(hostCommand.pSourceCommand, PSOURCE_IN_VALVE_MASK);
	}
	else
	{
		hostCommand.pressureCmd_pSource = hostCommand.pSourceCommand;
	}

	//decode pSink command
	if (hostCommand.controlMode == OpeningControlMode)
	{
		hostCommand.openingCmd_pSink_pump = __GET_BIT(hostCommand.pSinkCommand, PSINK_OUT_PUMP_MASK);
		hostCommand.openingCmd_pSink_valve = __GET_BIT(hostCommand.pSinkCommand, PSINK_OUT_VALVE_MASK);
	}
	else
	{
		hostCommand.pressureCmd_pSink = hostCommand.pSinkCommand;
	}
}

void HydroUnderwaterManipulator::encodeStatus()
{
	manipulatorStatus.controlModeStatus = hostCommand.controlMode;

	//decode actuator command, no implementation of pressure control yet
	for (int i = 0; i < SEGNUM; i++)
	{
		for (int j = 0; j < ACTNUM; j++)
		{
			//if (hostCommand.controlMode == OpeningControlMode)
			//{
			manipulatorStatus.actuatorStatusBuf[i][j] = (((actuators[i][j].valves[0].getDuty() != 0) << 1) | (actuators[i][j].valves[1].getDuty() != 0));
			//}
			// else
			// {
			//	manipulatorStatus.actuatorStatus[i*ACTNUM+j] = actuators[i][j].pressure;
			// }
		}
	}

	//decode gripper command, no implementation of pressure control yet
	//if (hostCommand.controlMode == OpeningControlMode)
	//{
	manipulatorStatus.gripperStatus = (((gripper.valves[0].getDuty() != 0) << 1) | (gripper.valves[1].getDuty() != 0));
	//}
	// else
	// {
	// 	manipulatorStatus.gripperStatus =    gripper.pressure;
	// }

	//decode pSource command
	if (hostCommand.controlMode == OpeningControlMode)
	{
		manipulatorStatus.pSourceStatus = (((pSource.pump.status != 0) << 1) | (pSource.valve.getDuty() != 0));
	}
	else
	{
		hostCommand.pressureCmd_pSource = pSource.pressure;
	}

	//decode pSink command
	if (hostCommand.controlMode == OpeningControlMode)
	{
		manipulatorStatus.pSinkStatus = (((pSink.pump.status != 0) << 1) | (pSink.valve.getDuty() != 0));
	}
	else
	{
		hostCommand.pressureCmd_pSink = pSink.pressure;
	}
}

void HydroUnderwaterManipulator::execInfoCommand(char *infoBuf)
{
	if (infoBuf[0] == 'z')
	{
	}
	if (infoBuf[0] == 'o')
	{
	}
}
