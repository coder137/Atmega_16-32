#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#include "serial.h"

//Change OSC value if needed
#define OSC F_CPU/16

void serial_init(unsigned int baud)
{
	unsigned int b = ((OSC/baud) - 1);
	UBRRH = (b >> 8); 
	UBRRL = b;
	UCSRB = (1 << TXEN)| (1 << RXEN);
	UCSRC = (1 << UCSZ1) | (1 << UCSZ0) | (1 << URSEL); // 0x06;
}

unsigned char serial_rx()
{
	while(!(UCSRA & (1 << RXC))); //wait here till RXC is 1
	return UDR;
}

void serial_tx(unsigned char data)
{
	while(!(UCSRA & (1 << UDRE))); //wait here till UCSRA is 1
	UDR = data;
}


void serial_tx_str(char* string)
{
	unsigned char i;
	int len = strlen(string);
	for(i=0;i<len;i++)
	{
		serial_tx(*(string + i));
	}
}

/*
char * serial_rx_str()
{
	unsigned char i =0; 
	static char data[10];

	while(data[i] == '\n')
	{
		data[i] = serial_rx();
		//serial_tx(*(data+i));
		i++;
	}

	return data;
}
*/
