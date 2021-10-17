/*
 * DIO.c
 *
 * Created: 10/13/2021 3:36:27 AM
 *  Author: Abdulrahman Sorour
 */ 
#include "DIO_Regs.h"
#include "Types.h"
#include "B_Math.h"
#include "DIO_Args.h"


void DIO_SetPortDirection (DIO_PORTID Port_ID	,	DIO_Direction Direction)				//Setting the direction of all pins in the port
{
if (Output == Direction)	
	{
		switch(Port_ID)
		{
			case PORTA: PA_Ctrl = 0xFF; break;
			case PORTB: PB_Ctrl = 0xFF; break;
			case PORTC: PC_Ctrl = 0xFF; break;
			case PORTD: PD_Ctrl = 0xFF; break;
			
		}
	}
else if(Input == Direction) 

 {
	 		switch(Port_ID)
	 		{
		 		case PORTA: PA_Ctrl = 0x00; break;
		 		case PORTB: PB_Ctrl	= 0x00; break;
		 		case PORTC: PC_Ctrl	= 0x00; break;
		 		case PORTD: PD_Ctrl = 0x00; break;
		 		
	 		}

}
}

void DIO_SetPortOutput(DIO_PORTID Port_ID	,uint8_t value)							    	//setting a value for all pins of the port
{
			switch(Port_ID)
			{
				case PORTA: PA_Data = value; break;
				case PORTB: PB_Data = value; break;
				case PORTC: PC_Data = value; break;
				case PORTD: PD_Data = value; break;
				
			}
}

void DIO_SetPinDirection(DIO_PORTID Port_ID , DIO_PIN_ID PIN_id, DIO_Direction Direction)   // setting the direction of specific pin in specific port
{
	if (	(Port_ID <= PORTD) && (PIN_id <= PIN7)	)
	{
		if (Direction == Output)
		{
			switch(Port_ID)
			{
							case PORTA: Set_Bit(PA_Ctrl , PIN_id); break;
							case PORTB: Set_Bit(PB_Ctrl , PIN_id); break;
							case PORTC: Set_Bit(PC_Ctrl , PIN_id); break;
							case PORTD: Set_Bit(PD_Ctrl , PIN_id); break;
			}

		}
		else if (Direction == Input)
		{
			switch(Port_ID)
			{				case PORTA: Clear_Bit(PA_Ctrl , PIN_id); break;
							case PORTB: Clear_Bit(PB_Ctrl , PIN_id); break;
							case PORTC: Clear_Bit(PC_Ctrl , PIN_id); break;
							case PORTD: Clear_Bit(PD_Ctrl , PIN_id); break;
			}
		}
}
}

void DIOSetPinOutput(DIO_PORTID Port_ID	,	DIO_PIN_ID PIN_id	,DIO_value	value)			// setting the value of specific pin in specific port
{
	if (	(Port_ID <= PORTD) && (PIN_id <= PIN7)	)
	{
		if (value == HIGH)
		{
			switch(Port_ID)
			{
				case PORTA: Set_Bit(PA_Data , PIN_id); break;
				case PORTB: Set_Bit(PB_Data , PIN_id); break;
				case PORTC: Set_Bit(PC_Data , PIN_id); break;
				case PORTD: Set_Bit(PD_Data , PIN_id); break;
			}

		}
		else if (value == LOW)
		{
			switch(Port_ID)
			{	
				case PORTA: Clear_Bit(PA_Data , PIN_id); break;
				case PORTB: Clear_Bit(PB_Data , PIN_id); break;
				case PORTC: Clear_Bit(PC_Data , PIN_id); break;
				case PORTD: Clear_Bit(PD_Data , PIN_id); break;
			}
		}
	}
}

DIO_value DIO_GetPinInput(DIO_PORTID Port_ID	,	DIO_PIN_ID PIN_id	)				    //getting the input value of specific pin in specific port
{
	DIO_value Pin_State;
			if (	(Port_ID <= PORTD) && (PIN_id <= PIN7)	)
			{
					switch(Port_ID)
					{
						case PORTA: Pin_State = GET_Bit(PA_Stat , PIN_id); break;
						case PORTB: Pin_State = GET_Bit(PB_Stat , PIN_id); break;
						case PORTC: Pin_State = GET_Bit(PC_Stat , PIN_id); break;
						case PORTD: Pin_State = GET_Bit(PD_Stat , PIN_id); break;
					}
			}
			
			
			return Pin_State;
}
