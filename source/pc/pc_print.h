/*
 * pc_print.h
 *
 *  Created on: Sep 29, 2019
 *      Author: azzentys
 */

#ifndef PC_PC_PRINT_H_
#define PC_PC_PRINT_H_
#endif /* PC_PC_PRINT_H_ */

#include <stdio.h>
#include <stdint.h>

#define RED 	(0)
#define BLUE 	(1)
#define GREEN 	(2)

void proc_init(void);
void led_execute(uint8_t flag, uint8_t mode);
