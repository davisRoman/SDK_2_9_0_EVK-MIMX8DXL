Overview
========
The FTM project is a demonstration program of the SDK FTM driver's dual-edge capture feature.
This feature is available only on certain SoC's.
The example sets up a FTM channel-pair for dual-edge capture. Once the input signal is received,
this example will print the capture values and period of the input signal on the terminal window.

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
- Oscilloscope

Board settings
==============
- CM4: Connect input signal to U21-7.
- note: square wave at fixed rate is recommended as the input signal for easily checking the result. 

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
These instructions are displayed/shown on the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
FTM dual-edge capture example
Once the input signal is received the input capture values are printed
The input signal's pulse width is calculated from the capture values & printed

Capture value C(n)V=19b0

Capture value C(n+1)V=38e7

Input signals pulse width=49 us
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
