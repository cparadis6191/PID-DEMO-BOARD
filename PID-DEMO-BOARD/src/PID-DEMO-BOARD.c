#include "PID-DEMO-BOARD.h"

int main(void) {
	
	pwm_init();
	adc_init();
	
	
	while (1) {
		double p_error = 0;
		double i_error = 0;
		double d_error = 0;
		
		double Kp = adc_get_p();
		double Ki = adc_get_i();
		double Kd = adc_get_d();
		
		p_error = adc_get_desired_angle() - adc_get_actual_angle();
		
	}
	
	return 0;
}