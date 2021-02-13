/* 
 * File:   assignment1_4.h
 * Author: Boyan Nikolov @ 3 July 2017
 * Editor: Joachim Lazaroms @ 7 oct 2017
 *
 */

#ifndef ASSIGNMENT1_4_H
#define	ASSIGNMENT1_4_H

/* ------------------------------------------------------------ */
/*						Configuration Bits		                */
/* ------------------------------------------------------------ */

// Device Config Bits in  DEVCFG1:	
#pragma config FNOSC    = FRCPLL
#pragma config FSOSCEN  = OFF
#pragma config POSCMOD  = XT
#pragma config OSCIOFNC = ON
#pragma config FPBDIV   = DIV_2

// Device Config Bits in  DEVCFG2:	
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLMUL  = MUL_20
#pragma config FPLLODIV = DIV_1

#pragma config JTAGEN   = OFF     
#pragma config FWDTEN   = OFF  


/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

#define VOLUME_MIN      0
#define VOLUME_DEFAULT  7
#define VOLUME_MAX     13

#define PAN_DEFAULT     C

typedef enum e_panrange {
    L2,
    L1,
    C,
    R1,
    R2
} panrange;

/**
 * Knight Rider state
 */
typedef enum kr_states {
    init,
    on,
    off,
    swoosh,
    turbo
} krState;

/**
 * LED pattern state
 */
typedef enum led_states {
    up,
    down
} ledState;

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/**
 * Configures timer 2.
 */
void setTimer2();

/**
 * Executes knight rider pattern for the LEDs.
 */
void moveKnightRider();

/**
 * Resets display position to initial starting position after LCD_DisplayClear()
 * is called.
 */
void resetDisplayPosition();

/**
 * Checks if button L, C, R, U and D are pressed.
 */
void checkButtons();

/* Private functions */

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* ASSIGNMENT1_4_H */

