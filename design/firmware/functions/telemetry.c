/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#include "telemetry.h"

void PopTmFifo(void)
{           
    uint8_t buffer, b, i;

    buffer = MemRead(TM_FIFO, tmOctetsOut >> 8, tmOctetsOut & 0xFF);
    
    for (i = 0; i < 8; i++)
    {
        b = (buffer >> (7-i)) & 0x01; /* get bit, MSB first */
        while(TRX_DCLK == SET);
        TRX_DIO = b & 0x01;
        while (TRX_DCLK == CLEAR);
    }
    
    tmOctetsOut++; 
    IncreaseTmByteCounter();
}

void StartTransmission(void)
{
    LnaState(OFF); /* No need for LNA now */  
    DuplexerState(DUPLEXER_SELECT_TX);
    TransceiverState(TRX_SELECT_TX);
    TransceiverPower(reg.tm_power); 
    HpaState(ON);
    TRX_DIO = CLEAR;            
    _TX_LED = _ON; 
    reg.flag.tx_on = reg.flag.sending_tm_data = SET;    
}

void EndTransmission(void)
{
    HpaState(OFF);
    TransceiverPower(0);
    TransceiverState(TRX_SELECT_RX);
    DuplexerState(DUPLEXER_SELECT_TX);
    LnaState(ON);
    _TX_LED = _OFF;
    reg.flag.tx_on = reg.flag.sending_tm_data = CLEAR;
}

void IncreaseTmByteCounter(void)
{
    reg.tm_byte_count_l++;
    if (reg.tm_byte_count_l == 0) /* If we came from 0xFF */
    {
        reg.tm_byte_count_m++;
        if (reg.tm_byte_count_m == 0)
        {
            reg.tm_byte_count_h++;
        }
    }
}
