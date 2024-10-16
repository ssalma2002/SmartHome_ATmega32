/*
 * DC_Motor.c
 *
 *  Created on: Oct 6, 2024
 *      Author: syous
 */
#include "DC_Motor.h"
void DcMotor_Init(void) {

	GPIO_setupPinDirection(PORT_IN1, PIN_IN1, PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_IN2, PIN_IN2, PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_EN1, PIN_EN1, PIN_OUTPUT);

	/* Turn off the motor */
	GPIO_writePin(PORT_IN1, PIN_IN1, LOGIC_LOW);
	GPIO_writePin(PORT_IN2, PIN_IN2, LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state, uint8 speed) {

	PWM_Timer0_Start(speed);
	switch (state) {

	case CW:
		/* Rotates the motor CW */
		GPIO_writePin(PORT_IN1, PIN_IN1, LOGIC_HIGH);
		GPIO_writePin(PORT_IN2, PIN_IN2, LOGIC_LOW);
		break;

	case A_CW:

		/* Rotates the motor A-CW */
		GPIO_writePin(PORT_IN1, PIN_IN1, LOGIC_LOW);
		GPIO_writePin(PORT_IN2, PIN_IN2, LOGIC_LOW);
		break;

	case Stop:

		/* Stop the motor */
		GPIO_writePin(PORT_IN1, PIN_IN1, LOGIC_LOW);
		GPIO_writePin(PORT_IN2, PIN_IN2, LOGIC_HIGH);
		break;

	default:
		/* Do Nothing */
		break;
	}
}
