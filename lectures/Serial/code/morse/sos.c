#include "gpio.h"
#include "timer.h"

int pin = 20; 

#define SECOND 1000

#define DOT         (SECOND/6)
#define DASH        (3*DOT)

#define SPACE       (DOT)
#define LETTERSPACE (3*DOT-SPACE)
#define WORDSPACE   (7*DOT-LETTERSPACE)

void dit(void)
{
    pinWrite(pin,1);
    delay_ms(DOT);
    pinWrite(pin,0);
    delay_ms(SPACE);
}

void dash(void)
{
    pinWrite(pin,1);
    delay_ms(DASH);
    pinWrite(pin,0);
    delay_ms(SPACE);
}

void s(void)
{
    dit();
    dit();
    dit();
    delay_ms(LETTERSPACE);
}

void o(void)
{
    dash();
    dash();
    dash();
    delay_ms(LETTERSPACE);
}

void sos(void)
{
    s();
    o();
    s();
    delay_ms(WORDSPACE);
}

void notmain(void)
{
    pinMode(pin,OUTPUT);
    while(1) 
        sos();
}

