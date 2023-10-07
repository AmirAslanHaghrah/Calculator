/*
 * 8digit_seven_segment_display.cpp
 *
 * Created: 10/7/2023 12:05:29 PM
 * Author : amira
 */ 
#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
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
		
	DDRC = 0xff;
	DDRD = 0xff;
		
	uint32_t input = 123;
    /* Replace with your application code */
    while (1) 
    {
		//uint32_t N = input;
		//for (int n = 0; n < 6; n++){
			//PORTD = 0xff;
			//PORTC = digit[N % 10];
			//PORTD = ~(0b00000001 << n);
			//N = N / 10;
			//_delay_ms(7);
		//}
		
		uint8_t n = 0;
		uint32_t N = input;
		while(N > 0){
			PORTD = 0xff;
			PORTC = digit[N % 10];
			PORTD = ~(0b00000001 << n);
			N = N / 10;
			_delay_ms(7);
			n++;
		}		
    }
}

