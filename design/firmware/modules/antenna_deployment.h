/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#ifndef	ANTENNA_DEPLOYMENT_H
#define ANTENNA_DEPLOYMENT_H

/* Includes */
#include "c8051f120.h"
#include "../definitions.h"
#include "microcontroller.h"

/* Settings */
#define DEPLOY_SEC		30000UL /* yields roughly one second */

/* Function declarations */
void AntennaDeploymentInit(void);
void AntennaDeployment(const uint8_t duration); 

#endif
