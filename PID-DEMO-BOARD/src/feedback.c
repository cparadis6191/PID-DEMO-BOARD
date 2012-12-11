#include "feedback.h"


double * feedback_loop(double * error_previous) {
	double delta_t = .01;	// 10ms delta_t
	
	double p_error = 0;
	double d_error = 0;
	
	double Kp = 0;
	double Ki = 0;
	double Kd = 0;
	
	double controller_output;
	
	
	Kp = adc_get_p();
	Ki = adc_get_i();
	Kd = adc_get_d();
	
	// Compute the proportional
	p_error = (adc_get_desired_angle() - adc_get_actual_angle());
	// Compute the integral
	error_previous[1] += p_error*delta_t;
	// Compute the derivative
	d_error = (p_error - error_previous[0])/delta_t;
	
	controller_output = (Kp*p_error + Ki*error_previous[1] + Kd*d_error);
	
	
	pwm_adjust(controller_output);
	
	
	return error_previous;
}