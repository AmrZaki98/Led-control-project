#ifndef SysClock_H
#define SysClock_H
#include "STD_TYPES.h"
#include "SysClockConfig.h"
#define MOSC					0
#define PIOSC					1
#define SYS						2



void SysClock_VidInit(void);
void SysClock_VidSysTimrEnable(uint32 Target);
void SysClock_VidUpdateLoad(uint32 Target);
void SysClock_VidUpdateLoadSeconds(uint32 time);
void SysClock_IntEnable(void);
void SysClock_IntDisable(void);
void SysClock_VidSetCallBackFunction(void (*CallBack)(void));
#endif