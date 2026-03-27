#include <LiquidCrystal_I2C.h>
#include "globals.h"

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);
State state = IDLE;

OneButton buttonLeft = OneButton(11, true, true);
OneButton buttonRight = OneButton(12, true, true);
OneButton buttonUp = OneButton(6, true, true);
OneButton buttonDown = OneButton(5, true, true);

Servo leftKnee, leftHip, rightKnee, rightHip;

void lcdPrint(String str1, String str2)
{
  lcd.clear();
  if (str1 != "") {
    lcd.setCursor(0, 1);
    lcd.print(str1);
  }
  if (str2 != "") {
    lcd.setCursor(0, 0);
    lcd.print(str2);
  }
}
