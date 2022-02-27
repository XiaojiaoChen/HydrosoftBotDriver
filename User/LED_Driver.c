/*
 * LED_Driver.c
 *
 *  Created on: 2021年7月21日
 *      Author: SHEN Zhong
 */

#include "LED_Driver.h"
extern I2C_HandleTypeDef hi2c2;

static uint8_t channelAddress[LED_CHANNEL_NUM]={
		OUT0_COLOR_ADDR,OUT1_COLOR_ADDR,OUT2_COLOR_ADDR,OUT3_COLOR_ADDR,
		OUT4_COLOR_ADDR,OUT5_COLOR_ADDR,OUT6_COLOR_ADDR,OUT7_COLOR_ADDR,
		OUT8_COLOR_ADDR,OUT9_COLOR_ADDR,OUT10_COLOR_ADDR,OUT11_COLOR_ADDR,
		OUT12_COLOR_ADDR,OUT13_COLOR_ADDR,OUT14_COLOR_ADDR,OUT15_COLOR_ADDR,
		OUT16_COLOR_ADDR,OUT17_COLOR_ADDR,OUT18_COLOR_ADDR,OUT19_COLOR_ADDR,
		OUT20_COLOR_ADDR,OUT21_COLOR_ADDR,OUT22_COLOR_ADDR,OUT23_COLOR_ADDR
};

/* LP5024 Initialization
 * Linear scale mode
 * Automatic power saving mode
 * Automatic increment mode
 * PWM dithering mode
 * Output maximum current 25.5mA */
int LED_Driver_Setup()
{
	uint8_t txBuf[1];
	int ret = HAL_OK;

	txBuf[0] = DEVICE_CONFIG0_CHIP_EN;
	if((ret = HAL_I2C_Mem_Write(&hi2c2,LED_DRIVER_ADDR, DEVICE_CONFIG0_ADDR, I2C_MEMADD_SIZE_8BIT, txBuf,1,100))!=HAL_OK){
	}

	HAL_Delay(5);

	txBuf[0] = DEVICE_CONFIG1_POWER_SAVE_EN | DEVICE_CONFIG1_AUTO_INCR_EN | DEVICE_CONFIG1_PWM_DITHERING_EN | DEVICE_CONFIG1_MAX_CURRENT_OPTION;
	if((ret = HAL_I2C_Mem_Write(&hi2c2,LED_DRIVER_ADDR, DEVICE_CONFIG1_ADDR, I2C_MEMADD_SIZE_8BIT, txBuf,1,100))!=HAL_OK){
	}

	return ret;
}

void LED_Driver_SetPWM_One(uint16_t channel, uint8_t dutyCycle)
{
	HAL_I2C_Mem_Write(&hi2c2,LED_DRIVER_ADDR, channelAddress[channel],I2C_MEMADD_SIZE_8BIT,&dutyCycle , 1,1);
}

void LED_Driver_SetPWM_Multi(uint8_t startChannel, uint8_t numofChannels, uint8_t dutyCycles[])
{
	HAL_I2C_Mem_Write(&hi2c2,LED_DRIVER_ADDR, channelAddress[startChannel],I2C_MEMADD_SIZE_8BIT,dutyCycles , numofChannels,10);
}

uint8_t LED_Driver_GetPWM_One(uint16_t channel)
{
	uint8_t dutyCycle=0;
	HAL_I2C_Mem_Read(&hi2c2,LED_DRIVER_ADDR, channelAddress[channel],I2C_MEMADD_SIZE_8BIT,&dutyCycle , 1,10);
	return dutyCycle;
}

void LED_Driver_GetPWM_Multi(uint8_t startChannel, uint8_t numofChannels, uint8_t dutyCycles[])
{
	HAL_I2C_Mem_Read(&hi2c2,LED_DRIVER_ADDR, channelAddress[startChannel],I2C_MEMADD_SIZE_8BIT,dutyCycles , numofChannels,10);
}
