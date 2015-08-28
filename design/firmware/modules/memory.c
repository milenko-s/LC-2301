/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#include "memory.h"

void MemInit(void)
{
    _MEM_CE = _OFF;
    _MEM_WE = _OFF;
    _MEM_OE = _OFF;
}

uint8_t MemRead(const uint8_t adr_h, const uint8_t adr_m, const uint8_t adr_l)
{
    uint8_t SFRPAGE_SAVE = SFRPAGE;
    uint8_t buffer;
    SFRPAGE = CONFIG_PAGE;
    
    ADDRESS_L = adr_l;
    ADDRESS_M = adr_m;
    ADDRESS_H = adr_h;
    _MEM_CE = _ON;
    _MEM_OE = _ON;
    buffer = DATA;    // read byte from port				
    _MEM_CE = _OFF;
    _MEM_OE = _OFF;
    
    SFRPAGE = SFRPAGE_SAVE;
    return buffer;
}

void MemWrite(const uint8_t adr_h, const uint8_t adr_m, const uint8_t adr_l, const uint8_t value)
{
    uint8_t SFRPAGE_SAVE = SFRPAGE;
    SFRPAGE = CONFIG_PAGE;
    
    P3MDOUT = 0xFF;    // port must be in push-pull
    ADDRESS_L = adr_l;
    ADDRESS_M = adr_m;
    ADDRESS_H = adr_h;
    _MEM_CE = _ON;
    _MEM_WE = _ON;
    DATA = value;    // write byte to port
    _MEM_CE = _OFF;
    _MEM_WE = _OFF;
    P3MDOUT = 0x00;    // port back to open-drain
    DATA = 0xFF;
    
    SFRPAGE = SFRPAGE_SAVE;
}
