/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#include "i2c.h"

void I2cInit(const uint8_t address)
{
    SFRPAGE = SMB0_PAGE;
    AA = 1;
    SMB0ADR = (address << 1);
}
