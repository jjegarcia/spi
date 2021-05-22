/*
 * File            : newmain.c
 */

#include <xc.h>
#include <pic18f8722.h>
#include "spi.h"
#include "config.h"
#include "main.h"

#define _XTAL_FREQ 8000000
void __interrupt() SPI_Slave_Read() {
    if (SSPIF == 1) {
        //        PORTD = spiRead();
        //        spiWrite(0b11110000);
        SSPIF = 0;
        readValue = spiRead();
        FLAGS.ByteBits.DISPLAY_READING = 1;
    }
}

void main() {
    nRBPU = 0; //Enable PORTB internal pull up resistor
    TRISD = 0x00; //PORTD as output
    PORTD = 0x00; //All LEDs OFF
 
    GIE = 1;
    PEIE = 1;
    SSPIF = 0;
    SSPIE = 1;
    ADCON1 = 0x07;


    spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);

    spiWrite(0b01010101);
    while (1) {
        if (FLAGS.ByteBits.DISPLAY_READING) {
            //            readValue = spiRead();
            PORTD = readValue;
            FLAGS.ByteBits.DISPLAY_READING = 0;
            readValue = ~readValue;
                        spiWrite(readValue);
        }
                __delay_ms(1000);
    }
}
