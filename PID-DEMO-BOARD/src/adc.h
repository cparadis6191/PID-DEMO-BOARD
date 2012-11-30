// Initialize the ADC
void adc_init(void);

// Get values for P, I, and D. Result is multiplied by 100.
int adc_get_p(void);
int adc_get_i(void);
int adc_get_d(void);