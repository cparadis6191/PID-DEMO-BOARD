#include "adc.h"

void adc_init(void) {
	PORTC &= ~((1 << PC4) | (1 << PC3) | (1 << PC2) | (1 << PC1) | (1 << PC0));
	DDRC &= ~((1 << PC4) | (1 << PC3) | (1 << PC2) | (1 << PC1) | (1 << PC0));
	DIDR0 |= ((1 << ADC4D) | (1 << ADC3D) | (1 << ADC2D) | (1 << ADC1D) | (1 << ADC0D));
	
	// Turn on the ADC
	ADCSRA = (1 << ADEN);
	// P/I/D inputs on PC0/PC1/PC2
	
	// Use AVcc as a voltage
	ADMUX = (1 << REFS0);
	
	
	return;
}	


double adc_get_actual_angle(void) {
	// Clear the ADCMUX
	ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
	
	// Poll on PC0
	
	
	// Start a conversion
	ADCSRA |= (1 << ADSC);
	
	// Wait until the conversion is complete
	while (!(ADCSRA & (1 << ADIF)));
	
	
	// Return the converted value
	// 10k potentiometer with a 1k resistor in series
	// angle = (270*(ADC - 85)/939) - 135
	return 270*(((ADCL | (ADCH << 8)) - 95)/((double) 929));
}


double adc_get_desired_angle(void) {
	// Clear the ADCMUX
	ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
	
	// Poll on PC1
	ADMUX |= (1 << MUX0);
	
	
	// Start a conversion
	ADCSRA |= (1 << ADSC);
	
	// Wait until the conversion is complete
	while (!(ADCSRA & (1 << ADIF)));
	
	// Return the converted value
	// 10k potentiometer with a 1k resistor in series
	// angle = (270*(ADC - 85)/939) - 135
	return 270*(((ADCL | (ADCH << 8)) - 80)/((double) 944));
}


// Returns a value for Kp
// Ranges from 0 to 10
double adc_get_p(void) {
	// Clear the ADCMUX
	ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
	
	// Poll on PC2
	ADMUX |= (1 << MUX1);
	
	
	// Start a conversion
	ADCSRA |= (1 << ADSC);
	
	// Wait until the conversion is complete
	while (!(ADCSRA & (1 << ADIF)));
	
	// Return the converted value
	// 10k potentiometer with a 1k resistor in series
	// Kp = ((10*ADC - 85)/939)
	return Kp_max*(((ADCL | (ADCH << 8)) - 85)/((double) 939));
}	
	
	
// Returns a value for Ki
// Ranges from 0 to 1
double adc_get_i(void) {
	// Clear the ADCMUX
	ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
	
	// Poll on PC3
	ADMUX |= ((1 << MUX1) | (1 << MUX0));
	
	
	// Start a conversion
	ADCSRA |= (1 << ADSC);
	
	// Wait until the conversion is complete
	while (!(ADCSRA & (1 << ADIF)));
	
	// Return the converted value
	// 10k potentiometer with a 1k resistor in series
	// Ki = ((10*ADC - 90)/934)
	return Ki_max*(((ADCL | (ADCH << 8)) - 90)/((double) 934));
}	
	

// Returns a value for Kd
// Ranges from 0 to 2
double adc_get_d(void) {
	// Clear the ADCMUX
	ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
	
	// Poll on PC4
	ADMUX |= (1 << MUX2);
	
	
	// Start a conversion
	ADCSRA |= (1 << ADSC);
	
	// Wait until the conversion is complete
	while (!(ADCSRA & (1 << ADIF)));
	
	// Return the converted value
	// 10k potentiometer with a 1k resistor in series
	// Ki = ((10*ADC - 95)/929)
	return Kd_max*(((ADCL | (ADCH << 8)) - 95)/((double) 929));
}	