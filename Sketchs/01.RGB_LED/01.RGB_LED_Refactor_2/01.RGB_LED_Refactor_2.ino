#include "rgb.h"

void setup() {
  rgbInit();
}

void loop() {
  RGBColor red = { 255, 0, 0 };
  RGBColor green = { 0, 255, 0 };
  RGBColor blue = { 0, 0, 255 };

  fadeToColor(red, green, 255, 10);
  fadeToColor(green, blue, 255, 10);
  fadeToColor(blue, red, 255, 10);
  fadeToColor(red, green, 255, 10);
  fadeToColor(green, blue, 255, 10);
  fadeToColor(blue, red, 255, 10);
}
