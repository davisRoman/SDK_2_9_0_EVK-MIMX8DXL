Overview
========

The example shows the way to use ENET QOS driver to  
 receive and transmit frames supported multi-ring platforms.
 this example is only supported in multi-ring platform.

1. This example shows how to initialize the ENET MAC.
2. How to use ENET MAC to transmit frames in avb supported 
multiple-ring platforms.

The example transmits 20 number frames. For simple demo, we create frames with some special definition.
1. Build transmission frames with broadcast mac address.
2. Build frames with unicast mac address
3. Send broadcast frames to ring 0 and unitcase frames to ring 1, then receive them back in associated rings.

Toolchain supported
===================
- IAR embedded Workbench  8.50.5
- GCC ARM Embedded  9.2.1

Hardware requirements
=====================
- Mini/micro USB cable
- J-Link Debug Probe
- 12V power supply
- EVK-MIMX8DXL board
- Personal Computer
- Loopback network cable RJ45 standard
- Network cable RJ45 standard
- Network switch 

Board settings
==============
J8 connected with PC through RJ45 network cable.

#### Please note this application can't support running with Linux BSP! ####
This example aims to show the basic usage of the IP's function, some of the used Pads/Resources are also used by Cortex-A core.

Prepare the Demo
================
1.  Connect 12V power supply and J-Link Debug Probe to the board.
2.  Connect a micro USB cable between the host PC and the J19 USB Debug Port on the CPU board.
3.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
4.  Insert loopback network cable into network switch device(support loopback frames) and connect switch to board's Ethernet RJ45 port.
5.  Download the program to the target board.
6.  Launch the debugger in your IDE to begin running the example.

Make loopback network cable:
      Standard 1	     Standard 2
J1    orange+white       green+white
J2    orange             green
J3    green+white        orange+white
J4    blue               brown+white
J5    blue+white         brown
J6    green              orange
J7	  brown+white        blue
J8    brown              blue+white

Connect J1 => J3, J2 => J6, J4 => J7, J5 => J8. 10/100M transfer only requires J1, J2, J3, J6, and 1G transfer requires all 8 pins.
Check your net cable color order and refer to the sheet above. If your cable's color order is not showed in the list,
please connect J1~J8 based on your situation.

Running the demo
================
When the demo runs, the log would be seen on the terminal like:

ENET multi-ring txrx example start.
Wait for PHY init...
Wait for PHY link up...

30 frames will be sent in 3 queues, and frames will be received in 3 queues.
The frame transmitted from the ring 0, 1, 2 is 10, 10, 10!
30 frames transmitted succeed!
The frames successfully received from the ring 0, 1, 2 is 10, 10, 10!
