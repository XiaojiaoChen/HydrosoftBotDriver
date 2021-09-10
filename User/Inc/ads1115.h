/*
 * ads1115.h
 *
 *  Created on: 2021年7月22日
 *      Author: SHEN Zhong
 */

#ifndef INC_ADS1115_H_
#define INC_ADS1115_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f1xx_hal.h"


#define ADS1115_ADDR					((0x48UL)<<1)

#define CONVERSION_ADDR					(0X0UL)
#define CONFIG_ADDR						(0X1UL)
#define LO_THRESH_ADDR					(0X2UL)
#define HI_THRESH_ADDR					(0X3UL)

#define CONFIG_OS_POS					(15U)
#define CONFIG_OS						(0X1UL << CONFIG_OS_POS)
#define CONFIG_MUX_POS					(12U)
#define CONFIG_MUX_0					(0X1UL << CONFIG_MUX_POS)
#define CONFIG_MUX_1					(0X2UL << CONFIG_MUX_POS)
#define CONFIG_MUX_2					(0X4UL << CONFIG_MUX_POS)
#define CONFIG_PGA_POS					(9U)
#define CONFIG_PGA_0					(0X1UL << CONFIG_PGA_POS)
#define CONFIG_PGA_1					(0X2UL << CONFIG_PGA_POS)
#define CONFIG_PGA_2					(0X4UL << CONFIG_PGA_POS)
#define CONFIG_MODE_POS					(8U)
#define CONFIG_MODE						(0X1UL << CONFIG_MODE_POS)
#define CONFIG_DR_POS					(5U)
#define CONFIG_DR_0						(0X1UL << CONFIG_DR_POS)
#define CONFIG_DR_1						(0X2UL << CONFIG_DR_POS)
#define CONFIG_DR_2						(0X4UL << CONFIG_DR_POS)
#define CONFIG_COMP_MODE_POS			(4U)
#define CONFIG_COMP_MODE				(0X1UL << CONFIG_COMP_MODE_POS)
#define CONFIG_COMP_POL_POS				(3U)
#define CONFIG_COMP_POL					(0X1UL << CONFIG_COMP_POL_POS)
#define CONFIG_COMP_LAT_POS				(2U)
#define	CONFIG_COMP_LAT					(0X1UL << CONFIG_COMP_LAT_POS)
#define CONFIG_COMP_QUE_POS				(0U)
#define CONFIG_COMP_QUE_0				(0X1UL << CONFIG_COMP_QUE_POS)
#define CONFIG_COMP_QUE_1				(0X2UL << CONFIG_COMP_QUE_POS)

int ADS1115_Setup(void);
int16_t ADS1115_Read(int num);
void ads1115_Callback();
#ifdef __cplusplus
}
#endif

#endif /* INC_ADS1115_H_ */
