/*
 * myMain.cpp
 *
 *  Created on: Aug 19, 2021
 *      Author: Xiaojiao Chen
 */

#include "myMain.h"
#include "rosserialNode.h"
#include "CANbus.h"

int32_t globalSensorTaskPeriod = 10;      //10 ms period for loop()  (100Hz)

int32_t globalCommunicationTaskPeriod = 5;    //5 ms period for loop2()  (200Hz)


void setup(){

}

void loop(){

}

void loop2(){
	rosserialNode.spinOnce();
}
