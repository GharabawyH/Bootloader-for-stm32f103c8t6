#include "LSTD_TYPES.h"

#include "MRCC_private.h"

#include "MRCC_interface.h"



void MRCC_Initialize(void)
{
	RCC.CR	  = 0x00010001;/*Enable HSI and HSE*/
	while( (RCC.CR & 0x2) != 2);/*Wait till HSI is ready*/
	RCC.CFGR  = 0x00000001;/*Choose HSE as clock source*/
	RCC.CR   &= ~(0xFFFFFFFE);/*Disable HSE and enable HSI*/
	RCC.CFGR    = 0x003F0402;/**/
	RCC.CR    = 0x01000001;
	while (( (RCC.CR & 0x02000000) != 0) && ((RCC.CR & 0x2) != 2));
	RCC.CFGR    = 0x003F0402;
	while ((RCC.CFGR & 0x8)!=8);
//	RCC.CR	  = 0x00010001;
//	RCC.CFGR    = 0x1;

}


void MRCC_EnableClock(u8 Bus,u32 Peripheral)
{
	switch(Bus)
	{
	case BUS_AHB:RCC.AHBENR|=Peripheral;break;
	case BUS_APB1:RCC.APB1ENR|=Peripheral;break;
	case BUS_APB2:RCC.APB2ENR|=Peripheral;break;
	}
}

void MRCC_DisableClock(u8 Bus,u32 Peripheral)
{
	switch(Bus)
	{
	case BUS_AHB :	RCC.AHBENR	 &=~Peripheral;	break;
	case BUS_APB1:	RCC.APB1ENR	 &=~Peripheral;	break;
	case BUS_APB2:	RCC.APB2ENR	 &=~Peripheral;	break;
	}
}
