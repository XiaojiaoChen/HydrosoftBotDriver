/*
 * ros.h
 *
 *  Created on: Aug 18, 2021
 *      Author: Xiaojiao Chen
 *       Email: yii402072495@gmail.com
 */

#ifndef __ROS_H_
#define __ROS_H_


/*******************Usage *****************
 1. config your publisher and subscriber informations in "rosserialNode.cpp"

 2. in your file: 
    #include "ros.h"

    void setup(){
        rosserialNode.init(&huart1);
    }

    void loop(){
        rosserialNode.publish(&(yourPubData));
        rosserialNode.spinOnce();
    }
  
    void sub1Callback(const std_msgs::String &msg){
        //code here
    }
******************Usage  End******************/


#include "main.h"  
#include "ros/node_handle.h"
#include "STM32Hardware.h"
//#include "stm32f1xx_hal.h" if necessary
namespace ros{
    typedef NodeHandle_<STM32Hardware> NodeHandle; // default 25, 25, 512, 512
}
#include "rosserialNode.h"






#endif /* __ROS_H_ */
