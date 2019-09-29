/*
 * main.c
 *
 *  Created on: Sep 28, 2019
 *      Author: azzentys
 */

#include "main.h"


uint16_t time_table[20] = {3000, 1000, 2000, 600, 1000, 400, 1000,\
		                   200, 500, 100, 500, 100, 500, 100, 1000,\
						   200, 1000, 400, 2000, 600};

uint32_t look_up_table[20];

int main(void)
{
	uint8_t looper = 0;
	uint8_t flag = 0;
	uint8_t mode = 0;
	proc_init();

	for (uint8_t i = 0; i < 10; i++)
	{
		for (uint8_t j = 0; j < 20; j++)
		{
			mode = looper % 2;
			flag = looper / 6;
			led_execute(flag, mode);
			loop(time_table[j]);
			(looper == 17)?looper = 0:looper;
			looper++;
		}
	}
	return 0;
}
