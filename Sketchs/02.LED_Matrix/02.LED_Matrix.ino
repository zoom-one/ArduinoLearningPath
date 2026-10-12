#include "Arduino_LED_Matrix.h"   //Include the LED_Matrix library
#include "frame.h"
// Create an instance of the ArduinoLEDMatrix class
ArduinoLEDMatrix matrix;  

void setup() {
  Serial.begin(115200);
  // you can also load frames at runtime, without stopping the refresh
  matrix.loadSequence(frame);
  matrix.begin();
  matrix.play(true);
}

void loop() {
}