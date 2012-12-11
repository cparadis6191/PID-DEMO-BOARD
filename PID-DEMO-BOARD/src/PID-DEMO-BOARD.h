#ifndef _PID_DEMO_BOARD_H_
#define _PID_DEMO_BOARD_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "feedback.h"
#include "motor.h"


// Global timer flag
volatile extern int g_TIMER_FLAG;


// Set up a timer to use for each iteration of the feedback loop
void timer_init(void);

#endif