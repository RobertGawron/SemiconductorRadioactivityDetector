#include "gm_display_hw.h"
#include "ssd1306.h"
#include "fonts.h"

void GMDisplayHW_Init()
{
    (void)SSD1306_Init();
}

void GMDisplayHW_Clean()
{
    SSD1306_Fill(0);
}

void GMDisplayHW_Update()
{
    SSD1306_UpdateScreen();
}

void GMDisplayHW_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    SSD1306_DrawLine(x0, y0, x1, y1, SSD1306_COLOR_WHITE);
}

void GMDisplayHW_DrawText(uint16_t x0, uint16_t y0, char* str)
{
    SSD1306_GotoXY (x0, y0);
    SSD1306_Puts (str, &Font_7x10, 1);
}
