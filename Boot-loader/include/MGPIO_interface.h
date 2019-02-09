#ifndef _MGPIO_INTERFACE_H
#define _MGPIO_INTERFACE_H

#define Low						50
#define High					70


#define PORTA					0
#define PORTB					1
#define PORTC					2
#define PORTD					3

#define Pin0					0x0001
#define Pin1					0x0002
#define Pin2					0x0004
#define Pin3					0x0008
#define Pin4					0x0010
#define Pin5					0x0020
#define Pin6					0x0040
#define Pin7					0x0080
#define Pin8					0x0100
#define Pin9					0x0200
#define Pin10					0x0400
#define Pin11					0x0800
#define Pin12					0x1000
#define Pin13					0x2000
#define Pin14					0x4000
#define Pin15					0x8000

void MGPIO_INITIALIZE(/*u8 PortNum,u8 PinNum,u8 Mode,u8 CNF*/void);
void MGPIO_SetPin(u8 Port ,u8 Pin);
void MGPIO_ClearPin(u8 Port,u8 Pin);
u8 MGPIO_GetPinValue(u8 Port, u8 Pin);
void MGPIO_AssignPort(u8 Port,u16 Value);





#endif
