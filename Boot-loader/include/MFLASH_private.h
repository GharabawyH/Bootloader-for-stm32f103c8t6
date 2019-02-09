#ifndef _MFLASH_PRIVATE_H
#define _MFLASH_PRIVATE_H


typedef struct
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 AR;
	u32 RESERVED;
	u32 OBR;
	u32 WRPR;
}MFLASH_Type;


#define MFLASH ((volatile MFLASH_Type*)0x40022000)




#endif