#include "gm_circular_buffer.h"
#include "stub_gm_circular_buffer.h"

#define MAX_ELEMENTS 5000u

static StubGMCircularBuffer_ElementCount;
static GMMeasurement_Value_t StubGMCircularBuffer_MinElement;
static GMMeasurement_Value_t StubGMCircularBuffer_MaxElement;
static GMMeasurement_Value_t StubGMCircularBuffer_Elements[MAX_ELEMENTS];
static uint16_t StubGMCircularBuffer_ElementsAmount = 0u;

void GMCircularBuffer_Init()
{

}

uint16_t GMCircularBuffer_GetElementCount()
{
    return StubGMCircularBuffer_ElementCount;
}

void GMCircularBuffer_Insert(GMMeasurement_Value_t element)
{

}

GMCircularBuffer_GetElementStatus_t GMCircularBuffer_GetElement(GMMeasurement_Value_t *element, uint16_t index)
{
    *element = StubGMCircularBuffer_Elements[index];
}

GMCircularBuffer_GetMinMaxElementStatus_t GMCircularBuffer_GetMinMaxElement(GMMeasurement_Value_t* minElement, GMMeasurement_Value_t* maxElement)
{
    *minElement = StubGMCircularBuffer_MinElement;
    *maxElement = StubGMCircularBuffer_MaxElement;
}


void StubGMCircularBuffer_Reset()
{
    StubGMCircularBuffer_ElementsAmount = 0u;
}

void StubGMCircularBuffer_SetElementCount(uint16_t value)
{
    StubGMCircularBuffer_ElementCount = value;
}

void StubGMCircularBuffer_SetElement(GMMeasurement_Value_t value)
{
    StubGMCircularBuffer_Elements[StubGMCircularBuffer_ElementsAmount++] = value;
}

void StubGMCircularBuffer_SetMinMaxElement(GMMeasurement_Value_t minElement, GMMeasurement_Value_t maxElement)
{
    StubGMCircularBuffer_MinElement = minElement;
    StubGMCircularBuffer_MaxElement = maxElement;
}
