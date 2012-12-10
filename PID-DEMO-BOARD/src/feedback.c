#include "feedback.h"


double feedback_loop(double p_error_previous) {
	double delta_t = .01;	// 10ms delta_t
	
	double p_error = 0;
	double i_error = 0;
	double d_error = 0;
	
	double Kp = 0;
	double Ki = 0;
	double Kd = 0;
	
	double controller_output;
	
	
	Kp = adc_get_p();
	Ki = adc_get_i();
	Kd = adc_get_d();
	
	p_error = (adc_get_desired_angle() - adc_get_actual_angle());
	//i_error += p_error*delta_t;
	//d_error = (p_error - p_error_previous)/delta_t;
	
	controller_output = Kp*p_error;
	//controller_output = (Kp*p_error + Ki*i_error + Kd*d_error);
	
	
	pwm_adjust(controller_output);
	
	
	return p_error;
}


//uint8_t pwm_feedback_output_convert(double feedback_output) {
	
	//return (uint8_t) feedback_output;
//}