/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#include "microcontroller.h"

void Reset_Sources_Init()
{
    WDTCN = 0xDE;
    WDTCN = 0xAD;
    SFRPAGE = LEGACY_PAGE;
    RSTSRC = 0x06;
}

void Timer_Init()
{
    SFRPAGE = TIMER01_PAGE;
    TCON = 0x54;
    TMOD = 0x22;
    CKCON = 0x10;
    TL0 = TH0 = 0xE6;
    TH1 = 0xEC;
    SFRPAGE = TMR2_PAGE;
    TMR2CN = 0x04;
    TMR2CF = 0x08;
    RCAP2H = 0x0F;
    TMR2H = 0x0F;
}

void UART_Init()
{
    SFRPAGE = UART0_PAGE;
    SCON0 = 0x50;
}

void SMBus_Init()
{
    SFRPAGE = SMB0_PAGE;
    SMB0CN = 0x40;
    SMB0CR = 0xFA;
}

void Voltage_Reference_Init()
{
    SFRPAGE = ADC0_PAGE;
    REF0CN = 0x06;
}

void Port_IO_Init()
{
    // P0.0  -  TX0 (UART0), Push-Pull,  Digital
    // P0.1  -  RX0 (UART0), Open-Drain, Digital
    // P0.2  -  SDA (SMBus), Open-Drain, Digital
    // P0.3  -  SCL (SMBus), Open-Drain, Digital
    // P0.4  -  INT0 (Tmr0), Open-Drain, Digital
    // P0.5  -  INT1 (Tmr1), Open-Drain, Digital
    // P0.6  -  Unassigned,  Open-Drain, Digital
    // P0.7  -  Unassigned,  Open-Drain, Digital
    
    // P1.0  -  Unassigned,  Push-Pull,  Digital
    // P1.1  -  Unassigned,  Push-Pull,  Digital
    // P1.2  -  Unassigned,  Push-Pull,  Digital
    // P1.3  -  Unassigned,  Open-Drain, Digital
    // P1.4  -  Unassigned,  Push-Pull,  Digital
    // P1.5  -  Unassigned,  Open-Drain, Digital
    // P1.6  -  Unassigned,  Open-Drain, Digital
    // P1.7  -  Unassigned,  Push-Pull,  Digital
    
    // P2.0  -  Unassigned,  Push-Pull,  Digital
    // P2.1  -  Unassigned,  Push-Pull,  Digital
    // P2.2  -  Unassigned,  Push-Pull,  Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital
    // P2.4  -  Unassigned,  Push-Pull,  Digital
    // P2.5  -  Unassigned,  Push-Pull,  Digital
    // P2.6  -  Unassigned,  Push-Pull,  Digital
    // P2.7  -  Unassigned,  Push-Pull,  Digital
    
    // P3.0  -  Unassigned,  Open-Drain, Digital
    // P3.1  -  Unassigned,  Open-Drain, Digital
    // P3.2  -  Unassigned,  Open-Drain, Digital
    // P3.3  -  Unassigned,  Open-Drain, Digital
    // P3.4  -  Unassigned,  Open-Drain, Digital
    // P3.5  -  Unassigned,  Open-Drain, Digital
    // P3.6  -  Unassigned,  Open-Drain, Digital
    // P3.7  -  Unassigned,  Open-Drain, Digital
    
    SFRPAGE = CONFIG_PAGE;
    P0MDOUT = 0x01;
    P1MDOUT = 0x97;
    P2MDOUT = 0xFF;
    P4MDOUT = 0xFF;
    P5MDOUT = 0xFF;
    P6MDOUT = 0x07;
    XBR0 = 0x05;
    XBR1 = 0x14;
    XBR2 = 0x40;
    
    P0 = 0xFF;
}

void Oscillator_Init()
{
    SFRPAGE = CONFIG_PAGE;
    OSCICN = 0x81;
}

void Interrupts_Init()
{
    IE = 0xB6;
    IP = 0x26;
    EIE1 = 0x02;
    EIP1 = 0x02;
}

void MicrocontrollerInit(void)
{
    Reset_Sources_Init();			// disable WDT
    Timer_Init();	
    UART_Init();				// 9600 bps
    SMBus_Init();				// 100 kHz
    Voltage_Reference_Init();
    Port_IO_Init();
    Oscillator_Init();				// 6.126 MHz
    Interrupts_Init();				
    AdcInit();
}

void MicrocontrollerReset(void)
{
    RSTSRC = RSTSRC | 0x10;
}

void AdcInit(void)
{
    uint8_t SAVEPAGE = SFRPAGE;
    SFRPAGE = ADC0_PAGE;
    
    ADC0CN = 0xC0;
    
    SFRPAGE = SAVEPAGE;
}

void AdcState(const uint8_t state)
{
    if (state == ON)
        AD0EN = 1;
    else if (state == OFF)
        AD0EN = 0;
}

uint16_t AdcMeasure(const uint8_t channel)
{
    uint16_t buffer;
    uint8_t SAVEPAGE = SFRPAGE;
    SFRPAGE = ADC0_PAGE;
    
    AMX0SL = channel; 		// 0 = AIN0.0, etc., 8 = TEMP			
    
    AD0INT = 0; 			// clear ADC interrupt flag 
    AD0BUSY = 1; 			// trigger conversion 
    while (!AD0INT)
        ; 		// wait for conversion to complete 
        
    buffer = (ADC0H & 0x0F);    // 12 bit ADC
    buffer = (buffer << 8) + ADC0L;
    
    SFRPAGE = SAVEPAGE;
    return buffer;    // return result as 16-bit value
}
