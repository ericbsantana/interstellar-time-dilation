unsigned long millisTime;
long seconds;
long timeFactor = 61320;
long yearSec = 31536000;
long timeDilation;
long nYears;

void setup() {
  Serial.begin(9600);
}

void loop() {
  millisTime = millis(); // See https://www.arduino.cc/en/Reference/Millis
  seconds = millisTime / 1000;
  timeDilation = seconds * timeFactor;
  nYears = timeDilation/yearSec;
  Serial.println("Miller's time:");
  Serial.println(String(seconds)+"s");
  Serial.println();

  Serial.println("Earth time:");
  // Plural and sec -> year change
  if (nYears >= 2) {
    Serial.println(String(nYears)+" years");
  }
  if (nYears == 1) {
    Serial.println(String(nYears)+" years");
  }
  if (nYears < 1) {
    Serial.println(String(timeDilation)+"s");
  }
  Serial.println();
  delay(1000);
}



