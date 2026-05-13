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

void buttonPressed(int button){
  String number = String(button+1);
  String message = "Button " + number + " pressed!";
  Serial.println(message);
}

void checkButton(int buttonNumber) {
  if (analogRead(buttons[buttonNumber]) < LOW_TRIGGER) buttonPressed(buttonNumber); 
}

void checkButtons() {
  for (int i=0; i<5; i++) {
    checkButton(i);
  }
  
}

void setup() {
  Serial.begin(115200); // Any baud rate should work

  for (int i=0; i<5; i++){
    pinMode(buttons[i], INPUT_PULLUP);
  }

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