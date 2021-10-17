/*
 * DIO_Args.h
 *
 * Created: 10/13/2021 3:46:53 AM
 *  Author: Abdulrahman Sorour
 */ 


#ifndef DIO_ARGS_H_
#define DIO_ARGS_H_

typedef enum
	{
	Input,	//0
	Output	//1
	}DIO_Direction;

typedef enum
	{
	PORTA, //0
	PORTB, //1
	PORTC, //2
	PORTD  //3
	}DIO_PORTID;

typedef enum
{
	LOW, //0
	HIGH //1
	}DIO_value;
	
typedef enum
{
	PIN1, //0
	PIN2, //1
	PIN3, //2
	PIN4, //3
	PIN5, //4
	PIN6, //5
	PIN7, //6
	}DIO_PIN_ID;
#endif /* DIO_ARGS_H_ */