// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;
 
int JoystickX;
int JoystickY;
int JoystickZ;
int Throttle;

int currentButtonState0;
int lastButtonState0;
int currentButtonState1;
int lastButtonState1;
int currentButtonState2;
int lastButtonState2;
int currentButtonState3;
int lastButtonState3;
int currentButtonState4;
int lastButtonState4;
int currentButtonState5;
int lastButtonState5;
int currentButtonState6;
int lastButtonState6;

void setup() {
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(A6, INPUT_PULLUP);
  pinMode(A7, INPUT_PULLUP);
  pinMode(A8, INPUT_PULLUP); 
  pinMode(A9, INPUT_PULLUP);
  

// Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, 1024); 
  Joystick.setYAxisRange(0, 1024);
  Joystick.setZAxisRange(0, 1024);
  Joystick.setThrottleRange(0, 1024);
}

void loop() {

// Read Joystick
  JoystickX = analogRead(A9); // Hall effect sensor connects to this analog pin
  JoystickY = analogRead(A8); // Hall effect sensor connects to this analog pin

// Read Rudder Pedals
  JoystickZ = analogRead(A6); // Hall effect sensor connects to this analog pin

// Read Throttle
  Throttle = analogRead(A4); // Potentiometer signal connects to this analog pin


// Read Switches
int currentButtonState0 = !digitalRead(7); // Button 0
  if (currentButtonState0 != lastButtonState0)
  {
  Joystick.setButton(0, currentButtonState0);
  lastButtonState0 = currentButtonState0;
  }

int currentButtonState1 = !digitalRead(A0); // Button 1
  if (currentButtonState1 != lastButtonState1)
  {
  Joystick.setButton(1, currentButtonState1);
  lastButtonState1 = currentButtonState1;
  }
  
int currentButtonState2 = !digitalRead(6); // Button 2
  if (currentButtonState2 != lastButtonState2)
  {
  Joystick.setButton(2, currentButtonState2);
  lastButtonState2 = currentButtonState2;
  }

int currentButtonState3 = !digitalRead(A1); // Button 3
  if (currentButtonState3 != lastButtonState3)
  {
  Joystick.setButton(3, currentButtonState3);
  lastButtonState3 = currentButtonState3;
  }
  
int currentButtonState4 = !digitalRead(A2); // Button 4
  if (currentButtonState4 != lastButtonState4)
  {
  Joystick.setButton(4, currentButtonState4);
  lastButtonState4 = currentButtonState4;
  } 

int currentButtonState5 = !digitalRead(A3); // Button 5
  if (currentButtonState5 != lastButtonState5)
  {
  Joystick.setButton(5, currentButtonState5);
  lastButtonState5 = currentButtonState5;
  } 
  
int currentButtonState6 = !digitalRead(A5); // Button 6
  if (currentButtonState6 != lastButtonState6)
  {
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
