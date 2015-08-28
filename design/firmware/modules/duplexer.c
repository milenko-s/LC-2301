/* ---------------------------------------
 * LibreCube LC-2301a Communication System
 * ---------------------------------------
 */

#include "duplexer.h"

void DuplexerInit(void)
{
    DuplexerState(DUPLEXER_SELECT_RX);
}

void DuplexerState(const uint8_t state)
{
    if (state == DUPLEXER_SELECT_RX)
    {
        DUPLEX_TX = 0;
        DUPLEX_RX = 1;
    }
    else if (state == DUPLEXER_SELECT_TX)
    {
        DUPLEX_TX = 1;
        DUPLEX_RX = 0;
    }
}
