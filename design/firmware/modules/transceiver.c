/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#include "transceiver.h"

void TransceiverInit(void)
{
    TransceiverReset();
    TransceiverConfigureTX();
    TransceiverCalibrate();
    TransceiverConfigureRX();
    TransceiverCalibrate();
    
    TRX_PCLK = 0;
    TRX_PALE = 0;
    TRX_PDATA = 0;
    TRX_DCLK = 1;
    TRX_DIO = 0;
}

void TransceiverReset(void)
{
    uint32_t i;
    TransceiverWriteReg(0x00, 0x3A);
    for (i = 0; i < 10000; i++)
        ;
    TransceiverWriteReg(0x00, 0x3B);
    for (i = 0; i < 10000; i++)
        ;
}

void TransceiverCalibrate(void)
{
    uint8_t buffer, pa;
    uint32_t i;
    
    pa = TransceiverReadReg(CC1000_PA_POW);
    TransceiverWriteReg(CC1000_PA_POW, 0x00);    // turn off PA to avoid spurs during calibration in TX mode 
    for (i = 0; i < 10000; i++)
        ; 						// 2ms delay
    TransceiverWriteReg(CC1000_CAL, 0x26); 			// prepare calibration 	
    TransceiverWriteReg(CC1000_CAL, 0xA6); 			// start calibration 
    do
    {
        for (i = 0; i < 100000UL; i++)
            ; 						// delay
        buffer = TransceiverReadReg(CC1000_CAL);	// poll CAL_COMPLETE flag
    }
    while ((buffer & 0x08) == 0);
    TransceiverWriteReg(CC1000_CAL, 0x26);  		// stop calibration  
    TransceiverWriteReg(CC1000_PA_POW, pa); 		// restore PA setting  
}

void TransceiverConfigureTX(void)
{
    TransceiverWriteReg(CC1000_MAIN, 0xE1);    // TX : RegB : -LNA : +PA :: +FS : +CORE : +BIAS : No Reset
    TransceiverWriteReg(CC1000_FREQ_2A, CAL_FRX >> 16);
    TransceiverWriteReg(CC1000_FREQ_1A, (CAL_FRX >> 8) & 0xFF);
    TransceiverWriteReg(CC1000_FREQ_0A, CAL_FRX & 0xFF);
    TransceiverWriteReg(CC1000_FREQ_2B, CAL_FTX >> 16);
    TransceiverWriteReg(CC1000_FREQ_1B, (CAL_FTX >> 8) & 0xFF);
    TransceiverWriteReg(CC1000_FREQ_0B, CAL_FTX & 0xFF);
    TransceiverWriteReg(CC1000_FSEP1, CAL_FSEP >> 8);
    TransceiverWriteReg(CC1000_FSEP0, CAL_FSEP & 0xFF);
    TransceiverWriteReg(CC1000_CURRENT, 0x81);    // 1000=1450uA :: 00=0.5mA : 01=2mA
    TransceiverWriteReg(CC1000_FRONT_END, 0x00);	// 0.8mA for LNA : no RSSI : internal XOSC
    TransceiverWriteReg(CC1000_PA_POW, 0x00); 		// set to zero
    TransceiverWriteReg(CC1000_PLL, 0x60);    // internal LP : div by 12 : alarm enabled
    TransceiverWriteReg(CC1000_LOCK, 0x10);    // lock continous outputed : normal
    TransceiverWriteReg(CC1000_CAL, 0x26); 			// single calibration 	 
    TransceiverWriteReg(CC1000_MODEM0, (CAL_BAUDRATE << 4) + 0x03);    // 1.2 kbaud : NRZ : 14.7456 MHz crystal used
    TransceiverWriteReg(CC1000_FSCTRL, 0x01); 		// no FS reset
    TransceiverWriteReg(CC1000_PRESCALER, 0x00); 	// default
}

void TransceiverConfigureRX(void)
{
    TransceiverWriteReg(CC1000_MAIN, 0x11);    // RX : RegA : +LNA : -PA :: +FS : +CORE : +BIAS : No Reset
    TransceiverWriteReg(CC1000_FREQ_2A, CAL_FRX >> 16);
    TransceiverWriteReg(CC1000_FREQ_1A, (CAL_FRX >> 8) & 0xFF);
    TransceiverWriteReg(CC1000_FREQ_0A, CAL_FRX & 0xFF);
    TransceiverWriteReg(CC1000_FREQ_2B, CAL_FTX >> 16);
    TransceiverWriteReg(CC1000_FREQ_1B, (CAL_FTX >> 8) & 0xFF);
    TransceiverWriteReg(CC1000_FREQ_0B, CAL_FTX & 0xFF);
    TransceiverWriteReg(CC1000_FSEP1, CAL_FSEP >> 8);
    TransceiverWriteReg(CC1000_FSEP0, CAL_FSEP & 0xFF);
    TransceiverWriteReg(CC1000_CURRENT, 0x44);    // 0100=950uA :: 01=1.0mA : 00=1mA
    TransceiverWriteReg(CC1000_FRONT_END, 0x02); 	// 0.8mA for LNA : RSSI : internal XOSC
    TransceiverWriteReg(CC1000_PA_POW, 0x00); 		// set to zero
    TransceiverWriteReg(CC1000_PLL, 0x60);    // internal LP : div by 12 : alarm enabled
    TransceiverWriteReg(CC1000_LOCK, 0x10);    // lock continous outputed : normal
    TransceiverWriteReg(CC1000_CAL, 0x26); 			// single calibration 	 
    TransceiverWriteReg(CC1000_MODEM2, 0x96);
    TransceiverWriteReg(CC1000_MODEM1, 0x0F);    // Average filter free running, manual lock
    TransceiverWriteReg(CC1000_MODEM0, (CAL_BAUDRATE << 4) + 0x03);    // 1.2 kbaud : NRZ : 14.7456 MHz crystal used
    TransceiverWriteReg(CC1000_MATCH, 0x00);
    TransceiverWriteReg(CC1000_FSCTRL, 0x01); 		// no FS reset
    TransceiverWriteReg(CC1000_PRESCALER, 0x00); 	// default
}

void TransceiverUpdate(const uint32_t ftx, const uint32_t frx, const uint16_t fsep, const uint8_t baudrate)
{
    TransceiverWriteReg(CC1000_FREQ_2A, frx >> 16);
    TransceiverWriteReg(CC1000_FREQ_1A, (frx >> 8) & 0xFF);
    TransceiverWriteReg(CC1000_FREQ_0A, frx & 0xFF);
    TransceiverWriteReg(CC1000_FREQ_2B, ftx >> 16);
    TransceiverWriteReg(CC1000_FREQ_1B, (ftx >> 8) & 0xFF);
    TransceiverWriteReg(CC1000_FREQ_0B, ftx & 0xFF);
    TransceiverWriteReg(CC1000_FSEP1, fsep >> 8);
    TransceiverWriteReg(CC1000_FSEP0, fsep & 0xFF);
    TransceiverWriteReg(CC1000_MODEM0, (baudrate << 4) + 0x03);
}

void TransceiverState(const uint8_t state)
{
    uint8_t SFRPAGE_SAVE;
    
    if (state == TRX_SELECT_RX)
    {
        TransceiverWriteReg(CC1000_MAIN, 0x11);    // RX : RegA : +LNA : -PA :: +FS : +CORE : +BIAS : No Reset
        TransceiverWriteReg(CC1000_CURRENT, 0x44);    // 0100=950uA :: 01=1.0mA : 00=1mA
        TransceiverWriteReg(CC1000_FRONT_END, 0x02);    // 0.8mA for LNA : RSSI : internal XOSC
        TransceiverWriteReg(CC1000_PA_POW, 0x00);    // set to zero
        
        SFRPAGE_SAVE = SFRPAGE;
        SFRPAGE = CONFIG_PAGE;
        P1MDOUT = P1MDOUT & ~0x10;				// set TRX_DIO pin to open-drain
        SFRPAGE = SFRPAGE_SAVE;
        TRX_DIO = 1;
    }
    else if (state == TRX_SELECT_TX)
    {
        TransceiverWriteReg(CC1000_MAIN, 0xE1);    // TX : RegB : -LNA : +PA :: +FS : +CORE : +BIAS : No Reset
        TransceiverWriteReg(CC1000_CURRENT, 0x81);    // 1000=1450uA :: 00=0.5mA : 01=2mA
        TransceiverWriteReg(CC1000_FRONT_END, 0x00);    // 0.8mA for LNA : no RSSI : internal XOSC
        TransceiverWriteReg(CC1000_PA_POW, 0x00);
        
        SFRPAGE_SAVE = SFRPAGE;
        SFRPAGE = CONFIG_PAGE;
        P1MDOUT = P1MDOUT | 0x10;				// set TRX_DIO pin to push-pull
        SFRPAGE = SFRPAGE_SAVE;
        TRX_DIO = 0;
    }
    else if (state == OFF)
    {
        TransceiverWriteReg(CC1000_MAIN, 0x3F);
        TransceiverWriteReg(CC1000_PA_POW, 0x00);
    }
}

void TransceiverWriteReg(const uint8_t reg, const uint8_t value)
{
    uint8_t buffer, i, SFRPAGE_SAVE;
    
    SFRPAGE_SAVE = SFRPAGE;
    SFRPAGE = CONFIG_PAGE;
    P1MDOUT = P1MDOUT | 0x04;    // set TM_PDATA pin to push-pull
    SFRPAGE = SFRPAGE_SAVE;
    
    buffer = (reg << 1) | 0x01;    // append WRITE bit to reg byte	
    TRX_PALE = 1;
    TRX_PALE = 0;
    for (i = 0; i < 8; i++)
    {
        TRX_PDATA = 0x01 & (buffer >> (7 - i));
        TRX_PCLK = 1;
        TRX_PCLK = 0;
        TRX_PCLK = 1;
    }
    TRX_PALE = 1;
    for (i = 0; i < 8; i++)
    {
        TRX_PDATA = 0x01 & (value >> (7 - i));
        TRX_PCLK = 1;
        TRX_PCLK = 0;
        TRX_PCLK = 1;
    }
}

uint8_t TransceiverReadReg(const uint8_t reg)
{
    uint8_t buffer, i, SFRPAGE_SAVE;
    
    TRX_PDATA = 0;
    
    SFRPAGE_SAVE = SFRPAGE;
    SFRPAGE = CONFIG_PAGE;
    P1MDOUT = P1MDOUT | 0x04;    // set TRX_PDATA pin to push-pull
    SFRPAGE = SFRPAGE_SAVE;
    
    buffer = (reg << 1) & ~0x01;    // append READ bit to reg byte
    TRX_PALE = 1;
    TRX_PALE = 0;
    for (i = 0; i < 8; i++)
    {
        TRX_PDATA = 0x01 & (buffer >> (7 - i));
        TRX_PCLK = 1;
        TRX_PCLK = 0;
        TRX_PCLK = 1;
    }
    TRX_PALE = 1;
    
    SFRPAGE_SAVE = SFRPAGE;
    SFRPAGE = CONFIG_PAGE;
    P1MDOUT = P1MDOUT & ~0x04;    // set TRX_PDATA pin to open-drain
    SFRPAGE = SFRPAGE_SAVE;
    
    TRX_PDATA = 1;				// set TRX_PDATA high
    buffer = 0;
    for (i = 0; i < 8; i++)
    {
        TRX_PCLK = 1;
        TRX_PCLK = 0;
        buffer = buffer + (unsigned char) (TRX_PDATA << (7 - i));
        TRX_PCLK = 1;
    }
    return buffer;
}

void TransceiverFreqRangeCheck(const uint8_t state)
{
    if (state == 0)
    {
        TransceiverWriteReg(CC1000_TEST5, 0x3F);    // lowest possible frequency
        TransceiverWriteReg(CC1000_TEST3, 0x10);
    }
    else if (state == 1)
    {
        TransceiverWriteReg(CC1000_TEST5, 0x30);    // highest possible frequency
        TransceiverWriteReg(CC1000_TEST3, 0x17);
    }
}

void TransceiverPower(const uint8_t level)
{
    uint8_t value;
    
    value = level;
    
    if (level > 15)
    {
        switch (level)
        {
            case 16:
                value = 0x40;
                break;
                
            case 17:
                value = 0x50;
                break;
                
            case 18:
                value = 0x60;
                break;
                
            case 19:
                value = 0x70;
                break;
                
            case 20:
                value = 0x80;
                break;
                
            case 21:
                value = 0x90;
                break;
                
            case 22:
                value = 0xC0;
                break;
                
            case 23:
                value = 0xE0;
                break;
                
            case 24:
                value = 0xFF;
                break;
                
            default:    // higher levels are not implemented as they could damage the HPA
                value = 15;
                break;
        }
    }
    
    TransceiverWriteReg(CC1000_PA_POW, value);
}

void TransceiverAverageFilterState(const uint8_t state)
{
    if (state == LOCK)
        TransceiverWriteReg(CC1000_MODEM1, 0x1F);    // Average filter locked, manual lock
    else if (state == UNLOCK)
        TransceiverWriteReg(CC1000_MODEM1, 0x0F);    // Average filter free running, manual lock
}
