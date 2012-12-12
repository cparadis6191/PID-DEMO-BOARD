#ifndef _PWM_H_
#define _PWM_H_

#include <avr/io.h>

void pwm_init_A(void);
void pwm_init_B(void);

void pwm_adjust(double controller_output);

#endif