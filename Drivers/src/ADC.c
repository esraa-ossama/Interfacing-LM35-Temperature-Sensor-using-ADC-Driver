#include "stm32f4xx.h"
#include "gpio.h"
#include "ADC.h"
#include "lcd.h"

void ADC_Init(ADCConfigType* ConfigParamPtr) {
	//ADC1 clock enable
	RCC->APB2ENR |= (1 << 8);
	//A/D Converter ON / OFF
	ADC_control_reg->CR2 |= (1 << 0);

	//resolution selection
	switch (ConfigParamPtr->Resolution) {
	case bit_12:
		ADC_control_reg->CR1 &= ~(1 << 24);
		ADC_control_reg->CR1 &= ~(1 << 25);
		break;
	case bit_10:
		ADC_control_reg->CR1 |= (1 << 24);
		ADC_control_reg->CR1 &= ~(1 << 25);
		break;
	case bit_8:
		ADC_control_reg->CR1 &= ~(1 << 24);
		ADC_control_reg->CR1 |= (1 << 25);
		break;
	case bit_6:
		ADC_control_reg->CR1 |= (1 << 24);
		ADC_control_reg->CR1 |= (1 << 25);
		break;
	}

	//conversion mode selection
	switch (ConfigParamPtr->ConfiMode) {
	case Single_conversion_mode:
		ADC_control_reg->CR2 &= ~(1 << 1);
		break;
	case Continuous_conversion_mode:
		ADC_control_reg->CR2 |= (1 << 1);
		break;
	}

	//enable or disable interrupt
	if (USE_POLLING) {
		//disable interrupt EOC(end of conversion)
		ADC_control_reg->CR1 &= ~(1 << 5);
	} else {
		//enable interrupt
		ADC_control_reg->CR1 |= (1 << 5);  //Interrupt enable for EOC
		NVIC->ISER[0] |= (1 << 18);
	}
	ADC_control_reg->CR2 &=~(1<<11);

}

void ADC_StartConv(unsigned char ChannelNum) {
	//Regular channel sequence length
	// 0000 means 1 conversion
	ADC_control_reg->SQR1 &= ~(1 << 20);
	ADC_control_reg->SQR1 &= ~(1 << 21);
	ADC_control_reg->SQR1 &= ~(1 << 22);
	ADC_control_reg->SQR1 &= ~(1 << 23);
	//clear and choose the channel
	ADC_control_reg->SQR3 &= ~((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3)
			| (1 << 4));
	ADC_control_reg->SQR3 |= (ChannelNum);
	// Start conversion of regular channels
	ADC_control_reg->CR2 |= (1 << 30);
}

void ADC_GetConversionState(unsigned char* ConversionStatePtr) {
	if (USE_POLLING) {
		//check on EOC flag
		if ((ADC_control_reg->SR) & (1 << 1)) {
			*ConversionStatePtr = 1;
		} else {
			*ConversionStatePtr = 0;
		}
	}
	else{
		*ConversionStatePtr = 0;
	}
}

unsigned char ADC_ReadData(unsigned short int* DataPtr) {
	unsigned char valid;
	ADC_GetConversionState(&valid);
	if (valid == 1) {
		*DataPtr = ADC_control_reg->DR;
		return 0;
	} else {
		return 1;
	}
}

