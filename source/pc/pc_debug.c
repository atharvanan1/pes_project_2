/*
 * pc_debug.c
 *
 *  Created on: Oct 1, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */


#include "pc_debug.h"

// Leveraged Code - https://stackoverflow.com/questions/5248915/execution-time-of-c-program
// Time Difference

/*
 * Function - debug
 * Arguments -
 * loop_num : for pc version, this number means nothing
 * Brief - prints out debug information
 *
 */
void debug(uint16_t loop_num)
{
	// Algorithm to calculate time difference
	prevEvent = thisEvent;
	thisEvent = clock();
	diffEvent = (double)(thisEvent - prevEvent)/CLOCKS_PER_SEC;
	diffEvent = diffEvent * 1000;

	// Code to get timestamp
	time_t set_time = time(NULL);
	time_data = localtime(&set_time);
	printf("%02d:%02d:%02d  %-4.3lf\n", time_data -> tm_hour, \
			time_data -> tm_min, time_data -> tm_sec, \
			diffEvent);
}
