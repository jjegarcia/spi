/*
 * File            : spi.c
 */

#include "spi.h"
#include <pic18f8722.h>

void spiInit(Spi_Type sType, Spi_Data_Sample sDataSample, Spi_Clock_Idle sClockIdle, Spi_Transmit_Edge sTransmitEdge) {
    TRISC5 = 0;//SDO  
    TRISC4 = 1;//SDI
    if (sType & 0b00000100) //If Slave Mode
    {
        SSPSTAT = sTransmitEdge;
        TRISC3 = 1; //clock as input
        TRISC2 = 0; //CE For This IC as output
        RC0 = 1;
    } else //If Master Mode
    {
        SSPSTAT = sDataSample | sTransmitEdge;
        TRISC3 = 0; //clock as output
        TRISC2 = 1; //CE For This IC as input
    }
    SSP1CON1 = 0b00100101;//sType | sClockIdle;
}

static void spiReceiveWait() {
    while (!SSPSTATbits.BF); // Wait for Data Transmit/Receipt complete
}

void spiWrite(char dat) //Write data to SPI bus
{
    SSPBUF = dat;
}

unsigned spiDataReady() //Check whether the data is ready to read
{
    if (SSPSTATbits.BF)
        return 1;
    else
        return 0;
}

char spiRead() //REad the received data
{
    spiReceiveWait(); // wait until the all bits receive
    return (SSPBUF); // read the received data from the buffer
}
