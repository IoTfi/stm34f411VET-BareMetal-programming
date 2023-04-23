#include "stm32f4xx.h"



#define GPIODEN		(1U << 3)
#define GPIOAEN 	(1U << 0)
#define PIN13       (1U << 13)
#define PIN0		(1U << 0)
#define LED3_PIN    PIN13
#define BTN_PIN		PIN0


int main()
{
	/* Enable clock access to peripherals */
	RCC->AHB1ENR |= GPIODEN;
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PD13 as an output*/
	GPIOD->MODER |= (1U << 26);
	GPIOD->MODER &= ~(1U << 27 );

	/*Set PA0 as Input*/
	GPIOA->MODER &=~(1U << 0);
	GPIOA->MODER &=~(1U << 1);

	while(1)
	{
		/*Check if Button is pressed*/
		if(GPIOA->IDR & BTN_PIN)
		{
			/*Turn ON Led*/
		GPIOD->BSRR = LED3_PIN ;

		}
		else
		{
			/*Turn OFF Led*/
		GPIOD->BSRR = (1U << 29) ;
		}
	}

}
