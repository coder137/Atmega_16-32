#ifndef _LCD_H
#define _LCD_H

//send command
void lcd_Command(unsigned char command);
//send a char
void lcd_Data(unsigned char data);
//init lcd
void lcd_init();

//THIS CODE IS FOR 20*2 LCDS
void lcd_gotoxy(unsigned char line, unsigned char block);

//write a string
void lcd_writeString(char *str); //char type is used for pointers
//convert bcd to ascii
void lcd_writeRTCData(unsigned char data);

#endif
