/*
 * File            : spi.c
 */

#include "spi.h"
#include <pic16f15244.h>

void spiInit(Spi_Type sType, Spi_Data_Sample sDataSample, Spi_Clock_Idle sClockIdle, Spi_Transmit_Edge sTransmitEdge) {
    TRISC5 = 1;//SDI  
    TRISC4 = 0;//SDO
    if (sType & 0b00000100) //If Slave Mode
    {
        SSP1STAT = sTransmitEdge;
        TRISC3 = 1; //clock as input
        TRISC7 = 0; //CE For This IC as output
        RC0 = 1;
    } else //If Master Mode
    {
        SSP1STAT = sDataSample | sTransmitEdge;
        TRISC3 = 0; //clock as output
        TRISC7 = 1; //CE For This IC as input
    }
    SSP1CON1 = 0b00100101;//sType | sClockIdle;
}

static void spiReceiveWait() {
    while (!SSP1STATbits.BF); // Wait for Data Transmit/Receipt complete
}

void spiWrite(char dat) //Write data to SPI bus
{
    SSP1BUF = dat;
}

unsigned spiDataReady() //Check whether the data is ready to read
{
    if (SSP1STATbits.BF)
        return 1;
    else
        return 0;
}

char spiRead() //REad the received data
{
    spiReceiveWait(); // wait until the all bits receive
    return (SSP1BUF); // read the received data from the buffer
}
