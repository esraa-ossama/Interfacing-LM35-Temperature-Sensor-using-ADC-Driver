#include "stm32f4xx.h"



void INTER_Init (GPIO_TypeDef * GPIOx,int exti,char enable_pin)
{
	RCC->APB2ENR |=(1u<<enable_pin);

	if (exti==1)
	{
		// Set Selection lines of EXTI1

		SYSCFG->EXTICR[0] |=(1u<<4);
		SYSCFG->EXTICR[0] &=~(1u<<5);
		SYSCFG->EXTICR[0] &=~(1u<<6);
		SYSCFG->EXTICR[0] &=~(1u<<7);

		// Configure the mask bit of exti1

		EXTI->IMR |=(1u<<exti);

		// Configure the Trigger  as falling trigger

		EXTI->FTSR |=(1u<<exti);

		// enable EXTI1 interrupt from NVIC

		NVIC->ISER[0]|=(1u<<7);
	}
	else
	{
		// Set Selection lines of EXTI0

		SYSCFG->EXTICR[0] |=(1u<<0);
		SYSCFG->EXTICR[0] &=~(1u<<1);
		SYSCFG->EXTICR[0] &=~(1u<<2);
		SYSCFG->EXTICR[0] &=~(1u<<3);

		// Configure the mask bit of exti0

		EXTI->IMR |=(1u<<exti);

		// Configure the Trigger  as falling trigger

		EXTI->FTSR |=(1u<<exti);

		// enable EXTI0 interrupt from NVIC

		NVIC->ISER[0]|=(1u<<6);
	}

}
void SEVEN_SEGMENT_COUNTER(int counter)
{


		switch(counter){
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
	}




