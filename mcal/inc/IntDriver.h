#ifndef IntDriver_H
#define IntDriver_H

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#define INT_ADDRESS_0									0x100
#define INT_ADDRESS_1									0x104
#define INT_ADDRESS_2									0x108
#define INT_ADDRESS_3									0x10C
#define INT_ADDRESS_4									0x110
#define INT_ADDRESS_5									0x104


/*Tupes of priority groups*/

#define xxx					0
#define xxy					1
#define xyy					2
#define yyy					3

/*The interrupt enable of the registers*/

#define	INT_PORTA												0
#define	INT_PORTB												1
#define	INT_PORTC												2
#define	INT_PORTF												30
#define	INT_TIMERA_0										19
#define	INT_TIMERA_WIDE_0								94
							





typedef struct
{
	uint8 Enable;
	uint8 GroupPriority;
	uint8 SubGroupPriority;
	
} IntCtrlConfig;



void Int_VidInit(uint8 priGrp);
void Int_VidEnableInterrupt(uint8 trigger);
void Int_VidDisableInterrupt(uint8 trigger);
void Int_VidSetPriority(uint8 trigger,uint32 pri, uint32 subPri);
void Int_VidClrGlobalInterrupt(void);
void Int_VidSetGlobalInterrupt(void);


#endif