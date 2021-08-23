/*
 * rosserialNode.cpp
 *
 *  Created on: Aug 18, 2021
 *      Author: Xiaojiao Chen
 *       Email: yii402072495@gmail.com
 */

#include "ros.h"

RosserialNode rosserialNode; //Global variable

/*If you already have your own HAL_UART_TxCpltCallback function, just put the TxCallback() function inside of your code.and comment out below */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	rosserialNode.TxCallback(huart);
}

/*If you already have your own HAL_UART_RxCpltCallback function, just put the RxCallback() function inside of your code.and comment out below */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	rosserialNode.RxCallback(huart);
}


#if SUBSCRIBER_NUMBER >= 1
/* define your sub callback in your user file*/
__weak void Subscriber1_CallbackFunc_Name(const Subscriber1_MessageType &msg)
{
	UNUSED(msg);
}
#endif

#if SUBSCRIBER_NUMBER >= 2
/* define your sub callback in your user file*/

__weak void Subscriber2_CallbackFunc_Name(const Subscriber2_MessageType &msg)
{
	UNUSED(msg);
}
#endif

#if SUBSCRIBER_NUMBER >= 3
/* define your sub callback in your user file*/
__weak void Subscriber3_CallbackFunc_Name(const Subscriber3_MessageType &msg)
{
	UNUSED(msg);
}
#endif




RosserialNode::RosserialNode() :
#if PUBLISHER_NUMBER >= 1
								 Publisher1_Name(Publisher1_TopicName, &Publisher1_MessageName),
#endif
#if PUBLISHER_NUMBER >= 2
								 Publisher2_Name(Publisher2_TopicName, &Publisher2_MessageName),
#endif
#if PUBLISHER_NUMBER >= 3
								 Publisher3_Name(Publisher3_TopicName, &Publisher3_MessageName),
#endif
#if SUBSCRIBER_NUMBER >= 1
								 Subscriber1_Name(Subscriber1_TopicName, &Subscriber1_CallbackFunc_Name),
#endif
#if SUBSCRIBER_NUMBER >= 2
								 Subscriber2_Name(Subscriber2_TopicName, &Subscriber2_CallbackFunc_Name),
#endif
#if SUBSCRIBER_NUMBER >= 3
								 Subscriber3_Name(Subscriber3_TopicName, &Subscriber3_CallbackFunc_Name),
#endif
								rosuart(&(DEFAULT_ROS_HUART)),
								 initiatedFlag(0)
{
	setPort(rosuart);

#if PUBLISHER_NUMBER >= 1
	nh.advertise(Publisher1_Name);
#endif
#if PUBLISHER_NUMBER >= 2
	nh.advertise(Publisher2_Name);
#endif
#if PUBLISHER_NUMBER >= 3
	nh.advertise(Publisher3_Name);
#endif
#if SUBSCRIBER_NUMBER >= 1
	nh.subscribe(Subscriber1_Name);
#endif
#if SUBSCRIBER_NUMBER >= 2
	nh.subscribe(Subscriber2_Name);
#endif
#if SUBSCRIBER_NUMBER >= 3
	nh.subscribe(Subscriber3_Name);
#endif
};

void RosserialNode::setPort(UART_HandleTypeDef *huart)
{
	rosuart = huart;
	nh.getHardware()->setPort(huart);
}

/********************** put spinOnce() in loop routine*******************
 loop{
 rosserialNode.spinOnce();
 }*/
void RosserialNode::spinOnce()
{
	//The initialization process of nh.init() has to be done after HAL Uart configurations.
	//we combine the code here.
	if(!initiatedFlag)
	{
		nh.initNode();
		initiatedFlag=1;
	}
	nh.spinOnce();
}

void RosserialNode::TxCallback(UART_HandleTypeDef *huart)
{
	if (rosuart == huart)
	{
		nh.getHardware()->flush();
	}
}

void RosserialNode::RxCallback(UART_HandleTypeDef *huart)
{
	if (rosuart == huart)
	{
		nh.getHardware()->reset_rbuf();
	}
}
