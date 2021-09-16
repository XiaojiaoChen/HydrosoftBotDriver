/*
 * myUsartFunction.cpp
 *
 *  Created on: Jun 12, 2018
 *      Author: 402072495
 */
#include "main.h"
#include "myUsartFunction.h"
#include "cmsis_os.h"

#include "string.h"
#include <stdarg.h>
#include <stdio.h>

UART_DEVICE Usart1Device;

static void myInitUsartMode(UART_HandleTypeDef *huart,USARTMode usartMode);
static UART_DEVICE *getUsartDevice(UART_HandleTypeDef *huart);

/*put this function in the main.c for initilization*/
void my_UsartInit()
{
	 myInitUsartMode(&huart1,usartIntMode);
}
static void myInitUsartMode(UART_HandleTypeDef *huart,USARTMode usartMode){
	UART_DEVICE *uartDev=getUsartDevice(huart);
	memset(uartDev,0,sizeof(UART_DEVICE));
	uartDev->huart = huart;
	uartDev->pRxBuf = uartDev->RxBuf;
	uartDev->pRxLineBuf=uartDev->RxLineBuf;
	uartDev->usartmode=usartMode;
	if(usartMode==usartIntMode){
		 __HAL_UART_ENABLE_IT(huart,UART_IT_RXNE);
	}
}
static UART_DEVICE *getUsartDevice(UART_HandleTypeDef *huart){
	if(huart==&huart1)
		return &Usart1Device;
}





/************************************			*************************************/
/************************************	Transfer*************************************/
/************************************			************************************/
/*Redirect printf() by implementing (weak) _write function.
 *Every printf() call would store the output string in TxBuf[], ready for Usart DMA output instead of directly output*/
int _write(int file, char *pSrc, int len){
	return my_write_DMA(&huart1,(uint8_t *)pSrc,len);
}
int my_write_DMA(UART_HandleTypeDef *huart, uint8_t *pSrc, int len)
{
	UART_DEVICE *uartDev=getUsartDevice(huart);
	uint8_t *pDes=uartDev->TxBuf[uartDev->producerTxBufNum];

	//store the string to next buffer
	memcpy(pDes,pSrc,len);
	*(pDes+len)='\0';
	uartDev->countTxBuf[uartDev->producerTxBufNum] = len;

	//add one bufferedTxNum, recording how many buffered strings that haven't been sent
	uartDev->bufferedTxNum++;

	//Try to send just buffered string if this is the only one
	if(uartDev->bufferedTxNum == 1){
		HAL_UART_Transmit_DMA(uartDev->huart,pDes,uartDev->countTxBuf[uartDev->producerTxBufNum]);
//		uartDev->TxStart = micros();
	}
	else{
	//TO DO, There is a bug here, when the builtInPWMFrequency is changed, the uartDevs would somehow suddenly lost the configurations
		uartDev->bufferedTxNum=uartDev->bufferedTxNum-1+1;
	}
	//move producerTxBufNum forward
	uartDev->producerTxBufNum++;
	uartDev->producerTxBufNum%=UART_TX_BUF_NUM;

	//Buffered term full, wait for consumer to reduce producerTxBufNum
//	while(uartDev->bufferedTxNum > (UART_TX_BUF_NUM-2)){
//		//Danger! May block the main program continuously !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//		//This waiting mechanism is to take care of the high frequency output within a short period during the Ethercat Initialization
//		//If the producer is always quicker than consumer, for example a high frequency output ,this function would block the program permanently
//	};
	return len;
}

void printBin(char *buf,int len){
	_write(0,buf,len);
}

/************************************							*************************************/
/************************************Transfer Complete Callback*************************************/
/************************************							************************************/
/*this function would overwrite HAL's weak HAL_UART_TxCpltCallback for all usart*/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	UART_DEVICE *uartDev=getUsartDevice(huart);
	 /*update information*/
//	 uartDev->TxEnd = micros();
	 uartDev->lastTxTime = uartDev->TxEnd - uartDev->TxStart;
	 uartDev->lastTxCount = uartDev->countTxBuf[uartDev->consumerTxBufNum];

	/*One consumption done. move consumer forward*/
	uartDev->consumerTxBufNum++;
	uartDev->consumerTxBufNum%=UART_TX_BUF_NUM;

	/*reduce one bufferedTxNum*/
	 uartDev->bufferedTxNum--;

	/*If it is still positive, go on consume next*/
	if(uartDev->bufferedTxNum>0){
//		uartDev->TxStart = micros();
		uint8_t *px = &uartDev->TxBuf[uartDev->consumerTxBufNum][0];
		HAL_UART_Transmit_DMA(uartDev->huart,px,uartDev->countTxBuf[uartDev->consumerTxBufNum]);
	}

}

/************************************							*************************************/
/************************************Receive Complete Callback*************************************/
/************************************							************************************/
/*this function would overwrite HAL's weak HAL_UART_RxCpltCallback for all usart*/







/*put this function in stm32f7xx_it.c as below
	void USART2_IRQHandler(void)
	{
	  myUsartIntIRQ(&huart2);
	  HAL_UART_IRQHandler(&huart2);
	}
*/
void myUsartIntIRQ(UART_HandleTypeDef *huart)
{
	UART_DEVICE *uartDev=getUsartDevice(huart);
 	if(__HAL_UART_GET_FLAG(huart, UART_FLAG_RXNE)!=RESET)   //receive interrupt
	{
		*(uartDev->pRxBuf)=(uint8_t)(huart->Instance->DR & (uint8_t)0x00FF);  //read and clear flag
		if(*(uartDev->pRxBuf)==0x0a) // if current char is 0x0a, take care. If not, go on receiving.
		{
			uartDev->Received = 1;
			serialCallback((char *)(uartDev->RxBuf));
			memset(uartDev->RxBuf,0,UART_RX_BUF_SIZE);
			uartDev->pRxBuf=uartDev->RxBuf;
			uartDev->Received = 0;
		}
		else uartDev->pRxBuf++;
	}
}
