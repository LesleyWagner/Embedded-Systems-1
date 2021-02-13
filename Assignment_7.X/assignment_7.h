/* ************************************************************************** */
/** Descriptive File Name

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _ASSIGNMENT_7_H    /* Guard against multiple inclusion */
#define _ASSIGNMENT_7_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

#define samplingRate 10 // sampling rate is 100 Hz for the voltage measurement.


    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************




    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /* ================================================================= */

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
void timer3_init();

/* function: pot_init */
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
void pot_init ();
    
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
void adc_init (unsigned short int channels);

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
unsigned short int adc_getresult(unsigned char channel);

/**
 * Resets display position to initial starting position after LCD_DisplayClear()
 * is called.
 */
void resetDisplayPosition();

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
