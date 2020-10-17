#include "gm_histogram.h"
#include "gm_circular_buffer.h"
#include "gm_measurement.h"

// binIndex is zero-base numbered
uint16_t GMHistogram_GetBinValue(uint8_t binIndex, uint8_t totalBinAmount)
{
    uint16_t binValue = 0u;

    GMMeasurement_Value_t minElement = 0u;
    GMMeasurement_Value_t maxElement = 0u;
    GMCircularBuffer_GetMinMaxElement(&minElement, &maxElement);
    // TODO check return value

    // TODO +1 is to avoid overlap, I don't know how it works
    GMMeasurement_Value_t binLength = (maxElement - minElement) / totalBinAmount + 1; 

    GMMeasurement_Value_t elementOfBinMinValue = minElement + binLength * binIndex;
    GMMeasurement_Value_t elementOfBinMaxValue = elementOfBinMinValue + binLength;

#if DEBUG_PRINTS_ENABLED
    printf("\tminElement: %d \n\tmaxElement: %d \n\tbinLength %d \n\telementOfBinMinValue: %d \n\telementOfBinMaxValue %d\n\n" 
        , minElement
        , maxElement
        , binLength 
        , elementOfBinMinValue 
        , elementOfBinMaxValue);
#endif

    for(uint16_t j = 0u; j < GMCircularBuffer_GetElementCount(); j++)
    {
        GMMeasurement_Value_t sampleValue; 
        GMCircularBuffer_GetElement(&sampleValue, j);

        if ((sampleValue >= elementOfBinMinValue) && (sampleValue <= elementOfBinMaxValue))
        {
            binValue++;
        }
    }

    return binValue;
}

uint16_t GMHistogram_GetMaxBinValue(uint8_t totalBinAmount)
{
    uint16_t maxBinValue = 0u;

    for (uint16_t i = 0u; i < totalBinAmount; i++)
    {
        uint16_t currentBinValue = GMHistogram_GetBinValue(i, totalBinAmount);

        if(currentBinValue > maxBinValue)
        {
            maxBinValue = currentBinValue;
        }
    }

    return maxBinValue;
}