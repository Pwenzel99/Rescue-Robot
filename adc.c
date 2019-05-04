/**
 * ADC - All code required to get feedback from the IR sensor and format it to human readable information.
 *
 * @author Ryan Lanciloti
 *
 */


#include <adc.h>

/*
 * ir_value: Raw value from the IR sensor
 */
double ir_value;

/*
 * ir_distance: Calculated distance from IR sensor
 */
double ir_distance;

/**
 * adc_init: This method is resposible for initalizing
 * the adc
 *
 */
void adc_init(){
	ir_value = 0;
	ir_distance = 0;

	SYSCTL_RCGCADC_R |= 0x01;		//Enables clock for ADC0
	SYSCTL_RCGCGPIO_R |= 0x02;		//ACD Pin 4

	GPIO_PORTB_AFSEL_R |= 0x10;		//Set alternate function
	GPIO_PORTB_DIR_R &= 0xEF;		//Sets input on pin 4
	GPIO_PORTB_DEN_R &= 0xEF;		//Disables digital mode for pin 4
	GPIO_PORTB_AMSEL_R |= 0x10;		//Sets analog mode on pin 4

	ADC0_ACTSS_R &= 0xFFFE;
	GPIO_PORTB_ADCCTL_R = 0x00;		//Sets adc to be triggered by software

	ADC0_EMUX_R &= 0xFFF0;			//Sets ADC0 to trigger using ADCPSSI
	ADC0_SSMUX0_R |= 0x0000000A;	//Sample channel 10

	ADC0_SSCTL0_R = 0x00000000;
	ADC0_SSCTL0_R |= 0x00000006;

	ADC0_ACTSS_R |= 0x0001;
}

/**
 * adc_read: This method is responsible for reading values from the adc
 *
 * @return adc value
 */
int adc_read(){
	ADC0_PSSI_R |= 0x01;

	while((ADC0_RIS_R & 0x01) == 0);

	ADC0_ISC_R = 0x01;

	return (ADC0_SSFIFO0_R);
}

/**
 * adc_read_avg: This method is responsible for taking the average of
 * 16 samples from the adc
 *
 */
void adc_read_avg(){
	int avg =0;
	int i;
	for(i =0; i<16; i++){
		avg+=adc_read();
	}
	ir_value = (double)(avg/16);
}

/**
 * ir_calibrate: This method serves as a helper method for calibrating
 * the ir sensor
 */
void ir_calibrate(){
	lcd_init();
	adc_init();
	uart_init();
	ping_init();
	servo_ping_init();

	char mes[100];

	while(1){
		ir_getDistance();
		memset(mes, 0, strlen(mes));
		sprintf(mes, "%0.2f,%0.0f\n\r", ir_distance, ir_value);
		lcd_printf("Dist: %0.2fcm\nRaw:%0.2f\n", ir_distance, ir_value);
		timer_waitMillis(100);
	}
}

/**
 * getDistance: Scales the distance from the IR scanner
 *
 */
void ir_getDistance(){
	adc_read_avg();
	ir_distance = 138421*pow(ir_value,-1.2058);
}


















