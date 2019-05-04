/**
 * main.c - File used to set up interfacing with the android app.
 *			This is where we do polling for interrupts which set flags that then execute
 *			functions based around which flag was set.
 */

#include <final.h>

/*
 * playSong: Loops through all of the preprogramed music and plays all of our songs
 *
 * @param sensor_data: Open interface pointer used for interracting with the hardware.
 */
void playSong(oi_t* sensor_data);

/*
 * button_oi_free: Calls oi free if a function is triggered
 *
 * @param sensor_data: Open interface pointer used for interracting with the hardware.
 */
void button_oi_free(oi_t* sensor_data);

void main(void) {
	oi_t* sensor_data = oi_alloc();											//Allocated oi
	oi_init(sensor_data);													//Initalized sensor data to oi pointer

	adc_init();																//Initalizations
	button_init();
	lcd_init();
	movement_init(sensor_data);
	ping_init();
	servo_ping_init();
	uart_init();


	botX = 3000;
	botY = 3000;
	botAngle = 0;
	char sendStr[256];

	sprintf(sendStr, ".o b 0 0,");											//Calibrates the map on the android app
	uart_sendStr(sendStr);
	sprintf(sendStr, ".o b 3000 3000,");
		uart_sendStr(sendStr);
	sprintf(sendStr, ".o b 6000 6000,");
	    uart_sendStr(sendStr);

	while(1){
		if(playMusic == 1) playSong(sensor_data);							//Checks the playMusic flag to play music

		if(freeWilli == 1) oi_free(sensor_data);							//Checks the freeWilli flag to call oi_free

 		if(scan == 1){
			double degree = 0;
			char message[20]; 												// String to hold measurements
			move_servo(degree); 											//Moves to starting position
			timer_waitMillis(500);
			uart_sendChar('p'); 											//Tells app to wait for more commands
			while(degree < 181){											//Loops through and gets the sensor data
				ping_getDistance();
				ir_getDistance();

				sprintf(message, "%0.2f", ir_distance);
				uart_sendStr(message);
				uart_sendChar(' ');
				lcd_printf("%0.2f", ping_distance);
				sprintf(message, "%0.2f", ping_distance);

				uart_sendStr(message);
				uart_sendChar(',');

				timer_waitMillis(100);
				degree += 2;

				if (degree < 181)
					move_servo(degree);
			}
			scan = 0;
		}
 		button_oi_free(sensor_data);
	}
}


void playSong(oi_t* sensor_data){
	int curPhrase = 0;
	int curSong = 1;

	while(curSong < 20){															//Loops through all 19 songs
		music_init(curSong);
		while(curPhrase < 4){
			oi_play_song(curPhrase);
			oi_update(sensor_data);

			while(sensor_data -> songPlaying == 1) oi_update(sensor_data);			//Checks if a song is playing

			curPhrase++;
		}
		curPhrase = 0;
		curSong++;
	}
	playMusic = 0;
}

void button_oi_free(oi_t* sensor_data) {											//Frees the oi
    if (~GPIO_PORTE_DATA_R & 0x3F) {
        oi_free(sensor_data);
        lcd_printf("Cleared");
    }
}





















