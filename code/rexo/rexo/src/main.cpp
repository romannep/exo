#include <Arduino.h>
#include <OneButton.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <globals.h>

static void drawMenu()
{
  String row1 = modeLabels[mode];
  String row2 = "";
  if (menuLevel > 0)
  {
    row1 = row1.substring(0, 4);
    row1.concat(':');

    if (mode == 0)
    {
      row1.concat(settingLabels[setting]);

      if (menuLevel == 2)
      {
        row2 = String(settingValues[setting]);
      }
    }
    else if (mode == 1)
    {
      row2 = "  -  -  U  D";
    }
    else if (mode == 2)
    {
      row2 = "  -  -  L  R";
    }
  }
  lcdPrint(row1, row2);
}

static void clickLeft()
{
  Serial.println("Left");
  menuLevel--;
  if (menuLevel < 0)
  {
    menuLevel = 0;
  }

  drawMenu();
}

static void clickRight()
{
  Serial.println("Right");
  if (menuLevel == 0)
  {
    menuLevel++;
  }
  if (menuLevel == 1 && mode == 0)
  {
    menuLevel = 2;
  }

  drawMenu();
}

int leftState = 0;
int rightState = 0;

static void clickUp()
{
  Serial.println("UP");
  if (menuLevel == 0)
  {
    mode++;
    if (mode > modeMax)
    {
      mode = 0;
    }
  }
  else if (menuLevel == 1)
  {
    if (mode == 0)
    {
      setting++;
      if (setting > settingMax)
      {
        setting = 0;
      }
    }
    else if (mode == 1)
    {
      initialPosition();
    }
    else if (mode == 2)
    {
      if (leftState == 0)
      {
        move(LEV_BEDRO, 15);
        move(LEV_KOLENO, -30);
        leftState = 1;
      }
      else
      {
        move(LEV_BEDRO, 0);
        move(LEV_KOLENO, 0);
        leftState = 0;
      }
    }
  }
  else if (menuLevel == 2)
  {
    if (mode == 0)
    {
      settingValues[setting]++;
    }
  }

  drawMenu();
}

static void clickDown()
{
  Serial.println("DOWN");

  if (menuLevel == 0)
  {
    mode--;
    if (mode < 0)
    {
      mode = modeMax;
    }
  }
  else if (menuLevel == 1)
  {
    if (mode == 0)
    {
      setting--;
      if (setting < 0)
      {
        setting = settingMax;
      }
    }
    else if (mode == 1)
    {
      move(LEV_BEDRO, 15);
      move(LEV_KOLENO, -30);
      move(PRAV_BEDRO, 15);
      move(PRAV_KOLENO, -30);
    }
    else if (mode == 2)
    {
      if (rightState == 0)
      {
        move(PRAV_BEDRO, 15);
        move(PRAV_KOLENO, -30);
        rightState = 1;
      }
      else
      {
        move(PRAV_BEDRO, 0);
        move(PRAV_KOLENO, 0);
        rightState = 0;
      }
    }
  }
  else if (menuLevel == 2)
  {
    if (mode == 0)
    {
      settingValues[setting]--;
    }
  }

  drawMenu();
}

void setup()
{
  lcd.init();
  lcd.backlight();

  initialPosition();
  leftHip.attach(10);
  leftKnee.attach(9);
  rightHip.attach(8);
  rightKnee.attach(7);

  buttonLeft.attachClick(clickLeft);
  buttonRight.attachClick(clickRight);
  buttonUp.attachClick(clickUp);
  buttonDown.attachClick(clickDown);

  drawMenu();
}

void loop()
{
  buttonLeft.tick();
  buttonRight.tick();
  buttonUp.tick();
  buttonDown.tick();
}
