#include "PID-DEMO-BOARD.h"


volatile int g_TIMER_FLAG;

int main(void) {
	
	pwm_init_A();
	pwm_init_B();
	motor_init();
	adc_init();
	timer_init();
	
	sei();
	
	double * error_previous = malloc(sizeof(double)*2);
	error_previous[0] = 0;
	error_previous[1] = 0;
	
	while (1) {
		// Adjust the output every timer cycle (10ms)
		if (g_TIMER_FLAG) {
			// Clear the timer flag
			g_TIMER_FLAG = 0;
			
			error_previous = feedback_loop(error_previous);
		}
	}
	
	return 0;
}


void timer_init(void) {
	// 16-bit timer running in CTC mode
	// 0CRA is the top
	// Use the system clock prescaled by 1024
	TCCR1B = ((1 << WGM12) | (1 << CS12) | (1 << CS10));
	
	// Set up timer 1 to generate interrupts on match with OCR0A
	TIMSK1 = (1 << OCIE1A);
	
	// Generate interrupts at 100Hz (roughly every 10ms)
	// top = (10ms*8MHz)/1024 - 1
	OCR1A = 77;
	
	// Clear the counter
	TCNT1 = 0;
	
	
	return;
}

ISR(TIMER1_COMPA_vect) {
	// Set the flag
	g_TIMER_FLAG = 1;
	
	
	return;
}


ISR(WDT_vect) {
	// Ignore the watchdog timer
	
	
	return;
}