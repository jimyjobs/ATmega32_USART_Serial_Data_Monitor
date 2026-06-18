# Test Results

## Project

ATmega32 USART Serial Data Monitoring System

---

## Test Environment

| Item            | Description   |
| --------------- | ------------- |
| Microcontroller | ATmega32      |
| Clock Frequency | 8 MHz         |
| Simulation Tool | SimulIDE      |
| Terminal        | SerialTerm-32 |
| Communication   | USART         |
| Baud Rate       | 9600 bps      |

---

# Test 1: HELLO Command

## Objective

Verify that the ATmega32 can receive and process a valid serial command.

## Procedure

1. Open SerialTerm-32.
2. Send the command:

HELLO

## Expected Result

The microcontroller responds with:

HELLO

## Actual Result

PASS

## Screenshot

simulide/screenshots/HELLO_Test.png

---

# Test 2: STATUS Command

## Objective

Verify that the microcontroller can report the current switch states.

## Procedure

1. Open SerialTerm-32.
2. Send the command:

STATUS

## Expected Result

The terminal displays:

SW1=0
SW2=0
SW3=0

or the current switch values.

## Actual Result

PASS

## Screenshot

simulide/screenshots/Status_Command.png

---

# Test 3: Switch Detection

## Objective

Verify that switch states are correctly read by the microcontroller.

## Procedure

1. Press SW1.
2. Send STATUS.
3. Repeat for SW2 and SW3.

## Expected Result

The corresponding switch state changes to 1.

Example:

SW1=1
SW2=0
SW3=0

## Actual Result

PASS

## Screenshot

simulide/screenshots/SW3_Test.png

---

# Test 4: Command LED

## Objective

Verify that the command LED turns ON when a valid command is received.

## Procedure

1. Send STATUS.
2. Observe LED connected to PB2.

## Expected Result

LED flashes briefly.

## Actual Result

PASS

---

# Test 5: Invalid Command Handling

## Objective

Verify that unsupported commands are handled correctly.

## Procedure

Send:

TEST

## Expected Result

The system displays:

INVALID COMMAND

## Actual Result

PASS

---

# PCB Verification

| Check                 | Result |
| --------------------- | ------ |
| ERC                   | PASS   |
| DRC                   | PASS   |
| Unconnected Nets      | None   |
| Gerber Generation     | PASS   |
| Drill File Generation | PASS   |

---

# Summary

| Test                     | Status |
| ------------------------ | ------ |
| HELLO Command            | PASS   |
| STATUS Command           | PASS   |
| Switch Detection         | PASS   |
| Command LED              | PASS   |
| Invalid Command Handling | PASS   |
| PCB Verification         | PASS   |

---

## Conclusion

All required functions of the USART Serial Data Monitoring System were tested successfully. The firmware, simulation, PCB design, and manufacturing outputs behaved as expected.
