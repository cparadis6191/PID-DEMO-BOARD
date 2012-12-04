#ifndef _PID_DEMO_BOARD_H_
#define _PID_DEMO_BOARD_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "feedback.h"


volatile extern int TIMER_FLAG;


// Set up a timer to use for each iteration of the feedback loop
void timer_init(void);

#endif