/*
 * fb_loop.c
 *
 *  Created on: Sep 28, 2019
 *      Author: azzentys
 */

#include "fb_loop.h"

void loop(uint16_t number)
{
	uint64_t something = 1600000;
	while((something * number) != 0)
	{
		something--;
		__asm("NOP");
	}
}
