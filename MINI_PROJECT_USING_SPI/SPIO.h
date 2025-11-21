#define CS (1<<7)

void SPI0_Init(void) {

    PINSEL0 |= 0x00001500;        

    IODIR0 |= CS;                 

    S0SPCCR = 150;                  

    S0SPCR = (1<<5|3<<3);                

}



unsigned char SPI0(unsigned char data) {

    S0SPDR = data;

    while((S0SPSR & 1<<7)==0);

	return S0SPDR;      

}
