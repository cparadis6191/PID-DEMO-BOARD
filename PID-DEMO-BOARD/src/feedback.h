#ifndef _FEEDBACK_H_
#define _FEEDBACK_H_

#include "adc.h"
#include "pwm.h"


double feedback_loop(double p_error_previous);

// Returns a value for TOP for the PWM signal
uint8_t pwm_feedback_output_convert(double feedback_output);

#endif	