/*
 * led.c
 *
 * Created: 20.03.2017 17:37:14
 *  Author: didrikr
 */ 
#include <avr/io.h>

void led_init(){
	// Sett input og output. 0 er input. LED og switch annenhver
	DDRB |= 0b01010101;
	
	for (int i=0; i<4; i++){
		led_set(i, 0);
	}
	
}

void led_set(int n, int v){
	// Skifter bit v n plasser inn i register PORTB
	if (v == 1){
		PORTB &= ~(1 << 2*n);
	}
	else{
		PORTB |= (1 << 2*n);
	}
}