/*
 * main.c
 *
 *  Created on: Sep 28, 2019
 *      Author: azzentys
 */

#include "main.h"

#ifdef FB_RUN
	#include "fb_loop.h"
	#include "fb_led.h"
#elif FB_DEBUG
	#include "fb_loop.h"
	#include "fb_led.h"
#elif PC_RUN
	#include "pc_loop.h"
	#include "pc_print.h"
#elif PC_DEBUG
	#include "pc_loop.h"
	#include "pc_print.h"
#endif

uint16_t time_table[20] = {3000, 1000, 2000, 600, 1000, 400, 1000,\
		                   200, 500, 100, 500, 100, 500, 100, 1000,\
						   200, 1000, 400, 2000, 600};

uint32_t look_up_table[20];

int main(void)
{
	uint8_t looper = 0;
	uint8_t flag = 0;
	for (uint8_t i = 0; i < 10; i++)
	{
		for (uint8_t j = 0; j < 20; j++)
		{
			loop(time_table + j);
			led_execute(flag);
			flag = looper % 3;
			looper++;
		}
	}
	return 0;
}
