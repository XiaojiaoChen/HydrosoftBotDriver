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


uint8_t actuatorInitPorts[SEGNUM][ACTNUM][2] =
    {
        {{2, 12}, {0, 10}, {1, 11}},
        {{5, 15}, {3, 13}, {4, 14}},
        {{16, 6}, {16, 6}, {16, 6}},
}; //{In, Out}

uint8_t gripperInitPort[2] = {17, 7}; //{In, Out}

uint8_t pSourceValveInitPort = 8; //in valve
uint8_t pSourcePumpInitPort = 19;  //in pump

uint8_t pSinkValveInitPort = 18; //out valve
uint8_t pSinkPumpInitPort = 9;  //out pump

uint8_t pSourceSensorInitPort = 1; //in sensor
uint8_t pSinkSensorInitPort = 0;   //out sensor

/*********** transfer in KPa, otherwise all in Pa ******************/

HydroUnderwaterManipulator uwManipulator;

void setupLoopFrequency(int16_t fre);
void setupLoop2Frequency(int16_t fre);

uint8_t grxBuf[12];
void setup()
{
	//my_UsartInit();
  int ret = 0;
  /*PWM initiation*/
  if ((ret = LED_Driver_Setup()) != HAL_OK)
  {
  }
  /*ADC initiation*/
//  if ((ret = ADS1115_Setup()) != HAL_OK)
//  {
//  }

  /*CAN initiation*/
  canConfig();

  /*setup loop() frequency to be 100Hz*/
  setupLoopFrequency(100);

  /*ports mapping*/
  uwManipulator.setupActuatorPorts(actuatorInitPorts);
  uwManipulator.setupGripperPorts(gripperInitPort);
  uwManipulator.setupPsourcePorts(pSourcePumpInitPort, pSourceValveInitPort, pSourceSensorInitPort);
  uwManipulator.setupPsinkPorts(pSinkPumpInitPort, pSinkValveInitPort, pSinkSensorInitPort);
  PWMWriteFlush();

}

void getRx();

//100Hz default. change frequency by calling setupLoopFrequency(50);
void loop()
{
	int readnum=HAL_UARTEx_ReceiveToIdle_DMA(&huart1, grxBuf, sizeof(HydroManipulatorCommand));
  //AD start conversion two channel with DMA

//  ADS1115_ReadUnblocked();

//  ADS1115_Read(0);
//  ADS1115_Read(1);

  //while AD dma is ongoing, we could do control stuff without using sensor info
  uwManipulator.control();

  //wait for AD complete/Timeout for following action
//  waitTrue(&gAD_complete,6);

  //Get pressrue data from AD data. currently only pSource and pSink
//  uwManipulator.pSource.readPressure();
//  uwManipulator.pSink.readPressure();

  //I2C is released now, we could send PWM command.
  PWMWriteFlush();

  //publish status to usart 1 DMA
  uwManipulator.encodeStatus();
  HAL_UART_Transmit_DMA(&huart1,(uint8_t *)(&uwManipulator.manipulatorStatus),sizeof(HydroManipulatorStatus));

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
void serialCallback(){
	  memcpy(&uwManipulator.hostCommand,grxBuf,sizeof(HydroManipulatorCommand));
}

void setupLoopFrequency(int16_t fre)
{
  extern int32_t globalSensorTaskPeriod;
  globalSensorTaskPeriod = (int)(1000 / fre);
  if (globalSensorTaskPeriod < 1)
    globalSensorTaskPeriod = 1;
}
