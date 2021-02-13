/* ************************************************************************** */
/** Button Utilities

  @Description
    Utility functions for interacting with push buttons L, C, R, U and D.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include "button_utils.h"



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

 /** 
 * Variables that keep track of the state of the buttons.
 * lastBtnState and btnState holds the state of button number n in the nth bit:
 * the state of button L resides in the 0th bit, button C in the 1st bit.
  */
static unsigned char lastBtnState = 0; 
static unsigned char btnState = 0; 

/** 
 * lastDebounceTime holds the debounce time for the 5 buttons in their corresponding entry.
 * The debounce time for button L is in the 0th entry, button C is in the 1st entry.
 */
static unsigned int lastDebounceTime[5];


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

void buttons_init() {
    TRISBbits.TRISB0 = 1; // button L is input
    TRISFbits.TRISF0 = 1; // button C is input
    TRISBbits.TRISB8 = 1; // button R is input
    TRISBbits.TRISB1 = 1; // button U is input
    TRISAbits.TRISA15 = 1; // button D is input
    
    ANSELBbits.ANSB0 = 0; // analog function for button L is disabled
    ANSELBbits.ANSB8 = 0; // analog function for button R is disabled
    ANSELBbits.ANSB1 = 0; // analog function for button U is disabled
}

unsigned char btn_pressed(Button btn) {
    unsigned char reading;
    switch(btn) {
        case btnL:
            reading = PORTBbits.RB0;
            break;
        case btnC:
            reading = PORTFbits.RF0;
            break;
        case btnR:
            reading = PORTBbits.RB8;
            break;
        case btnU:
            reading = PORTBbits.RB1;
            break;
        case btnD:
            reading = PORTAbits.RA15;
            break;
    }
    
    // button value has changed
    if (reading != ((lastBtnState >> btn) & 0x01)) {
        // reset debouncing timer
        lastDebounceTime[btn] = _CP0_GET_COUNT();
    }
    // button reading has been there for longer then debounceDelay
    if ((_CP0_GET_COUNT() - lastDebounceTime[btn]) > debounceDelay) {
        if (reading != ((btnState >> btn) & 0x01)) {
            btnState ^= (-reading ^ btnState) & (0x01 << btn); // sets bit 'btn' in btnState to reading
            
            if (((btnState >> btn) & 0x01)) {
                lastBtnState ^= (-reading ^ lastBtnState) & (0x01 << btn); // sets bit 'btn' in lastBtnState to reading
                return 1;
            }
        }
    }
    
    lastBtnState ^= (-reading ^ lastBtnState) & (0x01 << btn); // sets bit 'btn' in lastBtnState to reading
    return 0;
}


/* *****************************************************************************
 End of File
 */
