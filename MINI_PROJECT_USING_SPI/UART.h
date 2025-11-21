void UART0_CONFIG(void){

PINSEL0|=0x00000005;

U0LCR=0x83;

U0DLL=97;

U0DLM=0;

U0LCR=0x03;                

}



void UART0_TX(unsigned char txByte){

while(((U0LSR>>5)&1)==0);

U0THR=txByte;

}


void UART0_STRING(char *str) {

    while(*str)

        UART0_TX(*str++);

}
