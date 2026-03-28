#include <LiquidCrystal_I2C.h>
#include "globals.h"

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

int menuLevel = 0;

String modeLabels[] = {
    "NASTROYKA",
    "PRISED",
    "NA MESTE"};
int mode = 0;
int modeMax = 2;

String settingLabels[] = {
    "LEV BEDRO INIT",
    "LEV KOLENO INIT",
    "PRAV BEDRO INIT",
    "PRAV KOLENO INIT"};
int setting = 0;
int settingMax = 3;
int settingValues[] = {1, 2, 3, 4};

OneButton buttonLeft = OneButton(12, true, true);
OneButton buttonRight = OneButton(11, true, true);
OneButton buttonUp = OneButton(6, true, true);
OneButton buttonDown = OneButton(5, true, true);

Servo leftKnee, leftHip, rightKnee, rightHip;

void lcdPrint(String str1, String str2)
{
  lcd.clear();
  if (str1 != "")
  {
    lcd.setCursor(0, 0);
    lcd.print(str1);
  }
  if (str2 != "")
  {
    lcd.setCursor(0, 1);
    lcd.print(str2);
  }
}

Servo getServo(int servo)
{
  switch (servo)
  {
  case LEV_KOLENO:
    return leftKnee;
    break;
  case LEV_BEDRO:
    return leftHip;
    break;
  case PRAV_KOLENO:
    return rightKnee;
    break;
  case PRAV_BEDRO:
    return rightHip;
    break;

  default:
    break;
  }
}

int servoZero = 90;
int servoDirection[] = {1, 1, -1, -1};

void move(int servo, int angle)
{
  // 0 to 180 on Servo equals 0 to 360 at device
  // so, we need divide angle by 2
  int value = servoZero + settingValues[servo] + (angle * servoDirection[servo] / 2);
  Servo servoObj = getServo(servo);
  servoObj.write(value);
}

void initialPosition()
{
  move(LEV_BEDRO, 0);
  move(LEV_KOLENO, 0);
  move(PRAV_BEDRO, 0);
  move(PRAV_KOLENO, 0);
}