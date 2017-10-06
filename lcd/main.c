#include <avr/io.h>
#include <util/delay.h>

#include <string.h>

#include "lcd.h"

int main()
{
	DDRD = 0xFF;
	PORTD = 0x55;
	
	lcd_init();
	lcd_gotoxy(1, 0);
	lcd_writeString("TIME: ");
	lcd_writeRTCData(0x35);

	while(1)
	{
		//We can input data here ever second
		_delay_ms(1000);
	}

}
