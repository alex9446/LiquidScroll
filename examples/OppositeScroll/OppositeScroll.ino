// include the library code:
#include <LiquidCrystal.h>
#include "LiquidScroll.h"

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

boolean toRight = true;
byte scroll = 0;
LiquidScroll line_1,line_2;

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
  line_1.setLine(0);
  line_1.setText("GULLI");
  line_1.setAlign('L', 1);
  line_1.commit(lcd);
  line_2.setLine(1);
  line_2.setText("LIVORNO");
  line_2.setAlign('R');
  line_2.commit(lcd);
  
}

void loop() {
  
  if(toRight) {
    line_1.scrollLeft(lcd);
    line_2.scrollRight(lcd);
  } else {
    line_1.scrollRight(lcd);
    line_2.scrollLeft(lcd);
  }
  scroll++;
  
  if(scroll = 9) {
    scroll = 0;
    if(toRight) {
      toRight = false;
    } else {
      toRight = true;
    }
  }
  
  // delay at the end of the full loop:
  delay(500);

}

