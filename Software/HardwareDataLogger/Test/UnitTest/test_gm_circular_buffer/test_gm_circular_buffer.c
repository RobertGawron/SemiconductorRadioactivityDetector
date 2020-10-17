#include <stdint.h>
#include "utest.h"
#include "gm_circular_buffer.h"
#include "gm_circular_buffer_length.h"


UTEST(GMCircularBuffer_Init, Initialize_Expect_Zero_Elements) 
{
    GMCircularBuffer_Init();
    EXPECT_EQ(GMCircularBuffer_GetElementCount(), 0);
}


UTEST(GMCircularBuffer_Insert, Insert_One_Element_Expect_One_Element_With_Correct_Value) 
{
    GMCircularBuffer_Init(); // reset buffer state

    GMMeasurement_Value_t elementInserted = 0xABCD;
    GMMeasurement_Value_t elementRetreived = 0xFFFF;

    GMCircularBuffer_Insert(elementInserted);
    EXPECT_EQ(GMCircularBuffer_GetElementCount(), 1);

    GMCircularBuffer_GetElementStatus_t isRetreiveOK = GMCircularBuffer_GetElement(&elementRetreived, 0);
    EXPECT_EQ(isRetreiveOK, GMCIRCULARBUFFER_GETELEMENT_OK);
    EXPECT_EQ(elementRetreived, elementInserted);
}


UTEST(GMCircularBuffer_Insert, Insert_Max_Amount_Of_Elements_Expect_Correct_Order_And_Correct_Value) 
{
    GMCircularBuffer_Init(); // reset buffer state

    const size_t MEASSUREMENTS_AMOUNT = GM_CIRCULAR_BUFFER_MAX_ELEMENTS;
    GMMeasurement_Value_t measurementIn[MEASSUREMENTS_AMOUNT];

    // generate meassurements, each sample is different
    for(uint16_t i = 0; i < MEASSUREMENTS_AMOUNT; i++)
    {
        // zero is tricky in test, could be returned as default value
        // its good to avoid it, so I will start test data values from 
        // arbitrary value that is 100
        measurementIn[i] = i + 100;
    }

    // insert meassurements, each time check if it was added
    for (uint16_t i = 0; i < GM_CIRCULAR_BUFFER_MAX_ELEMENTS; i++)
    {
        uint16_t expectedAmountOfElements = (i + 1);

        GMCircularBuffer_Insert(measurementIn[i]);
        EXPECT_EQ(GMCircularBuffer_GetElementCount(), expectedAmountOfElements);
    }

    // check order of meassurements
    for (uint16_t i = 0; i < GM_CIRCULAR_BUFFER_MAX_ELEMENTS; i++)
    {
        GMMeasurement_Value_t elementRetreived = 0xFFFF;

        uint16_t indexOfMeassurementInOriginalMeassurementSet = ((GM_CIRCULAR_BUFFER_MAX_ELEMENTS - 1)- i);

        GMCircularBuffer_GetElementStatus_t isRetreiveOK = GMCircularBuffer_GetElement(&elementRetreived, i);

        EXPECT_EQ(isRetreiveOK, GMCIRCULARBUFFER_GETELEMENT_OK);
        EXPECT_EQ(measurementIn[indexOfMeassurementInOriginalMeassurementSet], elementRetreived);
    }
}

UTEST(GMCircularBuffer_Insert, Insert_More_Than_Max_Amount_Of_Elements_Expect_Correct_Order_And_Correct_Value) 
{
    #warning ""missing implementation"
}

UTEST(GMCircularBuffer_GetMaxElement, TODO) 
{
    #warning ""missing implementation"
}

UTEST_MAIN();
