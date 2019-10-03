/*
 * pc_debug.h
 *
 *  Created on: Oct 1, 2019
 *  Author: Atharva Nandanwar
 *  Email: Atharva.Nandanwar@Colorado.EDU
 *
 */

#ifndef FB_FB_DEBUG_H_
#define FB_FB_DEBUG_H_
#endif /* FB_FB_DEBUG_H_ */


#include <stdint.h>

#define RED (0)
#define BLUE (1)
#define GREEN (2)

extern uint8_t flag;
extern uint8_t mode;

void debug(uint16_t loop_num);
static void print(void);
