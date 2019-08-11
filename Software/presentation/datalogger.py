from serial import Serial
import datetime

ser = Serial('/dev/serial/by-id/usb-STMicroelectronics_STM32_STLink_066AFF363732594D43214443-if02',  baudrate=115200)

ser.isOpen()
logFile = open('data.log', 'w')
logFile.write("Time,Counter\n")

while True:
    dataIn = int(ser.readline().rstrip())
    now = datetime.datetime.now()
    logFile.write("{0},{1}\n".format(now, dataIn))
    logFile.flush()

    print(dataIn)


