#include <avr/io.h>
#include <util/delay.h>

#include "i2c.h"
#include "rtc.h"

void rtc_init()
{
	i2c_init(); //WE ALWAYS NEED TO INIT THIS BUS
	i2c_start();
	i2c_write(0b11010000);
	//there is an ack between here that we arent checking for
	i2c_write(0x07);
	i2c_write(0x00);
	i2c_stop();
	//add a small delay here
	_delay_us(1);
}

void rtc_write(unsigned char address, unsigned char data)
{
	i2c_start();
	i2c_write(0xd0);
	i2c_write(address);
	i2c_write(data);
	i2c_stop();
	//add a small delay here
	_delay_us(1);
}

unsigned char rtc_read(unsigned char address)
{
	unsigned char data;
	i2c_start();
	i2c_write(0xd0);
	i2c_write(address);
	//i2c_stop();
	//IF IT IS A REPEATED START GIVE A SMALL DELAY
	i2c_start();
	i2c_write(0xd1); //SA + R
	data = i2c_read(0); //we send a NACK
	i2c_stop();
	//add a small delay here
	_delay_us(1);
	return data;
}

//WORKS
void rtc_multiread(unsigned char address, unsigned char* data, unsigned char len)
{
	i2c_start();
	//slave write address
	i2c_write(0xd0);
	i2c_write(address);

	//repeated start
	i2c_start();
	//slave read address
	i2c_write(0xd1);
	while(len > 1)
	{
		*data++ = i2c_read(1); //send ack here
		len--;
	}

	*data++ = i2c_read(0); //send nack here
	i2c_stop();
	//keep reading till len ==0
	_delay_us(1);
}
