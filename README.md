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

# Improvements

* I2C Communication library
	* Add more robust methods
* RTC_DS1307 Interfacing library
	* Create #define statements to get device slave hex code

# To Add

* RTC_DS3231 Interfacing library
	* Build this on top of the RTC_DS1307 (pure C)
* Timer Interfacing library
* Interrupt Interfacing library
* ADC/DAC Interfacing library
* SPI Communication library
* PWM library
* `Time.h` library for Interfacing with ds1307 and ds3231 RTC


# .gitignore

Not ignored any .c / .h file and Makeile

ignored files
* .d
* .o
* .elf
* .hex
* .lst
* .map
