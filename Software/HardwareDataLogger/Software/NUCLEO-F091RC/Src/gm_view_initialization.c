#include "gm_view_initialization.h"
#include "gm_display_hw.h"
#include "gm_display_labels.h"

#include <stdint.h>

// TOD move it somewhere
static const uint16_t DisplayUpdater_LCDHeightBlue = 48u;
static const uint16_t DisplayUpdater_LCDHeightYellow = 16u;
//static const uint16_t DisplayUpdater_LCDWidth = 128u;



void GMViewInitialization_Init()
{

}

void GMViewInitialization_Show()
{
    GMDisplayHW_Clean();
    GMDisplayHW_DrawText(0, DisplayUpdater_LCDHeightYellow,  (char*)labeWelcomeTop);
    GMDisplayHW_DrawText(0, DisplayUpdater_LCDHeightYellow + 10U, (char*)labeWelcomeBottom);
}
