#ifndef GMLOGGERHW_H_
#define GMLOGGERHW_H_

#include <stdint.h>

// this file wraps hardware related stuff of the logger (uart)

void GMLoggerHW_Init();

void GMLoggerHW_LogData(uint8_t* buffer, uint16_t size);

#endif
