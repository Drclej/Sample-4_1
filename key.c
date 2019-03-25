#include <msp430f249.h>
#include "key.h"
#define uchar unsigned char
#define uint unsigned int

extern uchar key;

void delayus(uchar t)
{
  while (t--);
}

void getkey(void)
{
  if ((P3IN & 0x07) == 0x06)
  {
    delayus(100);
    if ((P3IN & 0x07) == 0x06)
    {
      key = 1;
    }
  }
  else if ((P3IN & 0x07) == 0x05)
  {
    delayus(100);
    if ((P3IN & 0x07) == 0x05)
    {
      key = 2;
    }
  }
  else if ((P3IN & 0x07) == 0x03)
  {
    delayus(100);
    if ((P3IN & 0x07) == 0x03)
    {
      key = 3;
    }
  }
  else key = 0;
}

void processkey(void)
{
  if (key == 0) P1OUT = 0x3F;
  if (key == 1) P1OUT = 0x06;
  if (key == 2) P1OUT = 0x5B;
  if (key == 3) P1OUT = 0x4F;
}