/*
 * File:   init.c
 */

#include <pic18f8722.h>
#include "init.h"

void setSerial(void) {
    TXEN1 = 1;
    BRGH1 = 0;

    SPEN1 = 1;
    CREN1 = 1;

    WUE1 = 0;
    SPBRG = 0b01000000; //64d for 9600 bauds
    
    RC1IF = 0;
    RC1IE = 1;
    
//    TX1IE=1;
    

}

void setIo() {
    //    nRBPU = 0; //Enable PORTB internal pull up resistor
    TRISD = 0x00; //PORTD as output
    PORTD = 0x00; //All LEDs OFF
    TRISC7 = 1; //serial Port RC
    TRISC6 = 0; //serial Port TX
    TRISB0=1; //read switch
}

void setSPI(void) {
    SSPIF = 0;
    SSPIE = 1;
}

void setInterrupts(void) {
    GIE = 1;
    PEIE = 1;
    //    ADCON1 = 0x07;
}

void setSwitchInterrput(void){
    INTEDG0=1;   
}
