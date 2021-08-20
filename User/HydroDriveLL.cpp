/*
 * HydroDriveLL.c
 *
 *  Created on: Aug 20, 2021
 *      Author: 402072495
 */
#include <HydroDriveLL.h>
#include "ads1115.h"
#include "LED_Driver.h"
//extern TIM_HandleTypeDef htim5;

static int16_t adRawData=0;
float adVoltage=0;


float AnalogRead(uint16_t num)
{
	adRawData = ADS1115_Read(num);
	adVoltage = (float)(adRawData)/32767.0f*5.0f;     //raw data to voltage
	return adVoltage;
}


void DigitalWrite(uint16_t num, uint16_t state)
{

}

void PWMWriteDuty(uint16_t num, float fduty)
{
	fduty = fduty<0 ? 0 : ( fduty>1?1:fduty);
	uint8_t cycleduty = fduty*255;
	LED_Driver_SetPWM_One(num,cycleduty);

}

void PWMWriteFrequency(uint16_t num, float fre)
{

}








/*-------------------Delay Function needs modification--------------------------------*/



//uint32_t millis()
//{
//	return HAL_GetTick();
//}
//
//uint32_t micros()
//{
//	uint32_t t=(millis()*1000) + htim5.Instance->CNT;
//	return t;
//}
//
//void delay_us(int32_t t)  //1MHz 1us
//{
//	uint32_t ts=micros();
//	while((int32_t)(micros()-ts)<t);
//}
//void delay_ns(int32_t t)  ////20MHz 50ns
//{
//	__HAL_TIM_ENABLE(&htim7);
//   while((int32_t)(htim7.Instance->CNT)<t);
//   __HAL_TIM_DISABLE(&htim7);
//   htim7.Instance->CNT=0;
//
//}
