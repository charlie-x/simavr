/*
 * attiny2313a.c
 *
 * Test USI as SPI master.
 */

#include <util/delay.h>
#include <avr/cpufunc.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>

#include "avr_mcu_section.h"

AVR_MCU(F_CPU, "attiny4313");

static PROGMEM const char msg[] = "Hello there, 84";

int main()
{
	const char *cp = msg;

	/*  Set up SPI master. */

	USICR = _BV(USIWM0) | _BV(USICS1);
	DDRB = _BV(PB6) | _BV(PB7);		// Enable DO and SCLK output.

	for (;;) {
		static volatile uint8_t ch = 0xaa;

		PORTA = ch;

		DDRA = ch;

		PINA = ch;

		PORTB = ch;

		DDRB = ch;

		PINB = ch;

		ch++;

		_NOP();
		_NOP();
		_NOP();
		_NOP();
	}
}
