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


#define CONFIG_PINOUT_COUNT 28

Pin(Pin:Addr(DDRC, PINC, PORTC), PC6, false), // 1
Pin(Pin:Addr(DDRD, PIND, PORTD), PD0, false), // 2
Pin(Pin:Addr(DDRD, PIND, PORTD), PD1, false), // 3
Pin(Pin:Addr(DDRD, PIND, PORTD), PD2, true), // 4
Pin(Pin:Addr(DDRD, PIND, PORTD), PD3, true), // 5
Pin(Pin:Addr(DDRD, PIND, PORTD), PD4, true), // 6
Pin(Pin:Addr(nullptr, nullptr, nullptr), nullptr, true), // 7
Pin(Pin:Addr(nullptr, nullptr, nullptr), nullptr, true), // 8
Pin(Pin:Addr(DDRB, PINB, PORTB), PB6, true), // 9
Pin(Pin:Addr(DDRB, PINB, PORTB), PB7, true), // 10
Pin(Pin:Addr(DDRD, PIND, PORTD), PD5, true), // 11
Pin(Pin:Addr(DDRD, PIND, PORTD), PD6, true), // 12
Pin(Pin:Addr(DDRD, PIND, PORTD), PD7, true), // 13
Pin(Pin:Addr(DDRB, PINB, PORTB), PB0, true), // 14
Pin(Pin:Addr(DDRB, PINB, PORTB), PB1, true), // 15
Pin(Pin:Addr(DDRB, PINB, PORTB), PB2, true), // 16
Pin(Pin:Addr(DDRB, PINB, PORTB), PB3, false), // 17
Pin(Pin:Addr(DDRB, PINB, PORTB), PB4, false), // 18
Pin(Pin:Addr(DDRB, PINB, PORTB), PB5, false), // 19
Pin(Pin:Addr(nullptr, nullptr, nullptr), nullptr, true), // 20
Pin(Pin:Addr(nullptr, nullptr, nullptr), nullptr, true), // 21
Pin(Pin:Addr(nullptr, nullptr, nullptr), nullptr, true), // 22
Pin(Pin:Addr(DDRC, PINC, PORTC), PC0, true), // 23
Pin(Pin:Addr(DDRC, PINC, PORTC), PC1, true), // 24
Pin(Pin:Addr(DDRC, PINC, PORTC), PC2, true), // 25
Pin(Pin:Addr(DDRC, PINC, PORTC), PC3, true), // 26
Pin(Pin:Addr(DDRC, PINC, PORTC), PC4, true), //27
Pin(Pin:Addr(DDRC, PINC, PORTC), PC5, true) // 28, bez przecinka!