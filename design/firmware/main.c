/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 * Last update: 2014-11-18
 */

/*	To do:
 *		- add automatic ping mode? (i.e. send beacon when i2c idle for long duration)
 *		- implement watchdog timer
 *		- add i2c timeouts
 */

/* Includes */
#include "definitions.h"
#include "modules/c8051f120.h"
#include "functions/common.h"
#include "functions/telecommand.h"
#include "functions/telemetry.h"

/* Global variables */
Register_t reg;
uint8_t *regPtr = (uint8_t*) (&reg);
uint8_t targetReg = 0;
uint8_t targetRegFlag = 0;
uint8_t value = 0;
uint8_t valueFlag = 0;
uint32_t timerHk = 0;
uint32_t timer2Val = 0;
uint16_t tcOctetsIn = 0;
uint16_t tcOctetsOut = 0;
uint16_t tmOctetsIn = 0;
uint16_t tmOctetsOut = 0;

void main(void)
{
    InitRegister(); /* Load default register values */
    InitModules(); /* Configure and initialize hardware */
    
    /* Do the housekeeping measurements at boot */
    TriggerMeasurements();
    
    for (;;)
    {
        /* Execute a received command from I2C master */
        if (targetRegFlag && valueFlag)
        {
            RegWrite(targetReg, value);
            targetRegFlag = valueFlag = 0; /* Reset the flags afterwards */
        }

        /* Refresh housekeeping data, if timer expired */
        if ((reg.hkperiod != 0) && (timerHk >= reg.hkperiod))
        {
            timerHk = 0; /* Reset timer count */
            TriggerMeasurements();
        }          
        
        /* Are there TC bytes in the FIFO? */
		if (tcOctetsOut != tcOctetsIn) 
		{			
		    PopTcFifo(); /* Pop one byte from FIFO and route to UART0 */
		}

		/* Are there TM bytes in the FIFO? */
		if (tmOctetsOut != tmOctetsIn) 
		{
		    if (reg.flag.tx_enabled == SET) /* Is TX enabled? */
            {
		        if (reg.flag.tx_on == CLEAR) /* If TX is not on yet, switch it on */ 
		        {
		            StartTransmission();     
		        }
		        
                PopTmFifo(); /* Pop one byte from FIFO and route to transmitter */
            }
		    else
		    {
		        tmOctetsOut++; /* Otherwise skip this byte */
		    }
		}
		else /* Switch off TX after all FIFO data has been transmitted */
		{
			if (reg.flag.tx_on == SET) /* Check if TX is still on */
			{
				EndTransmission();
			}
		}
    }
}

void Timer0Isr(void) __interrupt 1 /* called every 0.00005 sec for sampling rx input */
{
    DetectCltuStartSequence();  
}

void SystemResetIsr(void) __interrupt 2 /* triggers when -RESET line is low */
{   
    MicrocontrollerReset();
}

void Timer2Isr(void) __interrupt 5 /* called every 0.01 sec, for hk period */
{
    timer2Val++;    
    if (timer2Val >= 10)
    {
        timer2Val = 0;
        timerHk++;    // increases every 0.1 sec
    }
    TF2 = 0;    /* clear interrupt flag (necessary) */
}

void I2cIsr(void) __interrupt 7 
{
    switch (SMB0STA)
    {
        case I2C_SROADACK:    /* (SR) own address + W received; ACK transmitted */
            targetRegFlag = 0;
            valueFlag = 0;
            break;
            
        case I2C_SRSTOP:    /* (SR) STOP or repeated START received while addressed as a slave */
            valueFlag = 0;
            AA = 1;
            break;
            
        case I2C_SRODBACK:    /* (SR) data byte received under own slave address; ACK returned */
            if (!targetRegFlag)    /* if this is the first byte */
            {
                targetRegFlag = 1;
                targetReg = SMB0DAT;
            }
            else    /* otherwise load second byte */
            {
                valueFlag = 1;
                value = SMB0DAT;
            }
            break;
            
        case I2C_STOADACK:    /* (ST) I2Cs own slave address + R received; ACK transmitted */
            SMB0DAT = regPtr[targetReg];
            break;
            
        case I2C_SRODBNACK:    /* (SR) data byte received under own slave address; NACK returned */
        case I2C_STDBNACK:    /* (ST) data byte transmitted; NACK received */
        case I2C_STDBLAST:    /* (ST) last data byte transmitted (AA=0); ACK received */
        case I2C_BUS_ERROR:
        default:    /* All other status codes meaningless in this application. */   
            STO = 1;    /* Reset communication. */
            break;
    }
    SI = 0;
}

void UartIsr(void) __interrupt 4
{   
    if (RI0) /* Push incoming data into TM FIFO */   
    {
		MemWrite(TM_FIFO, tmOctetsIn >> 8, tmOctetsIn & 0xFF, SBUF0);
		tmOctetsIn++;
		RI0 = 0;
    }
    
    if (TI0) 
    {
        TI0 = 0;
    }
}

