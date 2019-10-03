/*
 * fb_debug.c
 *
 *  Created on: Oct 1, 2019
 *      Author: azzentys
 */


#include "fb_debug.h"
#include "board.h"
#include "fsl_debug_console.h"

void debug(uint16_t loop_num)
{
	print(flag, mode);
	PRINTF("\t%d\n", loop_num * 2300);
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

	PRINTF("LED %5s %3s\t", led, state);
}
