#ifndef _LCD_H
#define _LCD_H

//send command
void lcd_Command(unsigned char);
//send a char
void lcd_Data(unsigned char);
//init lcd
void lcd_init();

//THIS CODE IS FOR 20*2 LCDS
void lcd_gotoxy(unsigned char, unsigned char);

//write a string
void lcd_writeString(char *); //char type is used for pointers

//Use with I2C RTC for BCD to ASCII conversions
//convert bcd to ascii
void lcd_writeRTCData(unsigned char);
void lcd_writeTimeString(unsigned char, unsigned char, unsigned char);

#endif
