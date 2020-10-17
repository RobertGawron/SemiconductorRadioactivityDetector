#ifndef GMHISTOGRAM_H_
#define GMHISTOGRAM_H_

#include <stdint.h>

uint16_t GMHistogram_GetBinValue(uint8_t binIndex, uint8_t totalBinAmount);
uint16_t GMHistogram_GetMaxBinValue(uint8_t totalBinAmount);

#endif
