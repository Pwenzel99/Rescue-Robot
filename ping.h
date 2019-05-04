/*
 * ping.h - Header file for ping sensor
 *
 *  Created on: Mar 14, 2019
 *      Author: ryanjl9
 */

#ifndef PING_H_
#define PING_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inc/tm4c123gh6pm.h>
#include "timer.h"
#include <lcd.h>

void ping_init();
void timer3b_init();
void ping_getDistance();
void ping_interrupt();
void dist(int val);

extern int timer_value;
extern double ping_distance;

#endif /* PING_H_ */
