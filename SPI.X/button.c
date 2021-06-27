#include "main.h"
#include "button.h"

void buttonCallback(void) {
    if (FLAGS.bits.PREVIOUS_BUTTON_STATE != FLAGS.bits.PUSHED_BUTTON) {
        FLAGS.bits.PREVIOUS_BUTTON_STATE = FLAGS.bits.PUSHED_BUTTON;
        TXREG1 = 'a';
    }
}

void buttonHandle(void) {
    FLAGS.bits.PUSHED_BUTTON = 1;
}