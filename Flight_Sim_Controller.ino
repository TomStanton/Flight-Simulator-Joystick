// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>
Joystick_ Joystick;

int bitResolution = 12;
unsigned long sampleValue = 0; 
unsigned int numberOfSamples = 1;

const uint8_t LINEAR_PINS[] = {
  A9, // JoystickX, Hall effect
  A8, // JoystickY, Hall effect
  A6, // JoystickZ, Hall effect
  A4, // Throttle,  Potentiometer
};
const uint8_t SWITCH_PINS[] = {
  7,  // Joystick Button 0
  A0, // Joystick Button 1
  6,  // Joystick Button 2
  A1, // Joystick Button 3
  A2, // Joystick Button 4
  A3, // Joystick Button 5
  A5, // Joystick Button 6
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
  Joystick.setXAxisRange(0, 1<<bitResolution); 
  Joystick.setYAxisRange(0, 1<<bitResolution));
  Joystick.setZAxisRange(0, 1<<bitResolution));
  Joystick.setThrottleRange(0, 1<<bitResolution));

// Calculate number of samples
  numberOfSamples = (bitResolution-10)<1 ? 1 : 1<<((bitResolution-10)<<1);
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
  Joystick.setXAxis(overSample(LINEAR_PINS[0]));    // Hall effect sensor connects to this analog pin
  Joystick.setYAxis(overSample(LINEAR_PINS[1]));    // Hall effect sensor connects to this analog pin
  Joystick.setZAxis(overSample(LINEAR_PINS[2]));    // Hall effect sensor connects to this analog pin
  Joystick.setThrottle(overSample(LINEAR_PINS[3])); // Potentiometer signal connects to this analog pin

  Joystick.sendState();

} 

int overSample(int analogPin)
{
  sampleValue = analogRead(analogPin);
  for(int n=1 ; n<numberOfSamples ; n++){
    sampleValue += analogRead(analogPin);
  }
  return ( (int) ((sampleValue>>(bitResolution-10))+(1<<bitResolution-11)-1) );
}