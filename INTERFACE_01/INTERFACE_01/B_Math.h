/*
 * B_Math.h
 *
 * Created: 10/13/2021 6:15:00 AM
 *  Author: Abdulrahman Sorour
 */ 


#ifndef B_MATH_H_
#define B_MATH_H_

#define Set_Bit(Port_ID , PIN_id)		( Port_ID |= (1 << (PIN_id))	)
#define Clear_Bit(Port_ID , PIN_id)		( Port_ID &= ~(1 << (PIN_id))	)
#define Toggle_Bit(Port_ID , PIN_id)	( Port_ID ^= (1 << (PIN_id))	)
#define GET_Bit(Port_ID , PIN_id)		(((Port_ID) >> (PIN_id)) & 0x01)



#endif /* B_MATH_H_ */