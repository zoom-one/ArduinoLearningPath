#include "Arduino_CapacitiveTouch.h"

CapacitiveTouch capacitiveTouch = CapacitiveTouch(D0);

void setup() {
  Serial.begin(9600);

  if (capacitiveTouch.begin()) {
    Serial.println("Capacitive sensor activated.");
  } else {
    Serial.println("Cannot activate capacitive sensor. Review configured pin.");
    while (true)
      ;  // stay here
  }

  capacitiveTouch.setThreshold(2000);
}

void loop() {
  int sensorValue = capacitiveTouch.read();

  Serial.print("Raw value: ");

  Serial.print(sensorValue);

  if (capacitiveTouch.isTouched()) {
    Serial.print(". Button touched!");
  }
  Serial.println();

  delay(1000);
}
