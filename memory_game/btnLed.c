#include "btnLed.h"

#define LED_CNT 25

static int leds_status = 0;

// A variable to hold the value of the button pio edge capture register
volatile int edge_capture;

/* Function to get the value of the edge_capture variable */
int btnLed_get_edge_capture(void) {
    return edge_capture;
}

/* Function to set the value of the edge_capture variable */
void btnLed_reset_edge_capture() {
    edge_capture = 0;
}

static void btnLed_handle_button_interrupts(void* context) {
    /* Cast context to edge_capture's type. It is important that this be
     * declared volatile to avoid unwanted compiler optimization.
     */
    volatile int* edge_capture_ptr = (volatile int*) context;
    /* Store the value in the Button's edge capture register in *context. */
    *edge_capture_ptr = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTON_PIO_BASE);
    /* Reset the Button's edge capture register. */
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTON_PIO_BASE, 0);

    /*
     * Read the PIO to delay ISR exit. This is done to prevent a spurious
     * interrupt in systems with high processor -> pio latency and fast
     * interrupts.
     */
    IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTON_PIO_BASE);
}


/* Initialize the button_pio. */
void btnLed_init()
{
    /* Recast the edge_capture pointer to match the alt_irq_register() function
     * prototype. */
    void* edge_capture_ptr = (void*) &edge_capture;
    /* Enable all 4 button interrupts. */
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BUTTON_PIO_BASE, 0xf);
    /* Reset the edge capture register. */
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTON_PIO_BASE, 0x0);
    /* Register the interrupt handler. */

    alt_ic_isr_register(BUTTON_PIO_IRQ_INTERRUPT_CONTROLLER_ID, BUTTON_PIO_IRQ,
      btnLed_handle_button_interrupts, edge_capture_ptr, 0x0);
    
    btnLed_set_sevenseg(0);
}

/* Output a value on the 7-segment display (hex) */
void btnLed_set_sevenseg(int value) {
  IOWR_ALTERA_AVALON_PIO_DATA(SEVEN_SEG_PIO_BASE, value);
}

void btnLed_set_led(int led_nr) {
  leds_status |= 1 << led_nr;
  IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE, leds_status);
}

void btnLed_set_all_red_leds() {
  leds_status = 0x1FFFF00;
  IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE, leds_status);
}

void btnLed_clear_all_leds() {
  leds_status = 0;
  IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE, leds_status);
}
