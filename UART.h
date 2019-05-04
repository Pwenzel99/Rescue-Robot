/*
 * UART.h - Header file used for UART
 *
 *  Created on: Feb 21, 2019
 *      Author: ryanjl9
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "timer.h"
#include "lcd.h"
#include <inc/tm4c123gh6pm.h>
#include "driverlib/interrupt.h"
#include <lab5_scan_data.h>

void uart_init();
void uart_sendChar(char data);
char uart_recieve();
void uart_handler();
void uart_interrupt_init();
void print(char* dir, int dist);
void uart_sendStr(const char *data);
void radarSweep();

extern int scan;
extern int playMusic;
extern int freeWilli;
extern char positionStr[256];

#endif /* UART_H_ */
