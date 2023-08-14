/**
 * Joel Brigida
 * CDA4102 Q6Q: Ports Operation in C.
 * Prof. Bassem Alhalabi
 * 
 * This code is meant to run on an MSP430. It has 3 modes:
 * Mode 0: Blinks Green onboard LED
 * Mode 1: Blinks Red onboard LED
 * Mode 2: Blinks Both LEDs Simultaneously
 * Note that if the switch is held down, the program will stay in the while loop
 * in the 'else' statement until the switch is released, so as not to keep incrementing
 * the counter variable continuously.
*/

#include <msp430.h>
#include "msp430g2553.h"

int sw2 = 0;                                        // Stores values for Port 1.
int counter = 0;                                    // Counter for Blink Mode.

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;                       // stop watchdog timer
    P1DIR  = 0x00;                                  // port 1 all inputs
    P1DIR |= (BIT0 | BIT6);                         // set P1.0 and P1.6 as outputs (LED1, LED2)
    P1REN |= BIT3;                                  // Activate resister on P1.3 (Push Button Switch)
    P1OUT |= BIT3;                                  // Pull Up Resistors: SW2 is active low

    for (;;)
    {
        sw2 = P1IN;                                 // read values from P1
        sw2 &= BIT3;                                // mask out only BIT3 where SW2 is connected
        if (sw2 == BIT3)                            // Switch open, value high
        {   
            switch(counter)
            {
                case 0:
                {
                    P1OUT ^= BIT0;                  // toggle LED1 (GREEN)
                    P1OUT &= ~BIT6;                 // turn LED2 (RED) off
                    __delay_cycles(50000);          // delay 50,000 micro seconds
                    break;
                }
                case 1:
                {
                    P1OUT &= ~BIT0;                 // turn LED1 (GREEN) off
                    P1OUT ^= BIT6;                  // toggle LED2 (RED)
                    __delay_cycles(50000);          // delay 50,000 micro seconds
                    break;
                }
                case 2:
                {
                    P1OUT |= BIT6;                  // switch RED LED ON
                    P1OUT |= BIT0;                  // switch GREEN LED ON
                    __delay_cycles(50000);          // wait 100,000 microsec
                    P1OUT &= ~BIT0;                 // switch GREEN LED OFF
                    P1OUT &= ~BIT6;                 // switch RED LED OFF
                    break;
                }
                default:                            // In case of ERROR
                {
                    P1OUT &= ~BIT0;                 // turn LED1 (GREEN) off
                    P1OUT &= ~BIT0;                 // turn LED1 (GREEN) off
                    break;
                }
            }
        }
        else                                        // Switch closed, value low
        {
            counter++;                              // increment the counter
            if (counter >= 3)                       // if counter reaches undefined value
            {
                counter = 0;                        // reset the counter to 1
            }
            while ((sw2 & BIT3) == 0)               // While switch is held down: Keep the counter from incrementing
            {
                sw2 = P1IN;                         // read the switch status for a change
                sw2 &= BIT3;                        // mask the switch variable
            }                                       // if the switch is let go, the loop condition becomes false
        }
    }   // end of for() loop
}   // end main()