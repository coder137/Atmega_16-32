#include <avr/io.h>
#include <util/delay.h>

#include "i2c.h"

void i2c_init()
{

	TWBR = 72; //16MHZ , 100K I2C SPEED
	//IF TWSR IS ENABLED CHANGE TWBR TO 2;
	///TWSR |= ((1 << TWPS1) | (0 << TWPS0)); //16 + 2*4^2 //we can change the timing, check

	//Enable the TWI MODULE
	TWCR |= (1 << TWEN);
}

void i2c_start()
{
	//Put Start Condition on Bus
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);

	//Poll Till Done
	while(!(TWCR & (1<<TWINT)));
}

void i2c_stop()
{
	//Put Stop Condition on bus
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
	//Wait for STOP to finish
	//NOTE: IS THIS NEEDED?
	while(TWCR & (1<<TWSTO));
}

void i2c_write(unsigned char data)
{
	TWDR=data;	

	//Initiate Transfer
	TWCR=(1<<TWEN)|(1<<TWINT);

	//Poll Till Done
	while(!(TWCR & (1<<TWINT)));
	
	/* DONT NEED ERROR DETECTION, AS OF NOW
	//Check Status
	if((TWSR & 0xF8) == 0x18 || (TWSR & 0xF8) == 0x28 || (TWSR & 0xF8) == 0x40)
	{
		//SLA+W Transmitted and ACK received
		//or
		//SLA+R Transmitted and ACK received
		//or
		//DATA Transmitted and ACK recived

		return 1;
	}
	else
		return 0;	//Error
	*/
}

unsigned char i2c_read(unsigned char ack)
{
	//Now enable Reception of data by clearing TWINT
	TWCR =((1<<TWINT) | (1 << TWEN) | (ack << TWEA));

	//Wait till done
	while(!(TWCR & (1<<TWINT)));
	
	return TWDR;
}