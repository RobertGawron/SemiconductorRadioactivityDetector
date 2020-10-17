#include "gm_circular_buffer.h"
#include "gm_circular_buffer_length.h"


typedef struct gm_circular_buffer_t
{
    GMMeasurement_Value_t data[GM_CIRCULAR_BUFFER_MAX_ELEMENTS];

    uint16_t indexOfNextToInsert;
    uint16_t elementsInBuffer;
} gm_circular_buffer_t;

static gm_circular_buffer_t buffer;

void GMCircularBuffer_Init()
{
    buffer.indexOfNextToInsert = 0;
    buffer.elementsInBuffer = 0;
}

uint16_t GMCircularBuffer_GetElementCount()
{
    return buffer.elementsInBuffer;
}

void GMCircularBuffer_Insert(GMMeasurement_Value_t element)
{
    buffer.data[buffer.indexOfNextToInsert] = element;

    buffer.indexOfNextToInsert++;
    buffer.indexOfNextToInsert %= GM_CIRCULAR_BUFFER_MAX_ELEMENTS;

    if(buffer.elementsInBuffer < GM_CIRCULAR_BUFFER_MAX_ELEMENTS)
    {
        buffer.elementsInBuffer++;
    }
}

// Index is counted up from most recently inserted element, 
// where 0 is index of the latest element, 1 is index of previous one etc.
// Function will will return false on error, e.g. index is bigger than the buffer size
// TODO: use enum instead of bool as return value
GMCircularBuffer_GetElementStatus_t GMCircularBuffer_GetElement(GMMeasurement_Value_t* element, uint16_t index)
{
    GMCircularBuffer_GetElementStatus_t retValue = GMCIRCULARBUFFER_GETELEMENT_INDEX_OUT_OF_RANGE;

    if(index < GM_CIRCULAR_BUFFER_MAX_ELEMENTS)
    {
        int16_t localIndex = (int16_t)( (int16_t)(buffer.indexOfNextToInsert - 1) - (int16_t)index );
        if(localIndex < 0)
        {
            localIndex = (int16_t)(GM_CIRCULAR_BUFFER_MAX_ELEMENTS + localIndex);
        }

        *element = buffer.data[localIndex];
        retValue = GMCIRCULARBUFFER_GETELEMENT_OK;
    }
    else
    {
        element = 0;
        retValue = GMCIRCULARBUFFER_GETELEMENT_INDEX_OUT_OF_RANGE;
    }

    return retValue;
}


GMCircularBuffer_GetMinMaxElementStatus_t GMCircularBuffer_GetMinMaxElement(GMMeasurement_Value_t* minElement, GMMeasurement_Value_t* maxElement)
{
    GMCircularBuffer_GetMinMaxElementStatus_t retValue = GMCIRCULARBUFFER_GETMINMAXELEMENT_NO_MEASSUREMENTS;

    if(GMCircularBuffer_GetElementCount() != 0u)
    {
        GMCircularBuffer_GetElement(minElement, 0);
        GMCircularBuffer_GetElement(maxElement, 0);

        for(uint16_t i = 0; i < GMCircularBuffer_GetElementCount(); i++)
        {
            GMMeasurement_Value_t currentElement;
            GMCircularBuffer_GetElementStatus_t status = GMCircularBuffer_GetElement(&currentElement, i);

            if(status == GMCIRCULARBUFFER_GETELEMENT_OK)
            {
                if(currentElement < *minElement)
                {
                    *minElement = currentElement;
                }
                if(currentElement > *maxElement)
                {
                    *maxElement = currentElement;
                }            
            }
        }

        retValue = GMCIRCULARBUFFER_GETMINMAXELEMENT_OK;
    }
    else
    {
        // no elements in buffer, so counting max element is pointless
        minElement = 0;
        maxElement = 0;
        retValue = GMCIRCULARBUFFER_GETMINMAXELEMENT_NO_MEASSUREMENTS;
    }

    return retValue;
}
