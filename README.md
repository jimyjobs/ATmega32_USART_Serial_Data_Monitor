# ATmega32 USART Serial Data Monitor System

## Overview

This project was completed for CT_321_PBL_04 as an exercise in serial communication using the ATmega32 microcontroller.

The idea behind the project was simple: monitor the state of multiple push buttons and report their status through a USART connection. In addition to transmitting data, the microcontroller was also required to receive commands from a serial terminal and respond appropriately.

The project started with a SimulIDE prototype to verify the firmware logic before moving to schematic capture and PCB design in KiCad.


## Development Process

The firmware was written in C using MPLAB XC8. USART communication was configured for 9600 baud at an 8 MHz system clock. Three push buttons were connected as digital inputs and two LEDs were used to provide visual feedback during operation.

Once the firmware was working correctly in simulation, a custom PCB was designed in KiCad. The design includes:

* ATmega32 DIP package
* 8 MHz crystal oscillator
* Crystal load capacitors
* Decoupling capacitors
* Three push-button inputs
* Two indicator LEDs
* USART header for serial communication

After routing was completed, the board was checked using KiCad's Design Rule Checker (DRC) and all reported issues were resolved before generating the manufacturing files.

## Functional Testing

Testing was performed in SimulIDE using the SerialTerm-32 terminal.

### Switch Monitoring

Each switch press generated the expected message on the serial terminal.

Example:

SW1 PRESSED

SW2 PRESSED

SW3 PRESSED

### Echo Function

To verify bidirectional communication, text entered into the serial terminal was echoed back by the microcontroller.

Example:

Input:
hello

Output:
hello

### STATUS Command

A STATUS command was added to display the current state of the monitored switches.

Example response:

SW1=0

SW2=0

SW3=0

### LED Behaviour

One LED was used as a status indicator while the second LED was used to acknowledge valid command processing. During testing both LEDs behaved as expected.

## PCB Verification

Before generating the fabrication files, the PCB was checked using KiCad verification tools.

Final verification results:

* No ERC errors
* No DRC violations
* No unrouted nets
* Gerber files generated successfully
* Drill files generated successfully

The board was also reviewed using KiCad's 3D Viewer to confirm component placement and overall appearance.


## What I Learned

Through this project I gained practical experience with:

* USART initialization and configuration
* Serial communication debugging
* Command-based firmware design
* PCB layout and routing
* Gerber generation for manufacturing
* Verification using ERC and DRC tools


## Conclusion

The final system met all project requirements. The ATmega32 successfully transmitted switch events, received serial commands, and provided visual feedback through LEDs. Both the firmware and PCB design were verified through simulation and design checks, resulting in a complete and manufacturable embedded system project.

## GROUP MEMBERS
1. NASANIA MSENGI    T23-03-00262
2. NERUSIGWE PATRICK      T23-03-17871
3. JIM JOB           T23-03-11228
4. STEPHEN SAMWEL    T23-03-01246