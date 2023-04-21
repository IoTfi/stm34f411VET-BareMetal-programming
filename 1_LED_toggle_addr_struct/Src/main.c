#include <stdint.h>
#define PERIPH_BASE 		(0x40000000UL)
#define AHB1_OFFSET			(0x20000UL)
#define AHB1_BASE   		(PERIPH_BASE + AHB1_OFFSET)
#define GPIOD_OFFSET 		(0xC00UL)
#define GPIOD_BASE			(AHB1_BASE + GPIOD_OFFSET)
#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1_BASE + RCC_OFFSET)
#define GPIODEN				(1U << 3)
#define PIN13				(1U << 13)
#define LED3_PIN			PIN13
#define __IO	volatile


typedef struct
{
	__IO uint32_t MODER; 		/*!< GPIO port mode register     address offset: 0x00; */
	__IO uint32_t DUMMY[4];
	__IO uint32_t ODR; 			/*!<GPIO port output data register       address offset: 0x14; */

}GPIO_TypeDef;

typedef struct
{
	__IO uint32_t DUMMY[12];
	__IO uint32_t AHB1ENR; 		/*!< RCC AHB1 Peripheral clock register          address offset: 0x30 */

}RCC_TypeDef;

#define RCC     ((RCC_TypeDef *)RCC_BASE)
#define GPIOD   ((GPIO_TypeDef *)GPIOD_BASE)




int main()
{
	/*Enable clock Access to GPIOD*/

	RCC->AHB1ENR |= GPIODEN;

	/*SET PD13 as Output*/

	GPIOD->MODER |= (1U << 26);
	GPIOD->MODER &= ~(1U << 27 );

	while(1)
	{
		/*Set PD13 as High*/
		GPIOD->ODR ^= LED3_PIN;
		for(int i =0;i<100000;i++){};
	}
}
