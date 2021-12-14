/*
 * ads1115.c
 *
 *  Created on: 2021年7月22日
 *      Author: SHEN Zhong
 */
#include "main.h"
#include "ads1115.h"
#include "i2c.h"

int16_t gAD_data[2];
int gAD_curIndex = 0;
int gAD_flag = 0;
int gAD_complete = 1;
static uint8_t txBuf[2][2];
static uint8_t rxBuf[2];

/* ADS115 setup function
 * RDY is connected to PA15
 * AIN0, AIN1, AIN2, AIN3 are connected to Vout1_H, Vout1_L, Vout2_H, Vout2_L respectively
 * Full scale range is set to +-4.096V
 * Sample rate is 250SPS
 * Single-shot mode
 * Conversion Ready pi enabled (MSB of Lo_thresh is 0 and MSB of Hi_thresh is 1)
 */

int waitTrue(int *waitingflag, uint32_t Timeout) {
	uint32_t Tickstart = HAL_GetTick();
	while ((*waitingflag) == 0) {
		/* Check for the Timeout */
		if (((HAL_GetTick() - Tickstart) > Timeout) || (Timeout == 0U)) {
			return HAL_TIMEOUT;
		}
	}
	return HAL_OK;
}

int ADS1115_Setup(void) {
	int ret = HAL_OK;
	uint8_t txb[2]={0,0};
	uint8_t rxb[2]={0,0};
	txb[0] = (CONFIG_PGA_0 | CONFIG_MODE) >> 8;			//Single-shot mode
	txb[1] = CONFIG_DR_2 | CONFIG_DR_1;
	if ((ret = HAL_I2C_Mem_Write(&hi2c2, ADS1115_ADDR, CONFIG_ADDR,
			I2C_MEMADD_SIZE_8BIT, txb, 2, 100)) != HAL_OK) {

	}

	txb[0] = 0x0;									//Set MSB of Lo_thresh to 0
	txb[1] = 0x0;
	if ((ret = HAL_I2C_Mem_Write(&hi2c2, ADS1115_ADDR, LO_THRESH_ADDR,
			I2C_MEMADD_SIZE_8BIT, txb, 2, 100)) != HAL_OK) {

	}

	txb[0] = 0xFF;								//Set MSB of Hi_thresh to 1
	txb[1] = 0xFF;
	if ((ret = HAL_I2C_Mem_Write(&hi2c2, ADS1115_ADDR, HI_THRESH_ADDR,
			I2C_MEMADD_SIZE_8BIT, txb, 2, 100)) != HAL_OK) {

	}

	HAL_Delay(10);

	//read register status
	if ((ret = HAL_I2C_Mem_Read(&hi2c2, ADS1115_ADDR, CONFIG_ADDR,
				I2C_MEMADD_SIZE_8BIT, rxb, 2, 10)) != HAL_OK) {
	}

	txBuf[0][0] = rxb[0];
	txBuf[0][0] |= CONFIG_OS >> 8;	//Set OS pin to 1 to start a conversion
	txBuf[0][0] &= ~(CONFIG_MUX_0 >> 8);//Set MUX to 000 (AIN_p = AIN0, AIN_n = AIN1)
	txBuf[0][0] &= ~(CONFIG_MUX_1 >> 8);
	txBuf[0][0] &= ~(CONFIG_MUX_2 >> 8);
	txBuf[0][1] = rxb[1];

	txBuf[1][0] = rxb[0];
	txBuf[1][0] |= CONFIG_OS >> 8;	//Set OS pin to 1 to start a conversion
	txBuf[1][0] |= CONFIG_MUX_0 >> 8;//Set MUX to 011 (AIN_p = AIN2, AIN_n = AIN3)
	txBuf[1][0] |= CONFIG_MUX_1 >> 8;
	txBuf[1][0] &= ~(CONFIG_MUX_2 >> 8);
	txBuf[1][1] = rxb[1];

	return ret;
}

int16_t ADS1115_Read(int num) {
	int ret = HAL_OK;

	//Read the setting of current CONFIG register,
	if ((ret = HAL_I2C_Mem_Read(&hi2c2, ADS1115_ADDR, CONFIG_ADDR,
			I2C_MEMADD_SIZE_8BIT, rxBuf, 2, 10)) != HAL_OK) {
	}
	gAD_flag = 0;

	txBuf[0][0] |= CONFIG_OS >> 8;	//Set OS pin to 1 to start a conversion
	txBuf[0][0] &= ~(CONFIG_MUX_0 >> 8);//Set MUX to 000 (AIN_p = AIN0, AIN_n = AIN1)
	txBuf[0][0] &= ~(CONFIG_MUX_1 >> 8);
	txBuf[0][0] &= ~(CONFIG_MUX_2 >> 8);

	txBuf[1][0] |= CONFIG_OS >> 8;	//Set OS pin to 1 to start a conversion
	txBuf[1][0] |= CONFIG_MUX_0 >> 8;//Set MUX to 011 (AIN_p = AIN2, AIN_n = AIN3)
	txBuf[1][0] |= CONFIG_MUX_1 >> 8;
	txBuf[1][0] &= ~(CONFIG_MUX_2 >> 8);

	//start a single-shot conversion with selected channel
	if ((ret = HAL_I2C_Mem_Write(&hi2c2, ADS1115_ADDR, CONFIG_ADDR,
			I2C_MEMADD_SIZE_8BIT, txBuf[num], 2, 2)) != HAL_OK) {

	};

	//Wait until flag is set (conversion complete)
	if (waitTrue(&gAD_flag, 4) == HAL_OK) {
		gAD_flag = 0;										//Clear flag
		if ((ret = HAL_I2C_Mem_Read(&hi2c2, ADS1115_ADDR,
				CONVERSION_ADDR, I2C_MEMADD_SIZE_8BIT, rxBuf, 2, 2)) != HAL_OK) {

		}
		gAD_data[num] = rxBuf[0] << 8 | rxBuf[1];
	}

	return gAD_data[num];//approximately 6 ms for one successful read, 11ms for two succesive channels
}

void ads1115_Callback() {
	gAD_flag = 1;
}

void ADS1115_ReadUnblocked(){
	int ret = HAL_OK;
	gAD_complete = 0;
	gAD_curIndex = 0;
	//start a single-shot conversion of channel 0
	if ((ret = HAL_I2C_Mem_Write(&hi2c2, ADS1115_ADDR, CONFIG_ADDR,
			I2C_MEMADD_SIZE_8BIT, txBuf[0], 2,2)) != HAL_OK) {
	};

}



void ads1115_Unblocked_Callback() {

	HAL_I2C_Mem_Read(&hi2c2, ADS1115_ADDR,CONVERSION_ADDR, I2C_MEMADD_SIZE_8BIT, rxBuf, 2, 2);
	gAD_data[gAD_curIndex++] = rxBuf[0] << 8 | rxBuf[1];
	if(gAD_curIndex==1){
		HAL_I2C_Mem_Write(&hi2c2, ADS1115_ADDR, CONFIG_ADDR,
					I2C_MEMADD_SIZE_8BIT, txBuf[1], 2,2);}
	else
	{
		gAD_curIndex=0;
		gAD_complete = 1;
	}
}
