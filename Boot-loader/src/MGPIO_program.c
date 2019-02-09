#include "LSTD_TYPES.h"

#include "MGPIO_private.h"

#include "MGPIO_interface.h"

void MGPIO_INITIALIZE(void)
{
	GPIOA.CRH=0x000004A0;
}

void MGPIO_SetPin(u8 Port ,u8 Pin)
{
	switch (Port)
	{
	case PORTA:GPIOA.BSRR=Pin;break;
	case PORTB:GPIOB.BSRR=Pin;break;
	case PORTC:GPIOC.BSRR=Pin;break;
	}
}

void MGPIO_ClearPin(u8 Port,u8 Pin)
{
	switch(Port)
	{
	case PORTA:GPIOA.BRR=Pin;break;
	case PORTB:GPIOB.BRR=Pin;break;
	case PORTC:GPIOC.BRR=Pin;break;
	}
}

void MGPIO_AssignPort(u8 Port,u16 Value)
{
	switch(Port)
	{
	case PORTA:GPIOA.ODR=Value;break;
	case PORTB:GPIOB.ODR=Value;break;
	case PORTC:GPIOC.ODR=Value;break;
	}
}
u8 MGPIO_GetPinValue(u8 Port, u8 Pin)
{
	u8 value;
	switch (Port)
	{
	case PORTA:value=(GPIOA.IDR&Pin);if(value)value=1;break;
	case PORTB:value=(GPIOB.IDR&Pin);if(value)value=1;break;
	}
	return value;
}


