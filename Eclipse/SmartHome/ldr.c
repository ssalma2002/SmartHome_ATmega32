/*
 * ldr.c
 *
 *  Created on: Oct 5, 2024
 *      Author: syous
 */
/*The LDR should be connected ADC channel 0
 * Light Sensor: LDR (Connected to PA0, ADC Channel 0)
 */

#include "ldr.h"

/*
 *Reads the LDR sensor value and returns the light intensity.
 */
uint16 LDR_getLightIntensity(void) {
	uint16 light_intensity_value = 0;
	uint16 adc_value = 0;
	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ((uint16) (ADC_readChannel(LDR_SENSOR_CHANNEL_ID)));
	/* Calculate the light_intensity_value from the ADC value*/
	light_intensity_value = (uint8) (((uint32) adc_value
			* LDR_SENSOR_MAX_LIGHT_INTENSITY * ADC_REF_VOLT_VALUE)
			/ (ADC_MAXIMUM_VALUE * LDR_SENSOR_MAX_VOLT_VALUE));
	return (light_intensity_value);
}

