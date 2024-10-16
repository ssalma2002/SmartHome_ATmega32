/*
 * buzzer.h
 *
 *  Created on: Oct 6, 2024
 *      Author: syous
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include "std_types.h"
#include "common_macros.h"
#include "gpio.h"

#define BUZZER_PORT PORTD_ID
#define BUZZER_PIN PIN3_ID
void Buzzer_init(void) ;

void Buzzer_on(void) ;

void Buzzer_off(void) ;


#endif /* BUZZER_H_ */
