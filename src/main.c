#include <stdio.h>
#include "stm32f4xx.h"
#include "gpio.h"
#include "ADC.h"
#include "lcd.h"

unsigned short int value;
float output_voltage;
unsigned char return_value = 1;
float Temp;

void ISR_OF_ADC(void) {
	LCD_ClearScreen();

	value = ADC_control_reg->DR;
	LCD_DisplayString("Temp:");
	output_voltage = ((float) value * 5) / 4096;
	Temp = (float) (output_voltage / 0.01);
	LCD_IntToStr(Temp);
	LCD_DisplayString("C");
	for (int i = 0; i < 500000; i++) {
	}

}

int main(void) {
	struct ADCConfigType configure;
	configure.Resolution = bit_12;
	configure.ConfiMode = Single_conversion_mode;
	configure.voltage = 5.0;
	LCD_Init();
	ADC_Init(&configure);
	LM35_INIT(GPIOA, 1, 0);

	while (1) {

		LCD_ClearScreen();
		ADC_StartConv(1);
		return_value = ADC_ReadData(&value);
		if (return_value == 0) {
			LCD_DisplayString("Temp:");
			output_voltage = ((float) value * 5) / 4096;
			Temp = (float) (output_voltage / 0.01);
			LCD_IntToStr(Temp);
			LCD_DisplayString("C");
			for (int i = 0; i < 500000; i++) {
			}

		}

	}
}

void ADC_IRQHandler(void) {
	ISR_OF_ADC();
}
