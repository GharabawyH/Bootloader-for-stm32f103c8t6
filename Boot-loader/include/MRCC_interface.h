#ifndef _MRCC_INTERFACE_H
#define _MRCC_INTERFACE_H


#define BUS_AHB		1
#define BUS_APB1	2
#define BUS_APB2	3


#define PERIPHERAL_GPIOA	0x0004
#define PERIPHERAL_GPIOB	0x0008
#define PERIPHERAL_GPIOC	0x0010
#define PERIPHERAL_USART1	0x4000
#define PERIPHERAL_AFIO		0x0001
#define PERIPHERAL_FLITF	0x0010
#define PERIPHERAL_SPI1		0x1000
#define PERIPHERAL_ADC1		0x0200



void MRCC_Initialize(void);
void MRCC_EnableClock(u8 Bus,u32 Peripheral);
void MRCC_DisableClock(u8 Bus,u32 Peripheral);



#endif
