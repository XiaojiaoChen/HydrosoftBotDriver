/*
 * myCanbus.h
 *
 *  Created on: 2020年1月7日
 *      Author: Xiaojiao Chen
 *       Email: yii402072495@gmail.com
 */

#ifndef CANBUS_H_
#define CANBUS_H_
#ifdef __cplusplus
 extern "C" {
#endif
#include "main.h"
#include "stm32f1xx_hal_can.h"


 struct CANBUS_HANDLE{
	CAN_HandleTypeDef     CanHandle;
	CAN_TxHeaderTypeDef   TxHeader;
	CAN_RxHeaderTypeDef   RxHeader;
	uint8_t               *TxData;
	uint8_t               *RxData;
	uint32_t              TxMailbox;
 };

 void canConfig();
 void canSend();
 void canRead();

#ifdef __cplusplus
}
#endif
#endif /* CANBUS_H_ */
