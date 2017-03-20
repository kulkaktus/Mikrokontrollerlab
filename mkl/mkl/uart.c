/*
 * uart.c
 *
 * Created: 20.03.2017 18:39:24
 *  Author: didrikr
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "uart.h"


#define F_CPU 16000000
static FILE usart_stdout = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);

void uart_init(){
	unsigned long baud = 19200;
	unsigned long ubrrval = (F_CPU/16)/baud-1;
	/* Set baud rate*/
	UBRR1 = ubrrval;
	/* Enable transmitter*/
	UCSR1B = (1<<TXEN1);
	/*Set frame format: 8data*/
	UCSR1C = (3<<UCSZ10);
	
	stdout = &usart_stdout;
}


int uart_putchar(char c){
	while (!(UCSR1A & (1 << UDRE1))){
		;
	}
	UDR1 = c;
	return 0;
}


