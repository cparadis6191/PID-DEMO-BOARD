#include "motor.h"


void motor_init(void) {
	// Set the motor control lines as outputs
	MOTOR_A |= MOTOR_1A;
	MOTOR_B |= MOTOR_2A;
	
	
	return;
}


void motor_brake_cw(void) {
	MOTOR_A |= MOTOR_1A;
	MOTOR_B &= ~MOTOR_2A;
	
	
	return;
}


void motor_rotate_ccw(void) {
	MOTOR_A &= ~MOTOR_1A;
	MOTOR_B = MOTOR_2A;
	
	
	return;
}