#ifndef MODESWITCH_H
#define MODESWITCH_H

#include <Arduino.h>

void initializeIndicators();

void automaticModeSwitch();

void buzzerBeep(int times);

void statusLED(bool state);

#endif