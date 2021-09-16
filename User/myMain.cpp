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
#include "HydroDriveLL.h"
#define SEGNUM 3
#define ACTNUM 4

uint8_t actuatorInitPorts[SEGNUM][ACTNUM][2] =
    {
        {{0, 1}, {2, 3}, {4, 5}, {6, 7}},
        {{8, 9}, {10, 11}, {12, 13}, {14, 15}},
        {{16, 17}, {16, 17}, {16,17}, {16,17}},
}; //{In, Out}

uint8_t gripperInitPort[2] = {18, 19}; //{In, Out}

uint8_t pSourceValveInitPort = 20;  //in valve
uint8_t pSourcePumpInitPort = 21;   //in pump

uint8_t pSinkValveInitPort = 22; //out valve
uint8_t pSinkPumpInitPort = 23;  //out pump

uint8_t pSourceSensorInitPort = 0; //in sensor
uint8_t pSinkSensorInitPort = 1; //out sensor

/*********** transfer in KPa, otherwise all in Pa ******************/

HydroUnderwaterManipulator uwManipulator;
extern RosserialNode rosserialNode;

void setupLoopFrequency(int16_t fre);
void setupLoop2Frequency(int16_t fre);

void setup()
{
  int ret=0;
  /*PWM initiation*/
  if((ret = LED_Driver_Setup())!=HAL_OK){
  }
  /*ADC initiation*/
  if((ret = ADS1115_Setup())!=HAL_OK){

  }
  rosserialNode.init(&huart1);

  /*CAN initiation*/
 // canConfig();

  /*setup loop() frequency to be 100Hz*/
  setupLoopFrequency(5);

  /*ports mapping*/
  uwManipulator.setupActuatorPorts(actuatorInitPorts);
  uwManipulator.setupGripperPorts(gripperInitPort);
  uwManipulator.setupPsourcePorts(pSourcePumpInitPort, pSourceValveInitPort, pSourceSensorInitPort);
  uwManipulator.setupPsinkPorts(pSinkPumpInitPort, pSinkValveInitPort, pSinkSensorInitPort);
  //PWMWriteFlush();
}



//100Hz default. change frequency by calling setupLoopFrequency(50);
void loop()
{
  //Get pressrue data. currently only pSource and pSink
//  uwManipulator.pSource.readPressure();
//  uwManipulator.pSink.readPressure();
	static uint32_t tt=0;
  uwManipulator.control();

  uwManipulator.encodeStatus();

  rosserialNode.publish(&(uwManipulator.manipulatorStatus));

  rosserialNode.spinOnce();

//  for(uint32_t i=0;i<24;i++){
//	  if(i==tt){
//		  PWMWriteDuty(i,0);
//	  }
//	  else{
//		  PWMWriteDuty(i,1);
//	  }
//  }
//  tt=(tt+1)%24;
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

