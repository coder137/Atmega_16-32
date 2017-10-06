#include <avr/io.h>
#include <util/delay.h>

#include "Keypad.h"
#include "serial.h"


/*
Use the Serial Library with this code
*/
int main(void)
{
	serial_init(9600);
	serial_tx_str("Input Data>\n");
	while(1)
	{
		//get 5 characters
		unsigned char i=0;
		unsigned char data[5];
		for(i=0;i<5;i++)
		{
			//get data from keypad
			data[i] = getKeypadData();
			//while(buttonState() == 1); //stay here while key is pressed (OLD)
			serial_tx(data[i]); //since this is in ascii we can directly print to terminal
		}
		
		serial_tx_str("The Entire Char STR is\n");
		for(i=0;i<5;i++)
		{
			serial_tx(data[i]);
		}

	}
}
