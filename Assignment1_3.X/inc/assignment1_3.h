/* 
 * File:   assignment1_3.h
 * Author: Boyan Nikolov
 *
 * Created on 2 July 2017, 16:52
 */

#ifndef ASSIGNMENT1_3_H
#define	ASSIGNMENT1_3_H
#include "config.h"
/* ------------------------------------------------------------ */
/*						Configuration Bits		                */
/* ------------------------------------------------------------ */

// Device Config Bits in  DEVCFG1:	
#pragma config FNOSC =	FRCPLL
#pragma config FSOSCEN =	OFF
#pragma config POSCMOD =	XT
#pragma config OSCIOFNC =	ON
#pragma config FPBDIV =     DIV_2

// Device Config Bits in  DEVCFG2:	
#pragma config FPLLIDIV =	DIV_2
#pragma config FPLLMUL =	MUL_20
#pragma config FPLLODIV =	DIV_1

#pragma config JTAGEN = OFF     
#pragma config FWDTEN = OFF  


/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

#define BTNC    PORTFbits.RF0
#define LD0     LATAbits.LATA7
#define UPPER_BOUND 15
#define LOWER_BOUND 0

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */
void LEDs_GroupVal(unsigned char leds_val);
void GPIO_init(unsigned char init_val);
unsigned char btn_pressed(unsigned char btn);


#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* ASSIGNMENT1_3_H */

