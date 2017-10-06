#include <avr/io.h>
#include <util/delay.h>

#include <string.h>

#include "lcd.h"

int main()
{	
	DDRD = 0XFF;
	PORTD = 0X55;
	lcd_init();
	lcd_gotoxy(1, 0);
	lcd_writeString("TIME: ");
	lcd_writeRTCData(0x35);

	while(1)
	{
		//We can out data here ever second
	}
}