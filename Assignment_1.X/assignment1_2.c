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

/* -------------------------------------------------------------------------- */
/* main function.                                                             */
/* -------------------------------------------------------------------------- */
int main( void ) {
    TRISA = 0; // pinMode(OUTPUT)
    LATA = 0xFF; // Turn on all leds
    // added to github
    return 1;
}