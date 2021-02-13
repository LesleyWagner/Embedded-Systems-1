/* 
 * File:   assignment_7.c
 * Author: Lesley Wagner
 *
 * Created on July 4, 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>
#include "config.h"
#include "pragma.h"
#include "assignment_7.h"

void main(int argc, char** argv) {
    unsigned short int channels = 0x2; // only use AN2 with the ADC converter
    unsigned short int reading;
    float voltage;
    char result[4]; // result on screen
    timer3_init();
    LCD_Init();
    adc_init (channels);
    LCD_WriteStringAtPos("Ch. AN2: ", 0, 0); 
    T3CONSET = 0x8000; // Start timer 3
    AD1CON1SET = 0x8000; // turn ADC ON
    AD1CON1SET = 0x0004; // start auto sampling every 100 ms
    
    while(1) {
        voltage = 3.3 * adc_getresult(2) / 1024; // get voltage reading from potmeter, ADC has 10 bit resolution, max = 3.3V      
        sprintf(result, "%4.2f", voltage);
        LCD_WriteStringAtPos(result, 0, 9); 
    }
}

/* ================================================================= */
/* function: timer3_init */
/* */
/* description: initialises timer 3 with a frequency of 625000. 
 * Timer 3 counts up to PR3 with a frequency of samplingRate.
/* */
/* pre: none
/* */
/* post: none */
/* ================================================================= */
void timer3_init() {
    T3CONbits.ON = 0;
    TMR3 = 0;
    PR3 = 625000/samplingRate; // period of 10 ms
    T3CONbits.TCS = 0; // clock source is internal
    T3CONbits.TCKPS = 0b110; // 64 clock divider, 625000 Hz frequency
}

/* ================================================================= */
/* function: adc_init */
/* */
/* description: initialises the 10-bit A/D converter. */
/* */
/* pre: channels ? 16-bit value, containing the analog inputs to be */
/* converted. Example: when only using AN2 and AN3, */
/* the channels variable should be 0b0000110 or 0x06 */
/* */
/* post: none */
/* ================================================================= */
void adc_init (unsigned short int channels) {
    ANSELBSET = 1 << 2; // PORTB = Digital; RB2 = analog in
    TRISBSET = 1 << 2;
    AD1CON1 = 0x40; // sampling with timer compare trigger
    AD1CHS = (int)channels << 16; // Connect RB2/AN2 as CH0 input
    AD1CSSL = 0; // no input scan, so don't specify inputs to scan
    AD1CON3 = 0x0000; // sample timer is TMR3
    AD1CON2 = 0; // no input scan
} 

/* ================================================================= */
/* function: adc_getresult */
/* */
/* description: obtains the last 10-bit conversion result for a */
/* specific analogue input channel. */
/* */
/* pre: channel ? the channel for which the result is required. */
/* range: 0-15. */
/* */
/* post: return value ? the 10-bit result of the last conversion for */
/* the specified channel. */
/* ================================================================= */
unsigned short int adc_getresult(unsigned char channel) {  
    while (!IFS0bits.AD1IF) {}; // check the ADIF interrupt bit
    IFS1CLR = 0x10000000;
    return ADC1BUF0;
}

/**
 * Resets display position to initial starting position after LCD_DisplayClear()
 * is called.
 */
void resetDisplayPosition() {
    unsigned char i;
    for (i = 0; i < 4; i++) {
        LCD_DisplayShift(1);
    }
}