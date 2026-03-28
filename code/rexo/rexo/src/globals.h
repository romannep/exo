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


enum ServoItem {
  LEV_BEDRO,
  LEV_KOLENO,
  PRAV_BEDRO,
  PRAV_KOLENO
};
extern Servo leftKnee, leftHip, rightKnee, rightHip;
extern int servoZero;
extern int servoDirection[];
Servo getServo(int servo);
void move(int servo, int angle);
void initialPosition();

enum Setting
{
  LEV_BEDRO_INIT,
  LEV_KOLENO_INIT,
  PRAV_BEDRO_INIT,
  PRAV_KOLENO_INIT
};
extern String settingLabels[];
extern int setting;
extern int settingMax;
extern int settingValues[];

enum Mode
{
  NASTROYKA, // 0
  PRISED,   // 1
  NA_MESTE  // 2
};
extern String modeLabels[];
extern int mode;
extern int modeMax;

extern int menuLevel;

void lcdPrint(String str1, String str2);

#endif