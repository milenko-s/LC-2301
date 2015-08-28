/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	MICROCONTROLLER_H
#define MICROCONTROLLER_H

/* Includes */
#include "c8051f120.h"
#include "../definitions.h"

/* ADC specific */
#define ADC_TEMP	8
#define ADC_AIN0	0
#define ADC_AIN1	1

/* Pin allocations */
#define _ANT_DEPLOY		        P0_4
#define _TX_LED                 P0_6
#define _RX_LED                 P0_7
#define TRX_PCLK                P1_0
#define TRX_PALE                P1_1
#define TRX_PDATA               P1_2
#define TRX_DCLK                P1_3
#define TRX_DIO                 P1_4
#define _LNA_ON                 P1_5
#define _HPA_ON                 P1_6
#define HPAM_EN                 P1_7
#define DUPLEX_TX               P2_0
#define DUPLEX_RX               P2_1
#define _MEM_CE                 P2_2
#define _MEM_OE                 P2_3
#define _MEM_WE                 P2_4
#define DATA                    P3
#define ADDRESS_L               P4
#define ADDRESS_M               P5
#define ADDRESS_H               P6

/* Function declarations */
void MicrocontrollerInit(void);
void MicrocontrollerReset(void);
void AdcInit(void);
void AdcState(const uint8_t state);
uint16_t AdcMeasure(const uint8_t channel);

#endif
