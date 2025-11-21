#include<LPC21xx.h>
#include "delays.h"
#define LCD_D 0xFF
#define Rs 1<<8
#define E 1<<9

void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STRING(unsigned char *);
void LCD_INTEGER(int);

void LCD_INIT(void)
{
IODIR0=LCD_D|Rs|E;
LCD_CMD(0x01);
LCD_CMD(0x02);
LCD_CMD(0x0c);
LCD_CMD(0x38);
LCD_CMD(0x80);
}

void LCD_CMD(unsigned char m)
{
IOCLR0=LCD_D;
IOSET0=m;
IOCLR0=Rs;
IOSET0=E;
delays(2);
IOCLR0=E;
}

void LCD_DATA(unsigned char d)
{
IOCLR0=LCD_D;
IOSET0=d;
IOSET0=Rs;
IOSET0=E;
delays(2);
IOCLR0=E;
}

void LCD_STRING(unsigned char *s)
{
while(*s)
{
LCD_DATA(*s++);
}
}

void LCD_INTEGER(int n)
{
unsigned char arr[100];
signed int i=0;
if(n==0)
{
LCD_DATA('0');
}
else
{
if(n<0)
{
LCD_DATA('-');
n=-n;
}
}
while(n>0)
{
arr[i++]=n%10;
n/=10;
}
for(i=i-1;i>=0;i--)
{
LCD_DATA(arr[i]+48);
}
}