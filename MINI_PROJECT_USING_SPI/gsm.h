#include "delay.h"

void GSM_SendSMS(char *number, char *msg) {

    UART0_STRING("AT\r\n");

    delay_ms(1000);

    UART0_STRING("AT+CMGF=1\r\n");     

    delay_ms(1000);

    UART0_STRING("AT+CMGS=\"");

    UART0_STRING(number);

    UART0_STRING("\"\r\n");

    delay_ms(1000);

    UART0_STRING(msg);

    delay_ms(1000);

    UART0_TX(0X1A);


}
