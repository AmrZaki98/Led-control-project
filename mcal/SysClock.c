#include "SysClock.h"
#include "SysClockConfig.h"
#include "BIT_MATH.h"
#include "Registers.h"
#include "STD_TYPES.h"

#define F_CPU				12000000ul
#define F_PIOSC			32000000ul


uint32	d=0;
uint32 Target_prev=0;
void (*GlobalCallBackPtr)(void);
	
void SysClock_VidInit(void)
{
	unsigned int SYSDIV_temp;
	unsigned int XTAL_temp;
	SET_BIT(RCC,0);
			/*MOSC/POISC*/
		#if OSCSRC==MOSC
			CLR_BIT(RCC,4); 
			CLR_BIT(RCC,5);
		#elif OSCSRC==PIOSC
			SET_BIT(RCC,4);
			CLR_BIT(RCC,5);		
		#endif
		/*Pypss ppl*/
	#if PYPASSPPL==1
		SET_BIT(RCC,11);
		SET_BIT(RCC,13);
	#else
		CLR_BIT(RCC,11);
		CLR_BIT(RCC,13);		
	#endif
	
	#if SYSDIV==3
		SYSDIV_temp=0x2;
	#else
		SYSDIV_temp=0;
	#endif
	
		RCC&=0xF87FFFFF;
		RCC|=(SYSDIV_temp<<23);
	#if USESYSDIV==1
		SET_BIT(RCC,22);
	#else
		CLR_BIT(RCC,22);
	#endif

	#if XTAL==16
		XTAL_temp=0x15;
	#endif
	
		RCC&=0xFFFFF83F;
		RCC|=(XTAL_temp<<6);	

		#if MOSCDIS==1
			SET_BIT(RCC,0);
		#else
			CLR_BIT(RCC,0);
		#endif
		

}

void SysClock_VidSysTimrEnable(uint32 Target)
{
		#if SYSTICK_CLK==PIOSC
			CLR_BIT(STCTRL,2);
	#else
			SET_BIT(STCTRL,2);
	#endif
	STRELOAD=Target;
	SET_BIT(STCTRL,1);
	SET_BIT(STCTRL,0);
}

void SysClock_VidUpdateLoad(uint32 Target)
{
	if(Target==Target_prev)
		return;
	
	if(Target<=0xFFFFFF)
	{
		STRELOAD=Target;
		d=0;
		
	}
	else
	{
		d=Target-0xFFFFFF;
		STRELOAD=0xFFFFFF;
	}
	Target_prev=Target;
}

void SysClock_IntEnable(void)
{
	SET_BIT(STCTRL,1);
}
void SysClock_IntDisable(void)
{
	CLR_BIT(STCTRL,1);
}

void SysClock_VidUpdateLoadSeconds(uint32 time)
{
	uint32 F_SYS;

	if(GET_BIT(STCTRL,2))
	{
		F_SYS=F_CPU/SYSDIV;
	}
	else
		{
			F_SYS=F_PIOSC/4;
		}
	uint32 Target=F_SYS*time;
	SysClock_VidUpdateLoad(Target);
}
void SysClock_VidSetCallBackFunction(void (*CallBack)(void))
{
	GlobalCallBackPtr=CallBack;
}




void SysClock_VidUpdateLoad_Int(uint32 Target)
{
	
	if(Target<=0xFFFFFF)
	{
		STRELOAD=Target;
		d=0;		
	}
	else
	{
		d=Target-0xFFFFFF;
		STRELOAD=0xFFFFFF;
	}
	
}


void SysTick_Handler(void)
{
	if(d==0){
		GlobalCallBackPtr();
		SysClock_VidUpdateLoad_Int(Target_prev);
	}
	else
	{
		SysClock_VidUpdateLoad_Int(d);
	}
}

