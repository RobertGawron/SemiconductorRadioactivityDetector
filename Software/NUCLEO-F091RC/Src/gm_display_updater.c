#include <stdint.h>
#include "gm_display_updater.h"
#include "gm_display_hw.h"
#include "gm_view_initialization.h"
#include "gm_view_histogram.h"
#include "gm_view_bargraph.h"

typedef struct GMDisplayUpdater_View_t
{
    void (*GMDisplayUpdater_Init)(void);
    void (*GMDisplayUpdater_Show)(void);
} GMDisplayUpdater_View_t;

typedef struct GMDisplayUpdater_ViewSelector_t
{
    const GMDisplayUpdater_View_t *views;
    const uint8_t viewsAmount;
    uint8_t currentViewIndex;

} GMDisplayUpdater_ViewSelector_t;

// add new views here
const GMDisplayUpdater_View_t GMDisplayUpdater_Views[] = 
{
    { &GMViewBargraph_Init, &GMViewBargraph_Show }
    , { &GMViewHistogram_Init, &GMViewHistogram_Show }
};

static GMDisplayUpdater_ViewSelector_t GMDisplayUpdater_ViewSelector = { 
    &GMDisplayUpdater_Views[0],
    sizeof(GMDisplayUpdater_Views) / sizeof(GMDisplayUpdater_Views[0]),
    0u
};

void GMDisplayUpdater_Init()
{
    for(uint8_t i = 0u; i < GMDisplayUpdater_ViewSelector.viewsAmount; i++)
    {
        (GMDisplayUpdater_ViewSelector.views[i].GMDisplayUpdater_Init)();
    }

    GMViewInitialization_Init();
    GMViewInitialization_Show();

    GMDisplayHW_Update();
}

void GMDisplayUpdater_UpdateMeasurements()
{
    GMDisplayHW_Clean();

    const uint8_t index = GMDisplayUpdater_ViewSelector.currentViewIndex;
    (GMDisplayUpdater_ViewSelector.views[index].GMDisplayUpdater_Show)();

    GMDisplayHW_Update();
}

void GMDisplayUpdater_ReactOnKeyPress(GMKeyboardKeys_Key_t key)
{
    GMDisplayHW_Clean();

    GMDisplayUpdater_ViewSelector.currentViewIndex++;
    GMDisplayUpdater_ViewSelector.currentViewIndex %= GMDisplayUpdater_ViewSelector.viewsAmount;

    const uint8_t index = GMDisplayUpdater_ViewSelector.currentViewIndex;
    (GMDisplayUpdater_ViewSelector.views[index].GMDisplayUpdater_Show)();

    GMDisplayHW_Update();
}
