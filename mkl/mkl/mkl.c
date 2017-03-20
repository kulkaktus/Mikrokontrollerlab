/*
 * mkl.c
 *
 * Created: 20.03.2017 17:08:06
 *  Author: didrikr
 */ 


#include <avr/io.h>
#include "switch.h"
#include "led.h"
#include "uart.h"
#include "adc.h"

int main(void)
{
	led_init();
	switch_init();
	uart_init();
	adc_init();
	
	
    while(1)
    {
        int x, y;
		
		x = adc_read('x');
		y = adc_read('y');
		
		
		printf("Didrik er en torsk\n");
		printf("X: %d \t Y: %d\n", x, y);
    }
}