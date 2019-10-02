/*
 * fb_debug.c
 *
 *  Created on: Oct 1, 2019
 *      Author: azzentys
 */


#include "fb_debug.h"

// Leveraged Code - https://www.adamtornhill.com/Patterns%20in%20C%204,%20OBSERVER.pdf
// Observer Pattern

void debug(void)
{
	print(flag, mode);
	prevEvent = thisEvent;
	thisEvent = clock();
	diffEvent = (double)(thisEvent - prevEvent)/CLOCKS_PER_SEC;
	diffEvent = diffEvent * 1000;
}

static void print(uint8_t flag, uint8_t mode)
{
	char *led = NULL;
	char *state = NULL;
	if (flag == RED)
	{
		led = "RED";
	}
	else if (flag == BLUE)
	{
		led = "BLUE";
	}
	else if (flag == GREEN)
	{
		led = "GREEN";
	}

	if (mode == 1)
	{
		state = "OFF";
	}
	else if (mode == 0)
	{
		state = "ON";
	}

	PRINTF("\nLED %5s %3s\t", led, state);
}
