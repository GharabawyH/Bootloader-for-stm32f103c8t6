#ifndef _MRCC_PRIVATE_H
#define _MRCC_PRIVATE_H



typedef struct
{
		u32 CR;
		u32 CFGR;
		u32 CIR;
		u32 APB2RSTR;
		u32 APB1RSTR;
		u32 AHBENR;
		u32 APB2ENR;
		u32 APB1ENR;
		u32 BDCR;
		u32 CSR;
}RCC_Type;

#define IOPAEN 2
#define IOPBEN 3
#define IOPCEN 4
#define IOPDEN 5

#define RCC				(*((volatile RCC_Type*)0x40021000))
/*#define RCC_CR 		*((volatile u32*)0x40021000)
#define RCC_CFGR 		*((volatile u32*)0x40021004)
#define RCC_CIR 		*((volatile u32*)0x40021008)
#define RCC_APB2RSTR 	*((volatile u32*)0x4002100C)
#define RCC_APB1RSTR 	*((volatile u32*)0x40021010)
#define RCC_AHBENR	 	*((volatile u32*)0x40021014)
#define RCC_APB2ENR 	*((volatile u32*)0x40021018)
#define RCC_APB1ENR 	*((volatile u32*)0x4002101C)
#define RCC_BDCR	 	*((volatile u32*)0x40021020)
#define RCC_CSR		 	*((volatile u32*)0x40021024)*/

#endif