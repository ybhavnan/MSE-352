// 352 Project 
 
 
#include <reg51.h>
#include <stdio.h>

// constants
float duty_cycle = 0.0;

// function declarations 
float readInputs(unsigned char input);

void main(void)
{
	unsigned char z;
	z = P1;
	z = z&0x07; // monitor the last 3 bits(P0 to P3)00000111
		//z = 000;
	duty_cycle = readInputs(z);
	printf("duty cycle: %f", duty_cycle);
}


/* Inputs and the corresponding duty_cycle 
0 0 0 z = 0; 0% 0 0 1 z = 110% 0 1 0 z =2; 30% 0 1 1 40% 1 0 0 50%  1 0 1 70%  1 1 0 80%  1 1 1 100% */ 

float readInputs(unsigned char input)
{
	float duty_cycle;
	switch(input)
	{
		case(0): // 0%
			duty_cycle = 0;
			break;
		
		case(1): // 10%
			duty_cycle = 0.1;
			break;
		
		case(2): // 30%
			duty_cycle = 0.3;
			break;

		case(3): // 40%
			duty_cycle = 0.4;
			break;
			
		case(4): // 50%
			duty_cycle = 0.5;
			break;
			
		case(5): // 70%
			duty_cycle = 0.7;
			break;
		
		case(6): // 80%
			duty_cycle = 0.8;
			break;
		
		case(7): // 100%
			duty_cycle = 1;
			break;
	}
	return duty_cycle;
}