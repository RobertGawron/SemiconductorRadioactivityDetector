#include "gm_measurement_calculator.h"
#include "gm_circular_buffer.h"
#include "gm_measurement.h"

static volatile GMMeasurement_Value_t occurenceCounter;

void GMMeasurementCalculator_Init()
{
    GMCircularBuffer_Init();
    occurenceCounter = 0U;
}

void GMMeasurementCalculator_OnSamplingDone()
{
    GMCircularBuffer_Insert(occurenceCounter);

    // reset counter to start from the beginning for the new sample
    occurenceCounter = 0;
}

void GMMeasurementCalculator_OnGMPulseObserved()
{
    if (occurenceCounter < SAMPLE_STORAGE_ELEMENT_MAX_VALUE)
    {
        occurenceCounter++;
    }
}
