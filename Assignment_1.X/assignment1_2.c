/* ========================================================================== */
/* assignment1_2.c                                                            */
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

/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include "assignment1_2.h"

/* -------------------------------------------------------------------------- */
/* global variables.                                                          */
/* -------------------------------------------------------------------------- */

int readSwitch0();
/* -------------------------------------------------------------------------- */
/* main function.                                                             */
/* -------------------------------------------------------------------------- */
int main( void ) {
    setTimer2();
    TRISA = 0x00;
    LATA = 0;
    
    while (1) {
        if (TMR2 > 50000) {
            TMR2 = 0;
            LATA++;
        }
    }
    return 1;
}

char switch0Prev = 0;
int readSwitch0() {
    if (switch0Prev == 0) {
        if (prt_SWT_SWT0 == 1) {
            switch0Prev = 1;
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (prt_SWT_SWT0 == 1) {
            return 0;
        }
        else {
            switch0Prev = 0;
            return 0;
        }
    }
}

void setTimer2() {
    T2CONbits.TCS = 0; // clock source is internal
    T2CONbits.T32 = 0; // 16 bit mode is used
    T2CONbits.TCKPS = 0b111; // 256 clock divider, 156250 Hz frequency
    T2CONbits.ON = 1;
}