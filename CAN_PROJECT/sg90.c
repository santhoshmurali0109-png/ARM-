#include<LPC21xx.h>
#define SW1 1<<11
#define SW2 1<<12
void PWM_INIT(void);
void servo_write(int );
void delay(unsigned int );

///////////main code////////////////////////
int main()
{
	PWM_INIT();
	servo_write(0);
	delay(2000);
while(1)
{
	if((IOPIN0&SW1)==0)
	{
		servo_write(0);
		delay(1000);
		servo_write(90);
		delay(1000);
		servo_write(180);
		delay(1000);
	}
	else if((IOPIN0&SW2)==0)
	{
		delay(500);
		servo_write(0);
		delay(1000);
	
	}
}
}
////////initilization code of servo and pwm////////////////
void PWM_INIT(void)
{
	PINSEL0|=0x00000008;
	PWMTCR=1<<1;
	PWMPR=15-1;
	PWMMR0=20000;
	PWMMR3=1000;
	PWMMCR=1<<1;
	PWMLER=(1<<1)|(1<<3);
	PWMPCR=0x800;
	PWMTCR=(1<<1)|(1<<3);
}
void servo_write(int angle)
{
	int val=1000+(angle*1000)/180;
	PWMMR3=val;
	PWMTCR=(1<<1)|(1<<3);
}

void delay(unsigned int ms)
{
	T0PR=15000-1;
	T0TCR=0x01;
	while(T0TC<ms);
	T0TCR=0x03;
	T0TCR-0x00;
}
