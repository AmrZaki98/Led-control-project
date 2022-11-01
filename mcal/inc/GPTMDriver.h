#ifndef GPTMDriver_H
#define GPTMDriver_H
#include "Registers.h"
#include "STD_TYPES.h"

#define GPTM_TIMER0											0
#define GPTM_TIMER1											1
#define GPTM_TIMER2											2
#define GPTM_TIMER3											3
#define GPTM_TIMER4											4
#define GPTM_TIMER5											5

#define GPTM_TIMER0_WIDE								6
#define GPTM_TIMER1_WIDE								7
#define GPTM_TIMER2_WIDE								8
#define GPTM_TIMER3_WIDE								9
#define GPTM_TIMER4_WIDE								10
#define GPTM_TIMER5_WIDE								11



typedef struct
{
	uint16 PreScaler;
	uint8 Mode;
	uint8 Dir;
} GPTM_config;



/*The prescaler values are
  *2
  *4
  *8
  *16 
*/

/*The Modes are

	*One shot
	*Periodic
*/

#define ONE_SHOT						0
#define PRIODIC							1

/*The directions are
	* Cointer is incrementing
	* Counter is decrementing
*/

#define DOWN								0
#define UP									1




void GPTM_VidInit(uint8 TimerId, GPTM_config config); 
void GPTM_VidStart(uint8 TimerId, uint32 target);
void GPTM_VidStop(uint8 TimerId);
uint32 GPTM_uint32GetTime(uint8 TimerId);
uint32 GPTM_uint32GetTimeRemaining(uint8 TimerId);
void GPTM_VidWriteTime(uint8 TimerId,uint32 Value);
void GPTM_VidSetCallBackFunction(uint8 portId,void (*CallBackFunc)(void));
#endif