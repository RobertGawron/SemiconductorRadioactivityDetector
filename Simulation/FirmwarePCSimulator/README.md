# Firmware imulator

This project consist of two parts:
- firmware that is builded to sharable object (.so)
- python script that loads this sharable object, and acts as a mockup of hardware

Note that in order to load .so object into an application, both of them needs to be 32bits, or 64bits. In case of errors during loading .so object, check your version on Python and gcc (both should be either 32bits or 64bits)


pip install PySide2
pip install PyQt5
