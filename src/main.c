// http://www.nongnu.org/avr-libc/user-manual/modules.html

#include "mcu.h"

#include "dmx.h"
#include "tlc.h"

#include "buffer.h"


// We require GCC 4.x for inlining and stuff.
// http://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html
#if __GNUC__ < 4
#error GCC 4.x.x required!
#endif

//////////////////////////////////////////
// Interrupts

// INT0:  External int, DMX sync
mcu_register_isr(INT0);
// TIMER0:  8-Bit: 4 us for DMX, timeouts
mcu_register_isr(TIMER0_OVF);
// USART:  RXD
mcu_register_isr(USART_RXC);

// TIMER1: 16-Bit: GSCLK
mcu_register_isr(TIMER1_COMPA);
// TIMER2:  8-Bit: GS-Refresh-Timer
mcu_register_isr(TIMER2_COMP);


//////////////////////////////////////////

/**
 * 
 */
void main_init(void)
{
  // Disable interrupts while initializing.
  cli();
  mcu_init();

  // Initialize buffer.
  buffer_init();

  // Initialize peripherals.
  dmx_init();
  tlc_init();

  // Enable interrupts again.
  sei();
}

/**
 *
 */
void main_exec(void)
{
  // Signal that we're running.
  pin_on(PIN_LED_ON);

  // Start DMX processing.
  dmx_exec();
}

/**
 *
 */
void main_loop(void)
{
  // Forever...
  while (1) {
    // FIXME
    tlc_set_data_done();
    tlc_wait_for_data();
  }
}

int main(void)
{
  // Initialize modules.
  main_init();
  // Start modules if necessary.
  main_exec();
  // Gogogo!
  main_loop();
  // Never reached.
  return 0;
}
