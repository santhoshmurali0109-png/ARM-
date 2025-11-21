#define LCD_D 0xf<<14

#define RS 1<<8

#define E 1<<9


void LCD_CMD(unsigned char cmd){

IOCLR0=LCD_D;

IOSET0=(cmd&0xf0)<<10;

IOCLR0=RS;

IOSET0=E;

delay_ms(2);

IOCLR0=E;


IOCLR0=LCD_D;

IOSET0=(cmd&0x0f)<<14;

IOCLR0=RS;

IOSET0=E;

delay_ms(2);

IOCLR0=E;

}

void LCD_DATA(unsigned char data){

IOCLR0=LCD_D;

IOSET0=(data&0xf0)<<10;

IOSET0=RS;

IOSET0=E;

delay_ms(2);

IOCLR0=E;


IOCLR0=LCD_D;

IOSET0=(data&0x0f)<<14;

IOSET0=RS;

IOSET0=E;

delay_ms(2);

IOCLR0=E;

}

void LCD_INIT(void){

IODIR0=LCD_D|RS|E;

LCD_CMD(0x01);

LCD_CMD(0x02);

LCD_CMD(0x0c);

LCD_CMD(0x28);

LCD_CMD(0x80);

}

void LCD_INTEGER(int n){

unsigned int arr[16];

		 int i=0;

		 if(n==0)

		 LCD_DATA('0');

		 else{

		 if(n<0){

		 LCD_DATA('-');

		 n=-n;

		 }

		 while(n>0){

		 arr[i++]=n%10;

		 n/=10;

		 }

		 }

		 for(i=i-1;i>=0;i--)

		 LCD_DATA(arr[i]+48);		 

}

void LCD_FLOAT(float f){

int n=f;

LCD_INTEGER(n);

LCD_DATA('.');

n=(f-n)*100;

LCD_INTEGER(n);		 		 

}

void LCD_STRING(unsigned char*p){

	while(*p){

		LCD_DATA(*p++);

	}

}
