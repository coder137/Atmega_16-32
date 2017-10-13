# Atmega_16-32

Code for Atmega16/32 based microcontrollers


# Usage

#### Windows

* Install mingw and add it to your path
* Install AVR Package in Sublime Text and create new project
* `make` the folder in which project exists


# Libraries

### Communication

* Serial Communication library
* I2C/TWI Communication library
* Serial Improved Communication library

### Interfacing

* Keypad Interfacing library
* LCD Interfacing library
* DS1307 Interfacing library
* Conversions library (ASCII to DEC, BCD to ASCII)


# To Add

* Timer Interfacing library
* Interrupt Interfacing library
* ADC/DAC Interfacing library
* SPI Communication library
* PWM library
* `Time.h` library for Interfacing with ds1307 RTC


# .gitignore

Not ignored any .c / .h file and Makeile

ignored files
* .d
* .o
* .elf
* .hex
* .lst
* .map
