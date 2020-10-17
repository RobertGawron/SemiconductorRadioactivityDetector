#include "gm_logger_hw.h"
#include "stm32f0xx_hal.h"

extern UART_HandleTypeDef huart2; // auto-generated in main.c

void GMLoggerHW_Init()
{

}

void GMLoggerHW_LogData(uint8_t* buffer, uint16_t size)
{
    HAL_UART_Transmit(&huart2, buffer, size, 0xFFFF);
}