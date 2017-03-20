/*
 * adc.c
 *
 * Created: 20.03.2017 19:35:43
 *  Author: didrikr
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "adc.h"

int adc_init(){
	//Enable ADC
	ADCSRA = (1 << ADEN);	
	//Setting prescaling, division factor 128, think this works. Should be 1 1 1
	ADCSRA |= (7 << ADPS0);
}

int adc_read(unsigned char n){
	
	//Choose channel
	if(n == 'y'){
		ADMUX = 0;
	}
	else if (n == 'x'){
		ADMUX = 1;
	}
	else{
		printf("ADC error you suck\n");
		return 0;
	}
	
	//Start conversion
	ADCSRA |= (1 << ADSC);
	
	//Waits for current conversion to finish
	while (! (ADCSRA & (1 << ADIF))){
	}
	
	//Read data
	int result = ADC;
	return result;
}
