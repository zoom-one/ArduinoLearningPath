int buzzer = 12;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  unsigned char i;

  // while (1)
  // {
    for(i=0; i<200;i++) // duration
    {
      // frecuency: The higher delay gives lower sound
      digitalWrite(buzzer, HIGH); // do not use analogWrite because pulse output is fixed to 500HZ!
      delay(5); 
      digitalWrite(buzzer, LOW);
      delay(5);
    }

    for(i = 0; i < 100; i++)
    {
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);
    }
  // }
}
