#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "gm_view_histogram.h"
#include "gm_display_hw.h"
#include "gm_histogram.h"
#include "gm_circular_buffer.h"
#include "gm_measurement.h"
#include "gm_display_labels.h"

static void GMViewHistogram_ShowHistogramLabel();
static void GMViewHistogram_ShowHistogram();

static const uint8_t histogramBinAmount = 128;

// TOD move it somewhere
static const uint16_t DisplayUpdater_LCDHeightBlue = 48u;
static const uint16_t DisplayUpdater_LCDHeightYellow = 16u;
//static const uint16_t DisplayUpdater_LCDWidth = 128u;

void GMViewHistogram_Init()
{

}

void GMViewHistogram_Show()
{
    GMViewHistogram_ShowHistogram();
    GMViewHistogram_ShowHistogramLabel();
}

void GMViewHistogram_ShowHistogram()
{
    const uint8_t binWidthOnDisplay = GMDisplayHW_GetDisplayWidth() / histogramBinAmount;

    uint8_t graphHeight = DisplayUpdater_LCDHeightBlue;
    uint16_t maxBinValue = GMHistogram_GetMaxBinValue(histogramBinAmount);

    if (maxBinValue > 0u)
    {
        uint8_t x0 = 0;
        
        for (uint16_t i = 0U; i < histogramBinAmount; i++)
        {
            uint16_t binValue = GMHistogram_GetBinValue(i, histogramBinAmount);
            uint32_t normalizedBinValue = binValue * graphHeight/ maxBinValue;

            uint8_t x1 = binWidthOnDisplay - 1; // one pixel to avoid overlap
            GMDisplayHW_DrawRectangle(x0, GMDisplayHW_GetDisplayHeight()-normalizedBinValue, x1, GMDisplayHW_GetDisplayHeight());

            x0 += binWidthOnDisplay;
        }
    }
}

void GMViewHistogram_ShowHistogramLabel()
{
    GMMeasurement_Value_t minElement = 0u;
    GMMeasurement_Value_t maxElement = 0u;
    GMCircularBuffer_GetElementStatus_t status = GMCircularBuffer_GetMinMaxElement(&minElement, &maxElement);

    const size_t LABEL_DOSE_LENGTH = 16U;
    char histogramLabel[LABEL_DOSE_LENGTH];

    uint16_t stringOffset = 0U;  

    if (status == GMCIRCULARBUFFER_GETELEMENT_OK)
    {
        const uint16_t base = 10;
        
        strcpy(&histogramLabel[stringOffset], "pulse:");
        stringOffset = strlen(histogramLabel);

        itoa(minElement, &histogramLabel[stringOffset], base);
        stringOffset = strlen(histogramLabel);

        strcpy(&histogramLabel[stringOffset], "-");
        stringOffset = strlen(histogramLabel);

        itoa(maxElement, &histogramLabel[stringOffset], base);
        stringOffset = strlen(histogramLabel);

        strcpy(&histogramLabel[stringOffset], "cpm");
    }
    else
    {
        strcpy(&histogramLabel[stringOffset], labelError);
    }

    GMDisplayHW_DrawText(0, 0, histogramLabel);
}
