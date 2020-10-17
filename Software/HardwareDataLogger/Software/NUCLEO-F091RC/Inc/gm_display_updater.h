#ifndef GMDISPLAY_UPDATER_H_
#define GMDISPLAY_UPDATER_H_

#include "gm_keyboard_keys.h"

void GMDisplayUpdater_Init();
void GMDisplayUpdater_UpdateMeasurements();
void GMDisplayUpdater_ReactOnKeyPress(GMKeyboardKeys_Key_t key);

#endif
