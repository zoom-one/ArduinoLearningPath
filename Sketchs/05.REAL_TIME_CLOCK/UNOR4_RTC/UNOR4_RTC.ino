#include "RTC.h"

bool timeSet = false;  // Marks whether the time has been manually set

// ====================== Custom default time (change here only) ======================
const int DEFAULT_YEAR = 2026;  // Default year
const int DEFAULT_MONTH = 3;    // Default month
const int DEFAULT_DAY = 17;     // Default day
const int DEFAULT_HOUR = 15;    // Default hour
const int DEFAULT_MINUTE = 30;  // Default minute
const int DEFAULT_SECOND = 0;   // Default second
// ==========================================================================

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(10);

  // Initialize RTC
  RTC.begin();

  // Automatically set the default time on power-up
  setDefaultTime();

  Serial.println("===== RTC Time Control =====");
  Serial.println("Currently using default time:");
  Serial.print(DEFAULT_DAY);
  Serial.print("/");
  Serial.print(DEFAULT_MONTH);
  Serial.print("/");
  Serial.print(DEFAULT_YEAR);
  Serial.print(" ");
  Serial.print(DEFAULT_HOUR);
  Serial.print(":");
  Serial.print(DEFAULT_MINUTE);
  Serial.print(":");
  Serial.println(DEFAULT_SECOND);
  Serial.println("------------------------");
  Serial.println("To change the time, enter: SET YYYY,MM,DD,HH,MM,SS");
  Serial.println("Example: SET 2026,03,17,16,00,00");
}

void loop() {
  // Listen for serial commands (only SET is supported to modify time)
  if (Serial.available() > 0) {
    handleSerialCommand();
  }

  // Continuously read and print the RTC time
  RTCTime now;
  RTC.getTime(now);

  // Print formatted time
  Serial.print(now.getDayOfMonth());
  Serial.print("/");
  Serial.print(Month2int(now.getMonth()));
  Serial.print("/");
  Serial.print(now.getYear());
  Serial.print(" ");
  Serial.print(now.getHour());
  Serial.print(":");
  Serial.print(now.getMinutes());
  Serial.print(":");
  Serial.println(now.getSeconds());

  delay(1000);
}

// Set default time
void setDefaultTime() {
  Month month = static_cast<Month>(DEFAULT_MONTH);
  DayOfWeek weekday = DayOfWeek::MONDAY;

  RTCTime defaultTime(DEFAULT_DAY, month, DEFAULT_YEAR,
                      DEFAULT_HOUR, DEFAULT_MINUTE, DEFAULT_SECOND,
                      weekday, SaveLight::SAVING_TIME_INACTIVE);
  RTC.setTime(defaultTime);
}

// Process serial commands (SET only)
void handleSerialCommand() {
  String cmd = Serial.readStringUntil('\n');
  cmd.trim();

  // Recognize SET command
  if (cmd.startsWith("SET ") && cmd.length() > 4) {
    String timeStr = cmd.substring(4);  // Extract the time string after SET
    parseAndSetTime(timeStr);
    timeSet = true;  // Mark as manually set
  }
}

// Parse time string and write it to RTC
void parseAndSetTime(String timeStr) {
  // Split the time string
  int c1 = timeStr.indexOf(',');
  int c2 = timeStr.indexOf(',', c1 + 1);
  int c3 = timeStr.indexOf(',', c2 + 1);
  int c4 = timeStr.indexOf(',', c3 + 1);
  int c5 = timeStr.indexOf(',', c4 + 1);

  // Extract time parameters
  int y = timeStr.substring(0, c1).toInt();
  int m = timeStr.substring(c1 + 1, c2).toInt();
  int d = timeStr.substring(c2 + 1, c3).toInt();
  int h = timeStr.substring(c3 + 1, c4).toInt();
  int min = timeStr.substring(c4 + 1, c5).toInt();
  int sec = timeStr.substring(c5 + 1).toInt();

  // Write to RTC
  Month month = static_cast<Month>(m);
  DayOfWeek wd = DayOfWeek::MONDAY;
  RTCTime newTime(d, month, y, h, min, sec, wd, SaveLight::SAVING_TIME_INACTIVE);
  RTC.setTime(newTime);

  // Notify that the change was successful
  Serial.println("------------------------");
  Serial.println("✅ Time updated successfully!");
  Serial.print("Current time:");
  Serial.print(d);
  Serial.print("/");
  Serial.print(m);
  Serial.print("/");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(h);
  Serial.print(":");
  Serial.print(min);
  Serial.print(":");
  Serial.println(sec);
  Serial.println("------------------------");
}
