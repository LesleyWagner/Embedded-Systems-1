/* ************************************************************************** */
/** Descriptive File Name

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _MAIN_H    /* Guard against multiple inclusion */
#define _MAIN_H


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

#define patternLength 7 // leds repeat pattern of length 7
#define pwmFrequency 200 // frequency of the PWM signals in Hz


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
void rgbled_init (unsigned int freq, unsigned char width);

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
        unsigned char bwidth);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
