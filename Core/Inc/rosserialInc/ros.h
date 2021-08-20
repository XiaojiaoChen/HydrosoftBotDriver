/*
 * ros.h
 *
 *  Created on: Aug 18, 2021
 *      Author: Xiaojiao Chen
 *       Email: yii402072495@gmail.com
 */

#ifndef __ROS_H_
#define __ROS_H_

/**
 * Configure:
 * 1. Complete the Configuration Zone.
 * 2. Include "ros.h" in your file. (Now you got a global variable named rosserialNode that can be directly used)
 * 3. put rosserialNode.spinOnce() in your loop()
 * 4. Implement your subscriber callback function in your file
 * 5. (optional*) if you have your own HAL_UART_TxCpltCallback or HAL_UART_RxCpltCallback implemented,
 * 	  add the content under the same name in RosserialNode.cpp to your version, and comment the version in RosserialNode.cpp.
 *
 * example usage(with default value):
 * 1.pubData1.data = 1;
 *	rosserialNode.publisher1.pub(&pubData1);
 *
 * 2.void rosserial_sub1Callback(const std_msgs::String &msg) //define your sub callback in your user file with same name
    {
        subData1.data = msg.data;
    }
 */



/*********************************************************************************************
**********************************  	              	  ************************************
**********************************  Configuration  Zone   ************************************
**********************************  	   BEGIN     	  ***********************************
********************************************************************************************/

#include "std_msgs/Float64.h"		//include messageType headers

#include "std_msgs/String.h"		//include messageType headers

#define DEFAULT_ROS_HUART huart3 //choose  your uart for ROS serial

#define PUBLISHER_NUMBER 1  //define how many publisher you have, currently <=3

#define SUBSCRIBER_NUMBER 1 //define how many subscriber you have

#if PUBLISHER_NUMBER >= 1
#define Publisher1_TopicName    	"pubTopic1"        	//define your Topic Name string to be published
#define Publisher1_MessageName  	pubData1         	//name your variable to be published
#define Publisher1_MessageType  	std_msgs::Float64 	//define your variable Type
#define Publisher1_Name		  		publisher1			//name a publisher for this topic
#endif
#if PUBLISHER_NUMBER >= 2
#define Publisher2_TopicName    	"pubTopic2"        	//define your Topic Name string to be published
#define Publisher2_MessageName  	pubData2         	//name your variable to be published
#define Publisher2_MessageType  	std_msgs::String 	//define your variable Type
#define Publisher2_Name		  		publisher2			//name a publisher for this topic
#endif
#if PUBLISHER_NUMBER >= 3
#define Publisher3_TopicName    	"pubTopic3"        	//define your Topic Name string to be published
#define Publisher3_MessageName  	pubData3         	//name your variable to be published
#define Publisher3_MessageType  	std_msgs::Float64 	//define your variable Type
#define Publisher3_Name		  		publisher3			//name a publisher for this topic
#endif

#if SUBSCRIBER_NUMBER >= 1
#define Subscriber1_TopicName 			"subTopic1"                 //define your sub topic name string
#define Subscriber1_MessageName 		subData1                    //name your local variable for receiving sub data
#define Subscriber1_MessageType 		std_msgs::String            //define your local variable type
#define Subscriber1_Name		  		subscriber1					//name a subscriber for this topic
#define Subscriber1_CallbackFunc_Name   sub1Callback                //define your sub callback function name
#endif
#if SUBSCRIBER_NUMBER >= 2
#define Subscriber2_TopicName 			"subTopic2"                 //define your sub topic name string
#define Subscriber2_MessageName 		subData2                    //name your local variable for receiving sub data
#define Subscriber2_MessageType 		std_msgs::String            //define your local variable type
#define Subscriber2_Name		  		subscriber2					//name a subscriber for this topic
#define Subscriber2_CallbackFunc_Name   sub2Callback                //define your sub callback function name
#endif
#if SUBSCRIBER_NUMBER >= 3
#define Subscriber3_TopicName 			"subTopic3"                 //define your sub topic name string
#define Subscriber3_MessageName 		subData3                    //name your local variable for receiving sub data
#define Subscriber3_MessageType 		std_msgs::String            //define your local variable type
#define Subscriber3_Name		  		subscriber3					//name a subscriber for this topic
#define Subscriber3_CallbackFunc_Name   sub3Callback                //define your sub callback function name
#endif
/*********************************************************************************************
**********************************  	              	  	************************************
**********************************  Configuration  Zone  	************************************
**********************************  	   END     	  		***********************************
********************************************************************************************/






/*************************No need to modify the following unless you know what you are doing*********/

#include "ros/node_handle.h"
#include "STM32Hardware.h"
#include "main.h"  
//#include "stm32f1xx_hal.h" if necessary
namespace ros{
    typedef NodeHandle_<STM32Hardware> NodeHandle; // default 25, 25, 512, 512
}

extern UART_HandleTypeDef DEFAULT_ROS_HUART;

class RosserialNode {
public:
	RosserialNode();
	void setPort(UART_HandleTypeDef *huart);
	void spinOnce(void);
	void TxCallback(UART_HandleTypeDef *huart);
	void RxCallback(UART_HandleTypeDef *huart);

#if PUBLISHER_NUMBER >= 1
	Publisher1_MessageType Publisher1_MessageName;
	ros::Publisher Publisher1_Name;
#endif
#if PUBLISHER_NUMBER >= 2
        Publisher2_MessageType Publisher2_MessageName;
        ros::Publisher Publisher2_Name;
#endif
#if PUBLISHER_NUMBER >= 3
        Publisher3_MessageType Publisher3_MessageName;
        ros::Publisher Publisher3_Name;
#endif

#if SUBSCRIBER_NUMBER >= 1
	Subscriber1_MessageType Subscriber1_MessageName;
	ros::Subscriber<Subscriber1_MessageType> Subscriber1_Name;
#endif
#if SUBSCRIBER_NUMBER >= 2
        Subscriber2_MessageType Subscriber2_MessageName;
        ros::Subscriber<Subscriber2_MessageType> Subscriber2_Name;
#endif
#if SUBSCRIBER_NUMBER >= 3
        Subscriber3_MessageType Subscriber3_MessageName;
        ros::Subscriber<Subscriber3_MessageType> Subscriber3_Name;
#endif
	UART_HandleTypeDef *rosuart;
	ros::NodeHandle nh;
        uint8_t initiatedFlag;
};

extern RosserialNode rosserialNode;





#endif /* __ROS_H_ */
