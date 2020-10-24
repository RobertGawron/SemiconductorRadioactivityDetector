# HardwareDataLogger

[![Unit Tests](https://github.com/RobertGawron/HardwareDataLogger/workflows/Unit%20Tests/badge.svg)](https://github.com/RobertGawron/HardwareDataLogger/actions?query=workflow%3A%22Unit+Tests%22) [![Static Code Analysis](https://github.com/RobertGawron/HardwareDataLogger/workflows/Static%20Code%20Analysis/badge.svg)](https://github.com/RobertGawron/HardwareDataLogger/actions?query=workflow%3A%22Static+Code+Analysis%22)

## Summary

It's a simple hardware data logger, that presents data both on LCD and via COM port so it's possible to gather data using PC and do further analysis. Currently it supports only pulse counting.

![Device Picture](https://raw.githubusercontent.com/RobertGawron/HardwareDataLogger/main/Documentation/Pictures/Device_10_01_2019.jpg)

## Hardware

The device is based on NUCLEO-F091RC evaluation board with added custom-made shield.

TODO: hardware documentation of the shield.


## Software

Firmware were made using CubeMX, Eclipse is used for firmware development.

PC Simulation of Firmware was made using Python+Qt, it uses build .so variant of the firmware (Makefile is used for firmware variant generation).