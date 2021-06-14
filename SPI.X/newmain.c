/*
 * File            : newmain.c
 */

#include <xc.h>
#include <pic18f8722.h>
#include "spi.h"
#include "config.h"
#include "main.h"
#include "interruptService.h"
#include "init.h"

#define _XTAL_FREQ 8000000

void __interrupt() service() {
    interruptService();
}

void main() {
    setIo();
    setSPI();
    setSerial();
    setInterrupts();
    //    spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);//master
//    spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE); //slave

//    spiWrite(0b01010101);
    
    TXREG= 0b11001100;
    while (1) {
        if (FLAGS.bits.DISPLAY_READING) {
            //           PORTD = readSPIValue;
            FLAGS.bits.DISPLAY_READING = 0;
            //                        readValue = ~readValue;
            spiWrite(0b00001111);
        }
        if (FLAGS.bits.UART_RECEIVED) {
            readSerialValue = RCREG;
            PORTD = readSerialValue;
            TXREG = readSerialValue;
        }

        //        __delay_ms(1000);
    }
}

