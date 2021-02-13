/* ========================================================================== */
/* assignment1_2.h                                                            */
/* ========================================================================== */
/* This program is used for demonstrating the transition from programming     */
/* language to machine code.                                                  */
/* ========================================================================== */
/* author:           Ronnie Duisters                                          */
/* affiliation:      Fontys Hogescholen Engineering, Eindhoven                */
/* initial revision: 30-08-2013 (v1.0)                                        */
/* current version:  1.0                                                      */
/* changes:                                                                   */
/* ========================================================================== */

#ifndef ASSIGNMENT1_2_H
#define ASSIGNMENT1_2_H

#pragma config JTAGEN = OFF     
#pragma config FWDTEN = OFF      

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
#include "config.h"
#endif /* ASSIGNMENT1_2_H */
