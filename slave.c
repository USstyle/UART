/*
 * File:   slave.c
 * Author: udits
 *
 * Created on 10 September, 2023, 8:38 PM
 */


#include <xc.h>
// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 6000000
void init(void);
unsigned char x;
void main(void) {
    init();
    while(1)
    {  
        if(PIR1 & 0x20);
        x=RCREG;
       
        switch(x)
        {
            case'A': PORTD=0x02;
           
            break;
            case'B':PORTD=0x40;
           
            break;
            case'C':PORTD=0x42;
           
            break;
            case'D':PORTD=0x00;
            
            break;
        }
    }
    return;
}
void init(void)
{
    TRISD=0x00;
    PORTD=0x00;
    TRISC=0xC0;
    RCSTA=0x90;
    TXSTA=0x20;
    
    SPBRG=0x09;
}
