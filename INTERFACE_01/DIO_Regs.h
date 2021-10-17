/*
 * DIO_Regs.h
 *
 * Created: 10/13/2021 4:23:29 AM
 *  Author: Abdulrahman Sorour
 */ 


#ifndef DIO_REGS_H_
#define DIO_REGS_H_


#define PA_Data *((volatile uint8_t*)	0x3B)
#define PB_Data *((volatile uint8_t*)	0x38)
#define PC_Data *((volatile uint8_t*)	0x35)
#define PD_Data *((volatile uint8_t*)	0x32)

#define PA_Ctrl *((volatile uint8_t*)	0x3A)
#define PB_Ctrl *((volatile uint8_t*)	0x37)
#define PC_Ctrl *((volatile uint8_t*)	0x34)
#define PD_Ctrl *((volatile uint8_t*)	0x31)

#define PA_Stat *((volatile uint8_t*)	0x39)
#define PB_Stat *((volatile uint8_t*)	0x36)
#define PC_Stat *((volatile uint8_t*)	0x33)
#define PD_Stat *((volatile uint8_t*)	0x30)


#endif /* DIO_REGS_H_ */