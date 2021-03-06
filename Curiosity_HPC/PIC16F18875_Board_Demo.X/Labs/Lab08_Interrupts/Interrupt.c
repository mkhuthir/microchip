/**
  Interrupt Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    Interrupt.c

  Summary:
    This is the source file for the Interrupt lab

  Description:
    This source file contains the code on how the Interrupt lab works.
   
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.38
        MPLAB             :  MPLAB X v3.45
        Device            :  PIC16F18875
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

/**
  Section: Included Files
 */

#include "../../mcc_generated_files/pin_manager.h"
#include "../../mcc_generated_files/interrupt_manager.h"
#include "../../mcc_generated_files/tmr0.h"
#include "../../labHeader.h"

#define LAST    16

/**
  Section: Global Variables Definitions
*/

static uint8_t rotateReg;
static uint8_t LEDs;

/*
                             Application    
 */
void LAB_ISR(void);
void Interrupt(void) {

    if (labState != RUNNING) {
        LED_D2_LAT = ON;
        LED_D3_LAT = LED_D4_LAT = LED_D5_LAT = OFF;
        
        rotateReg = 1;
       
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();

        TMR0_SetInterruptHandler(LAB_ISR);
                
        //Enable the TMR0 Interrupts
        TMR0IE = 1;

        labState = RUNNING;
    }

    //Check if a switch event occurs
    if (switchEvent) {
        //Disable the TMR0 Interrupts
        TMR0IE = 0;

        INTERRUPT_GlobalInterruptDisable();
        INTERRUPT_PeripheralInterruptDisable();

        labState = NOT_RUNNING;
    }
}

void LAB_ISR(void) {    
    //If the last LED has been lit, restart the pattern    
    if (rotateReg == 1) {
        rotateReg = LAST;
    }

    rotateReg >>= 1;
    
    //Check which LED should be lit
    LEDs = (rotateReg << 4);
    LATA = LEDs;
}
/**
 End of File
 */
