#include "motor.h"


void motor_init(void) {
	// Set the motor control lines as outputs
	MOTOR_A |= MOTOR_1A;
	MOTOR_B |= MOTOR_2A;
	
	
	return;
}