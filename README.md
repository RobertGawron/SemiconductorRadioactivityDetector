# SemiconductorRadioactivityDetector

[![Docs Generation](https://github.com/RobertGawron/SemiconductorRadioactivityDetector/workflows/Docs%20Generation/badge.svg)](https://github.com/RobertGawron/SemiconductorRadioactivityDetector/actions?query=workflow%3A%22Docs+Generation%22)

## Summary

There are many ways to measure radioactivity level, semiconductor detectors sense interactions between ionizing radiation and p-n junction. Because in hobbyist area most popular are Geiger-Muller based detectors (in short: not a semiconductor but lamp based devices), I think it's a cool idea to take a look at this approach.

![sensor viewed from the inside](https://1.bp.blogspot.com/-7oBQ1ETBhvU/XMwRGNKZN2I/AAAAAAAAHOM/hjzkPQSv9h0YTSOj255yFZFmSvXWYKPdQCLcBGAs/s1600/IMG_3274.JPG)


## System architecture

![architecture](https://raw.githubusercontent.com/RobertGawron/SemiconductorRadioactivityDetector/master/Documentation/Diagrams/ArchitectureOverview-1.png)

[HardwareDataLogger](https://github.com/RobertGawron/HardwareDataLogger) is a simple pulse counter based on NUCLEO-F091RC with additional shield (for real-time data display using LCD).

## Hardware

PCB project was done in KiCAD.

* [HW overview of the detector
](https://github.com/RobertGawron/SemiconductorRadioactivityDetector/wiki/HW-overview-of-the-detector) 
* [12V  to  3V3 logic converter
](https://github.com/RobertGawron/SemiconductorRadioactivityDetector/wiki/12V--to--3V3-logic-converter) 


## Software


* [Architecture of "Data processing and firmware flashing" node
](https://github.com/RobertGawron/SemiconductorRadioactivityDetector/wiki/%22Data-processing-and-firmware-flashing%22-node-architecture)
