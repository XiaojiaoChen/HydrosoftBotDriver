/*
 * ads1115.c
 *
 *  Created on: 2021年7月22日
 *      Author: SHEN Zhong
 */
#include "main.h"
#include "ads1115.h"
#include "i2c.h"


int ad_flag = 0;

/* ADS115 setup function
 * RDY is connected to PA15
 * AIN0, AIN1, AIN2, AIN3 are connected to Vout1_H, Vout1_L, Vout2_H, Vout2_L respectively
 * Full scale range is set to +-4.096V
 * Sample rate is 250SPS
 * Single-shot mode
 * Conversion Ready pi enabled (MSB of Lo_thresh is 0 and MSB of Hi_thresh is 1)
 */
int ADS1115_Setup(void)
{
	uint8_t txbuf[2];
	int ret = HAL_OK;
	txbuf[0] = (CONFIG_PGA_0 | CONFIG_MODE) >> 8;				//Single-shot mode
	txbuf[1] = CONFIG_DR_2 | CONFIG_DR_0;
	if((ret = HAL_I2C_Mem_Write(&hi2c2, ADS1115_ADDR, CONFIG_ADDR, I2C_MEMADD_SIZE_8BIT, txbuf,2, 100))!=HAL_OK)
	{

	}

	txbuf[0] = 0x0;											//Set MSB of Lo_thresh to 0
	txbuf[1] = 0x0;
	if((ret = HAL_I2C_Mem_Write(&hi2c2, ADS1115_ADDR,  LO_THRESH_ADDR, I2C_MEMADD_SIZE_8BIT,  txbuf, 2,100))!=HAL_OK){

	}

	txbuf[0] = 0xFF;											//Set MSB of Hi_thresh to 1
	txbuf[1] = 0xFF;
	if((ret = HAL_I2C_Mem_Write(&hi2c2, ADS1115_ADDR, HI_THRESH_ADDR,I2C_MEMADD_SIZE_8BIT,  txbuf, 2,100))!=HAL_OK){

	}
	return ret;
}


int16_t ADS1115_Read(int num)
{
	int ret = HAL_OK;
	int16_t data;
	uint8_t txBuf[2];
	uint8_t rxBuf[2];

	txBuf[0] = CONFIG_ADDR;									//Read the setting of current CONFIG register
	if((ret = HAL_I2C_Master_Transmit(&hi2c2, ADS1115_ADDR,  txBuf,1,10))!=HAL_OK){

	}
	if((ret = HAL_I2C_Master_Receive(&hi2c2, ADS1115_ADDR,  rxBuf,2,10))!=HAL_OK){

	}

	if(num==0){
	txBuf[0] = rxBuf[0] ;
	txBuf[0] |= CONFIG_OS >> 8;								//Set OS pin to 1 to start a conversion
	txBuf[0] &= ~(CONFIG_MUX_0 >> 8);						//Set MUX to 000 (AIN_p = AIN0, AIN_n = AIN1)
	txBuf[0] &= ~(CONFIG_MUX_1 >> 8);
	txBuf[0] &= ~(CONFIG_MUX_2 >> 8);
	txBuf[1] = rxBuf[1];
	}
	else if(num==1){
	txBuf[0] = rxBuf[0] ;
	txBuf[0] |= CONFIG_OS >> 8;								//Set OS pin to 1 to start a conversion
	txBuf[0] |= CONFIG_MUX_0 >> 8;							//Set MUX to 011 (AIN_p = AIN2, AIN_n = AIN3)
	txBuf[0] |= CONFIG_MUX_1 >> 8;
	txBuf[0] &= ~(CONFIG_MUX_2 >> 8);
	txBuf[1] = rxBuf[1];
	}
	if((ret = HAL_I2C_Mem_Write(&hi2c2, ADS1115_ADDR, CONFIG_ADDR,I2C_MEMADD_SIZE_8BIT, txBuf,2, 10))!=HAL_OK){

	}

	HAL_Delay(20);
	while(ad_flag == 0);										//Wait until flag is set (conversion complete)
	ad_flag = 0;												//Clear flag
	txBuf[0] = CONVERSION_ADDR;								//Read data
	if((ret = HAL_I2C_Master_Transmit(&hi2c2, ADS1115_ADDR,  txBuf,1,10))!=HAL_OK){

	}
	if((ret = HAL_I2C_Master_Receive(&hi2c2, ADS1115_ADDR,  rxBuf,2,10))!=HAL_OK){
	}

	data = rxBuf[0] << 8 | rxBuf[1];
	return data;
}

void ads1115_Callback(){
	ad_flag = 1;
}

