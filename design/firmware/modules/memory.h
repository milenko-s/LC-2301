/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	MEMORY_H
#define MEMORY_H

/* Includes */
#include "c8051f120.h"
#include "../definitions.h"
#include "microcontroller.h"

/* Function declarations */
void MemInit(void);
uint8_t MemRead(const uint8_t adr_h, const uint8_t adr_m, const uint8_t adr_l);
void MemWrite(const uint8_t adr_h, const uint8_t adr_m, const uint8_t adr_l, const uint8_t value);

#endif
