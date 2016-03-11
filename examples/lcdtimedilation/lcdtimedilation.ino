/* Interstellar Time Dilation Calculator by ericbsantana */

#include <LCD5110_Graph.h> // See www.rinkydinkelectronics.com/library.php?id=48

LCD5110 screen(8, 9, 10, 12, 11); // Instantiate LCD5110 class

unsigned long millisTime;
long seconds;
long timeFactor = 61320;
long yearSec = 31536000;
long timeDilation;
long nYears;

extern uint8_t SmallFont[]; // Getting font

void setup() {
  screen.InitLCD(); // Initiate Nokia 5110 display
  seconds = 0;
  Serial.begin(9600);
}

void loop() {
  millisTime = millis(); // See https://www.arduino.cc/en/Reference/Millis
  seconds = millisTime / 1000;
  timeDilation = seconds * timeFactor;
  nYears = timeDilation/yearSec;

  screen.clrScr();                                           // Print on Nokia LCD
  screen.setFont(SmallFont);                                 // Select font
  screen.print("INTERSTELLAR", CENTER, 0);
  screen.print("Time dilation", CENTER, 8);
  screen.print("Miller's Time:", CENTER, 16);
  screen.print(String(seconds)+"s", CENTER, 24);
  screen.print("Earth Time:", CENTER, 32);
  
  // Plural and sec -> year change
  
  if (nYears >= 2) {
    screen.print(String(nYears)+" years", CENTER, 40);
  } 
  else if (nYears == 1) {
    screen.print(String(nYears)+" year", CENTER, 40);
  } 
  else if (nYears < 1) {
    screen.print(String(timeDilation)+"s", CENTER, 40); 
  }
  screen.update();
  delay(1000);
}
