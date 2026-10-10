#define BLUE 3
#define GREEN 5
#define RED 6

void setup() {
  // return;

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

void loop() {
  // return;
  const int DELAY_TIME = 10;

  // de rojo a verde
  int redValue = 255;
  int greenValue = 0;
  int blueValue = 0;

  for (int i = 0; i < 255; i++) {
    redValue--;
    greenValue++;

    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    delay(DELAY_TIME);
  }

  // de verde a azul
  redValue = 0;
  greenValue = 255;
  blueValue = 0;
  for (int i = 0; i < 255; i++) {
    greenValue--;
    blueValue++;

    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(DELAY_TIME);
  }

  // de azul a rojo
  redValue = 0;
  greenValue = 0;
  blueValue = 255;
  for (int i = 0; i < 255; i++) {
    blueValue--;
    redValue++;

    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    delay(DELAY_TIME);
  }

  // de rojo a azul
  redValue = 255;
  greenValue = 0;
  blueValue = 0;
  for (int i = 0; i < 255; i++) {
    redValue--;
    blueValue++;

    analogWrite(RED, redValue);
    analogWrite(BLUE, blueValue);
    delay(DELAY_TIME);
  }

  // de azul a verde
  redValue = 0;
  greenValue = 0;
  blueValue = 255;
  for (int i = 0; i < 255; i++) {
    blueValue--;
    greenValue++;

    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(DELAY_TIME);
  }

  // de verde a rojo
  redValue = 0;
  greenValue = 255;
  blueValue = 0;
  for (int i = 0; i < 255; i++) {
    redValue++;
    greenValue--;

    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    delay(DELAY_TIME);
  }
}
