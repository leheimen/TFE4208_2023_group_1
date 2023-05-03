#ifndef BTNLED_H
#define BTNLED_H

#include <stdio.h>
#include "sys/alt_irq.h"
#include "system.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"

/* Function to get the value of the edge_capture variable */
int btnLed_get_edge_capture(void);

/* Function to set the value of the edge_capture variable */
void btnLed_reset_edge_capture();

/* Initialize the button_pio */
void btnLed_init();

/* Display a hex value on 7-segment display */
void btnLed_set_sevenseg(int hex);

/* Turn on led */
void btnLed_set_led(int led_nr);

/* Turn on all leds */
void btnLed_set_all_red_leds();

/* Turn off all leds */
void btnLed_clear_all_leds();

#endif /* BTNLED_H */
