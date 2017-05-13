/*
tinysnore.h - Library for putting ATtiny*5s to sleep!
Created by Connor Nishijima, May 12th 2017.
Released under the GPLv3 license.
*/

#ifndef tinysnore_h
#define tinysnore_h

#include "Arduino.h"
#include "avr/sleep.h"
#include "avr/wdt.h"

void snore(uint32_t snore_time);
void ts_system_sleep();
void ts_set_sleep(int ii);

#endif
