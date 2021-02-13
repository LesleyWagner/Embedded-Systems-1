/* 
 * File:   assignment1_4.h
 * Author: Boyan Nikolov @ 3 July 2017
 * Editor: Joachim Lazaroms @ 7 oct 2017
 *
 */

/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>

/* Your own custom made libraries */
#include <assignment1_5.h>
#include <button_utils.h>

/* Local variables */
char my_age          = 20;
char lcd_message[16];

/**
 * State of the program (Knight Rider).
 * Determines LCD screen and LED states.
 */
krState kr_state = init; 

/**
 * State of Knight Rider LED pattern. 
 */
ledState led_state = up;

/**
 * Sequence of button pressed. Keeps track of the last 3 button presses.
 * The least significant byte is not used, stays at 0x00.
 */
int btnSequence = 0xFFFFFF00;

int main() { 
    buttons_init();
    LCD_Init();
    setTimer2();
    TRISA = 0xFF00; // led pins are configured as outputs
    
    // Initial program state 
    LATA = 0x00;   
    LCD_WriteStringAtPos("Embedded Systems", 0, 0);
    LCD_WriteStringAtPos("KITT activated", 1, 0);
    
    while(1) {
        checkButtons();
        switch (kr_state) {
            case init:   
                // go to on state (btnSequence == "RRR")
                if (btnSequence == 0x02020200) {  
                    btnSequence = 0xFFFFFF00;
                    kr_state = on;
                    LATA = 0xF; // first 4 leds turned on
                    LCD_DisplayClear();
                    resetDisplayPosition();
                    LCD_WriteStringAtPos("Yes Michael", 0, 0);                   
                }
                break;
            case off: 
                // go to on state (btnSequence == "RRR")
                if (btnSequence == 0x02020200) {
                    btnSequence = 0xFFFFFF00;
                    kr_state = on;
                    LATA = 0xF; // first 4 leds turned on
                    LCD_DisplayClear();
                    resetDisplayPosition();
                    LCD_WriteStringAtPos("Yes Michael", 0, 0);  
                }
                break;
            case on: 
                // go to off state (btnSequence == "RRR")
                if (btnSequence == 0x02020200) {     
                    btnSequence = 0xFFFFFF00;
                    kr_state = off;
                    LATA = 0x0; // first 4 leds turned off
                    LCD_DisplayClear();
                    resetDisplayPosition();
                    LCD_WriteStringAtPos("Bye Michael", 0, 0);
                }
                // go to swoosh state (btnSequence == "DRD")
                else if (btnSequence == 0x04020400) {
                    btnSequence = 0xFFFFFF00;
                    kr_state = swoosh;                   
                    TMR2 = 0;
                    T2CONbits.ON = 1;
                    LATA = 1;
                    led_state = up;
                    LCD_DisplayClear();
                    resetDisplayPosition();
                    LCD_WriteStringAtPos("SWOOSH SWOOSH", 0, 0);
                }
                // go to turbo state (btnSequence == "DDR")
                else if (btnSequence == 0x04040200) {
                    btnSequence = 0xFFFFFF00;
                    kr_state = turbo;                   
                    TMR2 = 0;
                    T2CONbits.ON = 1;
                    LATA = 1;
                    led_state = up;
                    LCD_DisplayClear();
                    resetDisplayPosition();
                    LCD_WriteStringAtPos("TURBO BOOST", 0, 0);
                }
                break;          
            case swoosh: 
                // if 350 ms have passed, move forward in knight rider pattern
                if (TMR2 > 54688) {
                    TMR2 = 0;
                    moveKnightRider();
                }
                // go to off state (btnSequence == "RRR")
                if (btnSequence == 0x02020200) {      
                    btnSequence = 0xFFFFFF00;
                    kr_state = off;
                    LATA = 0x0; // first 4 leds turned off
                    T2CONbits.ON = 0;
                    TMR2 = 0;
                    LCD_DisplayClear();
                    resetDisplayPosition();
                    LCD_WriteStringAtPos("Bye Michael", 0, 0);
                }
                // go to turbo state (btnSequence == "DDR")
                else if (btnSequence == 0x04040200) {
                    btnSequence = 0xFFFFFF00;
                    kr_state = turbo;
                    LCD_DisplayClear();
                    resetDisplayPosition();
                    LCD_WriteStringAtPos("TURBO BOOST", 0, 0);
                }
                break;
            case turbo: 
                // if 175 ms have passed, move forward in knight rider pattern
                if (TMR2 > 27344) {
                    TMR2 = 0;
                    moveKnightRider();
                }
                if (btnSequence == 0x02020200) {
                    btnSequence = 0xFFFFFF00;
                    kr_state = off;
                    LATA = 0x0; // first 4 leds turned off
                    T2CONbits.ON = 0;
                    TMR2 = 0;
                    LCD_DisplayClear();
                    resetDisplayPosition();
                    LCD_WriteStringAtPos("Bye Michael", 0, 0);
                }
                // go to swoosh state (btnSequence == "DRD")
                else if (btnSequence == 0x04020400) {
                    btnSequence = 0xFFFFFF00;
                    kr_state = swoosh;
                    LCD_DisplayClear();
                    resetDisplayPosition();
                    LCD_WriteStringAtPos("SWOOSH SWOOSH", 0, 0);
                }
                break;
        }
    }   
    return (0);
}

/**
 * Configures timer 2.
 */
void setTimer2() {
    T2CONbits.ON = 0;
    TMR2 = 0;
    T2CONbits.TCS = 0; // clock source is internal
    T2CONbits.T32 = 0; // 16 bit mode is used
    T2CONbits.TCKPS = 0b111; // 256 clock divider, 156250 Hz frequency    
}

/**
 * Executes knight rider pattern for the LEDs.
 */
void moveKnightRider() {
    switch (led_state) {
        case up:
            LATA <<= 1;
            if (LATA == 8) { 
                led_state = down;
            }
            break;
        case down: 
            LATA >>= 1;
            if (LATA == 1) {
                led_state = up;
            }
            break;
    }
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

/**
 * Checks if button L, C, R, U and D are pressed and adds button presses to btnSequence.
 */
void checkButtons() {
    int i;
    for (i = 0; i < 5; i++) {
        if (btn_pressed(i)) {
            btnSequence <<= 8;
            btnSequence += (i << 8);
        }
    }
}
