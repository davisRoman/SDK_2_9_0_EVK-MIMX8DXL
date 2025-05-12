Overview
========
The sema42 uboot example shows how to use SEMA42 driver to lock and unlock a sema gate.
This example should work together with uboot. This example runs on Cortex-M core,
the uboot runs on the Cortex-A core.

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

Board settings
==============
No special settings are required.

#### Note! ####
This application requires the SCFW(System Controller Firmware) with CM4 core's Partition/Domain
configuration and related Resource Management. And it needs to work together with A core. 
Please use A core version targets in imx-mkimage to generate the target image, for example:
    -- flash_linux_m4 for TCM
    -- flash_linux_m4_ddr for DDR

#### Please note this application can't support running with Linux BSP! ####

Prepare the Demo
================
This example should be run together with uboot.
1.  Prepare an SD card with the prebuilt U-Boot image.
2.  Connect a micro USB cable between the host PC and the J19 USB port on the cpu board.
3.  Open a serial terminal with the following settings, please refer to Getting Started with MCUXpresso SDK 
    to determine the Cortex-M4 and Cortex-A debug COM port:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
4.  Connect 12V power supply and J-Link Debug Probe to the board, switch SW3 to power on the board.
5.  Hit any key to stop uboot autoboot in the Cortex-A terminals.
6.  Download the program to the target board.
7.  Launch the debugger in your IDE to begin running the example.

Running the demo
================
The simliar log below in the Cortex-M terminal window shows the commands to use in uboot:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**************************************************************
* Please make sure the uboot is started now.                 *
* Use the following commands in uboot for SEMA42 gate access *
* - md.b 0x371b0003 1 : Get SEMA42 gate status.              *
*   - 0 - Unlocked;                                          *
*   - 1 - Locked by Cortex-A;                                *
*   - 4 - Locked by Cortex-M;                                *
* - mw.b 0x371b0003 1 1 : Lock the SEMA42 gate.              *
* - mw.b 0x371b0003 0 1 : Unlock the SEMA42 gate.            *
**************************************************************

Press anykey to start the example...
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Follow the example output instructions:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Now the SEMA42 gate is unlocked, checking status in uboot returns 0.
Press anykey to lock the SEMA42 gate...

Now the SEMA42 gate is locked, checking status in uboot returns 4.
Lock or unlock the SEMA42 gate in uboot, the status does not change.

Press anykey to unlock the SEMA42 gate...

Now the SEMA42 gate is unlocked, checking status in uboot returns 0.

Lock the SEMA42 gate in uboot, after locked, then press anykey...

Cortex-A has locked the SEMA42 gate in uboot, Cortex-M could not lock.

Press anykey to reset the SEMA42 gate...

Now the SEMA42 gate is unlocked, checking status in uboot returns 0.

Press anykey to finish the example...

SEMA42 uboot example successed.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
