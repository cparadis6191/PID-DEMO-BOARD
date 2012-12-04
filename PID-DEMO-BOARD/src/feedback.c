#include "feedback.h"


double feedback_loop(double p_error_previous) {
	double delta_t = .001;
	
	double p_error = 0;
	double i_error = 0;
	double d_error = 0;
	
	double Kp = 0;
	double Ki = 0;
	double Kd = 0;
	
	double feedback_output;
	
	
	Kp = adc_get_p();
	Ki = adc_get_i();
	Kd = adc_get_d();
	
	p_error = (adc_get_desired_angle() - adc_get_actual_angle());
	i_error += p_error*delta_t;
	d_error = (p_error - p_error_previous)/delta_t;
	
	feedback_output = (Kp*p_error_previous + Ki*i_error + Kd*d_error);
	
	
	pwm_adjust(pwm_feedback_output_convert(feedback_output));
	
	
	return p_error;
}


uint8_t pwm_feedback_output_convert(double feedback_output) {
	int blah = 0;
	
	return (uint8_t) feedback_output;
}