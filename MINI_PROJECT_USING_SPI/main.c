#include "header.h"
#define BUZZ 1<<3 
int main() {

    float adc_value;
    char msg[50];

    LCD_INIT();   
    SPI0_Init();

    IODIR0 |= BUZZ | LED;
    IOSET0 |= BUZZ | LED;

    UART0_CONFIG();
    UART0_STRING("System Ready\r\n");

    LCD_STRING("System Ready");	

    while(1) {

        LCD_CMD(0x01);
        LCD_CMD(0x80);
        LCD_STRING("TEMPERATURE");

        adc_value = Read_ADC_MCP3204(0);

        LCD_CMD(0xC0);
        LCD_FLOAT(adc_value);

        LCD_CMD(0xC6);
        LCD_DATA('C');		

        if (adc_value > TEMP) {

            sprintf(msg, "FIRE ALERT! Temp: %.2f C\r\n", adc_value);
            GSM_SendSMS("+916374070576", msg);

            IOCLR0 |= BUZZ | LED;
            //IOSET0=BUZZ;
            delay_ms(2000);
            IOSET0=BUZZ;

            LCD_CMD(0xC0);
            LCD_STRING("      ");

        } else {

            delay_ms(2000);
            IOSET0 |= BUZZ | LED;

            LCD_CMD(0xC0);
            LCD_STRING("      ");
        }
    }
}
 