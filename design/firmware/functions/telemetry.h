/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	TELEMETRY_H
#define TELEMETRY_H

/* Includes */
#include "../definitions.h"
#include "../modules/c8051f120.h"
#include "../modules/transceiver.h"
#include "../modules/duplexer.h"
#include "../modules/memory.h"
#include "../modules/high_power_amplifier.h"
#include "../modules/low_noise_amplifier.h"

/* Globals */
extern Register_t reg;
extern uint16_t tmOctetsIn;
extern uint16_t tmOctetsOut;

/* Function declarations */
void PopTmFifo(void);
void StartTransmission(void);
void EndTransmission(void);
void IncreaseTmByteCounter(void);

#endif
