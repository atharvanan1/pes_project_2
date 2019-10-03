/*
 * pc_loop.c
 *
 *  Created on: Sep 28, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */

#include "pc_loop.h"

/*
 * Function - loop
 * Arguments -
 * number : taking number to generate desirable delay time
 * Brief - creates a delay based on number
 *
 */
void loop(uint16_t number)
{
	// loop_var will be used to generate delay
	uint64_t loop_var = number * (CLOCKS_PER_SEC - 60000) / 2;
	while(loop_var != 0)
	{
		loop_var--;
		// Assembly instruction to do nothing
		__asm volatile ("nop");
	}
}
