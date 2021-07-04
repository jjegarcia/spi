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
#include "serial.h"
#include "button.h"
#include "display.h"

#define _XTAL_FREQ 8000000

void __interrupt() service() {
    interruptService();
}

void main() {
    setIo();
    setSPIInterrupt();
    setSerialIo(); 
    setSerial();
    setupDisplayIo();
    setSwitchInterrput();
    setInterrupts();
    //    spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);//master
    //    spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE); //slave
    //    spiWrite(0b01010101);
    const unsigned char test[80] = "sssdddd"; //{'a','p'};

    while (1) {
        if (FLAGS.bits.DISPLAY_READING) {
            displayRequestHandle();
            FLAGS.bits.DISPLAY_READING = 0;
        }
        if (FLAGS.bits.UART_RECEIVED) {
            serialCallback();
            FLAGS.bits.UART_RECEIVED = 0;
        }
        if (FLAGS.bits.PUSHED_BUTTON) {
            buttonCallback();
            FLAGS.bits.PUSHED_BUTTON = 0;
        }
    }
}

