/*
 * main.c
 *
 *  Created on: Sep 28, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */

#include "main.h"

uint16_t time_table[20] = {3000, 1000, 2000, 600, 1000, 400, 1000,\
		                   200, 500, 100, 500, 100, 500, 100, 1000,\
						   200, 1000, 400, 2000, 600};

/*
 * Function - main
 * Arguments - none
 * Brief - Manages the logic to toggle the LEDs
 *
 */
int main(void)
{
	// Variable to hold RBG loop iterations
	uint8_t looper = 0;
	// Initialize system
	proc_init();

	// Loop for doing 10 cycles
	for (uint8_t i = 0; i < 10; i++)
	{
		// Loop for cycling in look up table
		for (uint8_t j = 0; j < 20; j++)
		{
			// Switch between alternative ON and OFF
			mode = looper % 2;
			// Change color after 6 led_execute
			flag = looper / 6;
			// Function for LED execution
			led_execute();
			// Delay
			loop(time_table[j]);

			looper++;
			(looper == 18)?looper = 0:looper;

			// Conditional execution for Debug
#if defined(FB_DEBUG) || defined(PC_DEBUG)
			debug(time_table[j]);
#endif
		}
	}
	return 0;
}
