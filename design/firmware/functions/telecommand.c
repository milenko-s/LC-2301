/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#include "telecommand.h"

void DetectCltuStartSequence(void)
{
    static uint16_t buffer = 0;
    static uint8_t lastClock = 0;
    static uint8_t symbol = 0;
    
    if (!reg.flag.tx_on) /* Check that we are in receive mode */
    {
        if (TRX_DCLK != lastClock) /* Check if clock transition occurred */
        {
            lastClock = TRX_DCLK; /* Save current state of clock */
            if (lastClock == 1) /* Check that we had a rising edge */
            {
                symbol = TRX_DIO; /* Save rf data bit */
                buffer = buffer << 1; /* Shift 16 bit buffer to left */
                buffer |= (symbol & 0x01); /* Insert the new bit at LSB position */
            
                if (buffer == CLTU_STARTSEQUENCE) /* Check if we have received a CLTU start sequence */
                {
                    reg.flag.busy = 1;
                    reg.flag.rf_bitlock = reg.flag.receiving_tc_data = 1;
                    _RX_LED = _ON;
                    ReceiveCltu();
                    _RX_LED = _OFF;
                    reg.flag.rf_bitlock = reg.flag.receiving_tc_data = 0;
                    reg.flag.busy = 0;
                }
            }
        }
    }
}

uint8_t ReceiveCltu(void)
{
    uint16_t i, j, n, m;
    uint8_t buffer, symbolNow;

    TransceiverAverageFilterState(LOCK);

    MemWrite(TC_FIFO, tcOctetsIn >> 8, tcOctetsIn & 0xFF, CLTU_STARTSEQUENCE >> 8);
    tcOctetsIn++;
    IncreaseTcByteCounter();
    MemWrite(TC_FIFO, tcOctetsIn >> 8, tcOctetsIn & 0xFF, CLTU_STARTSEQUENCE & 0xFF);
    tcOctetsIn++;
    IncreaseTcByteCounter();
       
    for (i = n = m = 0; i < MAX_SIZE_CLTU; i++)
    {
        buffer = 0;
        
        for (j = 0; j < 8; j++)    /* receive an octet */
        {
            while (TRX_DCLK == SET)
                ;
            while (TRX_DCLK == CLEAR)
                ;    /* wait for rising edge */
            symbolNow = TRX_DIO;
            
            buffer = buffer << 1;    /* shift left */
            buffer |= (symbolNow & 0x01);      /* append new bit */   
        }
        
        MemWrite(TC_FIFO, tcOctetsIn >> 8, tcOctetsIn & 0xFF, buffer);
        tcOctetsIn++;
        IncreaseTcByteCounter();
        
        if (buffer == CLTU_TAILSEQUENCE_8)
        {
            if (n == 7)
            {
                TransceiverAverageFilterState(UNLOCK);
                return PASS;
            }
            else
            {
                n = 0;
            }
        }
        else if (buffer == CLTU_TAILSEQUENCE_1TO7)
        {
            n++;
        }
        else
        {
            n = 0;
        }
        
        if (buffer == CLTU_IDLESEQUENCE)
        {
            if (m == 7)
            {
                TransceiverAverageFilterState(UNLOCK);
                return PASS;
            }
            else
            {
                m++;
            }
        }
        else
        {
            m = 0;
        }
    }
    
    TransceiverAverageFilterState(UNLOCK);
    return FAIL; /* Fails if no valid tail sequence was found */
}

void PopTcFifo(void)
{
	ES0 = 0; /* disable uart interrupt */

	SBUF0 = MemRead(TC_FIFO, tcOctetsOut >> 8, tcOctetsOut & 0xFF);
	while (!TI0);
	TI0 = 0;

    tcOctetsOut++;
 
	ES0 = 1; /* enable uart inerrupt */ 
}

void IncreaseTcByteCounter(void)
{
    reg.tc_byte_count_l++;
    if (reg.tc_byte_count_l == 0) /* If we came from 0xFF */
    {
        reg.tc_byte_count_m++;
        if (reg.tc_byte_count_m == 0)
        {
            reg.tc_byte_count_h++;
        }
    }
}
