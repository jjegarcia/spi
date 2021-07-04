
#include "main.h"
#include "serial.h"

void setSerial(void) {
    BRGH1 = 0;
    SPBRG = 15; //for 9600 bauds
    SYNC1 = 0;
    SPEN1 = 1;
    RC1IE = 1;
    CREN1 = 1;
    RC1IF = 0;
    TXEN1 = 1;
    RCREG1 = 0;
}

void setSerialIo(void) {
    TRISC7 = 1; //serial Port RC
    TRISC6 = 0; //serial Port TX
}

void serialCallback(void) {
    FLAGS.bits.DISPLAY_READING = 1;
    FLAGS.bits.DISPLAY_SERIAL_READING = 1;
    //    transmittRead();
}

void serialHandle() {
    FLAGS.bits.UART_RECEIVED = 1;
    readSerialValue = readSerial();
}

void transmittRead(void) {
    writeSerial(readSerialValue);
}

void writeSerial(unsigned char value) {
    TXREG1 = value;
}

unsigned char readSerial() {
    return RCREG1;
}
