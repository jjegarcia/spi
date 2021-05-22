/*
 * File            : newmain.c
 */

#include <xc.h>
#include <pic18f8722.h>
#include "spi.h"
#include "config.h"
#include "main.h"

#define _XTAL_FREQ 8000000
//#define _SPI_MODE_SLABE

//#ifdef _SPI_MODE_SLABE

void __interrupt() SPI_Slave_Read() {
    if (SSPIF == 1) {
        //        PORTD = spiRead();
        //        spiWrite(0b11110000);
        SSPIF = 0;
        readValue = spiRead();
        FLAGS.ByteBits.DISPLAY_READING = 1;
    }
}
//#endif

#ifdef _SPI_MODE_SLABE

void main() {
    FLAGS.fullByte = 0;
    readValue = 0;
    //    nRBPU = 0;                    //Enable PORTB internal pull up resistor
    //   TRISB = 0xFF;                 //PORTB as input

    TRISB0 = 1;
    TRISD = 0x00; //PORTD as output
    PORTD = 0x00;
    //    PORTD = 0xFF; //All LEDs OFF

    GIE = 1;
    PEIE = 1;
    SSPIF = 0;
    SSPIE = 1;
    ADCON1 = 0x07;
    TRISF7 = 1; //SS1 as slave reads from master



    spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);




    while (1) {
        if (!RB0) {
            spiWrite(0x80);
        }
        /*if(spiDataReady())
        {
            PORTD = spiRead();
            spiWrite(PORTB);
        }
         */
        if (FLAGS.ByteBits.DISPLAY_READING) {
            readValue = spiRead();
            PORTD = readValue;
            FLAGS.ByteBits.DISPLAY_READING = 0;
            spiWrite(readValue);
        }
        __delay_ms(500);
    }
}

#else

void main() {
    nRBPU = 0; //Enable PORTB internal pull up resistor
    //   TRISB = 0xFF;                 //PORTB as input
    TRISD = 0x00; //PORTD as output
    PORTD = 0x00; //All LEDs OFF
    //    TRISF7 = 0; //SS1 as master writes to slave
    //    RF7 = 1;

    GIE = 1;
    PEIE = 1;
    SSPIF = 0;
    SSPIE = 1;
    ADCON1 = 0x07;


    spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);

    spiWrite(0b01010101);
    while (1) {
        //        RF7 = 0; //Slave Select
        __delay_ms(1);

        //        PORTD = spiRead();


        if (FLAGS.ByteBits.DISPLAY_READING) {
            //            readValue = spiRead();
            PORTD = readValue;
            FLAGS.ByteBits.DISPLAY_READING = 0;
            readValue = ~readValue;
                        spiWrite(readValue);
        }


        __delay_ms(1);
        //        RF7 = 1; //Slave Deselect 

                __delay_ms(1000);
    }
}

#endif