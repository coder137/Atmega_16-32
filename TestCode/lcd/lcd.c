#include <avr/io.h>
#include <util/delay.h>

#include <string.h>

#include "lcd.h"

// PIN CONFIG
#define lcd_ddr DDRB
#define lcd_port PORTB
#define lcd_pin PINB

//command pins, USE WITH rs, rw and en
#define c_ddr DDRC
#define c_port PORTC
#define c_pin PINC

//0x07
#define rs 0
#define rw 1
#define en 2



void lcd_Command(unsigned char command)
{
	lcd_port = command;
	c_port &= ~(1 << rs);
	c_port &= ~(1 << rw);
	c_port |= (1 << en);

	_delay_us(1);

	c_port &= ~(1 << en);
	_delay_us(100);
}

void lcd_Data(unsigned char data)
{
	lcd_port = data;
	c_port |= (1 << rs);
	c_port &= ~(1 << rw);
	c_port |= (1 << en);

	_delay_us(1);

	c_port &= ~(1 << en);
	_delay_us(100);
}

void lcd_init()
{
	lcd_ddr = 0xff; //make all ports output
	c_ddr |= (1 << rs) | (1 << rw) | (1 << en); //make all ports output

	c_port &= ~(1 << en);
	_delay_us(2000);

	lcd_Command(0x38); //INIT LCD 2 LINES
	lcd_Command(0x0e); //DISPLAY ON, CURSOR ON
	lcd_Command(0x01); //CLEAR SCREEN
	_delay_us(2000);
	lcd_Command(0x06); //SHIFT CURSOR RIGHT
}


//THIS CODE IS FOR 20*2 LCDS
void lcd_gotoxy(unsigned char line, unsigned char block)
{
	//NOTE: block should be lesser than 20;
	if(line == 1)
	{
		lcd_Command(0x80|block);
	}
	else if(line == 2)
	{
		lcd_Command(0xC0|block);
	}
}

void lcd_writeString(char *str)
{
	int length = strlen(str); //returns an int
	for(int i=0;i<length;i++)
	{
		lcd_Data(str[i]);
	}
}

void lcd_writeRTCData(unsigned char data)
{
	lcd_Data((data >> 4)|0x30); //get msb first
	lcd_Data((data & 0x0f)| 0x30); //get lsb later
}
