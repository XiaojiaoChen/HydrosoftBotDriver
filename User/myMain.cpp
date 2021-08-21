/*
 * myMain.cpp
 *
 *  Created on: Aug 19, 2021
 *      Author: Xiaojiao Chen
 */

#include "myMain.h"
#include "messages.h"
#include "ros.h"
#include "CANbus.h"
#include "LED_Driver.h"
#include "ads1115.h"
#include "HydroUnderwaterManipulator.h"
#define ACTNUM 4
#define ACTALLNUM 8

#define MANNUALMASK (0x0001)
#define PUMPOUTMASK (0x0002)
#define PUMPINMASK (0x0004)
#define VALVEOUTMASK (0x0008)
#define VALVEINMASK (0x0010)
#define PUMPINVALVEMASK (0x0020)
#define PUMPOUTVALVEMASK (0x0040)

#define __SET_BIT(__VALUE__, __BITMASK__) ((__VALUE__) |= (__BITMASK__))
#define __RESET_BIT(__VALUE__, __BITMASK__) ((__VALUE__) &= ~(__BITMASK__))
#define __TOGGLE_BIT(__VALUE__, __BITMASK__) ((__VALUE__) ^= (__BITMASK__))
#define __GET_BIT(__VALUE__, __BITMASK__) (((__VALUE__) & (__BITMASK__)) != 0)

uint8_t valveControlPorts[2 * ACTALLNUM] =
    // Act1      Act2       Act3      Act4
    //In,Out,   In,Out,   In,Out,   In,Out,
    {
        0, 1, 2, 3, 4, 5, 6, 7, //Seg 1  (Root segment)
        8, 9, 10, 11, 12, 13, 14, 15  //Seg 2y
};
uint8_t PumpInControlPorts = 41;
uint8_t PumpInValveControlPorts = 43;

uint8_t PumpOutControlPorts =  25;
uint8_t PumpOutValveControlPorts = 27;

uint8_t gripperControlPorts[2] = {
    // gripperIn      gripperOut
    29, 45};

uint8_t PumpSensorPorts[2] = {
    // PumpHigh      PumpLow
    54, 55}; //A0 A1


class CommandTypeDef
{
public:
  uint16_t mannual_control; //0:auto control   1: mannual control
  uint16_t pumpIn;          //0:Force Off    1:Force On    ,only effecive when mannual_control==1;
  uint16_t pumpOut;         //0:Force Off    1:Force On  ,only effecive when mannual_control==1;
  uint16_t valveIn;         //0:Force Close    1:Force Open  ,only effecive when mannual_control==1;
  uint16_t valveOut;        //0:Force Close    1:Force Open  ,only effecive when mannual_control==1;
  uint16_t pumpInValve;
  uint16_t pumpOutValve;
  int16_t gripper;
};
CommandTypeDef host_command;


int32_t pressureUp = 30000;   //30,000Pa limit  for positive pressure
int32_t pressureDown =  -30000; //-30,000Pa limit for negative pressure

/*********** transfer in KPa, otherwise all in Pa ******************/

/*********** in Pa ******************/
int16_t sensorActuatorBuffer[ACTALLNUM]; //sensor buffer in KPa to store the sensor message
int16_t commandActuator[ACTALLNUM]; //translated command in Pa

int32_t globalSensorTaskPeriod = 10;      //10 ms period for loop()  (100Hz)
int32_t globalCommunicationTaskPeriod = 5;     //5 ms period for loop2()  (200Hz)


HydroUnderwaterManipulator uwManipulator;

void setup(){

	LED_Driver_Setup();
	ADS1115_Setup();

	canConfig();

	/*soft arm Valves' port mapping*/
	uwManipulator.setupValvePorts(valveControlPorts);

	/*soft arm Valves' port mapping*/
	uwManipulator.setupGripperPorts(gripperControlPorts[0], gripperControlPorts[1]);

	/*soft arm Pumps' port mapping*/
	uwManipulator.setupPumpPorts(PumpInControlPorts, PumpInValveControlPorts, PumpSensorPorts[0], PumpOutControlPorts, PumpOutValveControlPorts, PumpSensorPorts[1]);

	/*setup buffer pointer and length*/
	rosserialNode.sensor_msg.actuator = sensorActuatorBuffer;
	rosserialNode.sensor_msg.actuator_length = ACTALLNUM;

}


/***********Only transfer in KPa, otherwise all in Pa ******************/
void loop()
{
  //automatic switch. Press g to start and press s to stop.
  if (!host_command.mannual_control)
  {
    /*Maintain the up and down pressure from Host command*/
    //uwManipulator.maintainUpPressure(pressureUp, pressureUp + 10000);
    //uwManipulator.maintainDownPressure(pressureDown - 10000, pressureDown);
    if (pressureUp)
    {
      uwManipulator.pSource.openValve();
      uwManipulator.pSource.start(); /*soft arm Pumps' port mapping*/
    }
    else
    {
      uwManipulator.pSource.stop();
      uwManipulator.pSource.closeValve();
    }

    if (pressureDown)
    {
      uwManipulator.pSink.openValve();
      uwManipulator.pSink.start();
    }
    else
    {
      uwManipulator.pSink.stop();
      uwManipulator.pSink.closeValve();
    }

    /*If actuators have sensors*/
    //uwManipulator.readPressureAll();

    //uwManipulator.writePressureAll(commandActuator);
     uwManipulator.writeOpeningAll(commandActuator);
  }
  else
  {
    if (host_command.pumpIn)
    {
      uwManipulator.startPumpIn();
    }
    else
    {
      uwManipulator.stopPumpIn();
    }

    if (host_command.pumpOut)
    {
      uwManipulator.startPumpOut();
    }
    else
    {
      uwManipulator.stopPumpOut();
    }

    if (host_command.pumpInValve)
    {
      uwManipulator.pSource.openValve();
    }
    else
    {
      uwManipulator.pSource.closeValve();
    }

    if (host_command.pumpOutValve)
    {
      uwManipulator.pSink.openValve();
    }
    else
    {
      uwManipulator.pSink.closeValve();
    }

    //
    if ((!host_command.valveIn) && (!host_command.valveOut))
    {
      uwManipulator.writeOpening(0);
    }
    else if ((!host_command.valveIn) && (host_command.valveOut))
    {
      uwManipulator.writeOpening(-1);
    }
    else if ((host_command.valveIn) && (!host_command.valveOut))
    {
      uwManipulator.writeOpening(1);
    }
    else if ((host_command.valveIn) && (host_command.valveOut))
    {
      uwManipulator.writeOpening(2);
    }
  }

  uwManipulator.gripper.writeOpening(host_command.gripper);

  /*Filling the pump message, in KPa*/
  rosserialNode.sensor_msg.pumpIn = uwManipulator.pSource.pump.status;
  rosserialNode.sensor_msg.pumpOut = uwManipulator.pSink.pump.status;
  rosserialNode.sensor_msg.gripper = uwManipulator.gripper.opening;
  /*Filling the valve message, in [-1, 0, 1]*/
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 4; j++)
    {
    	rosserialNode.sensor_msg.actuator[4 * i + j] = (int16_t)(uwManipulator.actuators[i][j].opening);
    }
  }
  rosserialNode.publisher1.publish(&rosserialNode.sensor_msg);

  rosserialNode.spinOnce();
}



//200Hz loop2
void loop2(){

}

void sub1Callback(const hydrosoft_ros::Command_Arm &cmd_msg)
{
	 // for (int i = 0; i < ACTALLNUM; i++)
	  // {
	  //   commandActuator[i] = ((int32_t)cmd_msg.actuator[i]) * 1000;
	  // }
	  // pressureUp = ((int32_t)cmd_msg.pumpIn) * 1000;    //transfer in KPa, local in Pa
	  // pressureDown = ((int32_t)cmd_msg.pumpOut) * 1000; //transfer in KPa, local In Pa
	  for (int i = 0; i < ACTALLNUM; i++)
	  {
		commandActuator[i] = cmd_msg.actuator[i];
	  }
	  pressureUp = (cmd_msg.pumpIn);
	  pressureDown = (cmd_msg.pumpOut);
	  host_command.mannual_control = __GET_BIT(cmd_msg.cmd, MANNUALMASK);
	  host_command.pumpIn = __GET_BIT(cmd_msg.cmd, PUMPINMASK);
	  host_command.pumpOut = __GET_BIT(cmd_msg.cmd, PUMPOUTMASK);
	  host_command.valveIn = __GET_BIT(cmd_msg.cmd, VALVEINMASK);
	  host_command.valveOut = __GET_BIT(cmd_msg.cmd, VALVEOUTMASK);
	  host_command.pumpInValve = __GET_BIT(cmd_msg.cmd, PUMPINVALVEMASK);
	  host_command.pumpOutValve = __GET_BIT(cmd_msg.cmd, PUMPOUTVALVEMASK);
	  host_command.gripper = cmd_msg.gripper;
}






