import sys
from datetime import datetime
from PyQt5.QtWidgets import QApplication, QMainWindow, \
    QPushButton, QTextBrowser, QLabel
from PyQt5 import QtCore, QtGui, uic
from device_under_test import DeviceUnderTest


class MainWindow(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)

        self.dut = DeviceUnderTest()
        self.setupWidgets()
        self.startTimers()
        self.onHWDisplayUpdate()
        self.show()

    def setupWidgets(self):
        uic.loadUi("gui.ui", self)

        self.WidgetGenerateGMPulse = \
            self.findChild(QPushButton, "WidgetGenerateGMPulse")
        self.WidgetPushHWKey = self.findChild(QPushButton, "WidgetPushHWKey")
        self.WidgetLogger = self.findChild(QTextBrowser, "WidgetLogger")
        self.WidgetHWDisplay = self.findChild(QLabel, "WidgetHWDisplay")

        self.WidgetGenerateGMPulse.clicked.connect(self.onGenerateGMPulse)
        self.WidgetPushHWKey.clicked.connect(self.onPressHWKey)

    def startTimers(self):
        self.dutTimer = QtCore.QTimer()
        self.dutTimer.setInterval(3000)
        self.dutTimer.timeout.connect(self.onTimer)
        self.dutTimer.start()

    def onGenerateGMPulse(self):
        self.dut.generateGMPulse()

    def onTimer(self):
        self.dut.generateEndOfSampleCollecting()
        self.onNewLoggedData()
        self.onHWDisplayUpdate()

    def onNewLoggedData(self):
        logged_data = self.dut.getLoggedData()
        local_timestamp = datetime.now()
        data_with_timestamp = "{}: {}".format(local_timestamp, logged_data)
        self.WidgetLogger.append(data_with_timestamp)

    def onPressHWKey(self):
        self.dut.pressKey()
        self.onHWDisplayUpdate()

    def onHWDisplayUpdate(self):
        display_pixel_on_color = "#6df8fc"
        display_pixel_off_color = "#14182b"

        display_length = self.dut.getDisplayLength()
        display_height = self.dut.getDisplayHeight()

        canvas = QtGui.QPixmap(display_length, display_height)
        canvas.fill(QtGui.QColor(display_pixel_off_color))

        self.WidgetHWDisplay.setPixmap(canvas)

        painter = QtGui.QPainter(self.WidgetHWDisplay.pixmap())
        pen = QtGui.QPen()
        pen.setWidth(1)

        for y in range(display_height):
            for x in range(display_length):
                if(self.dut.getDisplayPixelValue(x, y)):
                    pen.setColor(QtGui.QColor(display_pixel_on_color))
                    painter.setPen(pen)
                else:
                    pen.setColor(QtGui.QColor(display_pixel_off_color))
                    painter.setPen(pen)
                painter.drawPoint(x, y)

        painter.end()


if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
