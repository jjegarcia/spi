
#include "serial.h"

void serialCallback(void) {
    readSerialValue = RCREG;
    PORTD = readSerialValue;
    TXREG = readSerialValue;
}
