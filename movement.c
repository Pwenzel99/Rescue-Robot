/*
 * movement.c: All the code required to control the wheels and interrupts associated with the open interfaces sensors
 *
 *  Created on: Feb 7, 2019
 *      Author: ryanjl9, Anthony Rosenhamer, Austin Lines
 */
#include <movement.h>
#include <lcd.h>

#define NUMINTERRUPTS 8
#define TAPEVALUE 2700

/**
 * sensor: Variable used for storing the open interface struct
 */
oi_t* sensor;

void movement_init(oi_t* s){
    sensor = s;
}

/**
 * move_forward: This method moves the CyBot forward
 *
 * @param centimeters: Distance we want the cybot to move
 */
void move_forward(int centimeters) {
    oi_setWheels(75, 75);                           //Set wheel speed
    int bot_distance = 0;


    while (checkInterrupts() == 0 && bot_distance < (centimeters * 10.65 - 2.50)) {                   //As long as the total distance traveled is less than the
        oi_update(sensor);                          //desired, keep going
        bot_distance += sensor -> distance;
    }
    botY += (bot_distance * 0.938 + 2.38 ) * cos(botAngle * 3.1416 / 180);
    botX -= (bot_distance * 0.938 + 2.38 ) * sin(botAngle * 3.1416 / 180);


    oi_setWheels(0, 0);
}

/**
 * move_backward: This method moves the CyBot backwards
 *
 * @param centimeters: Distance we want the cybot to move
 */
void move_backward(int centimeters) {
    oi_setWheels(-75, -75);
    int bot_distance = 0;

    while (checkInterrupts() == 0 && bot_distance > (centimeters * -10.65 + 2.50)) {
        oi_update(sensor);
        bot_distance += sensor -> distance;
    }
    botY += (bot_distance * 0.938 + 2.38 ) * cos(botAngle * 3.1416 / 180);
    botX -= (bot_distance * 0.938 + 2.38 ) * sin(botAngle * 3.1416 / 180);

    oi_setWheels(0, 0);
}

/**
 * move_backward: This method moves the CyBot backwards without checking interrupts
 * 				  Used for moving the CyBot when interrupts are triggered
 *
 * @param centimeters: Distance we want the cybot to move
 */
void move_backward_unsafe(int centimeters) {
    oi_setWheels(-75, -75);
    int bot_distance = 0;

    while (bot_distance > (centimeters * -10.65 + 2.50)) {
        oi_update(sensor);
        bot_distance += sensor -> distance;
    }
    botY += (bot_distance * 0.938 + 2.38 ) * cos(botAngle * 3.1416 / 180);
    botX -= (bot_distance * 0.938 + 2.38 ) * sin(botAngle * 3.1416 / 180);

    oi_setWheels(0, 0);
}

/**
 * turn_right: This method turns the CyBot right
 *
 * @param centimeters: Distance we want the cybot to move
 */
void turn_right(int degrees) {
    oi_setWheels(-75, 75);
    int bot_rotation = 0;

    while (checkInterrupts() == 0 && bot_rotation > degrees * -0.93) {
        oi_update(sensor);
        bot_rotation += sensor -> angle;
    }
    botAngle -= degrees;

    oi_setWheels(0, 0);
}

/**
 * turn_left: This method turns the CyBot left
 *
 * @param centimeters: Distance we want the cybot to move
 */
void turn_left(int degrees) {
    oi_setWheels(75, -75);                      //Sets wheel speeds to opposites so the roomba spins left
    int bot_rotation = 0;

    while (checkInterrupts() == 0 && bot_rotation < degrees * 0.93) {
        oi_update(sensor);
        bot_rotation += sensor -> angle;
    }
    botAngle += degrees;

    oi_setWheels(0, 0);
}

/*
 * checkInterrupts: Checks all interrupts to determine if we need to back up after hitting something or going too far
 *
 * @return A number which corresponds to a specific interrupt group
 */
int checkInterrupts(){
        if (sensor -> wheelDropLeft || sensor -> cliffFrontLeft || sensor -> cliffLeft || sensor -> bumpLeft) {
            currentPosition.appCommand = 'l';
            move_backward_unsafe(10);
            return 1;
        }
        if (sensor -> wheelDropRight || sensor -> cliffFrontRight || sensor -> cliffRight || sensor -> bumpRight) {
            currentPosition.appCommand = 'r';
            move_backward_unsafe(10);
            return 2;
        }
        else if (sensor -> cliffLeftSignal > TAPEVALUE) {
            currentPosition.appCommand = '1';
            move_backward_unsafe(10);
            return 3;
        }
        else if (sensor -> cliffFrontLeftSignal > TAPEVALUE) {
            currentPosition.appCommand = '2';
            move_backward_unsafe(10);
            return 4;
        }
        else if (sensor -> cliffFrontRightSignal > TAPEVALUE) {
            currentPosition.appCommand = '3';
            move_backward_unsafe(10);
            return 5;
        }
        else if (sensor -> cliffRightSignal > TAPEVALUE) {
            currentPosition.appCommand = '4';
            move_backward_unsafe(10);
            return 6;
        }
    currentPosition.appCommand = 'b';
	return 0;
}

































