/*
 * pc_debug.h
 *
 *  Created on: Oct 1, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */

#ifndef PC_PC_DEBUG_H_
#define PC_PC_DEBUG_H_
#endif /* PC_PC_DEBUG_H_ */

#include <stdio.h>
#include <time.h>
#include <stdint.h>

// Variables declared in main
extern clock_t prevEvent;
extern clock_t thisEvent;
extern double diffEvent;
extern struct tm *time_data;

void debug(uint16_t loop_num);
