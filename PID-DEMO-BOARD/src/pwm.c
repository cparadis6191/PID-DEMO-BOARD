#include "pwm.h"

void pwm_init(void) {
	// Set OR1A as an output
	PORTB = (1 << PB0);
	
	// Toggle OC1A on CNT match with OCR1A
	// Non-inverting mode
	TCCR1A = ((1 << COM1A1) | (1 << WGM10));
	
	// Phase and frequency correct PWM
	TCCR1B = (1 << WGM13);
	
	// Set the top to 0 initially
	// This will drive the motor very lightly until readings are taken
	OCR1A = 0;
	
	
	return;
}

void pwm_adjust(uint8_t top) {
	
		
	return;
}