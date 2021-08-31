/*
 * ros.h
 *
 *  Created on: Aug 18, 2021
 *      Author: Xiaojiao Chen
 *       Email: yii402072495@gmail.com
 */

#ifndef __ROS_H_
#define __ROS_H_

/*************************No need to modify the following unless you know what you are doing*********/

#include "ros/node_handle.h"
#include "STM32Hardware.h"
#include "main.h"  
//#include "stm32f1xx_hal.h" if necessary
namespace ros{
    typedef NodeHandle_<STM32Hardware> NodeHandle; // default 25, 25, 512, 512
}
#include "rosserialNode.h"



#endif /* __ROS_H_ */
