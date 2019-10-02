/*
 * fb_loop.c
 *
 *  Created on: Sep 28, 2019
 *      Author: azzentys
 */

#include "fb_loop.h"

void loop(uint16_t number)
{
	uint64_t loop_var = number * 2300;
	while((loop_var) != 0)
	{
		loop_var--;
		__asm volatile ("nop");
	}
}
