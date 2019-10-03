/*
 * fb_debug.c
 *
 *  Created on: Oct 1, 2019
 *      Author: azzentys
 */


#include "fb_debug.h"
//#include "fsl_rtc.h"
#include "board.h"
#include "fsl_debug_console.h"

// Leveraged Code - https://www.adamtornhill.com/Patterns%20in%20C%204,%20OBSERVER.pdf
// Observer Pattern

//void rtc_init(void)
//{
//	rtc_config_t set_config;
//	set_config.compensationInterval = 0;
//	set_config.compensationTime = 0;
//	set_config.supervi//sorAccess = false;
//	set_config.updateMode = false;
//	set_config.wakeupSelect = false;
//
//	RTC_Init(RTC, &set_config);
//
//	rtc_datetime_t set_date;
//	set_date.year = 0;
//	set_date.month = 0;
//	set_date.day = 0;
//	set_date.hour = 0;
//	set_date.minute = 0;
//	set_date.second = 0;
//	RTC_SetDatetime(RTC, &set_date);
//}

void debug(void)
{
	//rtc_datetime_t *get_date;
    BOARD_InitDebugConsole();
	/* Print a note to terminal. */
	PRINTF("\r\n GPIO Driver example\r\n");
	PRINTF("\r\n The LED is taking turns to shine.\r\n");
//	RTC_GetDatetime(RTC, get_date);
}
/*
static void print(uint8_t flag, uint8_t mode)
{
	char *led = NULL;
	char *state = NULL;
	if (flag == RED)
	{
		led = "RED";
	}
	else if (flag == BLUE)
	{
		led = "BLUE";
	}
	else if (flag == GREEN)
	{
		led = "GREEN";
	}

	if (mode == 1)
	{
		state = "OFF";
	}
	else if (mode == 0)
	{
		state = "ON";
	}

	//PRINTF("\nLED %5s %3s\t", led, state);
}*/
