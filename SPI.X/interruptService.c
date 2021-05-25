/*
 * File:   interruptService.c
 */


#include <xc.h>
#include "main.h"
#include "spi.h"
#include "interruptService.h"

void interruptService() {
    spiService();
}

static void spiService() {
    if (SSPIF == 1) {
        SSPIF = 0;
//        PORTD= spiRead();
        char test=spiRead();
        PORTD=test;
//        readValue = spiRead();
//        FLAGS.ByteBits.DISPLAY_READING = 1;
    }
}