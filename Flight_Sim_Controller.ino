// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;


const uint8_t LINEAR_PINS[] = {
  A9, // JoystickX, Hall effect
  A8, // JoystickY, Hall effect
  A6, // JoystickZ, Hall effect
  A4, // Throttle, Poti
};
const uint8_t SWITCH_PINS[] = {
  7,
  A0,
  6,
  A1,
  A2,
  A3,
  A5,
};

int lastButtonState[sizeof(SWITCH_PINS)];


void setup() {
  // Setup analog inputs
  for (size_t i = 0; i < sizeof(LINEAR_PINS); i++) {
    pinMode(LINEAR_PINS[i], INPUT_PULLUP);
  }
  // Setup digital switches
  for (size_t i = 0; i < sizeof(SWITCH_PINS); i++) {
    pinMode(SWITCH_PINS[i], INPUT_PULLUP);
  }

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, 1024);
  Joystick.setYAxisRange(0, 1024);
  Joystick.setZAxisRange(0, 1024);
  Joystick.setThrottleRange(0, 1024);
}

void loop() {
  // Read Switches
  for (size_t i = 0; i < sizeof(SWITCH_PINS); i++) {
    int currentButtonState = !digitalRead(SWITCH_PINS[i]);
    if (currentButtonState != lastButtonState[i]) {
      Joystick.setButton(i, currentButtonState);
      lastButtonState[i] = currentButtonState;
    }
  }

  // Output Controls
  Joystick.setXAxis(analogRead(LINEAR_PINS[0]));
  Joystick.setYAxis(analogRead(LINEAR_PINS[1]));
  Joystick.setZAxis(analogRead(LINEAR_PINS[2]));
  Joystick.setThrottle(analogRead(LINEAR_PINS[3]));

  Joystick.sendState();
}
