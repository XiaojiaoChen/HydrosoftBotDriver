/*
 * myMain.cpp
 *
 *  Created on: Aug 19, 2021
 *      Author: Xiaojiao Chen
 */

#include "myMain.h"
#include "usart.h"
#include "messages.h"
#include "ros.h"
#include "CANbus.h"
#include "LED_Driver.h"
#include "ads1115.h"
#include "HydroUnderwaterManipulator.h"
#define SEGNUM 3
#define ACTNUM 4

uint8_t actuatorInitPorts[SEGNUM][ACTNUM][2] =
    {
        {{0, 1}, {2, 3}, {4, 5}, {6, 7}},
        {{8, 9}, {10, 11}, {12, 13}, {14, 15}},
        {{16, 17}, {18, 19}, {20, 21}, {22, 23}},
}; //{In, Out}

uint8_t gripperInitPort[2] = {29, 45}; //{In, Out}

uint8_t pSourcePumpInitPort = 41;   //in pump
uint8_t pSourceValveInitPort = 43;  //in valve
uint8_t pSourceSensorInitPort = 44; //in sensor

uint8_t pSinkPumpInitPort = 25;  //out pump
uint8_t pSinkValveInitPort = 27; //out valve

uint8_t pSinkSensorInitPort = 44; //out sensor

int32_t pressureUp = 30000;    //30,000Pa limit  for positive pressure
int32_t pressureDown = -30000; //-30,000Pa limit for negative pressure

/*********** transfer in KPa, otherwise all in Pa ******************/

HydroUnderwaterManipulator uwManipulator;

void setupLoopFrequency(int16_t fre);
void setupLoop2Frequency(int16_t fre);

void setup()
{

  /*peripheral initiation*/
  LED_Driver_Setup();
  ADS1115_Setup();
  canConfig();

  /*setup loop() frequency to be 100Hz*/
  setupLoopFrequency(100);

  /*ports mapping*/
  uwManipulator.setupActuatorPorts(actuatorInitPorts);
  uwManipulator.setupGripperPorts(gripperInitPort);
  uwManipulator.setupPsourcePorts(pSourcePumpInitPort, pSourceValveInitPort, pSourceSensorInitPort);
  uwManipulator.setupPsinkPorts(pSinkPumpInitPort, pSinkValveInitPort, pSinkSensorInitPort);
}

//100Hz default. change frequency by calling setupLoopFrequency(50);
void loop()
{
  //Get sensor Data. currently only pSource and pSink
  uwManipulator.pSource.readPressure();
  uwManipulator.pSink.readPressure();

  //decode command data to readable cmds
  uwManipulator.decodeCommand();

  uwManipulator.control_pSource();
  uwManipulator.control_pSink();
  uwManipulator.control_actuators();
  uwManipulator.control_gripper();

  uwManipulator.encodeStatus();

  rosserialNode.publish(&(uwManipulator.manipulatorStatus));
  rosserialNode.spinOnce();
}

//200Hz loop2 reserved
void loop2()
{
}

/**
 * @brief callback of subscriber function to the command topic
 * 
 * @param cmd_msg 
 */
void sub1Callback(const hydrosoft_ros::Command_Arm &cmd_msg)
{

  //store command data to local variable
  uwManipulator.hostCommand.controlModeCommand = cmd_msg.controlModeCommand;
  memcpy(uwManipulator.hostCommand.actuatorCommand, cmd_msg.actuatorCommand, cmd_msg.actuatorCommand_length);
  uwManipulator.hostCommand.gripperCommand = cmd_msg.gripperCommand;
  uwManipulator.hostCommand.pSourceCommand = cmd_msg.pSourceCommand;
  uwManipulator.hostCommand.pSinkCommand = cmd_msg.pSinkCommand;
}

void setupLoopFrequency(int16_t fre)
{
  extern int32_t globalSensorTaskPeriod;
  globalSensorTaskPeriod = (int)(1000 / fre);
  if (globalSensorTaskPeriod < 1)
    globalSensorTaskPeriod = 1;
}

void setupLoop2Frequency(int16_t fre)
{
  extern int32_t globalCommunicationTaskPeriod;
  globalCommunicationTaskPeriod = (int)(1000 / fre);
  if (globalCommunicationTaskPeriod < 1)
    globalCommunicationTaskPeriod = 1;
}