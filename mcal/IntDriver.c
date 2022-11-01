#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Registers.h"
#include "IntDriver.h"


void Int_VidInit(uint8 priGrp)
{
	uint32 APINT_temp;
	switch (priGrp)
	{
		case xxx: APINT_temp=0x00; break;
		case xxy: APINT_temp=0x5;break;
		case xyy: APINT_temp=0x6;break;
		case yyy: APINT_temp=0x7;break;
	}
	APINT_temp<<=8;
	APINT_temp|=((0xF05)<<16);
	APINT=APINT_temp;
}

void Int_VidEnableInterrupt(uint8 trigger)
{
	uint8 IntReg=trigger/32;	
	uint8 bit=(trigger%32);
	IntReg*=4;
	SET_BIT(INTEN(IntReg),bit);
	
}

void Int_VidDisableInterrupt(uint8 trigger)
{
	uint8 IntReg=trigger/32;	
	uint8 bit=(trigger%32);
	IntReg*=4;
	SET_BIT(DIS(IntReg),bit);
}

void Int_VidSetPriority(uint8 trigger,uint32 pri, uint32 subPri)
{
	uint8 PriReg=trigger/4;	
	uint8 Group_bits=5+8*(trigger%4); /*The bits number in the pr register*/
	PriReg*=4;
	uint32 Pri_group=APINT>>8; /*which grouping technique is used (xxx,xxy,...)*/
	Pri_group&=(0x000007);
	switch(Pri_group)
	{
		case 0x5: 
				PRI(PriReg)=PRI(PriReg)|(pri<<(Group_bits+1));
				PRI(PriReg)=PRI(PriReg)|(subPri<<(Group_bits));
				break;
	
		case 0x6: 
				PRI(PriReg)=PRI(PriReg)|(pri<<(Group_bits+2));
				PRI(PriReg)=PRI(PriReg)|(subPri<<(Group_bits));
				break;
	
		case 0x7: 
				PRI(PriReg)=PRI(PriReg)|(subPri<<(Group_bits));
				break;

		default: 
				PRI(PriReg)=PRI(PriReg)|(pri<<(Group_bits));
				break;
	}		
}

void Int_VidClrGlobalInterrupt(void)
{
	//__set_FAULTMASK(temp);
	register char x=1;
		__asm
	(
		"MOV R1, 1"
	);
	__asm
	(
		"MSR FAULTMASK , R1"
	);

}

void Int_VidSetGlobalInterrupt(void)
{
			register char x=1;
		__asm
	(
		"MOV R1, 0"
	);
	__asm
	(
		"MSR FAULTMASK , R1"
	);

}