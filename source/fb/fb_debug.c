/*
 * fb_debug.c
 *
 *  Created on: Oct 1, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */

// Including all the required header files
#include "fb_debug.h"
#include "board.h"
#include "fsl_debug_console.h"

/*
 * Function - debug
 * Arguments -
 * loop_num : used to print the loop counter value used when creating
 * delay
 * Brief - printing debug information
 *
 */
void debug(uint16_t loop_num)
{
	print();
	PRINTF("\t%d\n", loop_num * 2300);
}

/*
 * Function - print
 * Arguments - void
 * Brief - collects and prints correct debug information
 * This is logically similar to led_execute function in pc_print.c
 * however, I didn't choose to abstract it out
 */
static void print(void)
{
	// char pointers to hold strings
	char *led = NULL;
	char *state = NULL;

	// Logic for color
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

	// Logic for ON/OFF
	if (mode == 1)
	{
		state = "OFF";
	}
	else if (mode == 0)
	{
		state = "ON";
	}

	// Printing them to console
	PRINTF("LED %5s %3s\t", led, state);
}
