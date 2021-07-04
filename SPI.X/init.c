/*
 * File:   init.c
 */

#include <pic18f8722.h>
#include "init.h"


void setIo() {
    //    nRBPU = 0; //Enable PORTB internal pull up resistor
    TRISB0 = 1; //read switch
}

void setInterrupts(void) {
    GIE = 1;
    PEIE = 1;
    //    ADCON1 = 0x07;
}

void setSwitchInterrput(void) {
    INTEDG0 = 1;
    INT0IE = 1;
}
