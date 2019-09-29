/*
 * pc_timestamp.c
 *
 *  Created on: Sep 29, 2019
 *      Author: azzentys
 */

#include "pc_timestamp.h"

void add_time_stamp(void)
{
	time_t epoch = time(NULL);
	struct tm *time_stamp = localtime(&epoch);
	printf("%d:%d:%d\t", time_stamp->tm_hour, time_stamp->tm_min, time_stamp->tm_sec);
}
