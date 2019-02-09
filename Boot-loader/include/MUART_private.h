#ifndef _MUART_PRIVATE_H
#define _MUART_PRIVATE_H

#define MUART_TXE_BIT	0x80
#define MUART_TC_BIT	0x40
#define MUART_RXNE_BIT 	0x20

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}MUART_Type;



#define MUSART1	((volatile MUART_Type*)0x40013800)





#endif
