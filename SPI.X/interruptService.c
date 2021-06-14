/*
 * File:   interruptService.c
 */


#include <xc.h>
#include "main.h"
#include "spi.h"
#include "interruptService.h"

void processInterruptService(void) {
    if (SSPIE == 1 && SSPIF == 1) {
        SSPIF = 0;
        readSPIValue = spiRead();
    }
    if (RC1IE == 1 && RC1IF == 1) {
        RC1IF = 0;
//        if (RCSTA1 == 0) {
            FLAGS.bits.UART_RECEIVED = 1;
            readSerialValue = RCREG;
//        }
    }
}

void interruptService(void) {
    processInterruptService();
}

