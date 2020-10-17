#include <stdint.h>
#include "utest.h"
#include "gm_histogram.h"
#include "stub_gm_circular_buffer.h"

UTEST(GMHistogram_GetBinValue, Set_One_Bin_Different_Meassurements_Expect_All_Meassurements_In_It) 
{
    uint8_t binIndex;
    uint8_t totalBinAmount;
    uint16_t binValue;

    StubGMCircularBuffer_Reset();
    StubGMCircularBuffer_SetElement(1);
    StubGMCircularBuffer_SetElement(2);
    StubGMCircularBuffer_SetElement(3);
    StubGMCircularBuffer_SetElementCount(3);
    StubGMCircularBuffer_SetMinMaxElement(1, 3);

    binIndex = 0;
    totalBinAmount = 1;

    binValue = GMHistogram_GetBinValue(binIndex, totalBinAmount);

    EXPECT_EQ(3, binValue);
}

UTEST(GMHistogram_GetBinValue, Set_One_Bin_Same_Meassurements_Expect_All_Meassurements_In_It) 
{
    uint8_t binIndex;
    uint8_t totalBinAmount;
    uint16_t binValue;

    StubGMCircularBuffer_Reset();
    StubGMCircularBuffer_SetElement(2);
    StubGMCircularBuffer_SetElement(2);
    StubGMCircularBuffer_SetElement(2);
    StubGMCircularBuffer_SetElementCount(3);
    StubGMCircularBuffer_SetMinMaxElement(2, 2);

    binIndex = 0;
    totalBinAmount = 1;

    binValue = GMHistogram_GetBinValue(binIndex, totalBinAmount);

    EXPECT_EQ(3, binValue);
}

UTEST(GMHistogram_GetBinValue, Set_Two_Bins_Same_Meassurements_Expect_All_Meassurements_In_It) 
{
    uint8_t binIndex;
    uint8_t totalBinAmount;
    uint16_t binValue;

    StubGMCircularBuffer_Reset();
    StubGMCircularBuffer_SetElement(2);
    StubGMCircularBuffer_SetElement(2);
    StubGMCircularBuffer_SetElement(2);
    StubGMCircularBuffer_SetElementCount(3);
    StubGMCircularBuffer_SetMinMaxElement(2, 2);

    binIndex = 0;
    totalBinAmount = 2;

    binValue = GMHistogram_GetBinValue(binIndex, totalBinAmount);

    EXPECT_EQ(3, binValue);

    binIndex = 1;
    totalBinAmount = 2;

    binValue = GMHistogram_GetBinValue(binIndex, totalBinAmount);

    EXPECT_EQ(0, binValue);
}

UTEST(GMHistogram_GetBinValue, Set_Two_Bins_Different_Meassurements_Expect_Different_Bin_Values) 
{
    uint8_t binIndex;
    uint8_t totalBinAmount;
    uint16_t binValue;

    StubGMCircularBuffer_Reset();
    StubGMCircularBuffer_SetElement(1);
    StubGMCircularBuffer_SetElement(3);
    StubGMCircularBuffer_SetElement(300);
    StubGMCircularBuffer_SetElement(3);
    StubGMCircularBuffer_SetElementCount(4);
    StubGMCircularBuffer_SetMinMaxElement(1, 300);

    binIndex = 0;
    totalBinAmount = 2;

    binValue = GMHistogram_GetBinValue(binIndex, totalBinAmount);

    EXPECT_EQ(3, binValue);


    binIndex = 1;
    totalBinAmount = 2;

    binValue = GMHistogram_GetBinValue(binIndex, totalBinAmount);

    EXPECT_EQ(1, binValue);
}

UTEST(GMHistogram_GetMaxBinValue, Set_Two_Bins_Different_Meassurements_Expect_Max_Bin_Value) 
{
    uint8_t totalBinAmount;
    uint8_t maxBinValue;

    StubGMCircularBuffer_Reset();
    StubGMCircularBuffer_SetElement(1);
    StubGMCircularBuffer_SetElement(3);
    StubGMCircularBuffer_SetElement(3);
    StubGMCircularBuffer_SetElement(3);
    StubGMCircularBuffer_SetElementCount(4);
    StubGMCircularBuffer_SetMinMaxElement(1, 3);

    totalBinAmount = 2;

    maxBinValue = GMHistogram_GetMaxBinValue(totalBinAmount);

    EXPECT_EQ(4, maxBinValue);
}


UTEST_MAIN();
