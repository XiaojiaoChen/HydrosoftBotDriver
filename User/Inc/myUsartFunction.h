/*
 * myUsartFunction.h
 *
 *  Created on: Jun 12, 2018
 *      Author: 402072495
 */

#ifndef FRAMEINC_MYUSARTFUNCTION_H_
#define FRAMEINC_MYUSARTFUNCTION_H_

#ifdef __cplusplus
 extern "C" {
#endif


#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "usart.h"

#define UART_TX_BUF_SIZE 100
#define UART_RX_BUF_SIZE 100
#define COMMAND_SIZE 50

#define UART_TX_BUF_NUM	5


typedef enum USARTMode_ENUM{
	usartIntMode,
	usartDMAIdleMode,
	usartDMACircularMode
}USARTMode;

typedef struct UART_DEVICE_STRUCT{
	UART_HandleTypeDef *huart;
	USARTMode	usartmode;

	uint8_t TxBuf[UART_TX_BUF_NUM][UART_TX_BUF_SIZE];  /*TxBuffer*/
	uint16_t consumerTxBufNum;
	uint16_t producerTxBufNum;
	uint16_t bufferedTxNum;
	uint16_t countTxBuf[UART_TX_BUF_NUM];

	uint8_t RxBuf[UART_RX_BUF_SIZE];
	uint8_t *pRxBuf;
	uint8_t RxLineBuf[UART_RX_BUF_SIZE];
	uint8_t *pRxLineBuf;
	uint16_t countRxLineBuf;
	uint16_t USART_RX_STA;
	uint32_t RxInd;

	uint8_t szCmd[COMMAND_SIZE];
	float	uiArgv[3];
	int32_t ulArgv[3];
	int     iArgc;
    int usartCommandCode;
	uint16_t countRxBuf;

	uint16_t Received;

	uint32_t TxStart;
	uint32_t TxEnd;

	uint32_t lastTxTime;
	uint32_t lastTxCount;
}UART_DEVICE;

void my_UsartInit();			/*put in the Initialization*/
void printBin(char *buf,int len);
void Usart_ReceivePolling(void);/*put In the polling loop*/
void myUsartIntIRQ(UART_HandleTypeDef *huart);/*put in the ISR*/

int my_write_DMA(UART_HandleTypeDef *huart, uint8_t *pSrc, int len);

__weak void serialCallback(char *buf);

#ifdef __cplusplus
}
#endif


#endif /* FRAMEINC_MYUSARTFUNCTION_H_ */