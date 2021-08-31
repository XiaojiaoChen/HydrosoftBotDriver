/*
 * rosserialNode.h
 *
 *  Created on: Aug 18, 2021
 *      Author: Xiaojiao Chen
 *       Email: yii402072495@gmail.com
 */

#ifndef __ROSSERIALNODE_H_
#define __ROSSERIALNODE_H_

#include "ros.h"
#include "main.h"

#include "ros/msg.h"





class RosserialNode : public ros::NodeHandle {
public:
        RosserialNode();
	RosserialNode(UART_HandleTypeDef *huart);
        void setPort(UART_HandleTypeDef *huart);
        void TxCallback(UART_HandleTypeDef *huart);
	void RxCallback(UART_HandleTypeDef *huart);
        void publish(const ros::Msg *msg);
        UART_HandleTypeDef *rosuart;
};

extern RosserialNode rosserialNode;





#endif /* __ROSSERIALNODE_H_ */
