
#ifndef LiquidScroll_h
#define LiquidScroll_h

#include "Arduino.h"
#include <LiquidCrystal.h>

class LiquidScroll {
  private:
    String memText = "";
    char fixText[17] = "";
    int textPos = 0;
    int linePos = 0;
    void printText(LiquidCrystal lcd);
    void splitChar(String text, int pos);
  
  public:
    // Without print
    void setText(char text[]);
    void setText(int numb);
    void addText(char text[]);
    void addText(int numb);
    void insTextAt(char text[], int pos);
    void insTextAt(int numb, int pos);
    void clearText();
    void scrollLeft();
    void scrollLeft(byte numb);
    void scrollRight();
    void scrollRight(byte numb);
    void resetPos();
    void setAlign(char lett, int margin);
    void setAlign(char lett);
    // S
    String getText();
    void setLine(int line);
    
    // With print
    void setText(char text[], LiquidCrystal lcd);
    void setText(int numb, LiquidCrystal lcd);
    void addText(char text[], LiquidCrystal lcd);
    void addText(int numb, LiquidCrystal lcd);
    void insTextAt(char text[], int pos, LiquidCrystal lcd);
    void insTextAt(int numb, int pos, LiquidCrystal lcd);
    void clearText(LiquidCrystal lcd);
    void scrollLeft(LiquidCrystal lcd);
    void scrollLeft(byte numb, LiquidCrystal lcd);
    void scrollRight(LiquidCrystal lcd);
    void scrollRight(byte numb, LiquidCrystal lcd);
    void resetPos(LiquidCrystal lcd);
    void setAlign(char lett, int margin, LiquidCrystal lcd);
    void setAlign(char lett, LiquidCrystal lcd);
    // S
    void commit(LiquidCrystal lcd);
    void sleepScrollLeft(byte numb, int tSleep, LiquidCrystal lcd);
    void sleepScrollRight(byte numb, int tSleep, LiquidCrystal lcd);
};

#endif

