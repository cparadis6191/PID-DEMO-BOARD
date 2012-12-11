#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <avr/io.h>

#define MOTOR_A DDRD
#define MOTOR_B DDRB
#define MOTOR_1A (1 << PD6)
#define MOTOR_2A (1 << PB3)


void motor_init(void);


#endif