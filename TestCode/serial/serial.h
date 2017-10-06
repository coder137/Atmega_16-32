#ifndef _SERIAL_H
#define _SERIAL_H

/*
USART Baud Rate Register
UBRR	16bit register for setting Baud Rate
UBRR = (F_CPU/16*BaudRate) -1 

UDR = USART Data Register

UCSRA, UCSRB, UCSRC = USART Control Status Register

UCSRA
RXC 	TXC		UDRE	FE		DOR		PE		U2X		MPCM

UCSRB
RXCIE	TXCIE	UDRIE	RXEN	TXEN	UCSZ2	RXB8	TXB8

UCSRC
URSEL	UMSEL	UPM1	UPM0	USBS	UCSZ1	UCSZ0	UCPOL

*/


/*
Here both the Tx and Rx are initialized
*/

//baud
void serial_init(unsigned int baud);

unsigned char serial_rx();

//data(char)
void serial_tx(unsigned char data);

//data(string)
void serial_tx_str(char* str);

//return a string
//char* serial_rx_str();

#endif