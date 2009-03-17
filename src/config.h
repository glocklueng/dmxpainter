#pragma once

// Settings
#define N_PAINTER 8

#define TLC_DC_ONCE 1


// MCU setup
#define PIN_TLC_GSCK  PIN_15
#define PIN_TLC_SCLK  PIN_28
#define PIN_TLC_XLAT  PIN_27
#define PIN_TLC_SIN   PIN_26
#define PIN_TLC_BLNK  PIN_25
#define PIN_TLC_VPRG  PIN_24
#define PIN_TLC_SRTN  PIN_23

#define PIN_DMX_INT   PIN_INT0
#define PIN_DMX_RXD   PIN_RXD

#define PIN_LED_ON    PIN_3

#define INT_TIMER1_COMPA tlc_int_timer1_ocma
#define INT_TIMER2_COMP  tlc_int_timer2_ocm

#define INT_TIMER0_OVF   dmx_int_timer_ovf
#define INT_INT0         dmx_int_ext_edge
#define INT_USART_RXC    dmx_int_usart_rxc

#define PIN_DEBUG     PIN_14
#define REG_DEBUG     EEARH


// Defaults
#ifndef N_PAINTER
  #define N_PAINTER 8
#elif (N_PAINTER < 1) || (N_PAINTER > 10)
  #error This will not work.
#endif

#if TLC_DC_ONCE == 0
  #undef TLC_DC_ONCE
#endif

#ifdef NDEBUG
  #undef PIN_DEBUG
#else
  #ifndef DEBUG
    #define DEBUG
  #endif
#endif
