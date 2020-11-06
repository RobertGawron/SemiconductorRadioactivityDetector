#include "gm_measurement_calculator.h"
#include "gm_circular_buffer.h"
#include "gm_measurement.h"

static volatile GMMeasurement_Value_t occurrenceCounter;

void GMMeasurementCalculator_Init()
{
    GMCircularBuffer_Init();
    occurrenceCounter = 0U;
}

void GMMeasurementCalculator_OnSamplingDone()
{
    GMCircularBuffer_Insert(occurrenceCounter);

    // reset counter to start from the beginning for the new sample
    occurrenceCounter = 0;
}

void GMMeasurementCalculator_OnGMPulseObserved()
{
    if (occurrenceCounter < SAMPLE_STORAGE_ELEMENT_MAX_VALUE)
    {
        occurrenceCounter++;
    }
}
