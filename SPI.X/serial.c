
#include "main.h"
#include "serial.h"

void serialCallback(void) {
    
}

void serialHandle() {
    FLAGS.bits.UART_RECEIVED = 1;
    readSerialValue = RCREG;
}
