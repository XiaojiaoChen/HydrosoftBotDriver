/*
 * myMain.cpp
 *
 *  Created on: Aug 19, 2021
 *      Author: Xiaojiao Chen
 */

#include "myMain.h"
#include "usart.h"
#include "messages.h"
#include "CANbus.h"
#include "LED_Driver.h"
#include "ads1115.h"
#include "HydroUnderwaterManipulator.h"
#include "HydroDriveLL.h"
#include "myUsartFunction.h"
#include "cstring"
#define SEGNUM 3
#define ACTNUM 3

uint8_t actuatorInitPorts[SEGNUM][ACTNUM][2] =
    {
        {{0, 10}, {1, 11}, {2, 12}},
        {{3, 13}, {4, 14}, {5, 15}},
        {{6, 16}, {6, 16}, {6, 16}},
}; //{In, Out}

uint8_t gripperInitPort[2] = {7, 17}; //{In, Out}

uint8_t pSourceValveInitPort = 18; //in valve
uint8_t pSourcePumpInitPort = 9;  //in pump

uint8_t pSinkValveInitPort = 8; //out valve
uint8_t pSinkPumpInitPort = 19;  //out pump

uint8_t pSourceSensorInitPort = 0; //in sensor
uint8_t pSinkSensorInitPort = 1;   //out sensor

/*********** transfer in KPa, otherwise all in Pa ******************/

HydroUnderwaterManipulator uwManipulator;

void setupLoopFrequency(int16_t fre);
void setupLoop2Frequency(int16_t fre);

void setup()
{
	my_UsartInit();
  int ret = 0;
  /*PWM initiation*/
  if ((ret = LED_Driver_Setup()) != HAL_OK)
  {
  }
  /*ADC initiation*/
  if ((ret = ADS1115_Setup()) != HAL_OK)
  {
  }

  /*CAN initiation*/
  //canConfig();

  /*setup loop() frequency to be 100Hz*/
  setupLoopFrequency(100);

  /*ports mapping*/
  uwManipulator.setupActuatorPorts(actuatorInitPorts);
  uwManipulator.setupGripperPorts(gripperInitPort);
  uwManipulator.setupPsourcePorts(pSourcePumpInitPort, pSourceValveInitPort, pSourceSensorInitPort);
  uwManipulator.setupPsinkPorts(pSinkPumpInitPort, pSinkValveInitPort, pSinkSensorInitPort);
  PWMWriteFlush();
}

//100Hz default. change frequency by calling setupLoopFrequency(50);
void loop()
{
  //Get pressrue data. currently only pSource and pSink
//  uwManipulator.pSource.readPressure();
//  uwManipulator.pSink.readPressure();

  uwManipulator.control();
  // PWMTest()
  uwManipulator.encodeStatus();

  printBin((char *)(&uwManipulator.manipulatorStatus),sizeof(HydroManipulatorStatus));

}

//200Hz loop2 reserved
void loop2()
{

//	memcpy()
//	HAL_UART_Transmit_DMA()
}

/**
 * @brief callback of subscriber function to the command topic
 * 
 * @param cmd_msg 
 */
void serialCallback(char *buf){
	  memcpy(&uwManipulator.hostCommand,buf,sizeof(HydroManipulatorCommand));
}

void setupLoopFrequency(int16_t fre)
{
  extern int32_t globalSensorTaskPeriod;
  globalSensorTaskPeriod = (int)(1000 / fre);
  if (globalSensorTaskPeriod < 1)
    globalSensorTaskPeriod = 1;
}
