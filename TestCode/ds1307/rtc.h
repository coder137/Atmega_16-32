#ifndef _RTC_H
#define _RTC_H

void rtc_init();
void rtc_write(unsigned char, unsigned char);
unsigned char rtc_read(unsigned char);

//NOTE: MAKE MORE FUNCTIONS LATER ON
//test this
void rtc_multiread(unsigned char, unsigned char*, unsigned char);

#endif