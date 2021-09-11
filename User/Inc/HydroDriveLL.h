/*
 * HydroDriveLL.h
 *
 *  Created on: Aug 20, 2021
 *      Author: Xiaojiao Chen
 */
#ifndef __HYDRODRIVELL_H_
#define __HYDRODRIVELL_H_

#ifdef __cplusplus
 extern "C" {
#endif
#include "main.h"


/*****************************Available low-levle APIs to use********************/
float AnalogRead(uint16_t num);

void DigitalWrite(uint16_t num, uint16_t state);

void PWMWriteFlush();

void PWMWriteDuty(uint16_t num, float duty);

void PWMWriteFrequency(uint16_t num, float fre);

void PWMTest();
//uint32_t millis();
//uint32_t micros();
//void delay_us(int32_t t);
//void delay_ns(int32_t t);



#ifdef __cplusplus
}
#endif

#endif /* __HYDRODRIVELL_H_ */
