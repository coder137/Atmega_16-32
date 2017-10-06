#include <avr/io.h>
#include <util/delay.h>

#include <stdio.h>

#include "serial.h"
#include "serialImproved.h"


int main(void)
{
	serial_init(9600);
	si_init();

	int standard;
	printf("Input a number, For ex: %d\n>", 937);
	scanf("%d", &standard);
	printf("NUM OUT:%d\n", standard);
	
	int new;
	p("Input a number, For ex: %d \n>", 712);
	s("%d", &new);
	p("new NUM OUT: %d\n\n\n", new);
	
	while(1);
}
