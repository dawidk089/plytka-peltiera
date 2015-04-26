/*
 * pinout.h
 *
 * Created: 2015-04-20 02:56:17
 *  Author: Kamil
 *
 * parametry konstruktora Pin:
 * - adres rejestru (dla DIRECTION, PIN_IN, PIN_OUT)
 * - nr bitu
 * - czy dostêpny
 *
 * wa¿ne: nale¿y ustawiæ CONFIG_PINOUT_COUNT
 * - jest to liczba dostêpnych pinów
 */ 

#define CONFIG_PINOUT_COUNT 23

Pin(1, DDRC, PINC, PORTC, PC6, false),
Pin(2, DDRD, PIND, PORTD, PD0, false),
Pin(3, DDRD, PIND, PORTD, PD1, false),
Pin(4, DDRD, PIND, PORTD, PD2, true),
Pin(5, DDRD, PIND, PORTD, PD3, true),
Pin(6, DDRD, PIND, PORTD, PD4, true),
Pin(9, DDRB, PINB, PORTB, PB6, true),
Pin(10, DDRB, PINB, PORTB, PB7, true),
Pin(11, DDRD, PIND, PORTD, PD5, true),
Pin(12, DDRD, PIND, PORTD, PD6, true),
Pin(13, DDRD, PIND, PORTD, PD7, true),
Pin(14, DDRB, PINB, PORTB, PB0, true),
Pin(15, DDRB, PINB, PORTB, PB1, true),
Pin(16, DDRB, PINB, PORTB, PB2, true),
Pin(17, DDRB, PINB, PORTB, PB3, false),
Pin(18, DDRB, PINB, PORTB, PB4, false),
Pin(19, DDRB, PINB, PORTB, PB5, false),
Pin(23, DDRC, PINC, PORTC, PC0, true),
Pin(24, DDRC, PINC, PORTC, PC1, true),
Pin(25, DDRC, PINC, PORTC, PC2, true),
Pin(26, DDRC, PINC, PORTC, PC3, true),
Pin(27, DDRC, PINC, PORTC, PC4, true),
Pin(28, DDRC, PINC, PORTC, PC5, true) // bez przecinka!