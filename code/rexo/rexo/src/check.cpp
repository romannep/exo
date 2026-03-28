#include "globals.h"


static void checkLeft() {
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

static void checkRight() {
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

static void checkUp() {
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

static void checkDown() {
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