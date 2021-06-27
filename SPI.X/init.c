/*
 * File:   init.c
 */

#include <pic18f8722.h>
#include "init.h"


void setIo() {
    //    nRBPU = 0; //Enable PORTB internal pull up resistor
    TRISD = 0x00; //PORTD as output
    PORTD = 0x00; //All LEDs OFF
    TRISC7 = 1; //serial Port RC
    TRISC6 = 0; //serial Port TX
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
