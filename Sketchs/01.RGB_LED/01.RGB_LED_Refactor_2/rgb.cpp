#include "api/Common.h"
#include "rgb.h"

void rgbInit() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void setColorRGB(const RGBColor& color) {
  analogWrite(RED_PIN, color.red);
  analogWrite(GREEN_PIN, color.green);
  analogWrite(BLUE_PIN, color.blue);
}

void fadeToColor(const RGBColor& from, const RGBColor& to, uint16_t steps, uint16_t delayMs) {
  if (steps == 0) return;

  for (uint16_t i = 0; i < steps; i++) {
    RGBColor current;
    current.red = from.red + ((to.red - from.red) * i) / steps;
    current.green = from.green + ((to.green - from.green) * i) / steps;
    current.blue = from.blue + ((to.blue - from.blue) * i) / steps;

    setColorRGB(current);
    delay(delayMs);
  }
}
