/* 
 * File:   main.c
 * Author: Robert Konarskis
 *
 * Created on July 4, 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>
#include "config.h"
#include "pragma.h"
#include "main.h"

int cycleCounter = 0; // increases with every new cycle of the PWM signal
int stepPeriod; // time period during which the PWM duty cycle is kept constant

int redWidth = 0; // percentage of PWM signal during which the red led is high
int greenWidth = 0; // percentage of PWM signal during which the green led is high
int blueWidth = 0; // percentage of PWM signal during which the blue led is high

/*
 * Patterns for the red, green and blue leds. 0 means the led is off. 
 * 1 means that the led changes linearly from 0 to 100% intensity and back in 2 seconds.
 * The 7th bit is irrelevant because the length of the patterns is 7.
 */
char redPattern   = 0b01111000; // pattern for red led 
char greenPattern = 0b01001110; // pattern for green led
char bluePattern  = 0b01100011; // pattern for blue led
char redValue = 0; // current value in the pattern of the red led
char greenValue = 0; // current value in the pattern of the green led
char blueValue = 1; // current value in the pattern of the blue led
int patternIndex = 0; // index for the current red, green and blue led values

void main(int argc, char** argv) {
    rgbled_init (pwmFrequency, 0);
    while(1) {
        // timer 2 generates interrupt request on bit 8 of IFS0
        // when it completes a PWM period
        if (IFS0bits.T2IF == 1) {
            IFS0CLR = 0x200; // reset interrupt flag
            cycleCounter++;
            // leds with a value of 1 in the pattern go up linearly in intensity over 1 second of time
            // until they reach 100% intensity.
            if ((cycleCounter % 20) == 0 && cycleCounter <= 200) {
                if (redValue) {
                    redWidth += 10;
                }
                if (greenValue) {
                    greenWidth += 10;
                }
                if (blueValue) {
                    blueWidth += 10;
                }
                rgbled_setpwmwidths(redWidth, greenWidth, blueWidth);
            } 
            // leds with a value of 1 in the pattern go down linearly in intensity over 1 second of time
            // until they reach 0% intensity.
            else if ((cycleCounter % 20) == 0) {
                if (redValue) {
                    redWidth -= 10;
                }
                if (greenValue) {
                    greenWidth -= 10;
                }
                if (blueValue) {
                    blueWidth -= 10;
                }
                rgbled_setpwmwidths(redWidth, greenWidth, blueWidth);
                // new led pattern at 2 seconds
                if (cycleCounter == 400) {
                    cycleCounter = 0;
                    patternIndex++;
                    patternIndex = patternIndex == 7 ? 0 : patternIndex;
                    redValue = (redPattern >> patternIndex) & 0x01;
                    greenValue = (greenPattern >> patternIndex) & 0x01;
                    blueValue = (bluePattern >> patternIndex) & 0x01;
                }
            }         
        }
    }
}

/* ================================================================= */
/* function: rgbled_init */
/* */
/* description: initialises the RGB LED connected to OC3 (R), OC5 (G)*/
/* and OC4 (B) at a given width each. The repetition */
/* frequency of the PWM signals can be set using the */
/* freq argument. */
/* */
/* pre: freq ? repetition frequency of the PWM signals in Hz. */
/* The range of frequencies is 100 Hz ? 2 kHz. */
/* width ? default width of the 3 channels in %. */
/* */
/* post: none */
/* ================================================================= */
void rgbled_init (unsigned int freq, unsigned char width) {
    T2CON = 0x0; // Stop any timer 2 operation
    T2CONSET = 0x0050; // 16-bit mode, prescaler 1:32 (frequency 1.250.000 HZ), internal peripheral clock source
    TMR2 = 0x0; // Clear contents of TMR2
    PR2 = 1250000/freq - 1; // set PWM period 
    int dutyCycle = (PR2*width)/100; // PWM duty cycle
    
    // Configure Output Compare Module 3 - for PWM usage
    OC3CONbits.ON = 0;       // Turn off OC3 while doing setup.
    OC3RS = dutyCycle; // Set PWM duty cycle for OC3;
    OC3R = dutyCycle;  // Set PWM duty cycle for OC3;
    OC3CONbits.OCM = 6;      // PWM mode on OC3; Fault pin is disabled
    OC3CONbits.OCTSEL = 0;   // Timer 2 is the clock source for this Output Compare module
    OC3CONbits.ON = 1;       // Start the OC3 module

    // Configure Output Compare Module 4 - for PWM usage
    OC4CONbits.ON = 0;       // Turn off OC4 while doing setup.
    OC4RS = dutyCycle; // Set PWM duty cycle for OC4;
    OC4R = dutyCycle;  // Set PWM duty cycle for OC4;
    OC4CONbits.OCM = 6;      // PWM mode on OC4; Fault pin is disabled
    OC4CONbits.OCTSEL = 0;   // Timer 2 is the clock source for this Output Compare module
    OC4CONbits.ON = 1;       // Start the OC4 module

    // Configure Output Compare Module 5 - for PWM usage
    OC5CONbits.ON = 0;       // Turn off OC5 while doing setup.
    OC5RS = dutyCycle; // Set PWM duty cycle for OC5;
    OC5R = dutyCycle;  // Set PWM duty cycle for OC5;
    OC5CONbits.OCM = 6;      // PWM mode on OC5; Fault pin is disabled
    OC5CONbits.OCTSEL = 0;   // Timer 2 is the clock source for this Output Compare module
    OC5CONbits.ON = 1;       // Start the OC5 module  
    
    rp_LED8_R = 0x0B; // rp_LED8_R = RPD2R = OC3
    rp_LED8_B = 0x0B; // rp_LED8_B = RPD3R = OC4
    rp_LED8_G = 0x0B; // rp_LED8_G = RPD12R = OC5
    
    // disable analog (set pins as digital))
    ansel_LED8_R = 0;
    ansel_LED8_B = 0;
    
    lat_LED8_R = 0;
    lat_LED8_G = 0;
    lat_LED8_B = 0;
    
    T2CONSET = 0x8000; // Start timer 2
}

/* ================================================================= */
/* function: rgbled_setpwmwidths */
/* */
/* description: sets the PWM widths for each of the channels of the */
/* RGB LED. */
/* */
/* pre: rwidth ? width of the R channel in %. */
/* gwidth ? width of the G channel in %. */
/* bwidth ? width of the B channel in %. */
/* */
/* post: none */
/* ================================================================= */
void rgbled_setpwmwidths (unsigned char rwidth, unsigned char gwidth,
        unsigned char bwidth) {
    int dutyCycleRed = (PR2*rwidth)/100; // PWM duty cycle red led
    int dutyCycleGreen = (PR2*gwidth)/100; // PWM duty cycle green led
    int dutyCycleBlue = (PR2*bwidth)/100; // PWM duty cycle blue led
    
    OC3RS = dutyCycleRed; // Set PWM duty cycle for red led;
    OC4RS = dutyCycleGreen; // Set PWM duty cycle for blue led;
    OC5RS = dutyCycleBlue; // Set PWM duty cycle for green led;
}