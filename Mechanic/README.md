# Purpose

Create a 3D-printed holder for the auxiliary board and visualize in Blender if it, the PCBs, and the chassis all fit together.

# Needed tools

* 1x https://www.tme.eu/Document/f0db5de1affb473276670eeca20421a8/hm-1550b.pdf
* 4x M2.5 nuts
* 4x Heat Set Insert Nuts M2.5 outside diameter 4mm
* 1x 3d printed model of the [PcbTray](./PcbTray/) - see more details below.

# Needed Software

* KiCad (for PCB design) + the pcb2blender extension
* OpenSCAD (for modeling the 3D-printed holder) + FreeCAD (for adding fillets and for file format conversion)
* Blender (to merge it all) + the pcb2blender extension

# Modeling Everything in Blender

It is to visualize how all the components fit together. This is only needed when changing the board's dimensions, hole placement, or the design of the PCB holder.

### Export the PCB from KiCad to Blender. 

Fortunately, there is a KiCad/Blender extension called pcb2blender that needs to be installed in both tools. The exported file needs to have the .pcb3d extension; otherwise, Blender fails to import it and the error message says nothing useful.

### Export STL models from FreeCAD to Blender

FreeCAD can export files to .STL, which Blender can then import. During the import in Blender, the scale of the .STL object needs to be set to 0.001. I don't know why.

### Export STEP models to Blender

The model of the metal enclosure for the device I found on the producer’s site, although it was in .STEP format, which Blender doesn't recognize. FreeCAD can import .STEP files and then export them to .STL, which works for Blender.

### Arrange models in Blender 

Now, when all the models are imported into Blender, it's time to arrange them in x, y, z and rotate them so they compose a real device. This could be done manually but would be very tedious; fortunately, Blender can be scripted in Python, and this way all objects can be correctly positioned. Just click the "Run" icon in Blender's scripting section. 

The script is in the project's repo too, it's just that it's not directly visible, but can be accessed via the "Scripting" tab in Blender once the Blender project is opened.

# Modeling the Auxiliary PCB Holder

It is to generate the file for 3D printing.

* The model is created in OpenSCAD.
* In FreeCAD, create a new project and click File > Open to select the OpenSCAD file.
* Add fillets to the model.
* Click File > Export and save it as an .stl file.
