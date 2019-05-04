/*
 * servo_ping.c: Handles the code required to control the servo which the ping and IR sensor are attached to
 *
 *  Created on: Mar 28, 2019
 *      Author: ryanjl9
 */

#include <servo_ping.h>

#define BYTE 8

double ang;
int clockwise;

/**
 * findMatch: This method finds the match value for the timer
 */
int findMatch(double angle){
	const int MS = 6942;
	int x = (int) (((4.1345) * MS * (angle/180.0)) + MS);
	return x;
}

/**
 * servo_ping_init: This method initializes the ping servo
 *
 * CALL THIS METHOD
 */
void servo_ping_init(){
	ang = 0;
	clockwise = 0;

	SYSCTL_RCGCGPIO_R |= 0x02; 						//Enables port B GPIO
	SYSCTL_RCGCTIMER_R |= 0x02;						//Enables Timer 1B

	GPIO_PORTB_DIR_R |= 0x20;						//Sets direction to output for pin 5
	GPIO_PORTB_DEN_R |= 0x20;						//Sets digital enable for pin 5

	GPIO_PORTB_AFSEL_R |= 0x20;						//Sets alternate function for pin 5
	GPIO_PORTB_PCTL_R |= 0x00700000;				//Sets alternate function to Timer 1B for pin 5

	timer1b_init();
}


/**
 * timer1b_init: This method initializes the timer1b
 */
void timer1b_init(){																								//p726, 725
	TIMER1_CTL_R &= 0xFEFF;																							//Disables Timer 1B
	TIMER1_CFG_R = 0x4;																								//Selects Timer 1B 16 bit

	TIMER1_TBMR_R |= 0x00A;																							//PWM Mode Enabled, Edge Count, Periodic Timer
	TIMER1_TBMR_R &= 0xFFA;

	//TIMER1_CTL_R &= 0xBFFF;																							//Set Timer to a non inverted state
	TIMER1_TBPR_R = 0x0004; 																						//Set an 8 bit pre-scale

	TIMER1_TBILR_R = 0xE200;																					//Sets start value for timer

	TIMER1_TBPMR_R = 0x0004;

	TIMER1_TBMATCHR_R = (TIMER1_TBPR_R << BYTE*4 | TIMER1_TBILR_R) - findMatch(ang);								//Sets match value;

	TIMER1_CTL_R |= 0x0100;																							//Reenables Timer 1B
}

/**
 * move_servo: This method moves the servo to a given position
 *
 * CALL THIS METHOD
 */
void move_servo(double angle){
	TIMER1_CTL_R &= 0xFEFF;
	TIMER1_TBMATCHR_R = TIMER1_TBILR_R - findMatch(angle);
	TIMER1_CTL_R |= 0x0100;
}

/**
 * servo_calibrate: This is a helper method used for calibrating the servo
 *
 * MAKE SURE button_getButton IS CALLED
 */
void servo_calibrate(){
	lcd_init();
	adc_init();
	uart_init();
	ping_init();
	servo_ping_init();

	lcd_printf("Angle: %0.1f\nClockwise: %i\n", ang, clockwise); //Initial print of data

	while(1); //Wait for interrupts
}

















