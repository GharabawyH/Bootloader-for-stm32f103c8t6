#include "LSTD_TYPES.h"

#include "MFLASH_private.h"

#include "MFLASH_interface.h"


void MFLASH_Initialize(void)
{
	MFLASH -> ACR  = 2;
	//0x00A5
	/*Unlock sequence for flash write and programming*/
	MFLASH -> KEYR = 0x45670123;
	MFLASH -> KEYR = 0xCDEF89AB;
}

void MFLASH_PageErase(u32 Address)
{
	/*Wait for busy flag*/
	while(((MFLASH -> SR)&(1))!=0);
	/*Set Page erase bit*/
	MFLASH -> CR |= 0x0002;
	/*Set the desired address*/
	MFLASH -> AR  = Address;
	/*Set the start bit to start erasing the page*/
	MFLASH -> CR |= 0x0040;
	/*Wait for busy flag*/
	while(((MFLASH -> SR)&(1))!=0);
	/*Reset Page Erase bit*/
	MFLASH -> CR &=~(0x0002);
}

void MFLASH_WriteHalfWord(u32 Address , u16 Data)
{
	/*Set the programming bit*/
	MFLASH -> CR |= 0x0001;
	/*Write Data to the desired address*/
	*(u16*)Address = Data;
	/*Wait for busy flag*/
	while(((MFLASH -> SR)&(1))!=0);
	/*Reset the programming bit*/
	MFLASH -> CR &= ~(0x0001);
}
