#include "pitches.h"

uint8_t const pin = 12;

// notes in the melody:
int const happyBirthdayMelody[]{
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_B4,           // 1st verse
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5,           // 2nd verse
  NOTE_G4, NOTE_G4, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4,  // 3rd verse
  NOTE_F5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_C5            // 4th verse
};

// duration of each note (1 = whole note, 2 = half note, 4 = quarter note, ...)
int const happyBirhtdayDuration[]{
  8, 8, 4, 4, 4, 2,     // 1st verse
  8, 8, 4, 4, 4, 2,     // 2nd verse
  8, 8, 4, 4, 4, 4, 2,  // 3rd verse
  8, 8, 4, 4, 4, 2      // 4th verse
};

// whole note duration in ms. (= 100 bpm @ four-four time)
int const duration = 2400;

void setup() {
  // nothing to set up.
}

void loop() {
  for (int thisNote = 0; thisNote < 25; thisNote++) {
    int noteDuration = (duration / happyBirhtdayDuration[thisNote]);
    tone(pin, happyBirthdayMelody[thisNote], noteDuration);
    // let the note ring
    delay(noteDuration);
  }
  // restart after two seconds
  delay(2000);
}
