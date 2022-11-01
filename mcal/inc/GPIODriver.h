#ifndef GPIODriver_H
#define GPIODriver_H

#include "STD_TYPES.h"


#define DIO_PORTA						0
#define DIO_PORTB						1
#define DIO_PORTC						2
#define DIO_PORTD						3
#define DIO_PORTE						4
#define DIO_PORTF						5

#define PIN_LOW							0
#define PIN_HIGH						1

#define PIN_INPUT						0
#define PIN_OUTPUT					1


typedef struct 
{
		uint8 PortPinMode;
		uint8 PortPinOutputCurrent;
		uint8 PinType;
}Config;

/*The choices of pin mode are
		*Digital IO
		*Alternative*/
#define DIGITAL								0
#define ALTERNATIVE						1

/*The choices for PortPinOutputCurrent
			* 2
			* 4
			* 8*/

/*The choice for PinType
	*NORMAL
	*OPEN_DRAIN
	*PULL_UP
	*PULL_DOWN
*/
#define NORMAL									0
#define OPEN_DRAIN							1
#define PULL_UP									2
#define PULL_DOWN								3


/*The interrupts could either be on or off*/

#define INT_OFF									0
#define INT_ON									1

/*The interrupt triger could be
		*Rising edge
		*Fallinf edge
		*Both falling and risng
		* High level
		* Low level
		*/
		
#define INT_RISING								0
#define INT_FALLING								1
#define INT_ANY_EDGE							2
#define INT_HIGH									3
#define INT_LOW										4
#define INT_NAN										5		/*Use this when disabling the interrupt*/

void DIO_PortActivate(uint8 PortId,uint8 PinNumber,Config config);
void DIO_VidWritePin(uint8 PortId, uint8 PinNumber, uint8 PinValue);
void DIO_VidWritePort(uint8 PortId,uint8 Mask, uint8 Data);
uint8 DIO_Uint8ReadPin(uint8 PortId,uint8 PinNumber);
void DIO_VidSetPinDirection(uint8 PortId, uint8 PinNumber, uint8 PinDir);
void DIO_ControlInterrupt(uint8 PortId,uint8 PinNumber,uint8 Enable, uint8 Trigger);
uint32	DIO_U32GetPortValue(uint8 PortId);
void DIO_VidSetPortDirection(uint8 PortId,uint32 DataDir);

#endif