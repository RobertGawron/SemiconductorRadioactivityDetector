#include "ssd1306.h"
#include "ssd1306_i2c_sim.h"

#define SSD1306I2CSIM_DisplayLength SSD1306_WIDTH
#define SSD1306I2CSIM_DisplayHeight SSD1306_HEIGHT

#define BUFFER_LLENGTH (SSD1306_WIDTH * SSD1306_HEIGHT / 8)
uint8_t SSD1306_Buffer[BUFFER_LLENGTH]; // originated from ssd1306.h

uint8_t SSD1306_Init() 
{
    memset(&SSD1306_Buffer[0], 0u, BUFFER_LLENGTH);
    return 0u;
}

void ssd1306_I2C_WriteMulti(uint8_t address, uint8_t reg, uint8_t* data, uint16_t count) 
{
}


void ssd1306_I2C_Write(uint8_t address, uint8_t reg, uint8_t data) 
{
}



uint8_t SSD1306I2CSIM_GetDisplayLength()
{
    return SSD1306I2CSIM_DisplayLength;
}

uint8_t SSD1306I2CSIM_GetDisplayHeight()
{
    return SSD1306I2CSIM_DisplayHeight;
}

uint8_t* SSD1306I2CSIM_GetDisplayContent()
{
   return &SSD1306_Buffer[0];
}
