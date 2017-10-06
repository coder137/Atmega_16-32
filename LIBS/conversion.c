#include "conversion.h"
#include <stdio.h>

//in the form 0x59 to '5', '9'
void bcd_to_ascii(unsigned char bcd, char *ret)
{
	//we need to add a null terminating \0 since C checks for String ends like that
	*ret++ = ((bcd >> 4) | 0x30);
	*ret++ = ((bcd & 0x0f) | 0x30);
	*ret = '\0';

}

//0x31,0x032 to 0x12
unsigned char ascii_to_bcd(unsigned char num1, unsigned char num2)
{
	num1 = num1 & ~(0x30);
	num2 = num2 & ~(0x30);

	return (num1 << 4) | num2;	
}

//0x10 to 10
unsigned char bcd_to_decimal(unsigned char bcd)
{
	return ((bcd>>4)*10 + (bcd&0x0f));
}

//can only be 2 digit decimals
//59 to 0x59 (make sure it is only 2 digits)
unsigned char decimal_to_bcd(unsigned char dec)
{
	return (((dec/10)<<4) + (dec%10));
}

//since it is int it can be 12 digits, 30 to "30"
char* decimal_to_ascii(int dec)
{
	//add the static here else will give warning
	static char str[12]; //12 can do all the conversions comfortably for int
	sprintf(str, "%d", dec);
	return str;
}

//ascii to decimal, 0x31 to 0x01, easy LOL