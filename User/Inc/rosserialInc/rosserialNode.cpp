/*
 * rosserialNode.cpp
 *
 *  Created on: Aug 18, 2021
 *      Author: Xiaojiao Chen
 *       Email: yii402072495@gmail.com
 */

#include "rosserialNode.h"


/*************************User Config Zone begin***********************/

/*1.necessary headers*/
#include "HydroUnderwaterManipulator.h"
#include "hydrosoft_ros/Command_Arm.h"		//include messageType headers
#include "hydrosoft_ros/Sensor_Arm.h"		//include messageType headers

/*1.modify your pub variable, could be external, */
extern HydroUnderwaterManipulator uwManipulator;
ros::Publisher publisher1("HydroStatus",  &(uwManipulator.manipulatorStatus));  //define pub topic and variable

/*1.dummy sub callback, implement in your own file */
__weak void sub1Callback(const hydrosoft_ros::Command_Arm &msg){  //dont modify the sub callback name
	UNUSED(msg);
	//implement your sub callback content in your file
}
ros::Subscriber<hydrosoft_ros::Command_Arm> subscriber1("HydroCommands", &sub1Callback);

/*************************User Config Zone End  ***********************/







RosserialNode rosserialNode;//global variable

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


void  RosserialNode::init(UART_HandleTypeDef *huart)
{

	rosuart= huart;

	initNode((char *)rosuart);

	advertise(publisher1);

	subscribe(subscriber1);

};


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

	publisher1.publish(msg);
}
