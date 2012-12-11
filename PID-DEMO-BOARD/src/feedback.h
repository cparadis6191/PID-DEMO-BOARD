#ifndef _FEEDBACK_H_
#define _FEEDBACK_H_

#include <stdint.h>

#include "adc.h"
#include "pwm.h"


double * feedback_loop(double * error_previous);

#endif	