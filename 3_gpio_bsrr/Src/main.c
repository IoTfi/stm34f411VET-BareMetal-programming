#include "stm32f4xx.h"



#define GPIODEN		(1U << 3)
#define PIN13       (1U << 13)
#define LED3_PIN    PIN13


int main()
{
	/* Enable clock access */
	RCC->AHB1ENR |= GPIODEN;

	/*Set pin13 as an output*/
	GPIOD->MODER |= (1U << 26);
	GPIOD->MODER &= ~(1U << 27 );

	while(1)
	{
		GPIOD->BSRR = LED3_PIN ;
		for(int i=0;i<1000000;i++){};

		GPIOD->BSRR = (1U << 29) ;
		for(int i=0;i<100000;i++){};
	}

}
