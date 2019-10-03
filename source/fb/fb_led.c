/*
 * fb_led.c
 *
 *  Created on: Sep 28, 2019
 *      Author: azzentys
 */

#include "fb_led.h"
#include "pin_mux.h"
#include "fsl_gpio.h"
#include "board.h"

void proc_init(void)
{
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();
	gpio_pin_config_t red_led = {
	        kGPIO_DigitalOutput, 1,
	    };
	gpio_pin_config_t blue_led = {
	        kGPIO_DigitalOutput, 1,
	    };
	gpio_pin_config_t green_led = {
	        kGPIO_DigitalOutput, 1,
	    };
	GPIO_PinInit(RED_GPIO, RED_PIN, &red_led);
	GPIO_WritePinOutput(RED_GPIO, RED_PIN, LOW);
	GPIO_PinInit(BLUE_GPIO, BLUE_PIN, &blue_led);
	GPIO_WritePinOutput(BLUE_GPIO, BLUE_PIN, LOW);
	GPIO_PinInit(GREEN_GPIO, GREEN_PIN, &green_led);
	GPIO_WritePinOutput(GREEN_GPIO, GREEN_PIN, LOW);
}

void led_execute(uint8_t flag, uint8_t mode)
{
	char *type = NULL;
	char *state = NULL;
	if (flag == RED)
	{
		GPIO_WritePinOutput(RED_GPIO, RED_PIN, mode);
		type = "RED";
	}
	else if (flag == BLUE)
	{
		GPIO_WritePinOutput(BLUE_GPIO, BLUE_PIN, mode);
		type = "BLUE";
	}
	else if (flag == GREEN)
	{
		GPIO_WritePinOutput(GREEN_GPIO, GREEN_PIN, mode);
		type = "GREEN";
	}
	state = (mode == 1)?"ON":"OFF";
}
