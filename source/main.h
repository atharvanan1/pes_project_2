/*
 * main.h
 *
 *  Created on: Sep 28, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */

#ifndef SOURCE_MAIN_H_
#define SOURCE_MAIN_H_
#endif /* SOURCE_MAIN_H_ */

// Standard inclusions to support fixed width integers,
// and time constructs
#include <stdint.h>
#include <time.h>

// Data types to store processor clock counts,
// and difference between two events
clock_t prevEvent;
clock_t thisEvent;
double diffEvent;

// Struct to store time_data
struct tm *time_data;

// Data types to store flag value, and mode
uint8_t flag;
uint8_t mode;

// Conditional execution according to different
// builds
#ifdef PC_RUN
#include "pc_loop.h"	// contains function with PC loop logic
#include "pc_print.h"	// contains function with PC print logic
#elif PC_DEBUG
#include "pc_loop.h"
#include "pc_print.h"
#include "pc_debug.h"	// contains function with debug logic
#elif FB_RUN
#include "fb_loop.h"    // contains function with Freedom Board
						// loop logic
#include "fb_led.h"		// contains function with Freedom Board
						// led logic
#elif FB_DEBUG
#include "fb_loop.h"
#include "fb_led.h"
#include "fb_debug.h"	// contains function with Freedom Board
						// debug logic
#endif
