/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#include "low_noise_amplifier.h"

void LnaInit(void) 
{
	_LNA_ON = _ON;
}

void LnaState(const uint8_t state) 
{
	if (state) 		
	{
		_LNA_ON = _ON;
	}
	else 	
	{
		_LNA_ON = _OFF;
	}
}

