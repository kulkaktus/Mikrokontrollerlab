/*
 * switch.c
 *
 * Created: 20.03.2017 17:37:04
 *  Author: didrikr
 */ 
#include <avr/io.h>

void switch_init(){
	DDRB &= ~((1 << DDB1) | (1 << DDB3) | (1 << DDB5) | (1 << DDB7)); 
}

int switch_read(int n){
	return (PINB & (1 << n*2+1)); 
}