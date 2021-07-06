#include "main.h"
#include "button.h"
#include "serial.h"
#include "spi.h"

void setButtonIo(void) {
    TRISB0 = 1; //read button
}

void initialiseButton(void) {
    FLAGS.bits.PUSHED_BUTTON = 0;
    FLAGS.bits.PUSH_REQUEST_SERVICED = 1;
}

void buttonCallback(void) {
    if (FLAGS.bits.PUSH_REQUEST_SERVICED == 0 && FLAGS.bits.PUSHED_BUTTON == 1) {
        //testSerialSend();
        testSpiSend();
    }
    FLAGS.bits.PUSHED_BUTTON = 0;
}

void buttonHandle(void) {
    if (FLAGS.bits.PUSH_REQUEST_SERVICED == 1 && FLAGS.bits.PUSHED_BUTTON == 0) {
        FLAGS.bits.PUSHED_BUTTON = 1;
    }
}

void buttonDebounce(void) {
    static int counter = 255;
    counter--;
    if (counter == 0) {
        FLAGS.bits.PUSH_REQUEST_SERVICED = 1;
        counter = 255;
    }
}
