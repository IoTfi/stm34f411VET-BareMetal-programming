/*LED3 :PD13*/

#define PERIPH_BASE 		(0x40000000UL)
#define AHB1_OFFSET			(0x20000UL)
#define AHB1_BASE   		(PERIPH_BASE + AHB1_OFFSET)

#define GPIOD_OFFSET 		(0xC00UL)
#define GPIOD_BASE			(AHB1_BASE + GPIOD_OFFSET)

#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1_BASE + RCC_OFFSET)
#define RCC_AHB1EN_R_OFFSET	(0x30U)
#define RCC_AHB1_EN_R		(*(volatile unsigned int *)(RCC_BASE + RCC_AHB1EN_R_OFFSET ))

#define MODE_R_OFFSET		(0x00UL)
#define GPIOD_MODE_R 		(*(volatile unsigned int *)(GPIOD_BASE + MODE_R_OFFSET))
#define OD_R_OFFSET			(0x14UL)
#define GPIOD_OD_R			(*(volatile unsigned int *)(GPIOD_BASE + OD_R_OFFSET))


#define GPIODEN				(1U << 3)

#define PIN13				(1U << 13)
#define LED3_PIN			PIN13


int main()
{
	/*Enable clock Access to GPIOD*/
	RCC_AHB1_EN_R |= GPIODEN;
	/*SET PD13 as Output*/
	GPIOD_MODE_R |= (1U << 26);
	GPIOD_MODE_R &= ~(1U << 27 );

	while(1)
	{
		/*Set PD13 as High*/
		GPIOD_OD_R |= LED3_PIN;
	}
}
