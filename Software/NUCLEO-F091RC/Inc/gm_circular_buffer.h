#ifndef GMCIRCULAR_BUFFER_H_
#define GMCIRCULAR_BUFFER_H_

#include <stdbool.h>
#include "gm_measurement.h"

typedef enum GMCircularBuffer_GetElementStatus_t
{
    GMCIRCULARBUFFER_GETELEMENT_OK = 0
    , GMCIRCULARBUFFER_GETELEMENT_INDEX_OUT_OF_RANGE
} GMCircularBuffer_GetElementStatus_t;

typedef enum GMCircularBuffer_GetMaxElementStatus_t
{
    GMCIRCULARBUFFER_GETMAXELEMENT_OK = 0
    , GMCIRCULARBUFFER_GETMAXELEMENT_NO_MEASSUREMENTS
} GMCircularBuffer_GetMaxElementStatus_t;

void GMCircularBuffer_Init();

uint16_t GMCircularBuffer_GetElementCount();

void GMCircularBuffer_Insert(GMMeasurement_Value_t element);

GMCircularBuffer_GetElementStatus_t GMCircularBuffer_GetElement(GMMeasurement_Value_t *element, uint16_t index);

GMCircularBuffer_GetMaxElementStatus_t GMCircularBuffer_GetMaxElement(GMMeasurement_Value_t* element);

#endif
