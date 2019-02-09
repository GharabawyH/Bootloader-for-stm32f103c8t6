/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */
#include "LSTD_TYPES.h"
#include "MRCC_interface.h"
#include "MUART_interface.h"
#include "MGPIO_interface.h"
#include "MFLASH_interface.h"
#include "MSTK_interface.h"


u8 volatile flag = 0;
u8 volatile x=0;

/*This function executes every 10 seconds if there's no new application to execute the old one*/
void CallBackFunc(void)
{
	x++;
	if(x==10)
	{
		if(flag==0)
		{
			void(*App)(void) = *((void(**)(void))0x08002004);
			App();
		}
		else
		{
			MSTK_DeInitialize();
		}
		x=0;
	}
}


void main(void)
{
	u8 i;
	u32 EntryPointAddress = 0x08002000;/*This is optional but you have to make sure this address isn't in the scope
	 	 	 	 	 	 	 	 	 	 	 	 of the bootloader project.*/
	/*Please note that the EntryPointAddress is not the beginning of your application ... it refers to
	  MSP : Main Stack Pointer (32 bits) .... so what you need to access is the EntryPointAddress + 0x4*/
	  /*You also have to edit the linker script (in application project not this project)where the memory section
	   lies(ldscripts/mem.ld) to tell your application its entry point.
	   Ex.: FLASH (rx) : ORIGIN = 0x08002000 (This is to edit the entry point)
	   Note : If you edit the entry point without changing anything in the code ... entry point will not be
	   	   	  updated in the HEX file ... so after editing the entry point make sure to edit something in the
	   	   	  code then build to generate a new HEX file.
	    LENGTH = 64K - 2000 (This is to be able to upload applications with interrupts)
	   While uploading the HEX file please make sure to set 15ms delay between each character receive of
	   the record (This project was tested with RealTerminal application)*/
	u32 Address = EntryPointAddress;
	u8 tmp;
	u8 CharCount;
	u8 RecType;
	u16 Data;
	u8 DataReceive[4];
	MRCC_Initialize();
	MRCC_EnableClock(BUS_AHB,PERIPHERAL_FLITF);/*You must enable Flash Interface Peripheral so you can
	 	 	 	 	 	 	 	 	 	 	 	 read from and write on the flash*/
	MRCC_EnableClock(BUS_APB2,PERIPHERAL_GPIOA);
	MRCC_EnableClock(BUS_APB2,PERIPHERAL_USART1);
	MGPIO_INITIALIZE();/*Initializing UART pins*/
	MUSART1_Initialize();
	MFLASH_Initialize();/*Flash interface initialize with unlock sequence and LATENCY set (for further info refer
							to Flash interface documentation)*/
	MSTK_SetCallBack(CallBackFunc);
	MSTK_Initialize();/*SYSTICK initialize*/
	while(1)
	{
		tmp = 0;
		CharCount = 0;
		RecType = 0;
		tmp = MUSART1_Receive();/*Receive the 1st Character of the record (:)*/
		/*Start of the record*/
		if(tmp == ':')
		{
			flag = 1;
			MUSART1_Transmit('R');/*This is just a check*/
			for(i=0 ; i < 2 ; i++ )
			{
				/*Character Count Receive*/
				tmp = MUSART1_Receive();
				/*Convert from ASCII to Decimal*/
				if(tmp >= 48 && tmp <= 57)
				{
					tmp = tmp - 48;
				}
				/*Convert from ASCII to Hexadecimal*/
				else if(tmp >= 65 && tmp <= 70)
				{
					tmp = tmp - 55;
				}
				CharCount |= tmp << ( 4 - ( 4 * i ) ) ;
			}
			/*Loop for offset address*/
			for(i = 0 ; i < 4 ; i++)
			{
				tmp = MUSART1_Receive();
			}
			/*Loop for record type*/
			for(i = 0 ; i < 2 ; i++)
			{
				/*Record Type Receive*/
				tmp = MUSART1_Receive();
				/*Convert from ASCII to Decimal*/
				if(tmp >= 48 && tmp <= 57)
				{
					tmp = tmp - 48;
				}
				/*Convert from ASCII to Hexadecimal*/
				else if(tmp >= 65 && tmp <= 70)
				{
					tmp = tmp - 55;
				}
				RecType |= tmp << ( 4 - ( 4 * i ) ) ;
			}
			if(RecType == 4)
			{
				for(i = 0 ; i < (CharCount*2) ; i++)
				{
					tmp = MUSART1_Receive();
				}
			}
			else if(RecType == 0)
			{
				for(i = 0 ; i < (CharCount*2) ; i++)
				{
					/*Data Receive*/
					tmp = MUSART1_Receive();
					/*Convert from ASCII to Decimal*/
					if(tmp >= 48 && tmp <= 57)
					{
						tmp = tmp - 48;
					}
					/*Convert from ASCII to Hexadecimal*/
					else if(tmp >= 65 && tmp <= 70)
					{
						tmp = tmp - 55;
					}
					DataReceive[i%4] = tmp;
					if(CharCount % 2 ==1)
					{
						if( i == ( ( 2 * CharCount ) - 1 ) )
						{
							Data = (DataReceive[0] << 4) | (DataReceive[1]);
							MFLASH_WriteHalfWord(Address , Data);
							Address +=2;
							Data = 0;
						}
					}
					if( (i % 4) == 3)
					{
						/*To arrange the received data*/
						Data = ((DataReceive[2] << 12) | (DataReceive[3] << 8) | (DataReceive[0] << 4) | (DataReceive[1]));
						/*To erase the flash page only one time at the beginning*/
						if( ( ( Address - EntryPointAddress ) % 0x0400 ) == 0 )
						{
							MFLASH_PageErase(Address);
						}
						MFLASH_WriteHalfWord(Address , Data);
						Address = (Address + 2);
						Data = 0;
					}
				}
			}
			else if(RecType == 5)
			{
				for( i = 0 ; i < (CharCount*2) ; i++)
				{
					tmp = MUSART1_Receive();
				}
			}
			else if(RecType == 1)
			{
				void(*App)(void) = *((void(**)(void))0x08002004);
				App();
			}
		}
	}
}

