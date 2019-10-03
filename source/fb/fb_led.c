/*
 * fb_led.c
 *
 *  Created on: Sep 28, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */

#include "fb_led.h"
#include "pin_mux.h"
#include "fsl_gpio.h"
#include "board.h"

/*
 * Function - proc_init
 * Arguments - none
 * Brief - Initialize system peripherals in desired state
 *
 */
void proc_init(void)
{
	// Initialize Pins, Clocks, and DebugConsole
	BOARD_InitPins();
	BOARD_BootClockRUN();
	//BOARD_InitDebugConsole();
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

/*
 * Function - led_execute
 * Arguments - none
 * Brief - Freedom Board version of execution
 *
 */
void led_execute(void)
{
	char *state = NULL;
	if (flag == RED)
	{
		GPIO_WritePinOutput(RED_GPIO, RED_PIN, mode);
	}
	else if (flag == BLUE)
	{
		GPIO_WritePinOutput(BLUE_GPIO, BLUE_PIN, mode);
	}
	else if (flag == GREEN)
	{
		GPIO_WritePinOutput(GREEN_GPIO, GREEN_PIN, mode);
	}
	state = (mode == 1)?"ON":"OFF";
}
