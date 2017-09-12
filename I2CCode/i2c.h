#ifndef _I2C_H
#define _I2C_H

/*
Init the RTC
*/
void i2c_init();

/*
Send the START / STOP signal
*/
void i2c_start();
void i2c_stop();

/*Write one byte (8 bit) of data */
void i2c_write(unsigned char);

/*Read one byte (8 bit) of data*/
unsigned char i2c_read(unsigned char);

#endif
