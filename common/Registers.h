#ifndef Registers_H
#define Registers_H
#include "STD_TYPES.h"
/*The system control registers*/
#define SYSTEMCONTROL_BASE					                           0x400FE000
#define RCC													*((volatile unsigned int *)(0x060+0x400FE000))
#define RCC2												*((volatile unsigned int *)(0x070+SYSTEMCONTROL_BASE))
#define MOSCCTL                     *((volatile unsigned int *)(0x07C+SYSTEMCONTROL_BASE))
#define RCGCGPIO										*((volatile unsigned int *)(0x608+SYSTEMCONTROL_BASE)) /*GPIO clock enable*/
#define RCGCWTIMER									*((volatile unsigned int *)(0x65C+SYSTEMCONTROL_BASE)) /*GPTM clock enable*/
#define RCGCTIMER										*((volatile unsigned int *)(0x604+SYSTEMCONTROL_BASE)) /*GPTM clock enable*/
#define RCGCPWM											*((volatile unsigned int *)(0x640+SYSTEMCONTROL_BASE)) /*GPTM clock enable*/

/*Sys tick*/
#define STRELOAD										*((volatile unsigned int *)(0x014+0xE000E000))
#define STCURRENT										*((volatile unsigned int *)(0x018+0xE000E000))
#define STCTRL                   		*((volatile unsigned int *)(0x010+0xE000E000))

/*GPIO registers */
#define GPIOA_BASE 					0x40004000
#define GPIOB_BASE 					0x40005000
#define GPIOC_BASE 					0x40006000
#define GPIOD_BASE 					0x40007000
#define GPIOE_BASE 					0x40024000
#define GPIOF_BASE 					0x40025000

#define PORTA								GPIOA_BASE
#define PORTB								GPIOB_BASE
#define PORTC								GPIOC_BASE
#define PORTD								GPIOD_BASE
#define PORTE								GPIOE_BASE
#define PORTF								GPIOF_BASE

#define GPIODATA(PORT,MASK)									*((volatile unsigned int *)(PORT+(((uint32)MASK)<<2)))  /*The data register*/
#define GPIODIR(PORT)												*((volatile unsigned int *)(PORT+0x400))	/*Data direction*/
#define GPIODEN(PORT) 											*((volatile unsigned int *)(PORT+0x51C))  /*Digital enable*/
#define GPIODR2R(PORT)											*((volatile uint32 *)(PORT+0x500))  /*2mA output*/
#define GPIODR4R(PORT)											*((volatile uint32 *)(PORT+0x504))	/*4mA output*/
#define GPIODR8R(PORT)											*((volatile uint32 *)(PORT+0x508))	/*8mA output*/
#define GPIOODR(PORT)							          *((volatile uint32 *)(PORT+0x50C))	/*Open drain select*/
#define GPIOPUR(PORT)												*((volatile uint32 *)(PORT+0x510))	/*Pull up select*/
#define GPIOPDR(PORT)												*((volatile uint32 *)(PORT+0x514)) 	/*Pull down select*/
#define GPIOAFSEL(PORT)											*((volatile uint32 *)(PORT+0x420)) /*Alternative function select*/
#define GPIOPCTL(PORT)											*((volatile uint32 *)(PORT+0x52C)) /*Alternative function control*/
#define GPIOIS(PORT)												*((volatile uint32 *)(PORT+0x404)) /*Interrupt sense (Detect edge or level)*/
#define GPIOIBE(PORT)												*((volatile uint32 *)(PORT+0x408)) /*Interrupt Both edges*/
#define GPIOIEV(PORT)												*((volatile uint32 *)(PORT+0x40C)) /*Interrupt on falling/risng, low/high*/
#define GPIOIM(PORT)												*((volatile uint32 *)(PORT+0x410)) /*Interrupt mask (enable)*/	
#define GPIORIS(PORT)												*((volatile uint32 *)(PORT+0x414)) /*Interrupt status (flags)*/		
#define GPIOMIS(PORT)												*((volatile uint32 *)(PORT+0x418)) /*Masked Interrupt status */
#define GPIOICR(PORT)												*((volatile uint32 *)(PORT+0x41C)) /*This register clears the interrupt flags */
	

/*General purpose timer register*/

/* 16/32 bit timers base*/
#define GPTM0_BASE 						0x40030000
#define GPTM1_BASE 						0x40031000
#define GPTM2_BASE 						0x40032000
#define GPTM3_BASE 						0x40033000
#define GPTM4_BASE 						0x40034000
#define GPTM5_BASE 						0x40035000

/* 32/64 bit timers base*/
#define GPTMW0_BASE 					0x40036000
#define GPTMW1_BASE 					0x40037000
#define GPTMW2_BASE 					0x4003C000
#define GPTMW3_BASE 					0x4003D000
#define GPTMW4_BASE 					0x4003E000
#define GPTMW5_BASE 					0x4003F000


#define TIMER0								GPTM0_BASE
#define TIMER1								GPTM1_BASE
#define TIMER2								GPTM2_BASE
#define TIMER3								GPTM3_BASE
#define TIMER4								GPTM4_BASE
#define TIMER5								GPTM5_BASE


#define TIMER0W								GPTMW0_BASE
#define TIMER1W								GPTMW1_BASE
#define TIMER2W								GPTMW2_BASE
#define TIMER3W								GPTMW3_BASE
#define TIMER4W								GPTMW4_BASE
#define TIMER5W								GPTMW5_BASE



#define GPTMCFG(PORT)						*((volatile uint32 *)(PORT+0x00)) /* The number of bits in the counter */
#define GPTMTAMR(PORT)					*((volatile uint32 *)(PORT+0x004)) /* The config. for timer A */
#define GPTMCTL(PORT)						*((volatile uint32 *)(PORT+0x00C)) /* Has the timer enable */
#define GPTMIMR(PORT)						*((volatile uint32 *)(PORT+0x018)) /* The interrupt mask */
#define GPTMRIS(PORT)						*((volatile uint32 *)(PORT+0x01C)) /* The raw interrupt status */
#define GPTMMIS(PORT)						*((volatile uint32 *)(PORT+0x020)) /* The masked interrupt status */
#define GPTMICR(PORT)						*((volatile uint32 *)(PORT+0x024)) /* clear interrupt status */
#define GPTMTAILR(PORT)					*((volatile uint32 *)(PORT+0x028)) /* Timer A interval*/
#define GPTMTAMATCHR(PORT)			*((volatile uint32 *)(PORT+0x030)) /* Timer A match */
#define GPTMTAPR(PORT)          *((volatile uint32 *)(PORT+0x038)) /* Timer A Prescaler */
#define GPTMTAPMR(PORT)					*((volatile uint32 *)(PORT+0x040)) /* Timer A Prescaler matcher*/
#define GPTMTAV(PORT)           *((volatile uint32 *)(PORT+0x050)) /* Timer A free running value*/
#define	GPTMTAPV(PORT)					*((volatile uint32 *)(PORT+0x064)) /* Timer A presccaler free running value*/


/*NVIC registers*/
#define NVIC_BASE																(0xE000E000+0x100)
													

#define	INTEN(OFFSET)						  *((volatile unsigned int *)(NVIC_BASE+OFFSET)) /*1-> enables the interrupts*/
#define	DIS(OFFSET)				    	  *((volatile unsigned int *)(NVIC_BASE+0x80+OFFSET)) /*1-> disables the interrupt*/
#define	PEND(OFFSET)				    	*((volatile unsigned int *)(NVIC_BASE+0x100+OFFSET)) /*Interrupt pending*/
#define	UNPEND(OFFSET)				    *((volatile unsigned int *)(NVIC_BASE+0x180+OFFSET)) /*Interrupt unpending*/
#define ACTIVE(OFFSET)						*((volatile unsigned int *)(NVIC_BASE+0x200+OFFSET)) /*the interrupt is active or not*/
#define PRI(OFFSET)								*((volatile unsigned int *)(NVIC_BASE+0x300+OFFSET)) /*the interrupt is active or not(read only)*/
#define APINT											*((volatile unsigned int *)(NVIC_BASE+0xD0C)) /*Interrupt control*/
	
#endif
