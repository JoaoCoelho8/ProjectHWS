#include <Keypad.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 200;
const int colorG = 200;
const int colorB = 200;
int flag = 0;
int first = 0;
int total = 1;
char customkey;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {4, 9, 8, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 3, 7}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
}

void loop()
{
  customkey = keypad.getKey();
  if (customkey) {
    if (customkey == '#') {
      total *= first ;
      lcd.setCursor(4, 0);
      lcd.print(first);
      lcd.setCursor(0, 1);
      lcd.print(total);
    }
    else if ( customkey == '*') {
      if (total != 1)
      {
        lcd.setCursor(0, 0);
        lcd.print(total);
        lcd.setCursor(3, 0);
        lcd.print("*");
        total = total;
        first=0;
      } else {
        lcd.setCursor(0, 0);
        lcd.print(first);
        lcd.setCursor(3, 0);
        lcd.print("*");
        total *= first ;
        first = 0;
      }
    }
    else {
      first = first * 10 + (customkey - '0');
    }
  }
}