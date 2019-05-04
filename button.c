/*
 *  button.c
 *  @author: Eric Middleton, Zhao Zhang, Chad Nelson, & Zachary Glanz.
 *  @date: Jul 18, 2016
 *
 *  @edit: Lindsey Sleeth and Sam Stifter on 02/04/2019
 */

#include "button.h"
#include <servo_ping.h>

#define BIT0		0x01
#define BIT1		0x02
#define BIT2		0x04
#define BIT3		0x08
#define BIT4		0x10
#define BIT5		0x20
#define BIT6		0x40
#define BIT7		0x80

uint8_t prev_Button; //must be set yourself in button_getButton()
uint8_t button; //current button being pressed, must be set yourself in button_getButton()

// These variables are declared in button.h for your use in the interrupt handler.
volatile int button_event = 0; // Boolean to keep track of whether a hardware event has happened (button pressed)
volatile int button_num = 0; // keeps track of button pressed

/**
 * Initialize PORTE and configure bits 0-5 to be used as inputs for the buttons.
 */
void button_init() {
	static uint8_t initialized = 0;

	//Check if already initialized
	if (initialized) {
		return;
	}

	//Turn on PORTE system clock
	SYSCTL_RCGCGPIO_R |= 0x10;

	//Set the buttons to inputs and enable
	GPIO_PORTE_DIR_R &= 0xC0;
	GPIO_PORTE_DEN_R |= 0x3F;

	initialized = 1;
}

/**
 * Interrupt handler -- executes when a hardware event occurs (a button is pressed)
 */
void init_button_interrupts() {
	// Mask the bits for pins 0-5
	GPIO_PORTE_IM_R &= 0xC0;

	// Set pins 0-5 to use edge sensing
	GPIO_PORTE_IS_R &= 0xC0;

	// Set pins 0-5 to use both edges. We want to update the LCD
	// when a button is pressed, and when the button is released.
	GPIO_PORTE_IBE_R |= 0x3F;

	// Clear the interrupts
	GPIO_PORTE_ICR_R |= 0x3F;

	// Unmask the bits for pins 0-5
	GPIO_PORTE_IM_R |= 0x3F;

	NVIC_EN0_R |= 0x00000010;

	// Bind the interrupt to the handler.
	IntRegister(INT_GPIOE, gpioe_handler);
}

/**
 * Handles a hardware interrupt that occurs from a button being pressed
 */
void gpioe_handler() {

	GPIO_PORTE_ICR_R = 0x3F;

	button_num = button_getButton(); //Get Button pressed and moved server
	lcd_printf("Angle: %0.1f\nClockwise: %i\n", ang, clockwise); //Print data to screen
	timer_waitMillis(250); //Rudementary debouncing
}

/**
 * returns a 6-bit bit field, representing the push buttons. A 1 means the corresponding button is pressed.
 */
uint8_t button_checkButtons() {
	return (~GPIO_PORTE_DATA_R) & (BIT6 - 1); //Return the button status
}

/**
 * Returns the position of the leftmost button being pushed.
 * @return the position of the leftmost button being pushed. A 6 is the leftmost button, 1 is the rightmost button. Return 0 if no button is being pressed.
 */
uint8_t button_getButton() {

	if (!((GPIO_PORTE_DATA_R >> 5) & 1)) { //If button pressed, move 1 degree
		return 0;
	}

	//Continues checking bits left to right (5)
	if (!((GPIO_PORTE_DATA_R >> 4) & 1)) {				//Move 2.5 degrees
		if(!clockwise && ang + 2.5 < 181) ang+=2.5;
		if(clockwise && ang - 2.5 >= 0) ang-=2.5;
		move_servo(ang);
		return 0;
	}

	//(4)
	if(!((GPIO_PORTE_DATA_R >> 3) & 1)){				//Move 5 degrees
		if(!clockwise && ang + 5 < 181) ang+=5;
		if(clockwise && ang - 5 >= 0) ang-=5;
		move_servo(ang);
		return 0;
	}

	//(3)
	if(!((GPIO_PORTE_DATA_R >> 2) & 1)){				//Toggle between CW and CCW
		if(clockwise) clockwise=0;
		else clockwise=1;
		return 0;
	}

	//(2)
	if(!((GPIO_PORTE_DATA_R >> 1) & 1)){				//Move to 0 degrees
		ang = 0;
		move_servo(0);
		return 0;
	}

	//(1)
	if(!((GPIO_PORTE_DATA_R >> 0) & 1)){				//Move to 180 degrees
		ang = 180;
		move_servo(180);
		return 0;
	}

	return 0;
}























