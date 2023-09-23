/*
 * File:   master.c
 * Author: udits
 *
 * Created on 5 September, 2023, 7:15 PM
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
       x=PORTB;
       switch(x)
       {
               case 0xE0: TXREG='A';
               __delay_ms(1000);
               break;
               case 0xD0: TXREG='B';
                __delay_ms(1000);
               break;
               case 0xB0: TXREG='C';
                __delay_ms(1000);
               break;
               case 0x70: TXREG='D';
               __delay_ms(1000);
               break;
       }
    }
    return;
}
void init(void)
{
    TRISB=0xF0;//directing as a output
    TRISC=0xC0;//Set RC6 and RC7
    PORTB=0x00;//initialize from 0x00
    OPTION_REG=0x7F;//internal pull ups are enabled
    RCSTA=0x90;
    TXSTA=0x20;
    
    SPBRG=0x09;
    
}
