#include "Registers.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPTMDriver.h"

/*This array has the prescaler of the 12 timers*/
/*PreScaler[0]->timer0
 *PreScaler[1]->timer1
 *PreScaler[2]->timer2
					.....
	*PreScaler[6]->timer0-WIDE
					.....*/
					
uint16 PreScaler[12]; /*To store the prescaler while in the increment mode*/
void (*GlobalCallBackPtr0)(void);
void (*GlobalCallBackPtr0W)(void);

void GPTM_VidInit(uint8 TimerId, GPTM_config config)
{
	/*Incrment/Decrement the clock*/
	if(config.Dir==DOWN)
	{
		switch(TimerId)
		{
			case GPTM_TIMER0: CLR_BIT(GPTMTAMR(TIMER0),4);GPTMTAPR(TIMER0)=config.PreScaler;GPTMCFG(TIMER0)=0x4;SET_BIT(RCGCTIMER,0);
			break;
			case GPTM_TIMER0_WIDE: CLR_BIT(GPTMTAMR(TIMER0W),4);GPTMTAPR(TIMER0W)=config.PreScaler;SET_BIT(RCGCWTIMER,0);GPTMCFG(TIMER0W)=0x4;
			break;
			case GPTM_TIMER1: CLR_BIT(GPTMTAMR(TIMER1),4);GPTMTAPR(TIMER1)=config.PreScaler;GPTMCFG(TIMER1)=0x4;SET_BIT(RCGCTIMER,1);
			break;
			case GPTM_TIMER1_WIDE: CLR_BIT(GPTMTAMR(TIMER1W),4);GPTMTAPR(TIMER1W)=config.PreScaler;SET_BIT(RCGCWTIMER,1);GPTMCFG(TIMER1W)=0x4;
			break;
			case GPTM_TIMER2: CLR_BIT(GPTMTAMR(TIMER2),4);GPTMTAPR(TIMER2)=config.PreScaler;GPTMCFG(TIMER2)=0x4;SET_BIT(RCGCTIMER,2);
			break;
			case GPTM_TIMER2_WIDE: CLR_BIT(GPTMTAMR(TIMER2W),4);GPTMTAPR(TIMER2W)=config.PreScaler;SET_BIT(RCGCWTIMER,2);GPTMCFG(TIMER2W)=0x4;
			break;
			
		}
		
	}
	else
	{
		switch(TimerId)
		{
			case GPTM_TIMER0: SET_BIT(GPTMTAMR(TIMER0),4);PreScaler[0]=config.PreScaler;
			break;
			case GPTM_TIMER0_WIDE: SET_BIT(GPTMTAMR(TIMER0W),4);SET_BIT(RCGCWTIMER,0);PreScaler[6]=config.PreScaler;
			break;
			case GPTM_TIMER1: SET_BIT(GPTMTAMR(TIMER1),4);PreScaler[1]=config.PreScaler;
			break;
			case GPTM_TIMER1_WIDE: SET_BIT(GPTMTAMR(TIMER1W),4);SET_BIT(RCGCWTIMER,1);PreScaler[7]=config.PreScaler;
			break;
			case GPTM_TIMER2: SET_BIT(GPTMTAMR(TIMER2),4);PreScaler[2]=config.PreScaler;
			break;
			case GPTM_TIMER2_WIDE: SET_BIT(GPTMTAMR(TIMER2W),4);SET_BIT(RCGCWTIMER,2);PreScaler[8]=config.PreScaler;
			break;

		}
	}
	/*One shot or periodic timer*/
	if(config.Mode==ONE_SHOT)
	{
		switch(TimerId)
		{
			case GPTM_TIMER0: CLR_BIT(GPTMTAMR(TIMER0),1);SET_BIT(GPTMTAMR(TIMER0),0);break;
			case GPTM_TIMER0_WIDE: SET_BIT(GPTMTAMR(TIMER0W),1);CLR_BIT(GPTMTAMR(TIMER0W),0);break;
			case GPTM_TIMER1: CLR_BIT(GPTMTAMR(TIMER1),1);SET_BIT(GPTMTAMR(TIMER1),0);break;
			case GPTM_TIMER1_WIDE: SET_BIT(GPTMTAMR(TIMER1W),1);CLR_BIT(GPTMTAMR(TIMER1W),0);break;
			case GPTM_TIMER2: CLR_BIT(GPTMTAMR(TIMER2),1);SET_BIT(GPTMTAMR(TIMER2),0);break;
			case GPTM_TIMER2_WIDE: SET_BIT(GPTMTAMR(TIMER2W),1);CLR_BIT(GPTMTAMR(TIMER2W),0);break;
		}
	}
	else
	{
		switch(TimerId)
		{
			case GPTM_TIMER0: SET_BIT(GPTMTAMR(TIMER0),1);CLR_BIT(GPTMTAMR(TIMER0),0);break;
			case GPTM_TIMER0_WIDE: SET_BIT(GPTMTAMR(TIMER0W),1);CLR_BIT(GPTMTAMR(TIMER0W),0);break;
			case GPTM_TIMER1: SET_BIT(GPTMTAMR(TIMER1),1);CLR_BIT(GPTMTAMR(TIMER1),0);break;
			case GPTM_TIMER1_WIDE: SET_BIT(GPTMTAMR(TIMER0W),1);CLR_BIT(GPTMTAMR(TIMER0W),0);break;
			case GPTM_TIMER2: SET_BIT(GPTMTAMR(TIMER2),1);CLR_BIT(GPTMTAMR(TIMER2),0);break;
			case GPTM_TIMER2_WIDE: SET_BIT(GPTMTAMR(TIMER2W),1);CLR_BIT(GPTMTAMR(TIMER2W),0);break;


		}
	}
}

void GPTM_VidStart(uint8 TimerId, uint32 target)
{
			switch(TimerId)
		{
			case GPTM_TIMER0: ;GPTMTAILR(TIMER0)=target;SET_BIT(GPTMCTL(TIMER0),0);
			break;
			case GPTM_TIMER0_WIDE: GPTMTAILR(TIMER0W)=target;SET_BIT(GPTMCTL(TIMER0W),0);
			break;
			case GPTM_TIMER1: GPTMTAILR(TIMER1)=target;SET_BIT(GPTMCTL(TIMER1),0);
			break;
			case GPTM_TIMER1_WIDE: GPTMTAILR(TIMER1W)=target;SET_BIT(GPTMCTL(TIMER1W),0);
			break;
			case GPTM_TIMER2: GPTMTAILR(TIMER2)=target;SET_BIT(GPTMCTL(TIMER2),0);
			break;
			case GPTM_TIMER2_WIDE: GPTMTAILR(TIMER2W)=target;SET_BIT(GPTMCTL(TIMER2W),0);
			break;

			
		}
}

void GPTM_VidStop(uint8 TimerId)
{
			switch(TimerId)
		{
			case GPTM_TIMER0: CLR_BIT(GPTMCTL(TIMER0),0);
			break;
			case GPTM_TIMER0_WIDE: CLR_BIT(GPTMCTL(TIMER0W),0);
			break;
		}
}

uint8 Log_2(uint32 Input)
{
	uint8 n=0;
	if(Input==0)
		return 0;
	while(Input!=1)
	{
		Input>>=1;
		n++;
	}
	return n;
}
uint32 GPTM_uint32GetTime(uint8 TimerId)
{
	uint32 out=0;
	uint32 TAV;
	uint32 TAPR;
		uint16 n;
		switch(TimerId)
		{
			case GPTM_TIMER0: 
				if(!GET_BIT(GPTMTAMR(TIMER0),4))
					{
						out=GPTMTAV(TIMER0);
					}
				else
				{
				n=Log_2(PreScaler[0]); 
				TAV=(GPTMTAV(TIMER0)>>n);
				out=TAV;
				}
				break;
			case GPTM_TIMER0_WIDE: 
					if(!GET_BIT(GPTMTAMR(TIMER0W),4))
					{
						out=GPTMTAV(TIMER0W);
					}
				else{
				n=Log_2(PreScaler[6]); 
				TAV=(GPTMTAV(TIMER0W)>>n);
				n=32-n;
				TAPR=(GPTMTAPR(TIMER0W))<<n;
				out=TAV|TAPR;
				}
		}
		return out;
}

void GPTM_VidWriteTime(uint8 TimerId,uint32 Value)
{
	uint32 Timer;
	uint32 Pre=0;
	uint8 n;
	switch(TimerId)
	{
		case GPTM_TIMER0:
			if(GET_BIT(GPTMTAMR(TIMER0W),4))
			{
				n=Log_2(PreScaler[0]);
				GPTMTAV(TIMER0)=Value<<n;
			}
			else
			{
				GPTMTAV(TIMER0)=Value;
			}
			break;
			
			
		case GPTM_TIMER0_WIDE:
			if(GET_BIT(GPTMTAMR(TIMER0W),4))
			{
				n=Log_2(PreScaler[6]);
				GPTMTAV(TIMER0W)=Value<<n;
				GPTMTAPV(TIMER0W)|=(Value>>(32-n));
			}
			else
			{
				GPTMTAV(TIMER0W)=Value;
			}
			break;
	}

}
void GPTM_VidSetCallBackFunction(uint8 portId,void (*CallBackFunc)(void))
{
	switch(portId)
	{
		case GPTM_TIMER0:GlobalCallBackPtr0=CallBackFunc;
		break;
		case GPTM_TIMER0_WIDE:GlobalCallBackPtr0W=CallBackFunc;
		break;
		
	}
}
