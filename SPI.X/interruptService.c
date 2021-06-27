/*
 * File:   interruptService.c
 */


#include <xc.h>
#include "main.h"
#include "spi.h"
#include "interruptService.h"
#include "serial.h"
#include "button.h"

void processInterruptService(void) {
    if (SSPIE == 1 && SSPIF == 1) {
        SPIHandle();
        SSPIF = 0;
    }
    if (RC1IE == 1 && RC1IF == 1 && FLAGS.bits.UART_RECEIVED == 0) {
        serialHandle();
        RC1IF = 0;
    }
    if (INTEDG0 == 1 && INT0IF == 1) {
        buttonHandle();
        INT0IF = 0;
    }
}

void interruptService(void) {
    processInterruptService();
}

