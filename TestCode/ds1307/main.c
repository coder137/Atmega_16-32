#include <avr/io.h>
#include <util/delay.h>

#include "rtc.h"
#include "serial.h"

int main(void)
{
	serial_init(9600);
	rtc_init();
	rtc_write(0x00, 0x40);
	rtc_write(0x01, 0x00);
	rtc_write(0x02, 0x23);
	
	rtc_write(0x04, 0x11);
	rtc_write(0x05, 0x05);
	rtc_write(0x06, 0x17);
	while(1)
	{
		unsigned char sec = rtc_read(0x00);
		unsigned char min = rtc_read(0x01);
		unsigned char hour = rtc_read(0x02);
		
		unsigned char day = rtc_read(0x04);
		unsigned char month = rtc_read(0x05);
		unsigned char year = rtc_read(0x06);

		//unsigned char min = rtc_read(0x01);
		serial_tx_str("TIME_");
		serial_tx((hour>>4)|0x30);
		serial_tx((hour&0x0f)|0x30);
		serial_tx(':');		
		serial_tx((min>>4)|0x30);
		serial_tx((min&0x0f)|0x30);
		serial_tx(':');		
		serial_tx((sec>>4)|0x30);
		serial_tx((sec&0x0f)|0x30);

		serial_tx_str("_DATE_");
		serial_tx((day>>4)|0x30);
		serial_tx((day&0x0f)|0x30);
		serial_tx(':');		
		serial_tx((month>>4)|0x30);
		serial_tx((month&0x0f)|0x30);
		serial_tx(':');		
		serial_tx((year>>4)|0x30);
		serial_tx((year&0x0f)|0x30);
		serial_tx('\n');		
		
		_delay_ms(1000);
	}
}