/*
 * flame.h
 *
 *  Created on: Oct 6, 2024
 *      Author: syous
 */

#ifndef FLAME_H_
#define FLAME_H_
#include "gpio.h"
#include "std_types.h"
#include "common_macros.h"

#define FLAME_PORT PORTD_ID
#define FLAME_PIN PIN2_ID
void FlameSensor_init(void) ;

uint8 FlameSensor_getValue(void);

#endif /* FLAME_H_ */
