#include "gm_keyboard.h"
#include "gm_display_updater.h"

void GMKeyboard_Init()
{

}


void GMKeyboard_OnKeyPressDetection(GMKeyboardKeys_Key_t key)
{
    GMDisplayUpdater_ReactOnKeyPress(key);
}