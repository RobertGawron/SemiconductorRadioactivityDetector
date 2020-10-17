#ifndef SSD1306I2CSIM_H_
#define SSD1306I2CSIM_H_

#include <stdint.h>

uint8_t SSD1306I2CSIM_GetDisplayLength();
uint8_t SSD1306I2CSIM_GetDisplayHeight();
uint8_t* SSD1306I2CSIM_GetDisplayContent();

#endif
