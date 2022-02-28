/*
 * myMain.cpp
 *
 *  Created on: Aug 19, 2021
 *      Author: Xiaojiao Chen
 */

#include "myMain.h"
#include "canbus_if.h"
#include "main.h"
#include "cstring"
#include "HydroDriveLL.h"
#include "HydroUnderwaterManipulator.h"
#include "LED_Driver.h"
#include "myUsartFunction.h"


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


uint8_t grxBuf[12];
void setup()
{

  /*PWM initiation*/
  LED_Driver_Setup();

  /*CAN initiation*/
  FDCAN_Config();

  /*ports mapping*/
  uwManipulator.setupActuatorPorts(actuatorInitPorts);
  uwManipulator.setupGripperPorts(gripperInitPort);
  uwManipulator.setupPsourcePorts(pSourcePumpInitPort, pSourceValveInitPort, pSourceSensorInitPort);
  uwManipulator.setupPsinkPorts(pSinkPumpInitPort, pSinkValveInitPort, pSinkSensorInitPort);
  PWMWriteFlush();

}

//100Hz
void loop()
{
	HAL_UARTEx_ReceiveToIdle_DMA(&huart1, grxBuf, sizeof(HydroManipulatorCommand));

 //uwManipulator.control();
for(int i=0;i<24;i++)
   PWMWriteDuty(0, 0.5);

  //I2C is released now, we could send PWM command.
  PWMWriteFlush();

  //publish status to usart 1 DMA
  uwManipulator.encodeStatus();

  HAL_UART_Transmit_DMA(&huart1,(uint8_t *)(&uwManipulator.manipulatorStatus),sizeof(HydroManipulatorStatus));

}

//10Hz loop2 reserved
void loop2()
{


}

void serialCallback(){
	  memcpy(&uwManipulator.hostCommand,grxBuf,sizeof(HydroManipulatorCommand));
}

