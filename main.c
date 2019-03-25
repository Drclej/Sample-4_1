#include <msp430f249.h>
#include "key.h"
#define uchar unsigned char
#define uint unsigned int

uchar key = 0;

void initialize()
{
  P1SEL = 0x00;
  P1DIR = 0xFF;
  P1OUT = 0x00;
  
  P3DIR = 0x00;
}



void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  initialize();
  while(1)
  {
    getkey();
    processkey();
    
  }
}
