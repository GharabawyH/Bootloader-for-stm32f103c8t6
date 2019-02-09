#ifndef _MFLASH_INTERFACE_H
#define _MFLASH_INTERFACE_H



void MFLASH_Initialize(void);
void MFLASH_PageErase(u32 Address);
void MFLASH_WriteHalfWord(u32 Address , u16 Data);





#endif
