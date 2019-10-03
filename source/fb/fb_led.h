/*
 * fb_led.h
 *
 *  Created on: Sep 28, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */

#ifndef FB_FB_LED_H_
#define FB_FB_LED_H_
#endif /* FB_FB_LED_H_ */

#include <stdint.h>

// Macros to simplify things
#define RED 		(0)
#define BLUE 		(1)
#define GREEN 		(2)
#define RED_GPIO 	BOARD_LED_RED_GPIO
#define BLUE_GPIO 	BOARD_LED_BLUE_GPIO
#define GREEN_GPIO 	BOARD_LED_GREEN_GPIO
#define RED_PIN 	BOARD_LED_RED_GPIO_PIN
#define BLUE_PIN  	BOARD_LED_BLUE_GPIO_PIN
#define GREEN_PIN 	BOARD_LED_GREEN_GPIO_PIN
#define LOW 		1
#define HIGH 		0

// Variables declared in main
extern uint8_t flag;
extern uint8_t mode;

void proc_init(void);
void led_execute(void);
