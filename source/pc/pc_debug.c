/*
 * pc_debug.c
 *
 *  Created on: Oct 1, 2019
 *      Author: azzentys
 */


#include "pc_debug.h"

// Leveraged Code - https://www.adamtornhill.com/Patterns%20in%20C%204,%20OBSERVER.pdf
// Observer Pattern

void debug(void)
{
	prevEvent = thisEvent;
	thisEvent = clock();
	diffEvent = (double)(thisEvent - prevEvent)/CLOCKS_PER_SEC;
	diffEvent = diffEvent * 1000;
	time_t set_time = time(NULL);
	time_data = localtime(&set_time);
	printf("%02d:%02d:%02d  %-4.3lf\n", time_data -> tm_hour, \
			time_data -> tm_min, time_data -> tm_sec, \
			diffEvent);
}
