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

uint8_t gripperInitPort[2] = {24, 25}; //{In, Out}

uint8_t pSourceValveInitPort = 26;  //in valve
uint8_t pSourcePumpInitPort = 27;   //in pump

uint8_t pSinkValveInitPort = 28; //out valve
uint8_t pSinkPumpInitPort = 29;  //out pump

uint8_t pSourceSensorInitPort = 1; //in sensor
uint8_t pSinkSensorInitPort = 2; //out sensor

/*********** transfer in KPa, otherwise all in Pa ******************/

HydroUnderwaterManipulator uwManipulator;

void setupLoopFrequency(int16_t fre);
void setupLoop2Frequency(int16_t fre);

void setup()
{
  int ret=0;
  /*peripheral initiation*/
//  if((ret = LED_Driver_Setup())!=HAL_OK){
//  }
  if((ret = ADS1115_Setup())!=HAL_OK){

  }

  while(1){
	  HAL_Delay(1000);
	  ADS1115_Read(0);
  }
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
  //Get pressrue data. currently only pSource and pSink
  uwManipulator.pSource.readPressure();
  uwManipulator.pSink.readPressure();

  uwManipulator.control();

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
  for(int i=0;i < (int)cmd_msg.actuatorCommand_length;i++){
    uwManipulator.hostCommand.actuatorCommand[i] = cmd_msg.actuatorCommand[i];
  }
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

