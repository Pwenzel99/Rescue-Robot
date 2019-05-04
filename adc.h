/*
 * adc.h
 *
 *  Created on: Mar 7, 2019
 *      Author: bjpierre
 */

#ifndef ADC_H_
#define ADC_H_

#include <lcd.h>
#include <inc/tm4c123gh6pm.h>
#include <uart.h>
#include <ping.h>
#include <adc.h>
#include <math.h>
#include <servo_ping.h>

void adc_init();
int adc_read();
void adc_read_avg();
void ir_calibrate();
void ir_getDistance();

extern double ir_value;
extern double ir_distance;

#endif /* ADC_H_ */
