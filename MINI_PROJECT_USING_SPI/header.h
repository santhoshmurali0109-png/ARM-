#include <lpc21xx.h>

#include <string.h>

#include <stdio.h>

#include "UART.h"

#include "SPIO.h"

#include "temp_cal.h"

#include "gsm.h"

#include "LCD4BIT.h"


//#define BUZZER (1<<10)

#define LED    (1<<12)

#define CS     (1<<7)


#define TEMP 30
