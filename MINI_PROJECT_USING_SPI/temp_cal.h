#define CS (1 << 7)

float Read_ADC_MCP3204(unsigned char channel) {

    unsigned char hByte, lByte;
    unsigned int adcVal = 0;

    IOCLR0=CS;      // Chip Select LOW

    SPI0(0x06);       // Start + Single-ended mode
    hByte=SPI0(channel<<6);
    lByte=SPI0(0x00);

    IOSET0=CS;      // Chip Select HIGH

    adcVal = ((hByte&0x0F)<<8)|lByte;   // 12-bit result

    return (((adcVal*3.3)/4096)*100);   // Convert to temperature
}
