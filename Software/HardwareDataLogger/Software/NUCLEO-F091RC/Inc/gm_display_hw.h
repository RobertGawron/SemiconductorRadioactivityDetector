#ifndef GMDISPLAY_HW_H_
#define GMDISPLAY_HW_H_

// this file wraps hardware related stuff of the display

#include <stdint.h>

void GMDisplayHW_Init();

void GMDisplayHW_Clean();

void GMDisplayHW_Update();

void GMDisplayHW_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

void GMDisplayHW_DrawRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

void GMDisplayHW_DrawText(uint16_t x0, uint16_t y0, char* str);

uint8_t GMDisplayHW_GetDisplayWidth();

uint8_t GMDisplayHW_GetDisplayHeight();

#endif