#include "pwm.h"

void pwm_init_A(void) {
	// Clear OC0A on CNT match with OCR0A
	// Non-inverting mode
	TCCR0A = ((1 << COM0A1) | (0 << COM0A0) | (1 << WGM00));
	
	// Set the clock prescaler to 1024
	TCCR0B = ((1 << CS00) | (0 << WGM02));
	
	// Set the top to 0 initially
	// This will drive the motor very lightly until readings are taken
	// The H-bridge enable lines are low anyway
	OCR0A = 0;
	
	// Clear the counter
	TCNT0 = 0;
	
	
	return;
}


void pwm_init_B(void) {
	// Clear OC2A on CNT match with OCR1A
	// Non-inverting mode
	TCCR2A = ((1 << COM2A1) | (0 << COM2A0) | (1 << WGM20));
	
	// Phase and frequency correct PWM
	TCCR2B = (1 << CS20) | (0 << WGM22);
	
	// Set the top to 0 initially
	// This will drive the motor very lightly until readings are taken
	// The H-bridge enable lines are low anyway
	OCR2A = 0;
	
	// Clear the counter
	TCNT2 = 0;
	
	
	return;
}


void pwm_adjust(double controller_output) {
	// Set top value
	if (controller_output < 0) {
		// Disable PWM channel B
		DDRB |= (1 << PB3);
		// Enable PWM channel A
		DDRD |= (1 << PD6);
		
		// Make sure the output PWM saturate properly
		OCR0A = ((((int) -controller_output) >> 2) > 0xFF)?0xFF:(((int) -controller_output) >> 2);
		OCR2A = 0;
		
	} else if (controller_output > 0) {
		// Disable PWM channel A
		DDRD |= (1 << PD6);
		// Enable PWM channel B
		DDRB |= (1 << PB3);
		
		OCR2A = ((((int) controller_output) >> 2) > 0xFF)?0xFF:(((int) controller_output) >> 2);
		OCR0A = 0;
		
	} else {
		// Disable all PWM if controller output is 0
		DDRD |= (1 << PD6);
		DDRB |= (1 << PB3);
		
		OCR0A = 0;
		OCR2A = 0;
	}		
		
	return;
}