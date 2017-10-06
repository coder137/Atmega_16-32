#ifndef _I2C_H
#define _I2C_H

void i2c_init();

void i2c_start();
void i2c_stop();

void i2c_write(unsigned char);
unsigned char i2c_read(unsigned char);


#endif