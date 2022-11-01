#include "SysClock.h"
#include "GPIODriver.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPTMDriver.h"
#include "IntDriver.h"


	
void Toggle(void);
static uint8 flag=0;
int main()
{
	Int_VidClrGlobalInterrupt();
	SysClock_VidInit();
	Config config_0={DIGITAL,2,NORMAL};

	DIO_PortActivate(DIO_PORTF,0,config_0);
	DIO_VidSetPinDirection(DIO_PORTF, 0, PIN_OUTPUT);
	DIO_VidWritePin(DIO_PORTF, 0, PIN_LOW);
	
	DIO_VidSetPortDirection(DIO_PORTA,0x00);
	DIO_VidSetPortDirection(DIO_PORTB,0x00);
	SysClock_VidSysTimrEnable(10000);
	SysClock_VidUpdateLoadSeconds(1);
	SysClock_VidSetCallBackFunction(&Toggle);
	uint32 Timer_Value;
	
	Int_VidSetGlobalInterrupt();
	
	while(1)
	{
	
		if(flag)
			SysClock_VidUpdateLoadSeconds(DIO_U32GetPortValue(DIO_PORTA));/*On time*/
		else
			SysClock_VidUpdateLoadSeconds(DIO_U32GetPortValue(DIO_PORTB)); /*off time*/
	}
	return 0;
}
     


void Toggle(void)
{
	
	if(flag)
	{
		DIO_VidWritePin(DIO_PORTF, 0, PIN_LOW);
		flag=0;
	}
	else{
		DIO_VidWritePin(DIO_PORTF, 0, PIN_HIGH);
		flag=1;
	}
}

