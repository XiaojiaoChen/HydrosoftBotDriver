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
HydroUnderwaterManipulator::HydroUnderwaterManipulator():
pSource(0,0,HIGH_PRESSURE_SOURCE),
pSink(0,0,LOW_PRESSURE_SINK)
{
}

void HydroUnderwaterManipulator::setupValvePorts(uint8_t *ports)
{
	/*Every actuator is refered to with two numbers, segNum(0-3) and bellowNum(0-3)*/

	for (int j = 0; j < SEGNUM; j++)
	{
		for (int i = 0; i < ACTNUM; i++)
		{
			actuators[j][i].attachPWM(ports[2*(j*ACTNUM+i)+0],ports[2*(j*ACTNUM+i)+1]);
			actuators[j][i].writeOpening(0);
		}
	}
}
void HydroUnderwaterManipulator::setupGripperPorts(uint8_t cp1,uint8_t cp2)
{
	gripper.attachPWM(cp1,cp2);
	gripper.writeOpening(0);
}
void HydroUnderwaterManipulator::setupPumpPorts(uint8_t cp1,uint8_t vp1,uint8_t sp1, uint8_t cp2, uint8_t vp2,uint8_t sp2)
{
	pSource.attach(cp1, vp1,sp1);
	pSink.attach(cp2,vp2, sp2);
}

void HydroUnderwaterManipulator::maintainUpPressure(int32_t posP, int32_t posP2)
{
	pSource.maintainPressure(posP, posP2);
}
void HydroUnderwaterManipulator::maintainDownPressure(int32_t negP, int32_t negP2)
{
	pSink.maintainPressure(negP, negP2);
}

void HydroUnderwaterManipulator::readPressureAll()
{
	for (int j = 0; j < SEGNUM; j++)
	{
		for (int i = 0; i < ACTNUM; i++)
		{
			actuators[j][i].readPressure();
		}
	}
}

void HydroUnderwaterManipulator::zeroPressureAll()
{
	for (int j = 0; j < SEGNUM; j++)
	{
		for (int i = 0; i < ACTNUM; i++)
		{
			actuators[j][i].zeroPressure();
		}
	}
}

void HydroUnderwaterManipulator::writePressureAll(int32_t *pCommand)
{
	for (int j = 0; j < SEGNUM; j++)
	{
		for (int i = 0; i < ACTNUM; i++)
		{
			actuators[j][i].writePressure(pCommand[j*ACTNUM+i]);
		}
	}
}

void HydroUnderwaterManipulator::writeOpening(int16_t op)
{

	for (int j = 0; j < SEGNUM; j++)
	{
		for (int i = 0; i < ACTNUM; i++)
		{
			actuators[j][i].writeOpening(op);
		}
	}
}

void HydroUnderwaterManipulator::writeOpeningAll(int16_t *op)
{

	for (int j = 0; j < SEGNUM; j++)
	{
		for (int i = 0; i < ACTNUM; i++)
		{
			actuators[j][i].writeOpening(op[j*ACTNUM+i]);
		}
	}
}

void HydroUnderwaterManipulator::startPumpIn()
{
	pSource.start();
}
void HydroUnderwaterManipulator::stopPumpIn()
{
	pSource.stop();
}
void HydroUnderwaterManipulator::startPumpOut()
{
	pSink.start();
}
void HydroUnderwaterManipulator::stopPumpOut()
{
	pSink.stop();
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
