#ifndef _MSTK_PRIVATE_H
#define _MSTK_PRIVATE_H

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_Type;


#define MSTK ((volatile STK_Type*)0xE000E010)











#endif