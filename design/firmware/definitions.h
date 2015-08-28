/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	DEFINITIONS_H
#define DEFINITIONS_H

/* Type definitions */
typedef signed char				int8_t;
typedef short int 				int16_t;
typedef long int 				int32_t;
typedef unsigned char 			uint8_t;
typedef unsigned short int		uint16_t;
typedef unsigned long int		uint32_t;

/* General definitions */
#define SET						1
#define CLEAR					0
#define ON						1
#define OFF						0
#define _ON						0
#define _OFF					1
#define PASS					1
#define FAIL 					0
#define HIGH					1
#define LOW 					0

/* Configuration */
#define I2C_ADR					0x13
#define HK_PERIOD				10		/* yields 1 second refresh rate */
#define DEPLOY_DURATION			5		/* seconds */
#define TC_FIFO					0		/* logical telecommand fifo start address in memory */
#define TM_FIFO					1		/* logical telemetry fifo start address in memory */ 

/* Register structure */
typedef struct Register 
{
	/* Main section */
	uint8_t null; 
	uint8_t cmd;

	/* Settings section */
	uint8_t hkperiod;
	union 
	{
		struct
		{
			uint8_t temp:1;				/* bit 0 */
			uint8_t rssi:1;
			uint8_t unused:6;
		};
		uint8_t byte;
	} measure;

    uint8_t tm_power;
	uint8_t frx_l;
	uint8_t frx_m;
	uint8_t frx_h;
	uint8_t ftx_l;
	uint8_t ftx_m;
	uint8_t ftx_h;
	uint8_t fsep_l;
	uint8_t fsep_h;

	/* Flags section */
	union  
	{
 		struct
		{
			uint8_t busy:1;
			uint8_t complete:1;
			uint8_t sending_tm_data:1;
			uint8_t receiving_tc_data:1;
			uint8_t ant_deloying:1;
			uint8_t rf_bitlock:1;
			uint8_t tx_enabled:1;
			uint8_t tx_on:1;
		};
		uint8_t byte;
	} flag;

	/* Values section */
	uint8_t mcutemp_l;
	uint8_t mcutemp_h;
	uint8_t hpatemp_l;
	uint8_t hpatemp_h;
	uint8_t rssi_l;
	uint8_t rssi_h;
	uint8_t tc_byte_count_l;
    uint8_t tc_byte_count_m;  	
    uint8_t tc_byte_count_h;
    uint8_t tm_byte_count_l;
    uint8_t tm_byte_count_m;    
    uint8_t tm_byte_count_h;    
   
} Register_t;

/* Register numbering (only needed for writable registers) */
#define REG_CMD					1
#define REG_HKPERIOD			2
#define REG_MEASURE				3

/* Command OpCodes */
#define CMD_RESET				0x01
#define CMD_MEASURE				0x02
#define CMD_UPDATE_TRX			0x03
#define CMD_DEPLOY_ANT			0x04
#define CMD_TX_ENABLE			0x05
#define CMD_TX_DISABLE			0x06            

#endif
