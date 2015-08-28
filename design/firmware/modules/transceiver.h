/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	TRANSCEIVER_H
#define TRANSCEIVER_H

/* Includes */
#include "c8051f120.h"
#include "../definitions.h"
#include "microcontroller.h"

/* Definitions */
#define LOCK					1
#define UNLOCK					0
#define TRX_SELECT_RX			1 		
#define TRX_SELECT_TX			2

/* CC1000 Register */
#define CC1000_MAIN			0x00
#define CC1000_FREQ_2A		0x01
#define CC1000_FREQ_1A		0x02
#define CC1000_FREQ_0A		0x03
#define CC1000_FREQ_2B		0x04
#define CC1000_FREQ_1B		0x05
#define CC1000_FREQ_0B		0x06
#define CC1000_FSEP1		0x07
#define CC1000_FSEP0		0x08
#define CC1000_CURRENT 		0x09
#define CC1000_FRONT_END 	0x0A
#define CC1000_PA_POW		0x0B
#define CC1000_PLL			0x0C
#define CC1000_LOCK			0x0D
#define CC1000_CAL			0x0E
#define CC1000_MODEM2		0x0F
#define CC1000_MODEM1		0x10
#define CC1000_MODEM0		0x11
#define CC1000_MATCH		0x12
#define CC1000_FSCTRL		0x13
#define CC1000_PRESCALER 	0x1C
#define CC1000_TEST6		0x40
#define CC1000_TEST5		0x41
#define CC1000_TEST4		0x42
#define CC1000_TEST3		0x43
#define CC1000_TEST2		0x44
#define CC1000_TEST1		0x45
#define CC1000_TEST0		0x46

/* Configuration */

// Calibration values
// FSEP = (  X kHz)/(14.7456 MHz) * 12 * 16384 				// => 1 kHz = 13.333
// RX FREQ = (  X MHz)/(14.7456 MHz) * 12 * 16384 - 8192	// FRX = fLO = fRF - 150 kHz														
// TX FREQ = (  X MHz)/(14.7456 MHz) * 12 * 16384 - 8192	// FTX = f0 = fc - fsep/2, f1 = f0 + fsep

// chosen:
// fLO = 436.850 MHz															
// f0 = 436.9952 MHz ;f1 = 437.0048 MHz

#define CAL_FSEP			0x80UL //0x00C0UL						// 14.25 kHz fsep
#define CAL_BAUDRATE		1 								// 0=0k6, 1=1k2, 2=2k4, 3=4k8, 4=9k6

/* select device to be programmed */
#define LOT1108221

#ifdef LOT1108221									
#define CAL_FTX				0x58C7dcUL //0x58C870UL 									
#define CAL_FRX				(CAL_FTX - 0x790) //0x58BFC0UL 	// 150 kHz below TX center								
#define CAL_TM_POWER		1  							// 26 dBm
#endif

#ifdef LOT1108191
#define CAL_FTX				0x58C774UL 
#define CAL_FRX				0x58BFE5UL 
#define CAL_TM_POWER			9 // 26 dBm
#endif

#ifdef LOT1112161
#define CAL_FTX				0x58C757UL 
#define CAL_FRX				0x58BFC6UL 
#define CAL_TM_POWER			15 // 26 dBm
#endif

#ifdef LOT1108181
#define CAL_FTX				0x58C768UL 
#define CAL_FRX				0x58BFD7UL 
#define CAL_TM_POWER			10 // 26 dBm
#endif

#ifdef LOT1111241									
#define CAL_FTX				0x58C740UL 									
#define CAL_FRX				0x58BFB0UL 									
#define CAL_TM_POWER			12 // 26 dBm
#endif

#ifdef LOT1112211									
#define CAL_FTX				0x58C752UL 									
#define CAL_FRX				0x58BFC0UL 									
#define CAL_TM_POWER			11 // 26 dBm
#endif

/* Function declarations */
void TransceiverInit(void);
void TransceiverReset(void);
void TransceiverCalibrate(void);
void TransceiverConfigureTX(void);
void TransceiverConfigureRX(void);
void TransceiverUpdate(const uint32_t ftx, const uint32_t frx, const uint16_t fsep, const uint8_t baudrate);
void TransceiverState(const uint8_t state);
void TransceiverWriteReg(const uint8_t reg, const uint8_t value);
uint8_t TransceiverReadReg(const uint8_t reg);
void TransceiverFreqRangeCheck(const uint8_t state);
void TransceiverPower(const uint8_t level);
void TransceiverAverageFilterState(const uint8_t state);

#endif
