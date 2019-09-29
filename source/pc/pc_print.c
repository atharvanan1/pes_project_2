/*
 * pc_print.c
 *
 *  Created on: Sep 28, 2019
 *      Author: azzentys
 */

#include "pc_print.h"

void proc_init(void)
{
	while(0)
	{
		;
	}
}

void led_execute(uint8_t flag, uint8_t mode)
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

	printf("LED %5s %3s\n", led, state);
}
