#include "gm_logger_hw.h"

#include <stdio.h>
#include <string.h>

#define GMLOGGERSIM_LOGGER_BUFFER_LEN 256

typedef struct GMLoggerSIM_Buffer_t {
    uint8_t data[GMLOGGERSIM_LOGGER_BUFFER_LEN];
    uint16_t size;
} GMLoggerSIM_Buffer_t;

static GMLoggerSIM_Buffer_t GMLoggerSIM_buffer;

void GMLoggerHW_Init()
{
    GMLoggerSIM_buffer.data[0] = '\0';
    GMLoggerSIM_buffer.size = 0u;
}

void GMLoggerHW_LogData(uint8_t* buffer, uint16_t size)
{
    size_t amountOfData = size  *sizeof(GMLoggerSIM_buffer.data[0]);
    memcpy((void*)&GMLoggerSIM_buffer.data[0], (void*)buffer, amountOfData);
    GMLoggerSIM_buffer.size = size;
}


void GMLoggerSIM_GetLoggedData(uint8_t** buffer, uint16_t* size)
{
    *buffer = &GMLoggerSIM_buffer.data[0];
    *size = GMLoggerSIM_buffer.size;
}
