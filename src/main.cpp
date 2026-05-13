#include <Arduino.h>

#define LOW_TRIGGER 200
int button1 = 0;
int button2 = 0;
int button3 = 0;
int button4 = 0;

const unsigned long loop_time = 500;  // interval at which to poll
unsigned long now; // where to put the current value of millis()
unsigned long before; // previous time millis() was called
bool newLoopTime = 0;
static const uint8_t buttons[] = {A0,A1,A2,A3,A4}; 

// need to refactor all of this testing stuff
void button1Pressed(){
  Serial.println("Button one pressed!");
}
void button2Pressed(){
  Serial.println("Button two pressed!");
}
void button3Pressed(){
  Serial.println("Button three pressed!");
}
void button4Pressed(){
  Serial.println("Button four pressed!");
}

void checkButton1() {
  if (analogRead(A0) < LOW_TRIGGER) button1Pressed(); 
}

void checkButton2() {
  if (analogRead(A1) < LOW_TRIGGER) button2Pressed(); 
}

void checkButton3() {
  if (analogRead(A2) < LOW_TRIGGER) button3Pressed(); 
}

void checkButton4() {
  if (analogRead(A3) < LOW_TRIGGER) button4Pressed(); 
}

void checkButtons() {
  checkButton1();
  checkButton2();
  checkButton3();
  checkButton4();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Any baud rate should work
  // Serial.println("Hello Arduino\n");

  for (int i=0; i<5; i++){
    pinMode(buttons[i], INPUT_PULLUP);
  }
  /* pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  */

  Serial.println("Start up!");
  before = millis();
  now = millis();
}

void loop() {

  now = millis();
  if ((now-before) >= loop_time) {
    Serial.println(". . . another loop passed by!");
    newLoopTime = 1;
    before = now; // start a new loop time
    checkButtons();
  } else {
    newLoopTime = 0;
  }

}