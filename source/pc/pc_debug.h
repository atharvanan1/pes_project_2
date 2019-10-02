/*
 * pc_debug.h
 *
 *  Created on: Oct 1, 2019
 *      Author: azzentys
 */

#ifndef PC_PC_DEBUG_H_
#define PC_PC_DEBUG_H_
#endif /* PC_PC_DEBUG_H_ */

#include <stdio.h>
#include <time.h>

extern clock_t prevEvent;
extern clock_t thisEvent;
extern double diffEvent;
extern struct tm *time_data;

void debug (void);
