#define BLUE 3
#define GREEN 5
#define RED 6
const int DELAY_TIME = 10;

struct colorStruct {
  int color;
  int value;
};

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

void changeColor(colorStruct offColor, colorStruct initialMaxColor, colorStruct initialMinColor) {
  initialMaxColor.value = 255;
  initialMinColor.value = 0;

  analogWrite(offColor.color, 0);
  analogWrite(initialMaxColor.color, initialMaxColor.value);
  analogWrite(initialMinColor.color, initialMinColor.value);

  for (int i = 0; i < 255; i++) {
    analogWrite(initialMaxColor.color, --initialMaxColor.value);
    analogWrite(initialMinColor.color, ++initialMinColor.value);
    delay(DELAY_TIME);
  }
}

void loop() {
  struct colorStruct offColor;
  struct colorStruct initialMaxColor;
  struct colorStruct initialMinColor;
  offColor.color = BLUE;
  initialMaxColor.color = RED;
  initialMinColor.color = GREEN;
  changeColor(offColor, initialMaxColor, initialMinColor);
}
