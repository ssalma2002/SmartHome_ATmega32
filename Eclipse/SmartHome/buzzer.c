/*
 * buzzer.c
 *
 *  Created on: Oct 6, 2024
 *      Author: syous
 */
#include "buzzer.h"


void Buzzer_init(void) {
	GPIO_setupPinDirection(BUZZER_PORT,BUZZER_PIN ,PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW);
}

void Buzzer_on(void) {
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_HIGH);
}

void Buzzer_off(void){
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW);
}
