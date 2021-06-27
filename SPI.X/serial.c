
#include "main.h"
#include "serial.h"

void setSerial(void) {
    TXEN1 = 1;
    BRGH1 = 0;

    SPEN1 = 1;
    CREN1 = 1;

    WUE1 = 0;
    SPBRG = 0b01000000; //64d for 9600 bauds

    RC1IF = 0;
    RC1IE = 1;
    
    RCREG1=0;
    TXREG1=0;

    //    TX1IE=1;
}


void serialCallback(void) {
    FLAGS.bits.DISPLAY_READING=1;
    FLAGS.bits.DISPLAY_SERIAL_READING=1;
    transmittRead();
}

void serialHandle() {
    FLAGS.bits.UART_RECEIVED = 1;
    readSerialValue = RCREG;
}
void transmittRead(void){
    TXREG=readSerialValue;
}