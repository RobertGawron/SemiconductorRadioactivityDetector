from ctypes import *
from ctypes.wintypes import *
import os.path

class DeviceUnderTest:
    def __init__(self):
        dll_name = "simulation.so"
        dllabspath = os.path.dirname(os.path.abspath(os.path.abspath(__file__))) + os.path.sep +"..\\..\\Software" + os.path.sep + "NUCLEO-F091RC" + os.path.sep + dll_name
        self.dut = ctypes.CDLL(dllabspath)
        self.dut.Lib_Simulation_Init()

    
    def generateGMPulse(self):
        self.dut.Lib_GMMeasurementCalculator_OnGMPulseObserved()

    
    def generateEndOfSampleCollecting(self):
        self.dut.Lib_GMMeasurementCalculator_OnSamplingDone()

    
    def getLoggedData(self):
        self.dut.Lib_GMLoggerSIM_GetLoggedData.argtypes = [POINTER(POINTER(c_uint8)),  POINTER(c_uint8)]
        data = POINTER(c_uint8)()
        size = c_uint8()

        self.dut.Lib_GMLoggerSIM_GetLoggedData(byref(data), byref(size))

        logged_data = ""
        for i in range(size.value):
            logged_data += chr(data[i])

        # it is expected that log  end with new line, 
        # this should be stripped application
        return logged_data[:-3]

    
    def getDisplayLength(self):
        self.dut.Lib_GMLoggerSIM_GetDisplayLength.restype = c_uint8
        return self.dut.Lib_GMLoggerSIM_GetDisplayLength()
    

    def getDisplayHeight(self):
        self.dut.Lib_GMLoggerSIM_GetDisplayHeight.restype = c_uint8
        return self.dut.Lib_GMLoggerSIM_GetDisplayHeight()


    def getDisplayData(self):
        self.dut.Lib_GMLoggerSIM_GetDisplayContent.restype = POINTER(c_uint8)
        return self.dut.Lib_GMLoggerSIM_GetDisplayContent()

    def getDisplayPixelValue(self, x, y):
        # note: this is not optimal data is fetched multiple times
        
        display_length = self.getDisplayLength()
        display_height = self.getDisplayHeight()

        self.dut.Lib_GMLoggerSIM_GetDisplayContent.restype = POINTER(c_uint8)
        display_data = self.dut.Lib_GMLoggerSIM_GetDisplayContent()

        # formula from SSD1306_DrawPixel()
        # SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] |= 1 << (y % 8);
        cell = display_data[x + int(y / 8) * display_length]
        value = cell & (1 << (y % 8))

        return value


