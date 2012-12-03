#ifndef _PWM_H_
#define _PWM_H_

#include <avr/io.h>


void pwm_init(void);

void pwm_adjust(uint8_t top);

#endif