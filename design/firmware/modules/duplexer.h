/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	DUPLEXER_H
#define DUPLEXER_H

/* Includes */
#include "c8051f120.h"
#include "../definitions.h"
#include "microcontroller.h"

/* Definitions */
#define DUPLEXER_SELECT_RX		0
#define DUPLEXER_SELECT_TX		1

/* Function declarations */
void DuplexerInit(void);
void DuplexerState(const uint8_t state);

#endif
