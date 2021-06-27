#include "display.h"
#include "main.h"
#include "serial.h"
#include "spi.h"

void displaySerial() {
    outValue = readSerialValue;
    displayCallback();
}

void displaySPI() {
    outValue = readSPIValue;
    displayCallback();
}

void displayRequestHandle() {
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

void displayCallback() {
    PORTD = outValue;
}

