/*
 * flame.c
 *
 *  Created on: Oct 6, 2024
 *      Author: syous
 */

#include "flame.h"

void FlameSensor_init(void) {
	GPIO_setupPinDirection(FLAME_PORT,FLAME_PIN ,PIN_OUTPUT );
}

uint8 FlameSensor_getValue(void){
	return GPIO_readPin(FLAME_PORT, FLAME_PIN);
}
