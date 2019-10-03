/*
 * pc_print.c
 *
 *  Created on: Sep 28, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */

#include "pc_print.h"

/*
 * Function - proc_init
 * Arguments - none
 * Brief - Just a placeholder function
 *
 */
void proc_init(void)
{
	while(0)
	{
		;
	}
}

/*
 * Function - led_execute
 * Arguments - none
 * Brief - PC version of execution - just prints LED ON/OFF
 *
 */
void led_execute(void)
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

	// Printing them
	printf("\nLED %5s %3s\t", led, state);
}
