#include "LSTD_TYPES.h"

#include "MUART_private.h"

#include "MUART_interface.h"


void MUSART1_Initialize(void)
{
	(MUSART1 -> BRR) =0x1A0B;
	(MUSART1 -> CR1) =0x00002000;
	(MUSART1 -> CR1) |=(3<<2);
}


void MUSART1_Transmit(u8 Data)
{
	(MUSART1 -> DR) = Data;
	while(((MUSART1 -> SR)&(MUART_TC_BIT))==0);

}


u8 MUSART1_Receive(void)
{
	while(((MUSART1 -> SR)&(MUART_RXNE_BIT))==0);
	return ((0xFF) & (MUSART1 -> DR));
}
