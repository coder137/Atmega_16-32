#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"

int main(void)
{
	serial_init(9600);
	while(1)
	{
		//Data echo example
		unsigned char data = serial_rx();
		serial_tx('{');
		serial_tx(data);
		serial_tx('}');		
	}
}