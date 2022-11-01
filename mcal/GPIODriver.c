#include "GPIOConfig.h"
#include "BIT_MATH.h"
#include "Registers.h"
#include "GPIODriver.h"

/*
void DIO_VidWritePin(uint8 PortId, uint8 PinNumber, uint8 PinValue)
{
		uint8 temp_address=((uint8)1)<<PinNumber;
		uint8	temp_data=((uint8)PinValue)<<PinNumber;
		switch (PortId)
		{
			case DIO_PORTA: GPIODATA(PORTA,temp_address)=temp_data;
				break;
			case DIO_PORTB: GPIODATA(PORTB,temp_address)=temp_data;
				break;
			case DIO_PORTC: GPIODATA(PORTC,temp_address)=temp_data;
				break;
			case DIO_PORTD: GPIODATA(PORTD,temp_address)=temp_data;
				break;
			case DIO_PORTE: GPIODATA(PORTE,temp_address)=temp_data;
				break;
			case DIO_PORTF: GPIODATA(PORTF,temp_address)=temp_data;
				break;
		}

}	
*/







void DIO_VidWritePin(uint8 PortId, uint8 PinNumber, uint8 PinValue)
{
		switch (PortId)
		{
			case DIO_PORTA: 
				if(PinValue==PIN_HIGH)
						SET_BIT(GPIODATA(PORTA,0xFF),PinNumber);
				else
						CLR_BIT(GPIODATA(PORTA,0xFF),PinNumber);
				break;
			case DIO_PORTB: 
				if(PinValue==PIN_HIGH)
						SET_BIT(GPIODATA(PORTB,0xFF),PinNumber);
				else
						CLR_BIT(GPIODATA(PORTB,0xFF),PinNumber);
				break;
			case DIO_PORTC: 
				if(PinValue==PIN_HIGH)
						SET_BIT(GPIODATA(PORTC,0xFF),PinNumber);
				else
						CLR_BIT(GPIODATA(PORTC,0xFF),PinNumber);
				break;
			case DIO_PORTD: 
				if(PinValue==PIN_HIGH)
						SET_BIT(GPIODATA(PORTD,0xFF),PinNumber);
				else
						CLR_BIT(GPIODATA(PORTD,0xFF),PinNumber);
				break;
			case DIO_PORTE: 
				if(PinValue==PIN_HIGH)
						SET_BIT(GPIODATA(PORTE,0xFF),PinNumber);
				else
						CLR_BIT(GPIODATA(PORTE,0xFF),PinNumber);
				break;
			case DIO_PORTF: 
				if(PinValue==PIN_HIGH)
						SET_BIT(GPIODATA(PORTF,0xFF),PinNumber);
				else
						CLR_BIT(GPIODATA(PORTF,0xFF),PinNumber);
				break;
		}

 }	

void DIO_VidWritePort(uint8 PortId,uint8 Mask, uint8 Data)
{
			switch (PortId)
		{
			case DIO_PORTA: GPIODATA(PORTA,Mask)=Data;
				break;
			case DIO_PORTB: GPIODATA(PORTB,Mask)=Data;  
 				break;
			case DIO_PORTC: GPIODATA(PORTC,Mask)=Data;
				break;
			case DIO_PORTD: GPIODATA(PORTD,Mask)=Data;
				break;
			case DIO_PORTE: GPIODATA(PORTE,Mask)=Data;
				break;
			case DIO_PORTF: GPIODATA(PORTF,Mask)=Data;  
				break;
		}
	
}
uint8 DIO_Uint8ReadPin(uint8 PortId,uint8 PinNumber)
{
		uint8 temp_address=0xFF;
		uint8 Data;
		switch (PortId)
		{
			case DIO_PORTA: Data=GET_BIT(GPIODATA(PORTA,temp_address),PinNumber); 
				break;
			case DIO_PORTB: Data=GET_BIT(GPIODATA(PORTB,temp_address),PinNumber); 
				break;
			case DIO_PORTC: Data=GET_BIT(GPIODATA(PORTC,temp_address),PinNumber);
				break;
			case DIO_PORTD: Data=GET_BIT(GPIODATA(PORTD,temp_address),PinNumber);
				break;
			case DIO_PORTE: Data=GET_BIT(GPIODATA(PORTE,temp_address),PinNumber);
				break;
			case DIO_PORTF: Data=GET_BIT(GPIODATA(PORTF,temp_address),PinNumber);
				break;
		}
		return Data;

}
void DIO_VidSetPinDirection(uint8 PortId, uint8 PinNumber, uint8 PinDir)
{
			switch (PortId)
		{
			case DIO_PORTA:

					if(PinDir==PIN_INPUT)
							CLR_BIT(GPIODIR(PORTA),PinNumber);
					else
							SET_BIT(GPIODIR(PORTA),PinNumber);
				break;
			case DIO_PORTB: 

					if(PinDir==PIN_INPUT)
							CLR_BIT(GPIODIR(PORTB),PinNumber);
					else
							SET_BIT(GPIODIR(PORTB),PinNumber);
				break;
			case DIO_PORTC: 

					if(PinDir==PIN_INPUT)
							CLR_BIT(GPIODIR(PORTC),PinNumber);
					else
							SET_BIT(GPIODIR(PORTC),PinNumber);
				break;
			case DIO_PORTD: 

					if(PinDir==PIN_INPUT)
							CLR_BIT(GPIODIR(PORTD),PinNumber);
					else
							SET_BIT(GPIODIR(PORTD),PinNumber);
				break;
			case DIO_PORTE: 
					if(PinDir==PIN_INPUT)
							CLR_BIT(GPIODIR(PORTE),PinNumber);
					else
							SET_BIT(GPIODIR(PORTE),PinNumber);
				break;
			case DIO_PORTF: 
					if(PinDir==PIN_INPUT)
							CLR_BIT(GPIODIR(PORTF),PinNumber);
					else
							SET_BIT(GPIODIR(PORTF),PinNumber);
				break;
		}
}

uint32	DIO_U32GetPortValue(uint8 PortId)
{
	switch(PortId)
	{
				case DIO_PORTA: return GPIODATA(PORTA,0xFF); 
				break;
				case DIO_PORTB: return GPIODATA(PORTB,0xFF); 
				break;
				case DIO_PORTC: return GPIODATA(PORTC,0xFF);  
				break;
				case DIO_PORTD: return GPIODATA(PORTD,0xFF); 
				break;
				case DIO_PORTE: return GPIODATA(PORTE,0xFF); 
				break;
				case DIO_PORTF: return GPIODATA(PORTF,0xFF); 
	}
	return 0;
}

void DIO_VidSetPortDirection(uint8 PortId,uint32 DataDir)
{
				switch(PortId)
			{
				case DIO_PORTA:  GPIODIR(PORTA)=DataDir;
				break;
				case DIO_PORTB: GPIODIR(PORTB)=DataDir; 
				break;
				case DIO_PORTC: GPIODIR(PORTC)=DataDir; 
				break;
				case DIO_PORTD: GPIODIR(PORTD)=DataDir; 
				break;
				case DIO_PORTE: GPIODIR(PORTE)=DataDir; 
				break;
				case DIO_PORTF: GPIODIR(PORTF)=DataDir; 
				break;
			}
}

void DIO_ControlInterrupt(uint8 PortId,uint8 PinNumber,uint8 Enable, uint8 Trigger)
{
		if(Enable==INT_ON)
		{
			switch(PortId)
			{
				case DIO_PORTA: SET_BIT(GPIOIM(PORTA),PinNumber); 
				break;
				case DIO_PORTB: SET_BIT(GPIOIM(PORTB),PinNumber); 
				break;
				case DIO_PORTC: SET_BIT(GPIOIM(PORTC),PinNumber); 
				break;
				case DIO_PORTD: SET_BIT(GPIOIM(PORTD),PinNumber); 
				break;
				case DIO_PORTE: SET_BIT(GPIOIM(PORTE),PinNumber); 
				break;
				case DIO_PORTF: SET_BIT(GPIOIM(PORTF),PinNumber); 
				break;
			}
		}
		else
		{		
			switch(PortId)
			{
				case DIO_PORTA: CLR_BIT(GPIOIM(PORTA),PinNumber); 
				break;
				case DIO_PORTB: CLR_BIT(GPIOIM(PORTB),PinNumber); 
				break;
				case DIO_PORTC: CLR_BIT(GPIOIM(PORTC),PinNumber); 
				break;
				case DIO_PORTD: CLR_BIT(GPIOIM(PORTD),PinNumber); 
				break;
				case DIO_PORTE: CLR_BIT(GPIOIM(PORTE),PinNumber); 
				break;
				case DIO_PORTF: CLR_BIT(GPIOIM(PORTF),PinNumber); 
				break;
			}
		}
		if(Trigger==INT_RISING)
		{
			switch(PortId)
			{
				case DIO_PORTA: CLR_BIT(GPIOIS(PORTA),PinNumber); CLR_BIT(GPIOIBE(PORTA),PinNumber); SET_BIT(GPIOIEV(PORTA),PinNumber); 
				break;
				case DIO_PORTB: CLR_BIT(GPIOIS(PORTB),PinNumber); CLR_BIT(GPIOIBE(PORTB),PinNumber); SET_BIT(GPIOIEV(PORTB),PinNumber); 
				break;
				case DIO_PORTC: CLR_BIT(GPIOIS(PORTC),PinNumber); CLR_BIT(GPIOIBE(PORTC),PinNumber); SET_BIT(GPIOIEV(PORTC),PinNumber);
				break;
				case DIO_PORTD: CLR_BIT(GPIOIS(PORTD),PinNumber); CLR_BIT(GPIOIBE(PORTD),PinNumber); SET_BIT(GPIOIEV(PORTD),PinNumber);
				break;
				case DIO_PORTE: CLR_BIT(GPIOIS(PORTE),PinNumber); CLR_BIT(GPIOIBE(PORTE),PinNumber); SET_BIT(GPIOIEV(PORTE),PinNumber);
				break;
				case DIO_PORTF: CLR_BIT(GPIOIS(PORTF),PinNumber); CLR_BIT(GPIOIBE(PORTF),PinNumber); SET_BIT(GPIOIEV(PORTF),PinNumber);
				break;
			}			
		}
		else if(Trigger==INT_FALLING)
		{
			switch(PortId)
			{
				case DIO_PORTA: CLR_BIT(GPIOIS(PORTA),PinNumber); CLR_BIT(GPIOIBE(PORTA),PinNumber); CLR_BIT(GPIOIEV(PORTA),PinNumber); 
				break;
				case DIO_PORTB: CLR_BIT(GPIOIS(PORTB),PinNumber); CLR_BIT(GPIOIBE(PORTB),PinNumber); CLR_BIT(GPIOIEV(PORTB),PinNumber); 
				break;
				case DIO_PORTC: CLR_BIT(GPIOIS(PORTC),PinNumber); CLR_BIT(GPIOIBE(PORTC),PinNumber); CLR_BIT(GPIOIEV(PORTC),PinNumber);
				break;
				case DIO_PORTD: CLR_BIT(GPIOIS(PORTD),PinNumber); CLR_BIT(GPIOIBE(PORTD),PinNumber); CLR_BIT(GPIOIEV(PORTD),PinNumber);
				break;
				case DIO_PORTE: CLR_BIT(GPIOIS(PORTE),PinNumber); CLR_BIT(GPIOIBE(PORTE),PinNumber); CLR_BIT(GPIOIEV(PORTE),PinNumber);
				break;
				case DIO_PORTF: CLR_BIT(GPIOIS(PORTF),PinNumber); CLR_BIT(GPIOIBE(PORTF),PinNumber); CLR_BIT(GPIOIEV(PORTF),PinNumber);
				break;
			}			
		}
		else if(Trigger==INT_ANY_EDGE)
		{
			switch(PortId)
			{
				case DIO_PORTA: CLR_BIT(GPIOIS(PORTA),PinNumber); SET_BIT(GPIOIBE(PORTA),PinNumber); CLR_BIT(GPIOIEV(PORTA),PinNumber); 
				break;
				case DIO_PORTB: CLR_BIT(GPIOIS(PORTB),PinNumber); SET_BIT(GPIOIBE(PORTB),PinNumber); CLR_BIT(GPIOIEV(PORTB),PinNumber); 
				break;
				case DIO_PORTC: CLR_BIT(GPIOIS(PORTC),PinNumber); SET_BIT(GPIOIBE(PORTC),PinNumber); CLR_BIT(GPIOIEV(PORTC),PinNumber);
				break;
				case DIO_PORTD: CLR_BIT(GPIOIS(PORTD),PinNumber); SET_BIT(GPIOIBE(PORTD),PinNumber); CLR_BIT(GPIOIEV(PORTD),PinNumber);
				break;
				case DIO_PORTE: CLR_BIT(GPIOIS(PORTE),PinNumber); SET_BIT(GPIOIBE(PORTE),PinNumber); CLR_BIT(GPIOIEV(PORTE),PinNumber);
				break;
				case DIO_PORTF: CLR_BIT(GPIOIS(PORTF),PinNumber); SET_BIT(GPIOIBE(PORTF),PinNumber); CLR_BIT(GPIOIEV(PORTF),PinNumber);
				break;
			}			
		}
		else if(Trigger==INT_HIGH)
		{
			switch(PortId)
			{
				case DIO_PORTA: SET_BIT(GPIOIS(PORTA),PinNumber); CLR_BIT(GPIOIBE(PORTA),PinNumber); SET_BIT(GPIOIEV(PORTA),PinNumber); 
				break;
				case DIO_PORTB: SET_BIT(GPIOIS(PORTB),PinNumber); CLR_BIT(GPIOIBE(PORTB),PinNumber); SET_BIT(GPIOIEV(PORTB),PinNumber); 
				break;
				case DIO_PORTC: SET_BIT(GPIOIS(PORTC),PinNumber); CLR_BIT(GPIOIBE(PORTC),PinNumber); SET_BIT(GPIOIEV(PORTC),PinNumber);
				break;
				case DIO_PORTD: SET_BIT(GPIOIS(PORTD),PinNumber); CLR_BIT(GPIOIBE(PORTD),PinNumber); SET_BIT(GPIOIEV(PORTD),PinNumber);
				break;
				case DIO_PORTE: SET_BIT(GPIOIS(PORTE),PinNumber); CLR_BIT(GPIOIBE(PORTE),PinNumber); SET_BIT(GPIOIEV(PORTE),PinNumber);
				break;
				case DIO_PORTF: SET_BIT(GPIOIS(PORTF),PinNumber); CLR_BIT(GPIOIBE(PORTF),PinNumber); SET_BIT(GPIOIEV(PORTF),PinNumber);
				break;
			}	
		}
		else if(Trigger==INT_LOW)
		{
			switch(PortId)
			{
				case DIO_PORTA: SET_BIT(GPIOIS(PORTA),PinNumber); CLR_BIT(GPIOIBE(PORTA),PinNumber); CLR_BIT(GPIOIEV(PORTA),PinNumber); 
				break;
				case DIO_PORTB: SET_BIT(GPIOIS(PORTB),PinNumber); CLR_BIT(GPIOIBE(PORTB),PinNumber); CLR_BIT(GPIOIEV(PORTB),PinNumber); 
				break;
				case DIO_PORTC: SET_BIT(GPIOIS(PORTC),PinNumber); CLR_BIT(GPIOIBE(PORTC),PinNumber); CLR_BIT(GPIOIEV(PORTC),PinNumber);
				break;
				case DIO_PORTD: SET_BIT(GPIOIS(PORTD),PinNumber); CLR_BIT(GPIOIBE(PORTD),PinNumber); CLR_BIT(GPIOIEV(PORTD),PinNumber);
				break;
				case DIO_PORTE: SET_BIT(GPIOIS(PORTE),PinNumber); CLR_BIT(GPIOIBE(PORTE),PinNumber); CLR_BIT(GPIOIEV(PORTE),PinNumber);
				break;
				case DIO_PORTF: SET_BIT(GPIOIS(PORTF),PinNumber); CLR_BIT(GPIOIBE(PORTF),PinNumber); CLR_BIT(GPIOIEV(PORTF),PinNumber);
				break;
			}			
		}
}

void DIO_PortActivate(uint8 PortId,uint8 PinNumber,Config config)
{
		
		if(config.PortPinMode==DIGITAL)
		{
			switch(PortId)
			{
				case DIO_PORTA: SET_BIT(GPIODEN(PORTA),PinNumber); CLR_BIT(GPIOAFSEL(PORTA),PinNumber);SET_BIT(RCGCGPIO,0);
				break;
				case DIO_PORTB: SET_BIT(GPIODEN(PORTB),PinNumber); CLR_BIT(GPIOAFSEL(PORTB),PinNumber);SET_BIT(RCGCGPIO,1);
				break;
				case DIO_PORTC: SET_BIT(GPIODEN(PORTC),PinNumber); CLR_BIT(GPIOAFSEL(PORTC),PinNumber);SET_BIT(RCGCGPIO,2);
				break;
				case DIO_PORTD: SET_BIT(GPIODEN(PORTD),PinNumber); CLR_BIT(GPIOAFSEL(PORTD),PinNumber);SET_BIT(RCGCGPIO,3);
				break;
				case DIO_PORTE: SET_BIT(GPIODEN(PORTE),PinNumber); CLR_BIT(GPIOAFSEL(PORTE),PinNumber);SET_BIT(RCGCGPIO,4);
				break;
				case DIO_PORTF: SET_BIT(GPIODEN(PORTF),PinNumber); CLR_BIT(GPIOAFSEL(PORTF),PinNumber);SET_BIT(RCGCGPIO,5);
				break;
			}
		}
		else
		{
			switch(PortId)
			{
				case DIO_PORTA: CLR_BIT(GPIODEN(PORTA),PinNumber); SET_BIT(GPIOAFSEL(PORTA),PinNumber);SET_BIT(RCGCGPIO,0);
				break;
				case DIO_PORTB: CLR_BIT(GPIODEN(PORTB),PinNumber); SET_BIT(GPIOAFSEL(PORTB),PinNumber);SET_BIT(RCGCGPIO,1);
				break;
				case DIO_PORTC: CLR_BIT(GPIODEN(PORTC),PinNumber); SET_BIT(GPIOAFSEL(PORTC),PinNumber);SET_BIT(RCGCGPIO,2);
				break;
				case DIO_PORTD: CLR_BIT(GPIODEN(PORTD),PinNumber); SET_BIT(GPIOAFSEL(PORTD),PinNumber);SET_BIT(RCGCGPIO,3);
				break;
				case DIO_PORTE: CLR_BIT(GPIODEN(PORTE),PinNumber); SET_BIT(GPIOAFSEL(PORTE),PinNumber);SET_BIT(RCGCGPIO,4);
				break;
				case DIO_PORTF: CLR_BIT(GPIODEN(PORTF),PinNumber); SET_BIT(GPIOAFSEL(PORTF),PinNumber);SET_BIT(RCGCGPIO,5);
				break;
			}			
		}
		
		if(config.PortPinOutputCurrent==2)
		{
			switch(PortId)
			{
				case DIO_PORTA: SET_BIT(GPIODR2R(PORTA),PinNumber); CLR_BIT(GPIODR4R(PORTA),PinNumber); CLR_BIT(GPIODR8R(PORTA),PinNumber);
				break;
				case DIO_PORTB: SET_BIT(GPIODR2R(PORTB),PinNumber); CLR_BIT(GPIODR4R(PORTB),PinNumber); CLR_BIT(GPIODR8R(PORTB),PinNumber);
				break;
				case DIO_PORTC: SET_BIT(GPIODR2R(PORTC),PinNumber); CLR_BIT(GPIODR4R(PORTC),PinNumber); CLR_BIT(GPIODR8R(PORTC),PinNumber);
				break;
				case DIO_PORTD: SET_BIT(GPIODR2R(PORTD),PinNumber); CLR_BIT(GPIODR4R(PORTD),PinNumber); CLR_BIT(GPIODR8R(PORTD),PinNumber);
				break;
				case DIO_PORTE: SET_BIT(GPIODR2R(PORTE),PinNumber); CLR_BIT(GPIODR4R(PORTE),PinNumber); CLR_BIT(GPIODR8R(PORTE),PinNumber);
				break;
				case DIO_PORTF: SET_BIT(GPIODR2R(PORTF),PinNumber); CLR_BIT(GPIODR4R(PORTF),PinNumber); CLR_BIT(GPIODR8R(PORTF),PinNumber);
				break;
			}	
		}
		else if(config.PortPinOutputCurrent==4)
		{
			switch(PortId)
			{
				case DIO_PORTA: CLR_BIT(GPIODR2R(PORTA),PinNumber); SET_BIT(GPIODR4R(PORTA),PinNumber); CLR_BIT(GPIODR8R(PORTA),PinNumber);
				break;
				case DIO_PORTB: CLR_BIT(GPIODR2R(PORTB),PinNumber); SET_BIT(GPIODR4R(PORTB),PinNumber); CLR_BIT(GPIODR8R(PORTB),PinNumber);
				break;
				case DIO_PORTC: CLR_BIT(GPIODR2R(PORTC),PinNumber); SET_BIT(GPIODR4R(PORTC),PinNumber); CLR_BIT(GPIODR8R(PORTC),PinNumber);
				break;
				case DIO_PORTD: CLR_BIT(GPIODR2R(PORTD),PinNumber); SET_BIT(GPIODR4R(PORTD),PinNumber); CLR_BIT(GPIODR8R(PORTD),PinNumber);
				break;
				case DIO_PORTE: CLR_BIT(GPIODR2R(PORTE),PinNumber); SET_BIT(GPIODR4R(PORTE),PinNumber); CLR_BIT(GPIODR8R(PORTE),PinNumber);
				break;
				case DIO_PORTF: CLR_BIT(GPIODR2R(PORTF),PinNumber); SET_BIT(GPIODR4R(PORTF),PinNumber); CLR_BIT(GPIODR8R(PORTF),PinNumber);
				break;
			}				
		}
		else if(config.PortPinOutputCurrent==8)
		{
			switch(PortId)
			{
				case DIO_PORTA: CLR_BIT(GPIODR2R(PORTA),PinNumber); CLR_BIT(GPIODR4R(PORTA),PinNumber); SET_BIT(GPIODR8R(PORTA),PinNumber);
				break;
				case DIO_PORTB: CLR_BIT(GPIODR2R(PORTB),PinNumber); CLR_BIT(GPIODR4R(PORTB),PinNumber); SET_BIT(GPIODR8R(PORTB),PinNumber);
				break;
				case DIO_PORTC: CLR_BIT(GPIODR2R(PORTC),PinNumber); CLR_BIT(GPIODR4R(PORTC),PinNumber); SET_BIT(GPIODR8R(PORTC),PinNumber);
				break;
				case DIO_PORTD: CLR_BIT(GPIODR2R(PORTD),PinNumber); CLR_BIT(GPIODR4R(PORTD),PinNumber); SET_BIT(GPIODR8R(PORTD),PinNumber);
				break;
				case DIO_PORTE: CLR_BIT(GPIODR2R(PORTE),PinNumber); CLR_BIT(GPIODR4R(PORTE),PinNumber); SET_BIT(GPIODR8R(PORTE),PinNumber);
				break;
				case DIO_PORTF: CLR_BIT(GPIODR2R(PORTF),PinNumber); CLR_BIT(GPIODR4R(PORTF),PinNumber); SET_BIT(GPIODR8R(PORTF),PinNumber);
				break;
			}			
		}
		
		if(config.PinType==NORMAL)
		{
			switch(PortId)
			{
				case DIO_PORTA: CLR_BIT(GPIOODR(PORTA),PinNumber); CLR_BIT(GPIOPUR(PORTA),PinNumber); CLR_BIT(GPIOPDR(PORTA),PinNumber);
				break;
				case DIO_PORTB: CLR_BIT(GPIOODR(PORTB),PinNumber); CLR_BIT(GPIOPUR(PORTB),PinNumber); CLR_BIT(GPIOPDR(PORTB),PinNumber);
				break;
				case DIO_PORTC: CLR_BIT(GPIOODR(PORTC),PinNumber); CLR_BIT(GPIOPUR(PORTC),PinNumber); CLR_BIT(GPIOPDR(PORTC),PinNumber);
				break;
				case DIO_PORTD: CLR_BIT(GPIOODR(PORTD),PinNumber); CLR_BIT(GPIOPUR(PORTD),PinNumber); CLR_BIT(GPIOPDR(PORTD),PinNumber);
				break;
				case DIO_PORTE: CLR_BIT(GPIOODR(PORTE),PinNumber); CLR_BIT(GPIOPUR(PORTE),PinNumber); CLR_BIT(GPIOPDR(PORTE),PinNumber);
				break;
				case DIO_PORTF: CLR_BIT(GPIOODR(PORTF),PinNumber); CLR_BIT(GPIOPUR(PORTF),PinNumber); CLR_BIT(GPIOPDR(PORTF),PinNumber);
				break;
			}
		}
		else if(config.PinType==OPEN_DRAIN)
		{
			switch(PortId)
			{
				case DIO_PORTA: SET_BIT(GPIOODR(PORTA),PinNumber); CLR_BIT(GPIOPUR(PORTA),PinNumber); CLR_BIT(GPIOPDR(PORTA),PinNumber);
				break;
				case DIO_PORTB: SET_BIT(GPIOODR(PORTB),PinNumber); CLR_BIT(GPIOPUR(PORTB),PinNumber); CLR_BIT(GPIOPDR(PORTB),PinNumber);
				break;
				case DIO_PORTC: SET_BIT(GPIOODR(PORTC),PinNumber); CLR_BIT(GPIOPUR(PORTC),PinNumber); CLR_BIT(GPIOPDR(PORTC),PinNumber);
				break;
				case DIO_PORTD: SET_BIT(GPIOODR(PORTD),PinNumber); CLR_BIT(GPIOPUR(PORTD),PinNumber); CLR_BIT(GPIOPDR(PORTD),PinNumber);
				break;
				case DIO_PORTE: SET_BIT(GPIOODR(PORTE),PinNumber); CLR_BIT(GPIOPUR(PORTE),PinNumber); CLR_BIT(GPIOPDR(PORTE),PinNumber);
				break;
				case DIO_PORTF: SET_BIT(GPIOODR(PORTF),PinNumber); CLR_BIT(GPIOPUR(PORTF),PinNumber); CLR_BIT(GPIOPDR(PORTF),PinNumber);
				break;
			}
		}
		else if(config.PinType==PULL_UP)
		{
			switch(PortId)
			{
				case DIO_PORTA: CLR_BIT(GPIOODR(PORTA),PinNumber); SET_BIT(GPIOPUR(PORTA),PinNumber); CLR_BIT(GPIOPDR(PORTA),PinNumber);
				break;
				case DIO_PORTB: CLR_BIT(GPIOODR(PORTB),PinNumber); SET_BIT(GPIOPUR(PORTB),PinNumber); CLR_BIT(GPIOPDR(PORTB),PinNumber);
				break;
				case DIO_PORTC: CLR_BIT(GPIOODR(PORTC),PinNumber); SET_BIT(GPIOPUR(PORTC),PinNumber); CLR_BIT(GPIOPDR(PORTC),PinNumber);
				break;
				case DIO_PORTD: CLR_BIT(GPIOODR(PORTD),PinNumber); SET_BIT(GPIOPUR(PORTD),PinNumber); CLR_BIT(GPIOPDR(PORTD),PinNumber);
				break;
				case DIO_PORTE: CLR_BIT(GPIOODR(PORTE),PinNumber); SET_BIT(GPIOPUR(PORTE),PinNumber); CLR_BIT(GPIOPDR(PORTE),PinNumber);
				break;
				case DIO_PORTF: CLR_BIT(GPIOODR(PORTF),PinNumber); SET_BIT(GPIOPUR(PORTF),PinNumber); CLR_BIT(GPIOPDR(PORTF),PinNumber);
				break;
			}			
		}
		else if (config.PinType==PULL_DOWN)
		{
			switch(PortId)
			{
				case DIO_PORTA: CLR_BIT(GPIOODR(PORTA),PinNumber); CLR_BIT(GPIOPUR(PORTA),PinNumber); SET_BIT(GPIOPDR(PORTA),PinNumber);
				break;
				case DIO_PORTB: CLR_BIT(GPIOODR(PORTB),PinNumber); CLR_BIT(GPIOPUR(PORTB),PinNumber); SET_BIT(GPIOPDR(PORTB),PinNumber);
				break;
				case DIO_PORTC: CLR_BIT(GPIOODR(PORTC),PinNumber); CLR_BIT(GPIOPUR(PORTC),PinNumber); SET_BIT(GPIOPDR(PORTC),PinNumber);
				break;
				case DIO_PORTD: CLR_BIT(GPIOODR(PORTD),PinNumber); CLR_BIT(GPIOPUR(PORTD),PinNumber); SET_BIT(GPIOPDR(PORTD),PinNumber);
				break;
				case DIO_PORTE: CLR_BIT(GPIOODR(PORTE),PinNumber); CLR_BIT(GPIOPUR(PORTE),PinNumber); SET_BIT(GPIOPDR(PORTE),PinNumber);
				break;
				case DIO_PORTF: CLR_BIT(GPIOODR(PORTF),PinNumber); CLR_BIT(GPIOPUR(PORTF),PinNumber); SET_BIT(GPIOPDR(PORTF),PinNumber);
				break;
			}				
		}
}
