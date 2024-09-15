# Hardware

* [SemiconductorRadioactivityDetector](./SemiconductorRadioactivityDetector) - the main project for the sensor.
* [LogicLevelConverter](./LogicLevelConverter) - a helper project. The sensor's digital output is 12V=high and 0V=low, which isn't suitable for most microcontrollers. This board is used to convert the levels to 3.3V=high and 0V=low.