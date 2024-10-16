/*
 * DC_Motor.h
 *
 *  Created on: Oct 6, 2024
 *      Author: syous
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include "common_macros.h"
#include "PWM.h"
#include "gpio.h"

#define PORT_IN1 PORTB_ID
#define PORT_IN2 PORTB_ID
#define PORT_EN1 PORTB_ID

#define PIN_IN1  PIN0_ID
#define PIN_IN2  PIN1_ID
#define PIN_EN1  PIN3_ID
typedef enum
{
	Stop,CW,A_CW
}DcMotor_State;
void DcMotor_Init(void) ;


void DcMotor_Rotate(DcMotor_State state, uint8 speed);
#endif /* DC_MOTOR_H_ */
