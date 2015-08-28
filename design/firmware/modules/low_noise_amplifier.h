/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	LOW_NOISE_AMPLIFIER_H
#define LOW_NOISE_AMPLIFIER_H

/* Includes */
#include "../definitions.h"
#include "c8051f120.h"
#include "microcontroller.h"

/* Function declarations */
void LnaInit(void);
void LnaState(const uint8_t state);

#endif
