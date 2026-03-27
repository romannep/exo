#include <Arduino.h>
#include <OneButton.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

enum State {
  IDLE,  // 0
  SETUP, // 1
  RUN    // 2
};

State state = IDLE;

OneButton buttonLeft;
OneButton buttonRight;
OneButton buttonUp;
OneButton buttonDown;

LiquidCrystal_I2C lcd  = LiquidCrystal_I2C(0x27,20,4);

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

static void clickLeft() {
  int angle = leftHip.read();
  if (angle == 90) {
    angle = 0;
  } else if (angle == 0) {
    angle = 180;
  } else {
    angle = 90;
  }
  lcdPrint("Clicked LEFT","Go to " + String(angle));
  leftHip.write(angle);
}

static void clickRight() {
  int angle = leftKnee.read();
  if (angle == 90) {
    angle = 0;
  } else if (angle == 0) {
    angle = 180;
  } else {
    angle = 90;
  }
  lcdPrint("Clicked RIGHT","Go to " + String(angle));
  leftKnee.write(angle);
}

static void clickUp() {
  int angle = rightHip.read();
  if (angle == 90) {
    angle = 0;
  } else if (angle == 0) {
    angle = 180;
  } else {
    angle = 90;
  }
  lcdPrint("Clicked UP","Go to " + String(angle));
  rightHip.write(angle);
}

static void clickDown() {
  int angle = rightKnee.read();
  if (angle == 90) {
    angle = 0;
  } else if (angle == 0) {
    angle = 180;
  } else {
    angle = 90;
  }
  lcdPrint("Clicked DOWN","Go to " + String(angle));
  rightKnee.write(angle);
}

void setup() {
  lcd.init();
  lcd.backlight();

  leftHip.write(90);
  leftHip.attach(10);

  leftKnee.write(90);
  leftKnee.attach(9);

  rightHip.write(90);
  rightHip.attach(8);

  rightKnee.write(90);
  rightKnee.attach(7);

  buttonLeft = OneButton(11, true, true);
  buttonLeft.attachClick(clickLeft);
  buttonRight = OneButton(12, true, true);
  buttonRight.attachClick(clickRight);
  buttonUp = OneButton(6, true, true);
  buttonUp.attachClick(clickUp);
  buttonDown = OneButton(5, true, true);
  buttonDown.attachClick(clickDown);
}

void loop() {
  buttonLeft.tick();
  buttonRight.tick();
  buttonUp.tick();
  buttonDown.tick();
}

