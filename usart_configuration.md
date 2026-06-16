# USART Configuration

## Project
ATmega32 USART-Based Serial Data Monitoring System

## USART Parameters
- Baud Rate: 9600 bps
- Data Bits: 8
- Parity: None
- Stop Bits: 1
- Clock Frequency: 8 MHz

## Hardware Connections
- PD0 (RXD) -> USB-to-Serial TX
- PD1 (TXD) -> USB-to-Serial RX
- GND -> GND

## Baud Rate Calculation
UBRR = (F_CPU / (16 × Baud)) - 1

F_CPU = 8,000,000 Hz
Baud = 9600 bps

UBRR ≈ 51

UBRRH = 0x00
UBRRL = 51

## Conclusion
USART communication was successfully configured and tested.
