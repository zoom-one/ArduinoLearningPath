#ifndef RGB_H
#define RGB_H

#include <Arduino.h>
#include "config/pins.h"

struct RGBColor {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

void rgbInit();
void setColorRGB(const RGBColor& color);
void fadeToColor(const RGBColor& from, const RGBColor& to, uint16_t steps, uint16_t delayMs);

#endif
