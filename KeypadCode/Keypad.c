#include <avr/io.h>
#include <util/delay.h>

#include "Keypad.h"

#define KEYPAD_DDR DDRA
#define KEYPAD_PORT PORTA
#define KEYPAD_PIN PINA

unsigned char keypadScan()
{	
	///Scan the Keypad
	unsigned char columns = 0x00, rows = 0x00; //give it a set value
	unsigned char ret;
	KEYPAD_DDR = 0b00001111; //make the rows ouput and the columns input 
	KEYPAD_PORT = 0b11110000;	//set the input high(Z), output low
	_delay_us(5); //we need to wait here for the above instructions to set

	//we read only columns
	columns = KEYPAD_PIN; //xxxx0000, one of the columns will be either high or low

	KEYPAD_DDR = ~KEYPAD_DDR; //do the opposite of the above step
	KEYPAD_PORT = ~KEYPAD_PORT; //^^
	_delay_us(5); 

	rows = KEYPAD_PIN & 0x0f; //this becomes //xxxx xxxx
	
	ret = columns|rows;
	_delay_us(10); 
	return ret;
}


unsigned char getKeypadData()
{
	while(1)
	{
		unsigned char state, dat;
		state = buttonState();
		if(state == 1)
		{
			dat = keypadScan();
			return buttonValue(dat); //we send the appropriate ascii value
		}
	}
}

unsigned char buttonState()
{
	if(keypadScan() != 0xff)
	{
		//button is pressed
		return 1;
	}
	else
	{
		//button is not pressed, keypadScan == 0xff
		return 0;
	}
}

/*
		1 		2  		3
4 		1 		2 		3

3		4 		5 		6

2 		7 		8 		9

1 		* 		0 		#
*/

unsigned char buttonValue(unsigned char buttonPress)
{
	///WE SEND ASCII VALUES
	//01111110[1] //10111110 [4]
	buttonPress = ~buttonPress;
	//10000001[1] //01000001[4]
	if(buttonPress == 0x81) return 0x01;
	if(buttonPress == 0x82) return 0x02;
	if(buttonPress == 0x84) return 0x03;

	if(buttonPress == 0x41) return 0x04;
	if(buttonPress == 0x42) return 0x05; 
	if(buttonPress == 0x44) return 0x06;

	if(buttonPress == 0x21) return 0x07;
	if(buttonPress == 0x22) return 0x08;
	if(buttonPress == 0x24) return 0x09;

	if(buttonPress == 0x11) return 0x0A; //return an equivalent value
	if(buttonPress == 0x12) return 0x00;
	if(buttonPress == 0x14) return 0x0B; //return an equivalent value
}
