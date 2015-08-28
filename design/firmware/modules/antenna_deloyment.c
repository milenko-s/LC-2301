/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#include "antenna_deployment.h"

void AntennaDeploymentInit(void) 
{
    _ANT_DEPLOY = _OFF;
}

void AntennaDeployment(const uint8_t duration) 
{
	uint32_t delay;

    _ANT_DEPLOY = _ON;

	for (delay = 0; delay < (uint32_t)(duration) * DEPLOY_SEC; delay++);

    _ANT_DEPLOY = _OFF;
}
