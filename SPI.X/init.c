/*
 * File:   init.c
 */

#include <pic18f8722.h>
#include "init.h"

 void setIo() {
//    nRBPU = 0; //Enable PORTB internal pull up resistor
    TRISD = 0x00; //PORTD as output
    PORTD = 0x00; //All LEDs OFF
}

 void setInterrupts() {
    GIE = 1;
    PEIE = 1;
    SSPIF = 0;
    SSPIE = 1;
//    ADCON1 = 0x07;
}
