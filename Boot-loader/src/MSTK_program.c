#include "LSTD_TYPES.h"

#include "MSTK_private.h"

#include "MSTK_interface.h"


void (*MSTK_CallBack)(void);


void MSTK_Initialize(void)
{
	MSTK -> CTRL = 3;
	MSTK -> VAL  = 8000000;
	MSTK -> LOAD = 8000000;
}

void MSTK_DeInitialize(void)
{
	MSTK -> CTRL = 0;
}


void SysTick_Handler(void)
{
	MSTK_CallBack();
}


void MSTK_SetCallBack(void(*ptr)(void))
{
	MSTK_CallBack = ptr;
}
