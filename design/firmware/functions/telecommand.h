/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	TELECOMMAND_H
#define TELECOMMAND_H

/* Includes */
#include "../definitions.h"
#include "../modules/c8051f120.h"
#include "../modules/transceiver.h"
#include "../modules/memory.h"

/* Globals */
extern Register_t reg;
extern uint16_t tcOctetsIn;
extern uint16_t tcOctetsOut;

/* Configuration */
#define MAX_SIZE_CLTU_CCSDS     1186 /* 1 byte TC Seg Hdr + max. 1026 byte TCTF 
                => 147 BCH blocks => 1176 bytes + 2 bytes start + 8 bytes tail */
#define MAX_SIZE_CLTU (MAX_SIZE_CLTU_CCSDS / 10) /* Maximum allowed size of a CLTU for this implementation */

/* General */
#define CLTU_STARTSEQUENCE		0xEB90 	// 1110 1011 1001 0000
#define CLTU_TAILSEQUENCE_1TO7	0xC5	// 1100 0101	
#define CLTU_TAILSEQUENCE_8		0x79	// 0111 1001
#define CLTU_IDLESEQUENCE		0x55	// 0101 0101

/* Function declarations */
void DetectCltuStartSequence(void);
uint8_t ReceiveCltu(void);
void PopTcFifo(void);
void IncreaseTcByteCounter(void);

#endif
