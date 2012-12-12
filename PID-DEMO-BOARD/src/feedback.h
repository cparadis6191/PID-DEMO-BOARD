#ifndef _FEEDBACK_H_
#define _FEEDBACK_H_

#include <stdint.h>

#include "adc.h"
#include "pwm.h"

#define Kp_max 25
#define Ki_max 5
#define Kd_max 1


double * feedback_loop(double * error_previous);

#endif	