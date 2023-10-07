/*
 * seven_segment_display_function.cpp
 *
 * Created: 10/7/2023 1:20:03 PM
 * Author : amira
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

uint8_t digit[10] = {	0b0111111, // -> 0
						0b0000110, // -> 1
						0b1011011, // -> 2
						0b1001111, // -> 3
						0b1100110, // -> 4
						0b1101101, // -> 5
						0b1111100, // -> 6
						0b0000111, // -> 7
						0b1111111, // -> 8
						0b1101111  // -> 9
};


void show(uint32_t value);


int main(void)
{
	DDRC = 0xff;
	DDRD = 0xff;
		
		
			
	/* Replace with your application code */
	while (1)
	{	
		show(1400);
	}
}



void show(uint32_t value)
{
	uint8_t n = 0;	
	while(value > 0){
		PORTD = 0xff;
		PORTC = digit[value % 10];
		PORTD = ~(0b00000001 << n);
		value = value / 10;
		_delay_ms(7);
		n++;
	}
}
