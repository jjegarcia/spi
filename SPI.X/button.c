#include "main.h"
#include "button.h"

void setButtonIo(void) {
    TRISB0 = 1; //read button
}

void initialiseButton(void) {
    FLAGS.bits.PUSHED_BUTTON = 0;
    FLAGS.bits.SERVICED = 1;
}

void buttonCallback(void) {
    if (FLAGS.bits.SERVICED == 0 && FLAGS.bits.PUSHED_BUTTON == 1) {
        TXREG1 = 'a';
    }
    FLAGS.bits.PUSHED_BUTTON = 0;
}

void buttonHandle(void) {
    if (FLAGS.bits.SERVICED == 1 && FLAGS.bits.PUSHED_BUTTON == 0) {
        FLAGS.bits.PUSHED_BUTTON = 1;
    }
}

void buttonDebounce(void) {
    static int counter = 255;
    counter--;
    if (counter == 0) {
        FLAGS.bits.SERVICED = 1;
        counter = 255;
    }
}
