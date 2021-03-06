
#include "Arduino.h"
#include "LiquidScroll.h"


LiquidScroll::LiquidScroll() {
  memText = "";
  textPos = 0;
  linePos = 0;
}

void LiquidScroll::printText(LiquidCrystal lcd) {
  for(byte i=0; i<16; i++) {
    if((fixText[i] = memText.charAt(textPos+i)) == NULL) {
        fixText[i] = ' ';
    }
  }
  lcd.setCursor(0, linePos);
  lcd.print(fixText);
}

void LiquidScroll::splitChar(String text, byte pos) {
  for(byte i=0; i<text.length();i++) {
    if((i+pos)<memText.length()) {
      memText.setCharAt(pos+i, text.charAt(i));
    } else {
      memText += text.charAt(i);
    }
  }
}


// Without print

void LiquidScroll::setText(char text[]) {
  memText = text;
}
void LiquidScroll::setText(int numb) {
  memText = String(numb);
}

void LiquidScroll::addText(char text[]) {
  memText += text;
}
void LiquidScroll::addText(int numb) {
  memText += String(numb);
}

void LiquidScroll::insTextAt(char text[], byte pos) {
  splitChar(text, pos);
}
void LiquidScroll::insTextAt(int num, byte pos) {
  splitChar(String(num), pos);
}

void LiquidScroll::clearText() {
  memText = "";
}

void LiquidScroll::scrollLeft() {
  textPos++;
}
void LiquidScroll::scrollLeft(byte numb) {
  textPos += numb;
}

void LiquidScroll::scrollRight() {
  textPos--;
}
void LiquidScroll::scrollRight(byte numb) {
  textPos-= numb;
}

void LiquidScroll::resetPos() {
  textPos = 0;
}

void LiquidScroll::setAlign(char lett, int margin) {
  switch(lett) {
    case 'L':
      textPos = -margin;
      break;
    case 'R':
      textPos = ( memText.length() - 16 ) + margin;
      break;
  }
}
void LiquidScroll::setAlign(char lett) {
  setAlign(lett, 0);
}

// S

String LiquidScroll::getText() {
  return memText;
}

int LiquidScroll::getTextPos() {
  return textPos;
}

void LiquidScroll::setLine(byte line) {
  linePos = line;
}


// With print

void LiquidScroll::setText(char text[], LiquidCrystal lcd) {
  setText(text);
  printText(lcd);
}
void LiquidScroll::setText(int numb, LiquidCrystal lcd) {
  setText(numb);
  printText(lcd);
}

void LiquidScroll::addText(char text[], LiquidCrystal lcd) {
  addText(text);
  printText(lcd);
}
void LiquidScroll::addText(int numb, LiquidCrystal lcd) {
  addText(numb);
  printText(lcd);
}

void LiquidScroll::insTextAt(char text[], byte pos, LiquidCrystal lcd) {
  insTextAt(text, pos);
  printText(lcd);
}
void LiquidScroll::insTextAt(int num, byte pos, LiquidCrystal lcd) {
  insTextAt(num, pos);
  printText(lcd);
}

void LiquidScroll::clearText(LiquidCrystal lcd) {
  clearText();
  printText(lcd);
}

void LiquidScroll::scrollLeft(LiquidCrystal lcd) {
  scrollLeft();
  printText(lcd);
}
void LiquidScroll::scrollLeft(byte numb, LiquidCrystal lcd) {
  scrollLeft(numb);
  printText(lcd);
}

void LiquidScroll::scrollRight(LiquidCrystal lcd) {
  scrollRight();
  printText(lcd);
}
void LiquidScroll::scrollRight(byte numb, LiquidCrystal lcd) {
  scrollRight(numb);
  printText(lcd);
}

void LiquidScroll::resetPos(LiquidCrystal lcd) {
  resetPos();
  printText(lcd);
}

void LiquidScroll::setAlign(char lett, int margin, LiquidCrystal lcd) {
  setAlign(lett, margin);
  printText(lcd);
}
void LiquidScroll::setAlign(char lett, LiquidCrystal lcd) {
  setAlign(lett);
  printText(lcd);
}

// S

void LiquidScroll::commit(LiquidCrystal lcd) {
  printText(lcd);
}

void LiquidScroll::sleepScrollLeft(byte numb, int tSleep, LiquidCrystal lcd) {
  for(byte i = 0; i<numb; i++) {
    scrollLeft();
    printText(lcd);
    delay(tSleep);
  }
}

void LiquidScroll::sleepScrollRight(byte numb, int tSleep, LiquidCrystal lcd) {
  for(byte i = 0; i<numb; i++) {
    scrollRight();
    printText(lcd);
    delay(tSleep);
  }
}
