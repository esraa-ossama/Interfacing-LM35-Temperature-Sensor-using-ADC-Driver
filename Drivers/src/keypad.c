#include "stm32f4xx.h"
//#include "keypad.h"
//#include "gpio.h"
//# include "interrupt.h"
//#include "ADC.h"
//#include "lcd.h"



const int no_raws = 4;
const int no_cols = 3;
char rows[4]={4,5,6,7}; //fill the array
char cols[3]={1,2,3}; //fill the array

char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};// fill the array

char currentvalue;


void KeyPad_INIT(void)
{
	//Input pins
	GPIO_Init (GPIOB,4,0,1);
	GPIO_Init (GPIOB,5,0,1);
	GPIO_Init (GPIOB,6,0,1);
	GPIO_Init (GPIOB,7,0,1);

	//output pins
	GPIO_Init (GPIOB,1,1,1);
	GPIO_Init (GPIOB,2,1,1);
	GPIO_Init (GPIOB,3,1,1);

	// set input and ouput pins
		// get pins from raw and set it as input
		// get pins from cols and set it as output
	// hint use gpio driver functions
}

void KeyPad_MANAGE(void)
{
	for(int i=0;i<3;i++){
		GPIO_Write(GPIOB,1,1);
		GPIO_Write(GPIOB,2,1);
		GPIO_Write(GPIOB,3,1);
		GPIO_Write(GPIOB,cols[i],0);
		for(int j=0;j<4;j++){
			char input_button= GPIO_Read(GPIOB,rows[j]);
				if(!(input_button)){
					currentvalue=lookupTable[j][i];
					KeypadCallouts_KeyPressNotificaton();
				}
				else{}

		}
	}
	//nested for loop to check which button is pressed
	//if pressed wait until released then change the value;
	//call KeypadCallouts_KeyPressNotificaton
}

char KeyPad_GET_VALUE(void)
{
	return currentvalue;
}

void KeypadCallouts_KeyPressNotificaton(void)
{
	char check=KeyPad_GET_VALUE();
	switch(check){
		case 0:
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,4,0);
			break;
		case 1:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,4,0);
			break;
		case 2:
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,4,0);
			break;
		case 3:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,4,0);
			break;
		case 4:
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,0);
			break;
		case 5:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,0);
			break;
		case 6:
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,0);
			break;
		case 7:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,1);
			GPIO_Write(GPIOA,3,1);
			GPIO_Write(GPIOA,4,0);
			break;
		case 8:
			GPIO_Write(GPIOA,1,0);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,4,1);
			break;
		case 9:
			GPIO_Write(GPIOA,1,1);
			GPIO_Write(GPIOA,2,0);
			GPIO_Write(GPIOA,3,0);
			GPIO_Write(GPIOA,4,1);
			break;

	}


	// set seven segment
}
void Seven_Segment_INIT(void)
{
	GPIO_Init (GPIOA,1,1,0);
	GPIO_Init (GPIOA,2,1,0);
	GPIO_Init (GPIOA,3,1,0);
	GPIO_Init (GPIOA,4,1,0);


}


