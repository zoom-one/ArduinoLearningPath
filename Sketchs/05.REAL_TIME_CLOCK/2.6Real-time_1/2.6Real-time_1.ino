#include "RTC.h"

void setup() {
  Serial.begin(9600);

  // Initialize RTC module
  RTC.begin();

  // Core logic: To set month N, write (N-1) directly in startTime
  // Example: Set March (3rd month) → write 3-1=2 → static_cast<Month>(3-1)
  RTCTime startTime(17, static_cast<Month>(3-1), 2026, 15, 11, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);

  // Write initial time to RTC
  RTC.setTime(startTime);
}

void loop() {
  RTCTime currentTime;

  // Get current time from RTC
  RTC.getTime(currentTime);

  // Print out date (DD/MM/YYYY)
  Serial.print(currentTime.getDayOfMonth());
  Serial.print("/");
  Serial.print(Month2int(currentTime.getMonth()));
  Serial.print("/");
  Serial.print(currentTime.getYear());
  Serial.print(" - ");

  // Print time (HH:MM:SS)
  Serial.print(currentTime.getHour());
  Serial.print(":");
  Serial.print(currentTime.getMinutes());
  Serial.print(":");
  Serial.println(currentTime.getSeconds());

  delay(1000);
}