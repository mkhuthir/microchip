// IS31FL3731 Library
// Muthanna A. Attyah (May 2017)
// Please feel free to copy and use code.
// Device datasheet https://download.mikroe.com/documents/datasheets/is31fl3731-datasheet.pdf

#include "mcc_generated_files/mcc.h"
#include "BlinkM.h"


// Main code
void main(void)
{
    // Setup and initializations
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    // LEDs initializations
    LED_D2_SetHigh();     // Not Used
    LED_D3_SetHigh();     // Not used
    LED_D4_SetHigh();     // Not used
    LED_D5_SetHigh();     // Not used
   
            
    StopScript();
    GoToRGB(0x00,0x00,0xFF);
        
    // Execution loop
    while(1){
        LED_D2_Toggle();
        __delay_ms(500);
    }
        
}
