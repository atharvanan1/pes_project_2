/*
 * fb_loop.c
 *
 *  Created on: Sep 28, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */

#include "fb_loop.h"

/*
 * Function - loop
 * Arguments -
 * number : used to generate variable delay
 * Brief - produces variable delay for freedom board
 *
 */
void loop(uint16_t number)
{
	uint64_t loop_var = number * 2300;
	while((loop_var) != 0)
	{
		loop_var--;
		__asm volatile ("nop");
	}
}
