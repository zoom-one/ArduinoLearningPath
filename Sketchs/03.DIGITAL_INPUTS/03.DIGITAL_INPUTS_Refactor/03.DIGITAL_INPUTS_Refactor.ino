// *************************** v0.2 ***************************
int ledPin = 5;
int buttonApin = 9;

bool ledIsOn = false;
bool lastButtonReading = HIGH;
bool stableButtonState = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
}

void loop() 
{
  bool reading = digitalRead(buttonApin);

  if (reading != lastButtonReading)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading != stableButtonState)
    {
      stableButtonState = reading;

      if (stableButtonState == LOW)
      {
        ledIsOn = !ledIsOn;
        digitalWrite(ledPin, ledIsOn ? HIGH : LOW);
      }
    }
  }

  lastButtonReading = reading;
}

/* // *************************** v0.1 ***************************
int ledPin = 5;
int buttonApin = 9;

bool ledIsOn = false;
bool lastButtonState = HIGH;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
}

void loop() 
{
  bool currentButtonState = digitalRead(buttonApin);

  if (lastButtonState == HIGH && currentButtonState == LOW)
  {
    ledIsOn = !ledIsOn;
    digitalWrite(ledPin, ledIsOn ? HIGH : LOW);
    delay(50);
  }

  lastButtonState = currentButtonState;
}
*/

/* // *************************** v0.0 ***************************
int ledPin = 5;
int buttonApin = 9;

bool ledIsOn = false;
bool isButtonPushed = false;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
}

void loop() 
{
  if (!isButtonPushed && digitalRead(buttonApin) == LOW)
  {
    isButtonPushed = true;
    ledIsOn = !ledIsOn;
    digitalWrite(ledPin, (ledIsOn ? HIGH : LOW));
    isButtonPushed = false;
    delay(100);
  }
}
*/