// rgbled.c
#include "rgbled.h"
#include <msp430.h>

void rgbLEDInit() {
    // Initialize timers and pins for RGB LED PWM
    P6DIR |= BIT0 | BIT1 | BIT2; // Set P6.0, P6.1, P6.2 as output pins

    // Configure Timer_A for PWM generation
    TA0CTL = TASSEL_2 | MC_1 | ID_0; // SMCLK, Up mode, no prescaler

    TA0CCTL1 = OUTMOD_7; // Reset/Set output mode for CCR1
    TA0CCTL2 = OUTMOD_7; // Reset/Set output mode for CCR2
    TA0CCTL3 = OUTMOD_7; // Reset/Set output mode for CCR3

    TA0CCR0 = 255; // PWM Period
}

void setRGBLED(int red, int green, int blue) {
    // Set brightness of RGB LED
    // Map 0-255 input values to PWM duty cycles

    // Ensure values are within range
    red = (red < 0) ? 0 : (red > 255) ? 255 : red;
    green = (green < 0) ? 0 : (green > 255) ? 255 : green;
    blue = (blue < 0) ? 0 : (blue > 255) ? 255 : blue;

    TA0CCR1 = red;   // Set PWM duty cycle for red LED (P6.0)
    TA0CCR2 = green; // Set PWM duty cycle for green LED (P6.1)
    TA0CCR3 = blue;  // Set PWM duty cycle for blue LED (P6.2)
}
