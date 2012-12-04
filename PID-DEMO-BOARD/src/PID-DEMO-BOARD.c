#include "PID-DEMO-BOARD.h"


volatile int TIMER_FLAG;

int main(void) {
	
	pwm_init();
	adc_init();
	timer_init();
	
	double p_error = 0;
	
	while(1) {
		// Adjust the output every timer cycle
		if (TIMER_FLAG) {
			TIMER_FLAG = 0;
			p_error = feedback_loop(p_error);
		}
	}
	
	return 0;
}


void timer_init(void) {
	// 8-bit timer running in CTC mode
	// 0CRA is the top
	TCCR0A = WGM01;
	
	// Use the system clock prescaled by 1024
	TCCR0B = (CS02 | CS00);
	
	// Set up timer 0 to generate interrupts on match with OCR0A
	TIMSK0 = OCIE0A; 
	
	// Generate interrupts at 100Hz (roughly) 
	OCR0A = 97;
	
	// Clear the counter
	TCNT0 = 0;
	
	return;
}

ISR(TIMER0_COMPA_vect) {
	// Set the flag
	TIMER_FLAG = 1;
	
	return;
}	