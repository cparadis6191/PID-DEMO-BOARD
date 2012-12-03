#include "pwm.h"

void pwm_init(void) {
	// Output on OC1A, PB1
	// ICR1 is the top value
	TCCR1A = COM1A0;
	
	// Phase and frequency correct PWM
	TCCR1B = WGM13;
	
	return;
}

void pwm_adjust(uint8_t top) {
	
		
	
	return;
}