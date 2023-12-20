#ifndef __SIM_MCU_STRUCTS_H__
#define __SIM_MCU_STRUCTS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "avr_eeprom.h"
#include "avr_watchdog.h"
#include "avr_extint.h"
#include "avr_ioport.h"
#include "avr_uart.h"
#include "avr_timer.h"
#include "avr_acomp.h"
#include "avr_usi.h"

typedef struct mcu_attiny4313_t {
	avr_t core;
	avr_eeprom_t 	eeprom;
	avr_watchdog_t	watchdog;
	avr_extint_t	extint;
	avr_ioport_t	porta, portb, portd;
	avr_uart_t		uart;
	avr_timer_t		timer0,timer1;
	avr_acomp_t		acomp;
	avr_usi_t	    usi;
} mcu_attiny4313_t;


#ifdef __cplusplus
}
#endif

#endif
