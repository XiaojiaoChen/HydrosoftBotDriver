/*
 * myMain.cpp
 *
 *  Created on: Aug 19, 2021
 *      Author: Xiaojiao Chen
 */

#include "myMain.h"
#include "usart.h"
#include "CANbus.h"
#include "LED_Driver.h"
#include "ads1115.h"
#include "HydroUnderwaterManipulator.h"
#include "HydroDriveLL.h"
#include "myUsartFunction.h"
#include "cstring"



uint8_t actuatorInitPorts[SEGNUM][ACTNUM][2] =
    {
        {{0, 9}, {1, 10}, {2, 11}},
        {{3, 12}, {4, 13}, {5, 14}},
        {{6, 15}, {6,15}, {6,15}},//ATTENTION!!! currently, port 6 and 7 are related and commanded together!!!!!!!!!!!!!!!!!!1
}; //{In, Out}

//uint8_t gripperInitPort[2] = {8, 17}; //{In, Out}

//uint8_t pSourceValveInitPort = 9; //in valve
uint8_t pSourcePumpInitPort = 8;  //in pump

//uint8_t pSinkValveInitPort = 18; //out valve
uint8_t pSinkPumpInitPort = 17;  //out pump

//uint8_t pSourceSensorInitPort = 1; //in sensor
//uint8_t pSinkSensorInitPort = 0;   //out sensor

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
 // canConfig();

  /*setup loop() frequency to be 100Hz*/
  setupLoopFrequency(20);

  /*ports mapping*/
  uwManipulator.setupActuatorPorts(actuatorInitPorts);
//  uwManipulator.setupGripperPorts(gripperInitPort);
  uwManipulator.setupPsourcePorts(pSourcePumpInitPort);
  uwManipulator.setupPsinkPorts(pSinkPumpInitPort);
  PWMWriteFlush();

}

void getRx();

//100Hz default. change frequency by calling setupLoopFrequency(50);
void loop()
{
	HAL_UARTEx_ReceiveToIdle_DMA(&huart1, grxBuf, sizeof(HydroManipulatorCommand));
  //AD start conversion two channel with DMA

//  ADS1115_ReadUnblocked();

//  ADS1115_Read(0);
//  ADS1115_Read(1);

  //while AD dma is ongoing, we could do control stuff without using sensor info
  uwManipulator.control();
  //uwManipulator.controlTest();

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
