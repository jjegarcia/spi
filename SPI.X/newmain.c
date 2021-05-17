 /*
 * File            : newmain.c
 */


// CONFIG
#pragma config FOSC = XT   // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF  // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF   // Low-Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF   // Data EEPROM Memory Code Protection bit 
#pragma config WRT = OFF   // Flash Program Memory Write Enable bits 
#pragma config CP = OFF    // Flash Program Memory Code Protection bit

#include <xc.h>
#include <pic18f8722.h>
#include "spi.h"

#define _SLABE true
#define _XTAL_FREQ 8000000
#define _SPI_MODE _SLABE

#ifdef _SPI_MODE 
void interrupt SPI_Slave_Read()
{
    if(SSPIF == 1)
    {
        PORTD = spiRead();
        spiWrite(PORTB);
        SSPIF = 0;
    }
}
#endif

#ifdef _SPI_MODE
void main()
{
    nRBPU = 0;                    //Enable PORTB internal pull up resistor
   TRISB = 0xFF;                 //PORTB as input
   TRISD = 0x00;                 //PORTD as output
   PORTD = 0x00;                 //All LEDs OFF
   
   GIE = 1;
   PEIE = 1;
   SSPIF = 0;
   SSPIE = 1;
   ADCON1 = 0x07;
   TRISA5 = 1; 

   spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
   while(1)
   {
       /*if(spiDataReady())
       {
           PORTD = spiRead();
           spiWrite(PORTB);
       }
       */
       __delay_ms(5);
   }
}
#else

void main()
{
   nRBPU = 0;                    //Enable PORTB internal pull up resistor
   TRISB = 0xFF;                 //PORTB as input
   TRISD = 0x00;                 //PORTD as output
   PORTD = 0x00;                 //All LEDs OFF
   TRISC7 = 0;
   RC7 = 1;
   
   spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
   
   while(1)
   {
       RC7 = 0;       //Slave Select
       __delay_ms(1);
       
       spiWrite(PORTB);
       PORTD = spiRead();
       
       __delay_ms(1);
       RC7 = 1;       //Slave Deselect 
       
       __delay_ms(100);
   }
}

#endif