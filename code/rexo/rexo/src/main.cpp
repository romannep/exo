#include <Arduino.h>
#include <OneButton.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <globals.h>



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

  buttonLeft.attachClick(clickLeft);
  buttonRight.attachClick(clickRight);
  buttonUp.attachClick(clickUp);
  buttonDown.attachClick(clickDown);
}

void loop() {
  buttonLeft.tick();
  buttonRight.tick();
  buttonUp.tick();
  buttonDown.tick();
}

