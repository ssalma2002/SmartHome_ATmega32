/*
 * main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: syous
 */

#include "lcd.h"
#include "led.h"
#include "buzzer.h"
#include "DC_Motor.h"
#include "flame.h"
#include "lm35_sensor.h"
#include "ldr.h"
#include "std_types.h"
#include "adc.h"
//#include "avr/io.h"
int main(void) {
	uint16 light_intensity = 0;
	/*Lighting Control: The LDR detects ambient light intensity and controls three LEDs to
	 indicate different levels of light.
	 */
	FlameSensor_init();
	Buzzer_init();
	LCD_init();
	ADC_init();
	LEDS_init();
	DcMotor_Init();
	Buzzer_init();

	while (1) {
		Buzzer_init();
		LCD_displayStringRowColumn(1, 0, "LDR=");

			LCD_displayStringRowColumn(1, 9, "Temp=");
		light_intensity = LDR_getLightIntensity();
		if (light_intensity < 15) {
			LED_on(red);
			LED_on(green);
			LED_on(blue);
		} else if (light_intensity > 16 && light_intensity < 50) {
			LED_on(red);
			LED_on(green);
			LED_off(blue);
		} else if (light_intensity > 51 && light_intensity < 70) {
			LED_on(red);
			LED_off(green);
			LED_off(blue);
		} else if (light_intensity > 70) {
			LED_off(red);
			LED_off(green);
			LED_off(blue);
		}

		LCD_moveCursor(1, 5);
		LCD_intgerToString(light_intensity);
		LCD_displayString("% ");
		uint8 temperature = LM35_getTemperature();
		if (temperature >= 40) {
			DcMotor_Rotate(CW, 100);
			LCD_displayStringRowColumn(0, 0, "Fan is ON ");
			LCD_displayString("     ");
		} else if (temperature >= 35 && temperature < 40) {
			DcMotor_Rotate(CW, 75);
			LCD_displayStringRowColumn(0, 0, "Fan is ON ");
			LCD_displayString("     ");
		} else if (temperature >= 30 && temperature < 35) {
			DcMotor_Rotate(CW, 50);
			LCD_displayStringRowColumn(0, 0, "Fan is ON ");
			LCD_displayString("     ");
		} else if (temperature >= 25 && temperature < 30) {
			DcMotor_Rotate(CW, 25);
			LCD_displayStringRowColumn(0, 0, "Fan is ON ");
			LCD_displayString("     ");
		} else if (temperature < 25) {
			DcMotor_Rotate(Stop, 0);
			LCD_displayStringRowColumn(0, 0, "Fan is OFF");
			LCD_displayString("     ");
		}
		LCD_moveCursor(1, 14);
		LCD_intgerToString(temperature);
		LCD_displayString(" ");
		uint8 flame_value = FlameSensor_getValue();
		if (flame_value) {
			LCD_clearScreen();
			LCD_displayStringRowColumn(0, 0, "Critical alert!");
			Buzzer_on();
		}
		while(flame_value){
			flame_value = FlameSensor_getValue();
			Buzzer_on();
		}
	}

}

