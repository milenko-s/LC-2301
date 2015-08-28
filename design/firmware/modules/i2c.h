/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	I2C_H
#define I2C_H

/* Includes */
#include "c8051f120.h"
#include "../definitions.h"

/* I2c status codes */
#define I2C_BUS_ERROR 	0x00	// (all modes) BUS ERROR
#define I2C_START 		0x08 	// (MT & MR) START transmitted
#define I2C_RP_START 	0x10 	// (MT & MR) repeated START
#define I2C_MTADDACK 	0x18 	// (MT) Slave address + W transmitted; ACK received
#define I2C_MTADDNACK 	0x20 	// (MT) Slave address + W transmitted; NACK received
#define I2C_MTDBACK 	0x28 	// (MT) data byte transmitted; ACK rec�vd
#define I2C_MTDBNACK 	0x30 	// (MT) data byte transmitted; NACK rec�vd
#define I2C_MTARBLOST 	0x38 	// (MT) arbitration lost
#define I2C_MRADDACK 	0x40 	// (MR) Slave address + R transmitted; ACK received
#define I2C_MRADDNACK 	0x48 	// (MR) Slave address + R transmitted; NACK received
#define I2C_MRDBACK 	0x50 	// (MR) data byte rec�vd; ACK transmitted
#define I2C_MRDBNACK 	0x58 	// (MR) data byte rec�vd; NACK transmitted
#define I2C_SROADACK 	0x60 	// (SR) I2C�s own slave address + W rec�vd; ACK transmitted
#define I2C_SROARBLOST 	0x68 	// (SR) I2C�s own slave address + W rec�vd; arbitration lost
#define I2C_SRGADACK 	0x70 	// (SR) general call address rec�vd; ACK transmitted
#define I2C_SRGARBLOST 	0x78 	// (SR) arbitration lost when transmitting slave addr + R/W as master; general call address rec�vd; ACK transmitted
#define I2C_SRODBACK 	0x80 	// (SR) data byte received under own slave address; ACK returned
#define I2C_SRODBNACK 	0x88 	// (SR) data byte received under own slave address; NACK returned
#define I2C_SRGDBACK 	0x90	// (SR) data byte received under general call address; ACK returned
#define I2C_SRGDBNACK 	0x98 	// (SR) data byte received under general call address; NACK returned
#define I2C_SRSTOP		0xa0 	// (SR) STOP or repeated START received while addressed as a slave
#define I2C_STOADACK 	0xa8 	// (ST) I2C�s own slave address + R rec�vd; ACK transmitted
#define I2C_STOARBLOST 	0xb0 	// (ST) arbitration lost in transmitting slave address + R/W as master; own slave address rec�vd; ACK transmitted
#define I2C_STDBACK		0xb8 	// (ST) data byte transmitted; ACK rec�ed
#define I2C_STDBNACK 	0xc0 	// (ST) data byte transmitted; NACK rec�ed
#define I2C_STDBLAST 	0xc8 	// (ST) last data byte transmitted (AA=0); ACK received
#define I2C_SCLHIGHTO	0xd0 	// (ST & SR) SCL clock high timer per I2C0CR timed out (FTE=1)
#define I2C_IDLE 		0xf8 	// (all modes) Idle

/* Function declarations */
void I2cInit(const uint8_t address);

#endif
