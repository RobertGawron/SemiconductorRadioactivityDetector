# SemiconductorRadioactivityDetector

[![Build Status](https://travis-ci.com/RobertGawron/SemiconductorRadioactivityDetector.svg?branch=master)](https://travis-ci.com/RobertGawron/SemiconductorRadioactivityDetector)

(CI is checking only documentation)

---

## Summary

There are many ways to measure radioactivity level, semiconductor detectors sense interactions between ionizing radiation and p-n junction. Because in hobbyist area most popular are Geiger-Muller based detectors (in short: not a semiconductor but lamp based devices), I think it's a cool idea to take a look at this approach.

![sensor viewed from the inside](https://1.bp.blogspot.com/-7oBQ1ETBhvU/XMwRGNKZN2I/AAAAAAAAHOM/hjzkPQSv9h0YTSOj255yFZFmSvXWYKPdQCLcBGAs/s1600/IMG_3274.JPG)


## System architecture

![architecture](https://raw.githubusercontent.com/RobertGawron/SemiconductorRadioactivityDetector/master/Documentation/Diagrams/ArchitectureOverview-1.png)


## Hardware

PCB project was done in KiCAD.

* [HW overview of the detector
](https://github.com/RobertGawron/SemiconductorRadioactivityDetector/wiki/HW-overview-of-the-detector) 
* [12V -> 5V logic converter
](https://github.com/RobertGawron/SemiconductorRadioactivityDetector/wiki/HW-overview-of-the-detector) 


## Software

* Firmware for data acquisition comes from my [Geiger Counter](https://github.com/RobertGawron/GeigerMullerCounter) project.
* ["Data processing and firmware flashing" node architecture
](https://github.com/RobertGawron/SemiconductorRadioactivityDetector/wiki/%22Data-processing-and-firmware-flashing%22-node-architecture)