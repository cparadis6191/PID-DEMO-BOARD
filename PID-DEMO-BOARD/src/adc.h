#ifndef _ADC_H_
#define _ADC_H_

#include <avr/io.h>
#include <stdint.h>

// Initialize the ADC
void adc_init(void);

// Returns an angle between -135 and 135
double adc_get_actual_angle(void);	// PC0

// Returns an angle between -135 and 135
double adc_get_desired_angle(void);	// PC1

// Get values for P, I, and D
double adc_get_p(void);	// PC2
double adc_get_i(void);	// PC3
double adc_get_d(void);	// PC4

#endif