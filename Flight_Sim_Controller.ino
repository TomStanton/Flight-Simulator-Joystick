// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;

#define X_PIN A9
#define Y_PIN A8
#define Z_PIN A6
#define THROTTLE_PIN A4
#define BTN_0 7
#define BTN_1 A0
#define BTN_2 6
#define BTN_3 A1
#define BTN_4 A2
#define BTN_5 A3
#define BTN_6 A5

int JoystickX;
int JoystickY;
int JoystickZ;
int Throttle;

boolean lastButtonState0;
boolean lastButtonState1;
boolean lastButtonState2;
boolean lastButtonState3;
boolean lastButtonState4;
boolean lastButtonState5;
boolean lastButtonState6;

void setup() {
  pinMode(X_PIN, INPUT_PULLUP);
  pinMode(Y_PIN, INPUT_PULLUP);
  pinMode(Z_PIN, INPUT_PULLUP);
  pinMode(THROTTLE_PIN, INPUT_PULLUP);
  pinMode(BTN_0, INPUT_PULLUP);
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);
  pinMode(BTN_4, INPUT_PULLUP);
  pinMode(BTN_5, INPUT_PULLUP);
  pinMode(BTN_6, INPUT_PULLUP);  

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, 1024); 
  Joystick.setYAxisRange(0, 1024);
  Joystick.setZAxisRange(0, 1024);
  Joystick.setThrottleRange(0, 1024);
}

void loop() {

  // Read Joystick
  JoystickX = analogRead(X_PIN); // Hall effect sensor connects to this analog pin
  JoystickY = analogRead(Y_PIN); // Hall effect sensor connects to this analog pin

  // Read Rudder Pedals
  JoystickZ = analogRead(Z_PIN); // Hall effect sensor connects to this analog pin

  // Read Throttle
  Throttle = analogRead(THROTTLE_PIN); // Potentiometer signal connects to this analog pin


  // Read Switches
  boolean currentButtonState0 = !digitalRead(BTN_0);
  if (currentButtonState0 != lastButtonState0) {
    Joystick.setButton(0, currentButtonState0);
    lastButtonState0 = currentButtonState0;
  }

  boolean currentButtonState1 = !digitalRead(BTN_1);
  if (currentButtonState1 != lastButtonState1) {
    Joystick.setButton(1, currentButtonState1);
    lastButtonState1 = currentButtonState1;
  }
  
  boolean currentButtonState2 = !digitalRead(BTN_2);
  if (currentButtonState2 != lastButtonState2) {
    Joystick.setButton(2, currentButtonState2);
    lastButtonState2 = currentButtonState2;
  }

  boolean currentButtonState3 = !digitalRead(BTN_3);
  if (currentButtonState3 != lastButtonState3) {
    Joystick.setButton(3, currentButtonState3);
    lastButtonState3 = currentButtonState3;
  }
  
  boolean currentButtonState4 = !digitalRead(BTN_4);
  if (currentButtonState4 != lastButtonState4) {
    Joystick.setButton(4, currentButtonState4);
    lastButtonState4 = currentButtonState4;
  } 

  boolean currentButtonState5 = !digitalRead(BTN_5);
  if (currentButtonState5 != lastButtonState5) {
    Joystick.setButton(5, currentButtonState5);
    lastButtonState5 = currentButtonState5;
  } 
  
  boolean currentButtonState6 = !digitalRead(BTN_6);
  if (currentButtonState6 != lastButtonState6) {
    Joystick.setButton(6, currentButtonState6);
    lastButtonState6 = currentButtonState6;
  }  
   
  // Output Controls
  Joystick.setXAxis(JoystickX);
  Joystick.setYAxis(JoystickY);
  Joystick.setZAxis(JoystickZ);
  Joystick.setThrottle(Throttle);

  Joystick.sendState();
}
