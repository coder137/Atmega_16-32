#ifndef _CONVERSION_H
#define _CONVERSION_H

//TEST THE ENTIRE CODE WITH SERIAL DATA VALUES, BEWARE CHAR* VALUES
///When it comes to strings always use a char* or a char[]
/*
unsigned char and signed char is different from char (NOTE)
*/

void bcd_to_ascii(unsigned char bcd,char *ret);
unsigned char ascii_to_bcd(unsigned char num1, unsigned char num2);

unsigned char bcd_to_decimal(unsigned char bcd);
unsigned char decimal_to_bcd(unsigned char dec);

char* decimal_to_ascii(int dec);
//ascii_to_decimal();
#endif