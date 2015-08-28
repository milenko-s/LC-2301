/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	HIGH_POWER_AMPLIFIER_H
#define HIGH_POWER_AMPLIFIER_H

/* Includes */
#include "c8051f120.h"
#include "../definitions.h"
#include "microcontroller.h"

/* Function declarations */
void HpaInit(void);
void HpaState(const uint8_t state);

#endif
