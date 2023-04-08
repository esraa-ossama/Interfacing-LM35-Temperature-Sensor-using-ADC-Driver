#ifndef INCLUDE_ADC_H_
#define INCLUDE_ADC_H_
#define ADC_control_reg ADC1
#define USE_POLLING 0

typedef struct ADCConfigType {
	enum Resolution {
		bit_12, bit_10, bit_8, bit_6
	} Resolution;
	enum ConfiMode {
		Single_conversion_mode, Continuous_conversion_mode
	} ConfiMode;
	float voltage;
} ADCConfigType;

void ADC_Init(ADCConfigType* ConfigParamPtr);
void ADC_StartConv(unsigned char ChannelNum);
void ADC_GetConversionState(unsigned char* ConversionStatePtr);
unsigned char ADC_ReadData(unsigned short int* DataPtr);

#endif /* INCLUDE_ADC_H_ */

