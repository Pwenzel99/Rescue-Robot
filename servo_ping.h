/*
 * servo_ping.h - Header file for servo_ping
 *
 *  Created on: Mar 28, 2019
 *      Author: ryanjl9
 */

#ifndef SERVO_PING_H_
#define SERVO_PING_H_
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inc/tm4c123gh6pm.h>
#include "timer.h"
#include <lcd.h>
#include <ping.h>
#include <button.h>

int findMatch(double angle);					//Finds the match value for TIMER1
void servo_ping_init();							//Initiates the Servo and Ping Sensor
void timer1b_init(); 							//Initiates timer1b
void move_servo(double angle);					//Moves the servo to the desired angle
void servo_calibrate();							//Funcation for calibrating servo

extern double ang;								//External variable to set and measure the angle of the servo
extern int clockwise;							//External variable to determine the direction to move

#endif /* SERVO_PING_H_ */
