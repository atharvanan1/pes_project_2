/*
 * fb_led.h
 *
 *  Created on: Sep 28, 2019
 *      Author: azzentys
 */

#ifndef FB_FB_LED_H_
#define FB_FB_LED_H_
#endif /* FB_FB_LED_H_ */

#include <stdint.h>
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_gpio.h"
#include "board.h"

#define RED 		(0)
#define BLUE 		(1)
#define GREEN 		(2)
#define RED_GPIO 	BOARD_LED_RED_GPIO
#define BLUE_GPIO 	BOARD_LED_BLUE_GPIO
#define GREEN_GPIO 	BOARD_LED_GREEN_GPIO
#define RED_PIN 	BOARD_LED_RED_GPIO_PIN
#define BLUE_PIN  	BOARD_LED_BLUE_GPIO_PIN
#define GREEN_PIN 	BOARD_LED_GREEN_GPIO_PIN
#define HIGH 		1
#define LOW 		0

void proc_init(void);
void led_execute(uint8_t flag, uint8_t mode);
