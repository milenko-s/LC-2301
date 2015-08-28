/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	COMMON_H
#define COMMON_H

/* Includes */
#include "../modules/c8051f120.h"
#include "../definitions.h"
#include "../modules/microcontroller.h"
#include "../modules/duplexer.h"
#include "../modules/transceiver.h"
#include "../modules/i2c.h"
#include "../modules/memory.h"
#include "../modules/antenna_deployment.h"
#include "../modules/high_power_amplifier.h"
#include "../modules/low_noise_amplifier.h"
#include "telecommand.h"

/* Globals */
extern Register_t reg;
extern uint8_t *regPtr;
extern uint32_t timerHk;

/* Function declarations */
void InitRegister(void);
void InitModules(void);
void RegWrite(const uint8_t target_reg, const uint8_t value);
void TriggerMeasurements(void);

#endif
