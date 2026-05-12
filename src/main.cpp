#include <Arduino.h>

#define LOW_TRIGGER 200
int button1 = 0;
const unsigned long loop_time = 2000;  // interval at which to poll
unsigned long now; // where to put the current value of millis()
unsigned long before; // previous time millis() was called

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Any baud rate should work
  // Serial.println("Hello Arduino\n");

  pinMode(A0, INPUT_PULLUP);
  Serial.println("Start up!");
  before = millis();
  now = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  while (loop_time < (before - now)) {
    now = millis();
    button1 = analogRead(A0);
    if (button1 < LOW_TRIGGER ) Serial.println("Button 1 pressed");
  }
  before = now;
  Serial.println("Before is now");
  
}


/*
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}*/