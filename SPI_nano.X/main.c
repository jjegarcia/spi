/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F15244
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"
#include "spi.h"
#include "config.h"
#include "main.h"
#include "init.h"
#include "interruptService.h"

void __interrupt() servive(void) {
    interruptService();
}

void main() {
    SYSTEM_Initialize();
//    TRISCbits.TRISC2 = 1;
    TRISAbits.TRISA2 = 0;
    LATAbits.LATA2 = 1;
//    setIo();
//    setInterrupts();
//    spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE); //master
    //spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE); //slave

    //    spiWrite(0b01010101);
    while (1) {
//        if (FLAGS.ByteBits.DISPLAY_READING) {
//            //            PORTD = readValue;
//            FLAGS.ByteBits.DISPLAY_READING = 0;
//            //                        readValue = ~readValue;
//            spiWrite(0b00001111);
//        }
//        if (LATCbits.LATC2 == 1) {
//            spiWrite(0b0011001100);
            LATAbits.LATA2 = ~LATAbits.LATA2;
//        }
        __delay_ms(3000);
    }
}
/*
                         Main application
 */
//void main(void)
//{
//    // initialize the device
//    SYSTEM_Initialize();
//
//    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
//    // Use the following macros to:
//
//    // Enable the Global Interrupts
//    //INTERRUPT_GlobalInterruptEnable();
//
//    // Enable the Peripheral Interrupts
//    //INTERRUPT_PeripheralInterruptEnable();
//
//    // Disable the Global Interrupts
//    //INTERRUPT_GlobalInterruptDisable();
//
//    // Disable the Peripheral Interrupts
//    //INTERRUPT_PeripheralInterruptDisable();
//
//    while (1)
//    {
//        // Add your application code
//    }
//}
/**
 End of File
 */