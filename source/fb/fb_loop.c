/*
 * fb_loop.c
 *
 *  Created on: Sep 28, 2019
 *      Author: azzentys
 */

#include "fb_loop.h"

void loop(uint16_t number)
{
	for (uint16_t i = 2000; i > 0; i--)
	{
		while(number != 0)
		{
			number--;
			__asm("NOP");
		}
	}
}
