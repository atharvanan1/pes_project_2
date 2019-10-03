/*
 * pc_print.h
 *
 *  Created on: Oct 1, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */

#ifndef PC_PC_PRINT_H_
#define PC_PC_PRINT_H_
#endif /* PC_PC_PRINT_H_ */

#include <stdio.h>
#include <stdint.h>

// Macros to simplify understanding which color
// is referred
#define RED (0)
#define BLUE (1)
#define GREEN (2)

// Variables declared in main
extern uint8_t flag;
extern uint8_t mode;

void proc_init(void);
void led_execute(void);
