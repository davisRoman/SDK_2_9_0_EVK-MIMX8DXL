Overview
========
The ELCDIF ALPHA project shows how to drive the use the eLCDIF alpha surface.
Int this example, there are two surfaces, the back ground surface is a blue
rectangle in the center of the frame, the overlay surface is full screen red.
If this example runs correctly, you can see two rectangles(a smaller blue rectangle
in the screen center, and a larger red rectangle), the alpha value of the two
rectangles change.

Toolchain supported
===================
- IAR embedded Workbench  8.50.5
- GCC ARM Embedded  9.2.1

Hardware requirements
=====================
- Micro USB cable
- MIMX8DXL EVK board
- J-Link Debug Probe
- 12V power supply
- Personal Computer
- WKS101WX001-WCT LCD panel

Board settings
==============
Connect the LCD panel to J9.

For REV.B board:
    Remove R259 and R251. Short LCD input pins: pin 30 and pin 26.
    Short TP114 and R251 (MCU side).

#### Note! ####
This application outputs characters to the third serial port 

#### Please note this application can't support running with Linux BSP! ####

Prepare the Demo
================
1.  Connect 12V power supply and J-Link Debug Probe to the board, switch SW3 to power on the board.
2.  Connect a micro USB cable between the host PC and the J19 USB port on the cpu board.
3.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
4.  Download the program to the target board.
5.  Launch the debugger in your IDE to begin running the example.

Running the demo
================
If this example runs correctly, the panel shows what described in overview.

Known issue on REV.B board:
The blue color bit5 is always 0, because panel pin B5 is connected to GND, to make
the DISP_EN signal work.
