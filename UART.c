/*
 * UART.c: Handles all the code required to do two way communication via UART. Primarily used to communicate over wifi
 *
 *  Created on: Feb 21, 2019
 *      Author: ryanjl9, Ben Pierre, Anthony Rosenhamer
 *
 */

#include <UART.h>
#include <MOVEMENT.h>
#include <lcd.h>
#include <final.h>

#define BIT0        0x01
#define BIT1        0x02
#define BIT2        0x04
#define BIT3        0x08
#define BIT4        0x10
#define BIT5        0x20
#define BIT6        0x40
#define BIT7        0x80

char data;
char message[21];
char command[21];
int len;
int distance = 0;
int scan;
int playMusic;
int freeWilli;

char positionStr[256];

/**
 * uart_init: This method is used to initialize the uart module
 *
 * CALL THIS METHOD
 */
void uart_init() {
	scan = 0;
	playMusic = 0;
	freeWilli = 0;

	SYSCTL_RCGCGPIO_R |= 0x02;
	SYSCTL_RCGCUART_R |= 0x02;

	GPIO_PORTB_AFSEL_R |= (BIT0 | BIT1);
	GPIO_PORTB_PCTL_R |= 0x00000011;

	GPIO_PORTB_DEN_R |= (BIT0 | BIT1);
	GPIO_PORTB_DIR_R &= 0xFE;
	GPIO_PORTB_DIR_R |= 0x02;

	UART1_CTL_R &= ~UART_CTL_UARTEN;

	//104. 11
	//8, 44

	UART1_IBRD_R = 8;
	UART1_FBRD_R = 44;

	UART1_CC_R = 0;

	UART1_LCRH_R = 0x60;

	UART1_ICR_R |= 0x0030;
	UART1_IM_R |= 0x0010;

	//6
	NVIC_PRI1_R |= 0x00002000;
	NVIC_EN0_R |= 0x00000040;

	IntRegister(INT_UART1, uart_handler);

	UART1_CTL_R = 0x0301;

	IntMasterEnable();
}

/**
 * uart_sendChar: This method is used to send data to putty
 *
 * @param ldata: The character we would like to send to putty
 */
void uart_sendChar(char ldata) {
	while ((UART1_FR_R & 0x20) != 0);    // Loops until a character is available to be transmitted

	UART1_DR_R = ldata;
}

/**
 * uart_recieve: This method is used to recieve data from putty
 */
char uart_recieve() {
	return (char) (UART1_DR_R & 0xFF);
}

/**
 * uart_handler: This method is used to handle interrupts involving uart
 */
void uart_handler() {
	data = uart_recieve();
	if (data == '.') {
		lcd_clear();
		len = 0;
	} else
		lcd_putc(data);
	message[len] = data;
	len++;
	if (data == ',') {
		lcd_clear();
		lcd_printf("%s", message);
		//Handle move inputs
		if (message[1] == 'f' || message[1] == 'l' || message[1] == 'r'
				|| message[1] == 'b') {
			char sub[4];
			int c = 0;
			while (c < 3) {
				sub[c] = message[2 + c];
				c++;
			}
			sub[c] = '\0';
			int target = atoi(sub);
			lcd_printf("%i , %s", target, sub);
			if (message[1] == 'f') {
				move_forward(target);
				sprintf(positionStr, ".o %c %d %d,", currentPosition.appCommand,
						botX, botY);
				uart_sendStr(positionStr);
			} else if (message[1] == 'b') {


				move_backward(target);
				sprintf(positionStr, ".o %c %d %d,", currentPosition.appCommand,
						botX, botY);
				uart_sendStr(positionStr);
			} else if (message[1] == 'l') {

				turn_left(target);
				sprintf(positionStr, ".o %c %d %d,", currentPosition.appCommand,
						botX, botY);
				uart_sendStr(positionStr);
			} else {

				turn_right(target);
				sprintf(positionStr, ".o %c %d %d,", currentPosition.appCommand,
						botX, botY);
				uart_sendStr(positionStr);
			}
		} else if (message[1] == 'm') {
			playMusic = 1;
		} else if (message[1] == 's') {
			scan = 1;
		} else if (message[1] == 'z'){
			freeWilli = 1;
		}
	}

	UART1_ICR_R |= 0x0030;
}

/**
 * print: This method is used to send information back to putty formatted
 *
 * CALL THIS METHOD
 *
 * @param dir: the string which holds the direction the cybot should go
 * @param dist: The distance the cybot should travel
 */
void print(char* dir, int dist) {
	char mes[21] = { 0 };
	char* buffer;
	int i;
	strcat(mes, "DIR: ");
	strcat(mes, dir);
	strcat(mes, "\r\nDIST: ");
	asprintf(&buffer, "%i", dist);
	strcat(mes, buffer);
	strcat(mes, "\0");

	for (i = 0; i < strlen(mes); i++) {
		uart_sendChar(mes[i]);
		timer_waitMillis(10);
	}
	uart_sendChar('\r');
	uart_sendChar('\n');
}


/*
 * uart_sendStr: Helper method used for sending a string to putty
 *
 * @param data: Char array we want to send to putty
 */
void uart_sendStr(const char *data) {
	//until we reach a null character
	int i = 0;
	while (i < strlen(data)) {
		//send the current character
		uart_sendChar(data[i]);
		// increment the pointer.
		i++;
	}
}














