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
#include <time.h>

clock_t prevEvent;
clock_t thisEvent;
double diffEvent;

struct tm *time_data;

uint8_t flag;
uint8_t mode;

#ifdef PC_RUN
#include "pc_loop.h"
#include "pc_print.h"
#elif PC_DEBUG
#include "pc_loop.h"
#include "pc_print.h"
#include "pc_debug.h"
#elif FB_RUN
#include "fb_loop.h"
#include "fb_led.h"
#elif FB_DEBUG
#include "fb_loop.h"
#include "fb_led.h"
#include "fb_debug.h"
#endif
