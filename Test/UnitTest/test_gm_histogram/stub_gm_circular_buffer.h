#ifndef STUBGMCIRCULAR_BUFFER_H_
#define STUBGMCIRCULAR_BUFFER_H_

#include <stdint.h>
#include "gm_measurement.h"

void StubGMCircularBuffer_Reset();

void StubGMCircularBuffer_SetElementCount(uint16_t value);

void StubGMCircularBuffer_SetElement(GMMeasurement_Value_t value);

void StubGMCircularBuffer_SetMinMaxElement(GMMeasurement_Value_t minElement, GMMeasurement_Value_t maxElement);

#endif