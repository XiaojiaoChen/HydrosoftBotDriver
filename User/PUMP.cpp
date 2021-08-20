/*
 * PUMP.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Xiaojiao Chen
 *		 Email: chen2014@connect.hku.hk
 *	Laboratory: Bio-Control Lab
 * Orgnization: the University of Hong Kong
 */

#include "main.h"
#include "HydroDriveLL.h"
#include "PUMP.h"


PUMP::PUMP(uint8_t num) {
	status=0;
	attach(num);
}

void PUMP::attach(uint8_t num)
{
	DigitalPort = num;
}

void PUMP::start()
{

	PWMWriteDuty(DigitalPort,(PWM_DIGITAL_OUTPUT_REVERSED?0:1));
	status=1;

}

void PUMP::stop()
{
	PWMWriteDuty(DigitalPort,(PWM_DIGITAL_OUTPUT_REVERSED?0:1));
	status=0;

}
