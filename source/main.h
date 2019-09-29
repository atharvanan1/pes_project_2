/*
 * main.h
 *
 *  Created on: Sep 28, 2019
 *      Author: azzentys
 */

#ifndef SOURCE_MAIN_H_
#define SOURCE_MAIN_H_
#endif /* SOURCE_MAIN_H_ */

#include <stdint.h>

#ifdef PC_RUN
	#include "pc_loop.h"
	#include "pc_print.c"
#elif FB_RUN
	#include "fb_loop.h"
	#include "fb_led.h"
#elif FB_DEBUG
	#include "fb_loop.h"
	#include "fb_led.h"
#elif PC_DEBUG
	#include "pc_loop.h"
	#include "pc_print.c"
#endif
