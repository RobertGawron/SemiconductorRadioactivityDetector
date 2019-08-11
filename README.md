# SemiconductorRadioactivityDetector


## Summary

There are many ways to measure radioactivity level, semiconductor detectors sense interactions between ionizing radiation and p-n junction. Because in hobbyist area most popular are Geiger-Muller based detectors (in short: not a semiconductor but lamp based devices), I think it's a cool idea to take a look at this approach.

![sensor viewed from the inside](https://1.bp.blogspot.com/-7oBQ1ETBhvU/XMwRGNKZN2I/AAAAAAAAHOM/hjzkPQSv9h0YTSOj255yFZFmSvXWYKPdQCLcBGAs/s1600/IMG_3274.JPG)


## Overall system architecture

TODO


## Hardware

![sensor circuit](https://2.bp.blogspot.com/-7W5Jt29pmRs/XMwYKqUDZuI/AAAAAAAAHOo/VTYzHdQfM1gHItS6yzRuQia_jbJGGmU1wCLcBGAs/s1600/p1d9ujoipb1vdl1p3ccgff3015er4.png)

Changes that I made during testing the device, that are not presented on the diagram:
* U1 is OPA657U
* U2 is OPA656U
* R4 is 1G
* As close as possible to input power socket are placed in paraller 1n/16V and 100n/16V, without them the device started to oscillate randomly.
* A Schottky diode is connected in series after mentioned above extra capacitors to reduce risk of damaging the device when power supply is connected incorrectly. I don't know if it will help enough but I have already broke one PCB of this device this way, so now it's there.

Digital output is 12V in high state, 0V in low state, this is not very useful for 3V3 logic microcontroller that I'm using for data acquisition, so I made a simple converter using additional PCB.

![12V to 5V logic converter circuit](https://3.bp.blogspot.com/-tmm_UR8f7hY/XMwiq-O-N_I/AAAAAAAAHO0/m6WsAqSBrycS8aX4pRH-y7wLGTkJhVCdQCLcBGAs/s1600/p1d9umb70ukl1plkhth1ine168v4.png)

Here it is visible soldered. I like in those SMA Female sockets that they can be soldered to the edge of the PCB (as visible below) and this is still quite mechanically stable, but doesn't require to drill holes as in regular mounting way.

![12V to 5V logic converter soldered](https://1.bp.blogspot.com/-1mo2DEVDrAQ/XMwRKulQToI/AAAAAAAAHOU/8N5ZdiqwCes5pCVYKO0DXvYaAEW8RV0nwCLcBGAs/s640/IMG_3265.JPG)


# Software

TODO