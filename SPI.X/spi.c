/*
 * File            : spi.c
 */

#include "spi.h"
#include "main.h"
#include <pic18f8722.h>

void setSPIInterrupt(void) {
    SSP1IF = 0;
    SSP1IE = 1;
}

void spiInit(Spi_Type sType, Spi_Data_Sample sDataSample, Spi_Clock_Idle sClockIdle, Spi_Transmit_Edge sTransmitEdge) {
    TRISC5 = 0; //SDO  
    TRISC4 = 1; //SDI


    if (sType & 0b00000100) //If Slave Mode
    {
        SSP1STAT = sTransmitEdge;
        TRISC3 = 1; //clock as input
        LATC0 = 1;
    } else //If Master Mode
    {
        SSP1STAT = sDataSample | sTransmitEdge;
        TRISC3 = 0; //clock as output
        TRISC2 = 0; //CE For This IC as output
    }
    SSP1CON1 = sType | sClockIdle;

    CKE1 = 0;
    CKP1 = 0;
}

static void spiReceiveWait() {
    while (!SSP1STATbits.BF); // Wait for Data Transmit/Receipt complete
}

void spiWrite(char dat) //Write data to SPI bus
{
    SSP1BUF = dat;
}

unsigned spiDataReady(void) //Check whether the data is ready to read
{
    if (SSP1STATbits.BF)
        return 1;
    else
        return 0;
}

char spiRead(void) //REad the received data
{
    spiReceiveWait(); // wait until the all bits receive
    return (SSP1BUF); // read the received data from the buffer
}

void SPIHandle(void) {
    readSPIValue = spiRead();
    FLAGS.bits.SPI_READ_REQUEST = 1;
    FLAGS.bits.DISPLAY_SPI_READING = 1;
}

void SPICallback(void) {
    spiWrite(readSPIValue); //acknowledge read value
    FLAGS.bits.DISPLAY_READING = 1;
}

void testSpiSend(void) {
    spiWrite(0x88);
}