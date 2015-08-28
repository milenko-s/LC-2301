/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#include "high_power_amplifier.h"

void HpaInit(void) 
{
    HPAM_EN 	= OFF;
	_HPA_ON = _OFF;
}

void HpaState(const uint8_t state) 
{
	uint32_t i;

	if (state == ON) 		
	{
		_HPA_ON = _ON;
		/* This delay is needed to make sure that HPA is first powered and THEN enabled */
		for (i = 0; i < 100000; i++);
		HPAM_EN = ON;
	}
	else if (state == OFF) 	
	{
		HPAM_EN = OFF;
		_HPA_ON = _OFF;
	}
}
