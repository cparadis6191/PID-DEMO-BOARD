#include "adc.h"

void adc_init(void) {
	// Turn on the ADC
	ADCSRA = ADEN; 
	// P/I/D inputs on PC0/PC1/PC2
	
	// Use AVcc as a reference
	ADMUX = REFS0;
	
	return;
}	


double adc_get_actual_angle(void) {
	// Clear the ADCMUX
	ADMUX &= ~(MUX3 | MUX2 | MUX1 | MUX0);
	
	// Poll on PC0
	
	
	// Start a conversion
	ADCSRA |= ADSC;
	
	// Wait until the conversion is complete
	while (ADCSRA & ADIF);
	
	// Return the converted value
	// 10k potentiometer with a 1k resistor in series
	// angle = (270*(ADC - (1/11*5V))/(1024 - 1/11*5V)) - 135
	// angle = (270*(ADC - 92)/(1024 - 92)) - 135
	return (270*(ADCL | ADCH << 8) - 92)/((double) 932) - 135;
}


double adc_get_desired_angle(void) {
	// Clear the ADCMUX
	ADMUX &= ~(MUX3 | MUX2 | MUX1 | MUX0);
	
	// Poll on PC1
	ADMUX |= MUX0;
	
	
	// Start a conversion
	ADCSRA |= ADSC;
	
	// Wait until the conversion is complete
	while (ADCSRA & ADIF);
	
	// Return the converted value
	// 10k potentiometer with a 1k resistor in series
	// angle = (270*(ADC - (1/11*5V))/(1024 - 1/11*5V)) - 135
	// angle = (270*(ADC - 92)/(1024 - 92)) - 135
	return (270*(ADCL | ADCH << 8) - 92)/(double) 932 - 135;
}


// Returns a value for Kp
// Ranges from 0 to 10
double adc_get_p(void) {
	// Clear the ADCMUX
	ADMUX &= ~(MUX3 | MUX2 | MUX1 | MUX0);
	
	// Poll on PC2
	ADMUX |= MUX1;
	
	
	// Start a conversion
	ADCSRA |= ADSC;
	
	// Wait until the conversion is complete
	while (ADCSRA & ADIF);
	
	// Return the converted value
	// 10k potentiometer with a 1k resistor in series
	// angle = (270*(ADC - (1/11*5V))/(1024 - 1/11*5V)) - 135
	// angle = (270*(ADC - 92)/(1024 - 92)) - 135
	return (10*(ADCL | ADCH << 8) - 92)/((double) 932);
}	
	
	
// Returns a value for Ki
// Ranges from 0 to 1
double adc_get_i(void) {
	// Clear the ADCMUX
	ADMUX &= ~(MUX3 | MUX2 | MUX1 | MUX0);
	
	// Poll on PC3
	ADMUX |= (MUX1 | MUX0);
	
	
	// Start a conversion
	ADCSRA |= ADSC;
	
	// Wait until the conversion is complete
	while (ADCSRA & ADIF);
	
	// Return the converted value
	// 10k potentiometer with a 1k resistor in series
	// angle = (270*(ADC - (1/11*5V))/(1024 - 1/11*5V)) - 135
	// angle = (270*(ADC - 92)/(1024 - 92)) - 135
	return (1*(ADCL | ADCH << 8) - 92)/((double) 932);
}	
	

// Returns a value for Kd
// Ranges from 0 to 2
double adc_get_d(void) {
	// Clear the ADCMUX
	ADMUX &= ~(MUX3 | MUX2 | MUX1 | MUX0);
	
	// Poll on PC4
	ADMUX |= MUX2;
	
	
	// Start a conversion
	ADCSRA |= ADSC;
	
	// Wait until the conversion is complete
	while (ADCSRA & ADIF);
	
	// Return the converted value
	// 10k potentiometer with a 1k resistor in series
	// angle = (270*(ADC - (1/11*5V))/(1024 - 1/11*5V)) - 135
	// angle = (270*(ADC - 92)/(1024 - 92)) - 135
	return (2*(ADCL | ADCH << 8) - 92)/((double) 932);
}	