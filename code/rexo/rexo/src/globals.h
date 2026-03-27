#include <OneButton.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#ifndef GLOBALS_H
#define GLOBALS_H

extern OneButton buttonLeft;
extern OneButton buttonRight;
extern OneButton buttonUp;
extern OneButton buttonDown;

extern LiquidCrystal_I2C lcd;

extern Servo leftKnee, leftHip, rightKnee, rightHip;

enum Settings {
  LEV_BEDRO_INIT,
  LEV_KOLENO_INIT,
  PRAV_BEDRO_INIT,
  PRAV_KOLENO_INIT
};

enum State {
  IDLE,  // 0
  SETUP, // 1
  RUN    // 2
};

extern State state;

void lcdPrint(String str1, String str2);

#endif