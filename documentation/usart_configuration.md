# ATmega32 USART Serial Data Monitoring System
## USART Configuration

**Project:** ATmega32_USART_Serial_Data_Monitor

---

## USART Parameters

| Parameter | Value | Description |
|-----------|-------|-------------|
| Communication Mode | Asynchronous | Standard serial communication |
| Baud Rate | 9600 bps | Data transmission speed |
| CPU Clock (F_CPU) | 6 MHz | System clock frequency |
| Data Bits | 8 | 8-bit character size |
| Parity | None | No parity checking |
| Stop Bits | 1 | One stop bit |
| Frame Format | 8N1 | 8 Data bits, No Parity, 1 Stop bit |
| UBRR Value | 38 | Baud rate register value |
| Double Speed (U2X) | Disabled | Normal USART mode |

---

## Baud Rate Calculation

```text
Formula:

UBRR = (F_CPU / (16 × Baud Rate)) - 1

Substitution:

UBRR = (6,000,000 / (16 × 9600)) - 1

UBRR = 39.0625 - 1

UBRR = 38 (rounded)
```

---

## USART Register Configuration

| Register | Value | Description |
|----------|-------|-------------|
| UCSRA | 0x00 | Normal speed mode |
| UCSRB | RXEN + TXEN | Receiver and transmitter enabled |
| UCSRC | URSEL + UCSZ1 + UCSZ0 | Asynchronous mode, 8-bit data, 1 stop bit, no parity |
| UBRRH | 0x00 | High byte of baud rate register |
| UBRRL | 38 | Low byte of baud rate register |

---

## USART Pin Configuration

| Signal | ATmega32 Pin | Port Bit | Direction | Connected To |
|--------|-------------|----------|-----------|--------------|
| USART RXD | PD0 | PORTD.0 | INPUT | USB-to-Serial TX |
| USART TXD | PD1 | PORTD.1 | OUTPUT | USB-to-Serial RX |

> **Important:** TX of the ATmega32 must be connected to RX of the USB-to-Serial converter, and RX of the ATmega32 must be connected to TX of the USB-to-Serial converter.

---

## Communication Features

| Feature | Status |
|---------|--------|
| USART Initialization | Enabled |
| Data Transmission | Enabled |
| Data Reception | Enabled |
| Interrupt Mode | Disabled (Polling Mode) |
| Error Detection | Frame, Overrun, and Parity Error supported by hardware |

---

## Data Flow

```text
Push Button Press
        │
        ▼
ATmega32 Processes Input
        │
        ▼
USART Transmitter (PD1)
        │
        ▼
USB-to-Serial Converter
        │
        ▼
Computer Serial Monitor

Computer Command
        │
        ▼
USB-to-Serial Converter
        │
        ▼
USART Receiver (PD0)
        │
        ▼
ATmega32 Executes Command
```