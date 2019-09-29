/*
 * pc_print.c
 *
 *  Created on: Sep 28, 2019
 *      Author: azzentys
 */

#include "pc_print.h"

void proc_init(void)
{
	;
}

void led_execute(uint8_t flag, uint8_t mode)
{
	char *led = NULL;
	char *state = NULL;
	if (flag == RED)
	{
		led = "RED";
	}
	else if (flag == RED)
	{
		led = "RED";
	}
	else if (flag == RED)
	{
		led = "RED";
	}

	if (mode == 0)
	{
		state = "OFF";
	}
	else if (mode == 1)
	{
		state = "ON";
	}

	printf("LED %5s %3s\n", led, state);
}
