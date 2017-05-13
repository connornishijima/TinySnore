/*
tinysnore.cpp - Library for putting ATtiny*5s to sleep!
Created by Connor Nishijima, May 12th 2017.
Released under the GPLv3 license.
*/

#include "tinysnore.h"

#ifndef cbi
	#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
	#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void snore(uint32_t snore_time){
  cbi(ADCSRA, ADEN);                   // switch Analog to Digitalconverter OFF

  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // sleep mode is set here
  sleep_enable();
  sleep_bod_disable();

  while (snore_time > 0) {
    if (snore_time >= 8000) {
      ts_set_sleep(9);
      ts_system_sleep();
      snore_time -= 8000;
    }
    else if (snore_time >= 4000) {
      ts_set_sleep(8);
      ts_system_sleep();
      snore_time -= 4000;
    }
    else if (snore_time >= 2000) {
      ts_set_sleep(7);
      ts_system_sleep();
      snore_time -= 2000;
    }
    else if (snore_time >= 1000) {
      ts_set_sleep(6);
      ts_system_sleep();
      snore_time -= 1000;
    }
    else if (snore_time >= 500) {
      ts_set_sleep(5);
      ts_system_sleep();
      snore_time -= 500;
    }
    else if (snore_time >= 250) {
      ts_set_sleep(4);
      ts_system_sleep();
      snore_time -= 250;
    }
    else if (snore_time >= 128) {
      ts_set_sleep(3);
      ts_system_sleep();
      snore_time -= 128;
    }
    else if (snore_time >= 64) {
      ts_set_sleep(2);
      ts_system_sleep();
      snore_time -= 64;
    }
    else if (snore_time >= 32) {
      ts_set_sleep(1);
      ts_system_sleep();
      snore_time -= 32;
    }
    else if (snore_time >= 16) {
      ts_set_sleep(0);
      ts_system_sleep();
      snore_time -= 16;
    }
    else {
      delay(snore_time);
      snore_time = 0;
    }
  }
  sbi(ADCSRA, ADEN);                   // switch Analog to Digitalconverter ON
}

void ts_system_sleep(){
  sleep_mode();                        // System sleeps here
  sleep_disable();                     // System continues execution here when watchdog timed out
}

void ts_set_sleep(int ii){
  byte bb;
  int ww;
  if (ii > 9 ) ii = 9;
  bb = ii & 7;
  if (ii > 7) bb |= (1 << 5);
  bb |= (1 << WDCE);
  ww = bb;

  MCUSR &= ~(1 << WDRF);
  // start timed sequence
  WDTCR |= (1 << WDCE) | (1 << WDE);
  // set new watchdog timeout value
  WDTCR = bb;
  WDTCR |= _BV(WDIE);
}

// Watchdog Interrupt Service / is executed when watchdog timed out
ISR(WDT_vect) {
  // NOTHING HERE BY DEFAULT
}
