/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#include "common.h"

void InitRegister(void)
{
    uint16_t i;

    for (i = 0; i < sizeof(reg); i++)
        regPtr[i] = 0; /* Initialize all entries to zero */

    reg.hkperiod = HK_PERIOD; 		
    reg.measure.temp = SET;
    reg.measure.rssi = SET;     
    reg.tm_power = CAL_TM_POWER;		
    reg.frx_l = CAL_FRX & 0xFF;
    reg.frx_m = (CAL_FRX >> 8) & 0xFF;
    reg.frx_h = CAL_FRX >> 16;
    reg.ftx_l = CAL_FTX & 0xFF;
    reg.ftx_m = (CAL_FTX >> 8) & 0xFF;
    reg.ftx_h = CAL_FTX >> 16;
    reg.fsep_l = CAL_FSEP & 0xFF;
    reg.fsep_h = (CAL_FSEP >> 8) & 0xFF;
    reg.flag.tx_enabled = SET;
}

void InitModules(void)
{
    MicrocontrollerInit();
    I2cInit(I2C_ADR);
    AntennaDeploymentInit();
    MemInit();
    DuplexerInit();
    HpaInit();
    TransceiverInit();
    TransceiverState(TRX_SELECT_RX);
    LnaInit();
    _TX_LED = _OFF;
    _RX_LED = _OFF;
}

void RegWrite(const uint8_t targetReg, const uint8_t value)
{
    reg.flag.busy = SET;

    switch (targetReg)
    {
        case REG_CMD:
            switch (value)
            {
                case CMD_RESET:
                    MicrocontrollerReset();
                    break;

                case CMD_MEASURE:
                    reg.flag.complete = CLEAR;
                    TriggerMeasurements();
                    reg.flag.complete = SET;
                    break;

                case CMD_UPDATE_TRX:
                {
                    uint32_t ftx, frx;
                    uint16_t fsep;

                    ftx = ((uint32_t) (reg.ftx_h) << 16)
                            + ((uint32_t) (reg.ftx_m) << 8) + reg.ftx_l;
                    frx = ((uint32_t) (reg.frx_h) << 16)
                            + ((uint32_t) (reg.frx_m) << 8) + reg.frx_l;
                    fsep = (uint16_t) (reg.fsep_h << 8) + reg.fsep_l;
                    TransceiverUpdate(ftx, frx, fsep, CAL_BAUDRATE);
                    TransceiverState(TRX_SELECT_RX);
                }
                    break;

                case CMD_DEPLOY_ANT:
                    reg.flag.ant_deloying = SET;
                    AntennaDeployment(DEPLOY_DURATION);
                    reg.flag.ant_deloying = CLEAR;
                    break;

                case CMD_TX_ENABLE:
                    reg.flag.tx_enabled = SET;
                    break;

                case CMD_TX_DISABLE:
                    reg.flag.tx_enabled = CLEAR;
                    break;                                     
                    
                default:
                    /* not a valid command opcode */
                    break;
            }
            break;

        case REG_HKPERIOD:
            reg.hkperiod = value;
            timerHk = 0;
            break;

        case REG_MEASURE:
            reg.measure.byte = value;
            break;

        default: /* replace by individual registers to restrict access to writable registers */
            regPtr[targetReg] = value;
            break;
    }

    reg.flag.busy = CLEAR;
}

void TriggerMeasurements(void)
{
    int16_t buffer;

    reg.flag.busy = SET;
    reg.flag.complete = CLEAR;   
    
    if (reg.measure.temp)
    {
        AdcState(ON);

        buffer = AdcMeasure(ADC_TEMP);
        reg.mcutemp_l = (buffer & 0xFF);
        reg.mcutemp_h = ((buffer >> 8) & 0xFF);

        buffer = AdcMeasure(ADC_AIN1);
        reg.hpatemp_l = (buffer & 0xFF);
        reg.hpatemp_h = ((buffer >> 8) & 0xFF);

        AdcState(OFF);
    }

    if (reg.measure.rssi)
    {
        AdcState(ON);

        buffer = AdcMeasure(ADC_AIN0);
        reg.rssi_l = (buffer & 0xFF);
        reg.rssi_h = ((buffer >> 8) & 0xFF);

        AdcState(OFF);
    }
    
    reg.flag.complete = SET;
    reg.flag.busy = CLEAR;
}
