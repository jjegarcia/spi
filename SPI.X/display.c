#include "display.h"
#include "main.h"
#include "serial.h"
#include "spi.h"

void setupDisplayIo(void) {
    TRISD = 0x00; //PORTD as output
    PORTD = 0x00; //All LEDs OFF
}

void displaySerial(void) {
    ledValue = readSerialValue;
    displayCallback();
}

void displaySPI(void) {
    ledValue = readSPIValue;
    displayCallback();
}

void displayRequestHandle(void) {
    if (FLAGS.bits.DISPLAY_SERIAL_READING) {
        displaySerial();
        FLAGS.bits.DISPLAY_SERIAL_READING = 0;
    } else {
        if (FLAGS.bits.DISPLAY_SPI_READING) {
            displaySPI();
            FLAGS.bits.DISPLAY_SPI_READING = 0;
        }
    }
}

void displayCallback(void) {
    PORTD = ledValue;
}

