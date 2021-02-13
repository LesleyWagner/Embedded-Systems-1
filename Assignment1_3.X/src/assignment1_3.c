/* 
 * File:   assignment1_3.c
 * Author: Boyan Nikolov
 *
 * Created on 2 July 2017, 16:53
 */

/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include "assignment1_3.h"
/* Your own custom made libraries */

     

/* Local variables */


int main(){
    int counter = 0;
    unsigned char leds_init = 0x00; // LD0, LD1, LD2, LD3 are 1
    GPIO_init(leds_init);
    
    while(1){
        // button R is pressed
        if (btn_pressed(2)){
            counter = ++counter & 0x0F; // upper bound = 15
            LEDs_GroupVal(counter);
        }
        // button C is pressed
        if (btn_pressed(1)){
            counter = --counter & 0x0F; // lower bound = 0
            LEDs_GroupVal(counter);
        }
    }
    
    return (0);
}

void GPIO_init(unsigned char init_val){
    
    TRISBbits.TRISB0 = 1; // button L is input
    TRISFbits.TRISF0 = 1; // button C is input
    TRISBbits.TRISB8 = 1; // button R is input
    TRISBbits.TRISB1 = 1; // button U is input
    TRISAbits.TRISA15 = 1; // button D is input
    
    ANSELBbits.ANSB0 = 0; // analog function for button L is disabled
    ANSELBbits.ANSB8 = 0; // analog function for button R is disabled
    ANSELBbits.ANSB1 = 0; // analog function for button U is disabled
    
    TRISA = 0xFF00; // led pins are configured as outputs
    
    LATA = init_val; // sets led initial values
}

/*
 * Assigns value to all four LEDS: LD0, LD1, LD2, LD3
 */
void LEDs_GroupVal(unsigned char leds_val) {
    LATA = leds_val;
}

/*
 * Reads the value of a push button.
 * @param button - push button to be read. ( L = 0, C = 1, R = 2, U = 3, D = 4)
 * Returns 1 when the button is pressed, 0 when it is not pressed).
 */
unsigned char lastBtnState = 0;
unsigned char btnState = 0; 
const int debounceDelay = 800000; // 20 ms debounce time, 400000 clock ticks
unsigned int lastDebounceTime[5];
unsigned char btn_pressed(unsigned char btn) {
    unsigned char reading;
    switch(btn) {
        case 0: // button L 
            reading = PORTBbits.RB0;
            break;
        case 1: // button C 
            reading = PORTFbits.RF0;
            break;
        case 2: // button R 
            reading = PORTBbits.RB8;
            break;
        case 3: // button U 
            reading = PORTBbits.RB1;
            break;
        case 4: // button D 
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