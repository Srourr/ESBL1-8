/*
 * DIO.h
 *
 * Created: 10/13/2021 3:35:56 AM
 *  Author: Abdulrahman Sorour
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_SetPortDirection (DIO_PORTID Port_ID	,	DIO_Direction Direction);				//Setting the direction of all pins in the port
void DIO_SetPortOutput	  (DIO_PORTID Port_ID	,uint8_t	value);								//setting a value for all pins of the port
void DIO_SetPinDirection  (DIO_PORTID Port_ID ,DIO_PIN_ID PIN_id,DIO_Direction Direction);    // setting the direction of specific pin in specific port
void DIOSetPinOutput	  (DIO_PORTID Port_ID	,	DIO_PIN_ID PIN_id	,DIO_value	value);			// setting the value of specific pin in specific port
DIO_value DIO_GetPinInput (DIO_PORTID Port_ID	,	DIO_PIN_ID PIN_id	);				    //getting the input value of specific pin in specific port


#endif /* DIO_H_ */