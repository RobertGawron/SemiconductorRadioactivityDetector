#include <stdlib.h>
#include <string.h>
#include "gm_display_updater.h"
#include "gm_circular_buffer.h"
#include "gm_dose_counter.h"
#include "gm_display_hw.h"
#include "gm_display_labels.h"

static const uint16_t DisplayUpdater_LCDHeightBlue = 48u;
static const uint16_t DisplayUpdater_LCDHeightYellow = 16u;
//static const uint16_t DisplayUpdater_LCDWidth = 128u;


#define LABEL_DOSE_LENGTH 16U
char labelDose[LABEL_DOSE_LENGTH];

// used on startup
static void GMDisplayUpdater_PrintInitialLaoyout();

// used in normal mode
static void GMDisplayUpdater_PrintDoseLabel();
static void GMDisplayUpdater_PrintBargraph();

void GMDisplayUpdater_Init()
{
    GMDisplayHW_Init();

    GMDisplayUpdater_PrintInitialLaoyout();
    GMDisplayHW_Update();
}

void GMDisplayUpdater_Update()
{
    GMDisplayHW_Clean();
    GMDisplayUpdater_PrintDoseLabel();
    GMDisplayUpdater_PrintBargraph();
    GMDisplayHW_Update();
}

static void GMDisplayUpdater_PrintInitialLaoyout()
{
    GMDisplayHW_DrawText(0, DisplayUpdater_LCDHeightYellow,  (char*)labeWelcomeTop);
    GMDisplayHW_DrawText(0, DisplayUpdater_LCDHeightYellow + 10U, (char*)labeWelcomeBottom);
}

static void GMDisplayUpdater_PrintDoseLabel()
{
	GMMeasurement_Value_t latestSampleValue;
    uint16_t latestSampleIndex = 0U;
    GMCircularBuffer_GetElementStatus_t status = GMCircularBuffer_GetElement(&latestSampleValue, latestSampleIndex);

    uint16_t stringOffset = 0U;

    if (status == GMCIRCULARBUFFER_GETELEMENT_OK)
    {
        // TODO check string size to avoid buffer overflow

        uint16_t base = 10;
        itoa(latestSampleValue, &labelDose[stringOffset], base);

        stringOffset = strlen(labelDose);
        strcpy(&labelDose[stringOffset], labelMinuteCounter);
#if 0
        uint16_t dosage = GMDoseCounter_Calculate();
        stringOffset = strlen(labelDose);
        itoa(dosage, &labelDose[stringOffset], base);

        stringOffset = strlen(labelDose);
        strcpy(&labelDose[stringOffset], labelDosageUnit);
#endif
    }
    else
    {
        strcpy(&labelDose[stringOffset], labelError);
    }

    GMDisplayHW_DrawText(0, 0, labelDose);
}


static void GMDisplayUpdater_PrintBargraph()
{
	GMMeasurement_Value_t maxValue = 0u;
	GMCircularBuffer_GetMaxElement(&maxValue);
	#warning "check return value"

    for(uint16_t i = 0; i < GMCircularBuffer_GetElementCount() ; i++)
    {
    	GMMeasurement_Value_t sampleValue;
        uint16_t indexInBuffer = (uint16_t)(GMCircularBuffer_GetElementCount() - (i + 1U));
        GMCircularBuffer_GetElementStatus_t status = GMCircularBuffer_GetElement(&sampleValue, indexInBuffer);

        if(status == GMCIRCULARBUFFER_GETELEMENT_OK)
        {
            const uint16_t DisplayUpdater_LCDHeight = (DisplayUpdater_LCDHeightBlue + DisplayUpdater_LCDHeightYellow);

            uint16_t y0 = DisplayUpdater_LCDHeight;

            uint16_t graphHeight = DisplayUpdater_LCDHeightBlue;
            uint16_t  normalizedSampleValue = (uint16_t)( ((float)(sampleValue) / (float)(maxValue)) * graphHeight);
            uint16_t y1 = (uint16_t)(DisplayUpdater_LCDHeight - normalizedSampleValue);

            GMDisplayHW_DrawLine(i, y0, i, y1);
        }
    }
}
