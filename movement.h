/*
 * movement.h
 *
 *  Created on: Feb 7, 2019
 *      Author: ryanjl9
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include "open_interface.h"

void movement_init(oi_t* s);
void move_forward(int centimeters);
void turn_right(int degrees);
void turn_left(int degrees);
void move_backward(int centimeters);
void move_backward_unsafe(int centimeters);
void move();
int checkInterrupts();

volatile int botX;
volatile int botY;
volatile int botAngle;
volatile struct position {
    char appCommand;
    int objectX;
    int objectY;
} currentPosition;

#endif /* MOVEMENT_H_ */
