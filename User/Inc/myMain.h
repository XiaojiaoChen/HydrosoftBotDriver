/*
 * myMain.h
 *
 *  Created on: Aug 19, 2021
 *      Author: softarm
 */

#ifndef INC_MYMAIN_H_
#define INC_MYMAIN_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32g0xx.h"


void setup();
void loop();
void loop2();
void serialCallback();

#ifdef __cplusplus
}
#endif


#endif /* INC_MYMAIN_H_ */
