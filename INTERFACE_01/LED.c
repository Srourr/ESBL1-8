/*
 * LED.c
 *
 * Created: 10/17/2021 12:45:17 AM
 *  Author: Abdulrahman Sorour
 */ 
#include "DIO_Args.h"
#include "Types.h"
#include "DIO.h"

 void LED()
 {
	 DIO_SetPortDirection(PORTA , Output);
	 DIO_SetPinDirection(PORTC	,PIN1	,Input);
	 
	 if (DIO_GetPinInput(PORTC , PIN1)) DIO_SetPortOutput(PORTA	,	0x0F);
	 else DIO_SetPortOutput(PORTA	,	0x00);
 }