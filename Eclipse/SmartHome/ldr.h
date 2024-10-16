/*
 * ldr.h
 *
 *  Created on: Oct 5, 2024
 *      Author: syous
 */

#ifndef LDR_H_
#define LDR_H_
# define LDR_SENSOR_CHANNEL_ID 0
# define LDR_SENSOR_MAX_VOLT_VALUE 2.56
# define LDR_SENSOR_MAX_LIGHT_INTENSITY 100
#include "adc.h"
#include "std_types.h"
uint16 LDR_getLightIntensity(void);


#endif /* LDR_H_ */
