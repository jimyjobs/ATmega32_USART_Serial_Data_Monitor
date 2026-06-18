# ATmega32 USART Serial Data Monitoring System
## Pin Mapping Table

**Project:** ATmega32_USART_Serial_Data_Monitor

---

## Input Pins

| Function       | ATmega32 Pin | Port Bit | Direction | Description                        |
|----------------|-------------|----------|-----------|------------------------------------|
| Switch 1 (SW1) | PA0         | PORTA.0  | INPUT     | Digital input, active LOW, pull-up |
| Switch 2 (SW2) | PA1         | PORTA.1  | INPUT     | Digital input, active LOW, pull-up |
| Switch 3 (SW3) | PA2         | PORTA.2  | INPUT     | Digital input, active LOW, pull-up |

---

## Output Pins

| Function        | ATmega32 Pin | Port Bit | Direction | Description                          |
|-----------------|-------------|----------|-----------|--------------------------------------|
| LED Status      | PB1         | PORTB.1  | OUTPUT    | ON when any switch is pressed        |
| LED Command     | PB2         | PORTB.2  | OUTPUT    | ON when valid command is received    |

---

## USART Communication Pins

| Function   | ATmega32 Pin | Port Bit | Direction | Connects To          |
|------------|-------------|----------|-----------|----------------------|
| USART RXD  | PD0         | PORTD.0  | INPUT     | USB-to-Serial TX pin |
| USART TXD  | PD1         | PORTD.1  | OUTPUT    | USB-to-Serial RX pin |

> **Important:** TX and RX lines must be CROSSED between ATmega32 and USB-to-serial converter.

---

## System Pins

| Function      | ATmega32 Pin | Description                              |
|---------------|-------------|------------------------------------------|
| Reset         | RESET       | Active LOW reset with pull-up resistor   |
| Power         | VCC         | 5V DC supply                             |
| Ground        | GND         | Common ground                            |
| Analog Power  | AVCC        | 5V DC (connect to VCC)                   |
| Oscillator 1  | XTAL1       | 8MHz crystal input                       |
| Oscillator 2  | XTAL2       | 8MHz crystal output                      |

---

## USART Configuration

| Parameter   | Value       |
|-------------|-------------|
| Baud Rate   | 9600 bps    |
| Data Bits   | 8           |
| Parity      | None        |
| Stop Bits   | 1           |
| Mode        | Asynchronous|
| UBRR Value  | 51          |

### Baud Rate Calculation
```
UBRR = (F_CPU / (16 x Baud)) - 1
UBRR = (8,000,000 / (16 x 9600)) - 1
UBRR = 52.083 - 1
UBRR = 51 (rounded)
```

---

## Net Labels (KiCad)

| Net Label    | Connected To         |
|--------------|----------------------|
| USART_RXD    | PD0                  |
| USART_TXD    | PD1                  |
| SW1          | PA0                  |
| SW2          | PA1                  |
| SW3          | PA2                  |
| LED_STATUS   | PB1                  |
| LED_CMD      | PB2                  |
| VCC          | Power supply +5V     |
| GND          | Power supply ground  |




