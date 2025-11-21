#include<LPC21xx.h>
#include "headerr.h"
void ext_int0_isr(void) __irq;
//unsigned int val;
unsigned int count;
unsigned char a;
void ext_int0_isr(void) __irq
{
EXTINT=0x01;
T0PR=6-1;
T0TCR=0x01;
a=T0PC;
if(a==0)
{
a=6;
}
VICVectAddr=0;
}

int main()
{
PINSEL1=0x1;
LCD_INIT();
VICIntSelect=0;
VICVectCntl0=(0x20)|14;
VICVectAddr0=(unsigned int)ext_int0_isr;
EXTMODE=0x01;
EXTPOLAR=0x00;
VICIntEnable=1<<14;

while(1)
{
LCD_CMD(0x80);
LCD_STRING("DICE VALUE");

LCD_CMD(0x8A);
LCD_DATA(':');

LCD_CMD(0xC0);
LCD_STRING("ROLL COUNT");

LCD_CMD(0xCA);
LCD_DATA(':');


LCD_CMD(0x8B);
LCD_INTEGER(a);

LCD_CMD(0xCB);
LCD_INTEGER(count);

if((IOPIN0&1<<16)==0)
{
delays(250);
count++;
}
}
}


