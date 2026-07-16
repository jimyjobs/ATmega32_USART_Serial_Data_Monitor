# ATmega32 USART Serial Data Monitoring System
## Pin Mapping Table

**Project:** ATmega32_USART_Serial_Data_Monitor

---

## Input Pins

| Function       | ATmega32 Pin | Port Bit | Direction | Description                         |
|----------------|-------------|----------|-----------|-------------------------------------|
| Switch 1 (SW1) | PA0         | PORTA.0  | INPUT     | Push button 1, active LOW, pull-up |
| Switch 2 (SW2) | PA2         | PORTA.2  | INPUT     | Push button 2, active LOW, pull-up |
| Switch 3 (SW3) | PA1         | PORTA.1  | INPUT     | Push button 3, active LOW, pull-up |

---

## Output Pins

| Function    | ATmega32 Pin | Port Bit | Direction | Description                       |
|-------------|-------------|----------|-----------|-----------------------------------|
| LED Status  | PB1         | PORTB.1  | OUTPUT    | ON when switch is pressed         |
| LED Ack     | PB2         | PORTB.2  | OUTPUT    | ON when valid command received    |

---

## USART Communication Pins

| Function   | ATmega32 Pin | Port Bit | Direction | Connects To          |
|------------|-------------|----------|-----------|----------------------|
| USART RXD  | PD0         | PORTD.0  | INPUT     | J1 Pin 2             |
| USART TXD  | PD1         | PORTD.1  | OUTPUT    | J1 Pin 3             |

> **Important:** TX and RX lines must be crossed between the ATmega32 and the USB-to-Serial converter.

---

## LCD Interface Pins (4-Bit Mode)

| LCD Signal | ATmega32 Pin | Port Bit | Direction | Description          |
|------------|-------------|----------|-----------|----------------------|
| LCD_RS     | PC0         | PORTC.0  | OUTPUT    | Register Select      |
| LCD_E      | PC1         | PORTC.1  | OUTPUT    | Enable Strobe        |
| LCD_D7     | PC2         | PORTC.2  | OUTPUT    | Data Bit 7           |
| LCD_D4     | PC3         | PORTC.3  | OUTPUT    | Data Bit 4           |
| LCD_D5     | PC4         | PORTC.4  | OUTPUT    | Data Bit 5           |
| LCD_D6     | PC5         | PORTC.5  | OUTPUT    | Data Bit 6           |
| LCD_RW     | GND         | —        | —         | Write-only operation |
| LCD_VO     | RV1 Wiper   | —        | —         | Contrast adjustment  |

---

## System Pins

| Function     | ATmega32 Pin | Description                                  |
|--------------|-------------|----------------------------------------------|
| Reset        | Pin 9       | Active LOW reset via 10kΩ pull-up resistor   |
| Power (VCC)  | Pin 10      | +5V DC supply                                |
| Analog Power | Pin 30      | AVCC connected to +5V                        |
| Ground       | Pin 11      | Common ground                                |
| XTAL1        | Pin 13      | 6 MHz crystal input                          |
| XTAL2        | Pin 12      | 6 MHz crystal output                         |

---

## Oscillator and Support Components

| Component | Value | Purpose |
|-----------|-------|---------|
| Y1        | 6 MHz | System clock |
| C1        | 22 pF | Crystal load capacitor |
| C2        | 22 pF | Crystal load capacitor |
| C3        | 100 pF | Supply decoupling |
| C4        | 100 pF | Supply decoupling |
| R3        | 10 kΩ | Reset pull-up resistor |
| R1        | 330 Ω | LED1 current limiting |
| R2        | 330 Ω | LED2 current limiting |

---

## USART Configuration

| Parameter  | Value |
|------------|-------|
| Baud Rate  | 9600 bps |
| Data Bits  | 8 |
| Parity     | None |
| Stop Bits  | 1 |
| Mode       | Asynchronous |
| CPU Clock  | 6 MHz |
| UBRR Value | 38 |

### Baud Rate Calculation

```
UBRR = (F_CPU / (16 × Baud)) - 1

UBRR = (6,000,000 / (16 × 9600)) - 1
UBRR = 39.0625 - 1
UBRR = 38
```

---

## Net Labels (KiCad)

| Net Label   | Connected To |
|-------------|-------------|
| SW1         | PA0 |
| SW2         | PA2 |
| SW3         | PA1 |
| LED_STATUS  | PB1 |
| LED_ACK     | PB2 |
| USART_RXD   | PD0 |
| USART_TXD   | PD1 |
| LCD_RS      | PC0 |
| LCD_E       | PC1 |
| LCD_D7      | PC2 |
| LCD_D4      | PC3 |
| LCD_D5      | PC4 |
| LCD_D6      | PC5 |
| VCC         | +5V |
| GND         | Ground |