///*
// * File            : newmain.c
// */
//
//#include <xc.h>
//#include <pic16f15244.h>
//#include "spi.h"
//#include "config.h"
//#include "main.h"
//#include "init.h"
//#include "interruptService.h"
//
//#define _XTAL_FREQ 8000000
//
//void __interrupt() service() {
//    interruptService();
//}
//
//void main() {
//    TRISC2=1;
//    TRISA2=0;
//    setIo();
//    setInterrupts();
//       spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);//master
//    //spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE); //slave
//
////    spiWrite(0b01010101);
//    while (1) {
//        if (FLAGS.ByteBits.DISPLAY_READING) {
////            PORTD = readValue;
//            FLAGS.ByteBits.DISPLAY_READING = 0;
////                        readValue = ~readValue;
//                        spiWrite(0b00001111);
//        }
//        if (RC2==0){
//            spiWrite(0b0011001100);
//            RA2=~RA2;
//        }
//        __delay_ms(1000);
//    }
//}