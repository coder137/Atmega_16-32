#include "serialImproved.h"
#include "serial.h"

#include <stdio.h>
#include <stdarg.h>

//We define the IO Stream here
static FILE mystdio = FDEV_SETUP_STREAM(si_putchar, si_getchar, _FDEV_SETUP_RW);

void si_init()
{
	stdin = stdout = &mystdio;
	//stderr can also be defined,
	//else stderr == stdout (default)
}

int si_putchar(char c, FILE *stream)
{
	serial_tx(c);
	return 0; //no use
}

int si_getchar(FILE *stream)
{
	int ret = serial_rx();
	serial_tx(ret); //we get visual output of what we are typing
	return ret;
}

void p(char * fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfprintf(&mystdio, fmt, args);
	va_end(args);
}

void s(char * fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfscanf(&mystdio, fmt, args);
	va_end(args);
}
