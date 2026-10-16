void setup() {
  // 1. Initialize serial port with baud rate 115200
  Serial.begin(115200);
  // Wait for serial port to connect (required for some boards)
  while (!Serial)
    ;

  // 2. Send welcome message
  Serial.println(" Simple Serial Program ");
  Serial.println("Commands:");
  Serial.println(" on - Turn on LED");
  Serial.println(" off - Turn off LED");
  Serial.println(" status - Check LED status");
  Serial.println("====================================");
}

void loop() {
  // put your main code here, to run repeatedly:
}
