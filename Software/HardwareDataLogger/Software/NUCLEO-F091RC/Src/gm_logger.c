#include <stdlib.h>
#include <string.h>

#include "gm_logger.h"
#include "gm_logger_hw.h"
#include "gm_measurement.h"
#include "gm_circular_buffer.h"


#define TX_BUFFER_SIZE 10
uint8_t txBuffer[TX_BUFFER_SIZE];

void GMLogger_Init()
{

}

void GMLogger_LogMeasurement()
{
    GMMeasurement_Value_t latestMeasurement;
    // TODO check return value
    GMCircularBuffer_GetElement(&latestMeasurement, 0);

    uint16_t base = 10;
    itoa(latestMeasurement, (char*)&txBuffer[0], base);
    uint16_t logLength = strlen((char*)txBuffer);

    txBuffer[logLength++] = '\r';
    txBuffer[logLength++] = '\n';
    txBuffer[logLength++] = '\0';

    GMLoggerHW_LogData(&txBuffer[0], logLength);
}
