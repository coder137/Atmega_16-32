#ifndef _SERIALIMPROVED_H
#define _SERIALIMPROVED_H

//since we use the FILE pointer
#include <stdio.h>
#include <stdarg.h>

/*
THIS LIBRARY is to be used with the Serial.h library,

we can use printf and scanf from stdio.h library
	this is heavy

function p and s use vfprintf and vfscanf
	this is more optimized
*/

int si_putchar(char c, FILE *stream);

int si_getchar(FILE *stream);

//setup
void si_init();

//functions p and s use vfprintf and vfscanf
void p(char * fmt, ...);

void s(char * fmt, ...);

#endif
