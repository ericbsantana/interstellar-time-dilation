# interstellar-time-dilation
A time dilation calculator of Miller's planet from Interstellar.
## Arduino with Nokia 5110 LCD
![Protoboard](/nokia5110.jpg)
From left to right: 
- RST: pin 8
- CE: pin 9
- DC: pin 10
- Din: pin 11
- CLK: pin 12
- Vcc: pin 5V
- BL: pin 5V with 330ohm resistor
- Gnd: pin GND

### Library
Uses Rinky-Dink Electronics' LCD5110 Graph library to print time on Nokia 5110 display (available on [LCD5110_Graph](http://www.rinkydinkelectronics.com/library.php?id=48)).
```cpp 
#include <LCD5110_Graph.h>
```
### Code
Source: [lcdtimedilation.ino](/examples/serialtimedilation/lcdtimedilation.ino)

Using a Nokia 5110 display (84x48 pixels), LCD5110.print parameters are: 
```cpp
LCD5110.print(string text, int x, int y); 
```
So, for a 84x48 display the code'll be like: 
```cpp
screen.print("INTERSTELLAR", CENTER, 0);                          // First line (0) print
screen.print("Time dilation", CENTER, 8);                         // Second line (8) print
screen.print("Miller's Time:", CENTER, 16);                       // Third line (16) print
screen.print(String(seconds)+"s", CENTER, 24);                    // Fourth line (24) print
screen.print("Earth Time:", CENTER, 32);                          // Fifth line (32) print

screen.print(String(nYears)+" years", CENTER, 40);                // Sixth line (40) print, if nYears > 2
```
### I want to use it without Nokia 5110, how?
You may want to use these variables:
```cpp 
  timeDilation = seconds * timeFactor; // Seconds on Miller's -> Second's on Earth conversion
  nYears = timeDilation/yearSec; // Where nYears = number of years passed on earth based on Miller's time dilation 
```
There is a [serialtimedilation.ino](/examples/serialtimedilation/serialtimedilation.ino) example that uses Serial to print values.
