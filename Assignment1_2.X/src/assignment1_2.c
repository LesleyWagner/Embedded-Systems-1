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
/* local function prototypes.                                                 */
/* -------------------------------------------------------------------------- */
int addnumbers
(
    int a,
    int b
);

/* -------------------------------------------------------------------------- */
/* main function.                                                             */
/* -------------------------------------------------------------------------- */
int main( void )
{
    int a = 4;
    int b = 12;
    int c;
    
    /* ---------------------------------------------------------------------- */
    /* call the addnumbers function and add a and b into c                    */
    /* ---------------------------------------------------------------------- */
    c = addnumbers( a, b ); 
    
    return 1;
}

/* ========================================================================== */
/* function: addnumbers( a, b );                                              */
/*                                                                            */
/* description: adds two integer numbers, a and b, and returns the result.    */
/*                                                                            */
/* pre:  a - an integer value to be added to b                                */
/*       b - an integer value to be added to a                                */
/*                                                                            */
/* post: return value - the integer sum of a and b                            */
/* ========================================================================== */

int addnumbers
(
    int a,
    int b
)
{
    return a << b;
}    