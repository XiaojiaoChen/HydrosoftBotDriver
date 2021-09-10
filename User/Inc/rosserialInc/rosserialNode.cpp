/*
 * rosserialNode.cpp
 *
 *  Created on: Aug 18, 2021
 *      Author: Xiaojiao Chen
 *       Email: yii402072495@gmail.com
 */

#include "ros.h"
#include "usart.h"

/*******************User config Zone******************/

#include "HydroUnderwaterManipulator.h"

#include "hydrosoft_ros/Command_Arm.h"		//include messageType headers

#include "hydrosoft_ros/Sensor_Arm.h"		//include messageType headers

RosserialNode rosserialNode(&huart1);		//define usart port

extern HydroUnderwaterManipulator uwManipulator;   
ros::Publisher publisher1("HydroStatus",  &(uwManipulator.manipulatorStatus));  //define pub topic and variable


__weak void sub1Callback(const hydrosoft_ros::Command_Arm &msg){	UNUSED(msg);} //define your sub callback in your user file
ros::Subscriber<hydrosoft_ros::Command_Arm> subscriber1("HydroCommand", &sub1Callback); //define sub topic and callback

/*******************User config Zone******************/





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



RosserialNode::RosserialNode()
{

	initNode();

	advertise(publisher1);

	subscribe(subscriber1);

};

RosserialNode::RosserialNode(UART_HandleTypeDef *huart) : 
		ros::NodeHandle(),
		rosuart(huart)
{
	initNode((char *)huart);

	advertise(publisher1);

	subscribe(subscriber1);

};

void RosserialNode::setPort(UART_HandleTypeDef *huart){
	rosuart = huart;
	getHardware()->init((char *)huart);
}



void RosserialNode::TxCallback(UART_HandleTypeDef *huart)
{
	if (rosuart == huart)
	{
		getHardware()->flush();
	}
}

void RosserialNode::RxCallback(UART_HandleTypeDef *huart)
{
	if (rosuart == huart)
	{
		getHardware()->reset_rbuf();
	}
}

void RosserialNode::publish(const ros::Msg * msg){
	uwManipulator.encodeStatus();
	publisher1.publish(msg);
}