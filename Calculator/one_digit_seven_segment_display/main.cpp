/*
 * one_digit_seven_segment_display.cpp
 *
 * Created: 10/7/2023 10:50:32 AM
 * Author : amiraslan haghrah
 */ 

#define  F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	uint8_t  digit[10] = {	0b0111111, // -> 0
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
	
	DDRC = 0xff;	// All pins as output
	
    /* Replace with your application code */
    while (1) 
    {
		for (int8_t i = 9; i >= 0; i--)
		{
			PORTC = digit[i];
			_delay_ms(500);
		}
    }
}

