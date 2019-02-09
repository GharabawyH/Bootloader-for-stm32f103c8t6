#ifndef _MGPIO_PRIVATE_H
#define _MGPIO_PRIVATE_H




#define Analog_Input 			0
#define Float_Input 			1
#define PullUp_PullDown_Input 	2

#define GP_PushPull_Output		0
#define GP_OpenDrain_Output		1
#define AF_PushPull_Output		2
#define AF_OpenDrain_Output		3

#define Input_Mode				0
#define Output_10MHZ			1
#define Output_2MHZ				2
#define Output_50MHZ			3


typedef struct
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;
}GPIO_Type;


#define GPIOA (*((volatile GPIO_Type*)0x40010800))
#define GPIOB (*((volatile GPIO_Type*)0x40010C00))
#define GPIOC (*((volatile GPIO_Type*)0x40011000))
#define GPIOD (*((volatile GPIO_Type*)0x40011400))







#endif
