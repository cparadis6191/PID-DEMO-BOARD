#ifndef _FEEDBACK_H_
#define _FEEDBACK_H_

#include <stdint.h>

#include "adc.h"
#include "pwm.h"

#define Kp_max 20
#define Ki_max 10
#define Kd_max 3


double * feedback_loop(double * error_previous);

#endif	