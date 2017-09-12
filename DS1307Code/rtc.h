#ifndef _RTC_H
#define _RTC_H

//Tested with DS1307

void rtc_init();
void rtc_write(unsigned char, unsigned char);
unsigned char rtc_read(unsigned char);

//char address, char* data (provided to store data), length to be stored
void rtc_multiread(unsigned char, unsigned char*, unsigned char);

#endif
