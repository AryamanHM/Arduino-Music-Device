//SkillShare Class
//Your first Arduino project: Design and Build a Colorful Musical Toy
//Bill Jamshedji - DroneBot Workshop
//For more information please visit http://dronebotworkshop.com


#include "pitches.h"
#define NO_SOUND 0 // make the rests in the music

//Define Constants

const int piezoPin = 12; //piezo speaker
const int rPin = 5;  //red LED or color #1
const int wPin = 4;  //white LED or color #2
const int bPin = 3;  //blue LED or color #3
const int pPin = 2;  //pushbutton switch

int ledState = 0;
int ledOn = false;

// notes for tune - Star Spangled Banner
// change this section for different tune

int melody[] = {
  NOTE_F5,NOTE_D5,NOTE_AS4,NOTE_D5,NOTE_F5,NOTE_AS5,NOTE_D6,NOTE_C6,NOTE_AS5,NOTE_D5,NOTE_E5,NOTE_F5,
  NOTE_F5,NOTE_F5,NOTE_D6,NOTE_C6,NOTE_AS5,NOTE_A5,NOTE_G5,NOTE_A5,NOTE_AS5,NOTE_AS5,NOTE_F5,NOTE_D5,NOTE_AS4,
  NOTE_D6,NOTE_D6,NOTE_D6,NOTE_DS6,NOTE_F6,NOTE_F6,NOTE_DS6,NOTE_D6,NOTE_C6,NOTE_D6,NOTE_DS6,NOTE_DS6,
  NO_SOUND,NOTE_DS6,NOTE_D6,NOTE_C6,NOTE_AS5,NOTE_A5,NOTE_G5,NOTE_A5,NOTE_AS5,NOTE_D5,NOTE_E5,NOTE_F5,
  NOTE_F5,NOTE_AS5,NOTE_AS5,NOTE_AS5,NOTE_A5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_C6,NOTE_DS6,NOTE_D6,NOTE_C6,NOTE_AS5,NOTE_AS5,NOTE_A5,
  NOTE_F5,NOTE_F5,NOTE_AS5,NOTE_C6,NOTE_D6,NOTE_DS6,NOTE_F6,NOTE_AS5,NOTE_C6,NOTE_D6,NOTE_DS6,NOTE_C6,NOTE_AS5
};

// durations: 2 = half note, 4 = quarter note, 8 = eight note etc
// also change this section to change tunes - 1 entry for each note in sequence

float noteDurations[] = {
  6,12,4,4,4,2,6,12,4,4,4,2,
  8,8,8/2.9,8,4,2,8,8,4,4,4,4,4,
  6,12,4,4,4,2,8,8,4,4,4,2,
  8,8,8/2.9,8,4,2,8,8,4,4,4,2,
  4,4,4,8,8,4,4,4,4,8,8,8,8,4,4,
  8,8,8/2.9,8,8,8,2,8,8,4,4,4,2
};

// calculates the number of elements in the melody array.
int musicLength=sizeof(melody)/sizeof('NOTE_F5');

void setup() {  
  pinMode(pPin, INPUT);  //pushbutton is an INPUT
  pinMode(piezoPin, OUTPUT);  //piezo speaker is an OUTPUT
  pinMode(rPin, OUTPUT);  //red LED is an OUTPUT
  pinMode(wPin, OUTPUT);  //white LED is an OUTPUT
  pinMode(bPin, OUTPUT);  //blue LED is an OUTPUT
}

void loop() {
  int pPinState=digitalRead(pPin);
  if(pPinState==HIGH) {
    ledState = 1;
  }
  if (pPinState==LOW and ledState ==1) {
    ledState = 2;
    ledOn = not ledOn;
  }
  if (ledOn && pPinState!=HIGH) {
    for (int thisNote = 0; thisNote < musicLength; thisNote++) {
      // blink the three LEDs in sequence
      if (thisNote%3==0){    
        digitalWrite(rPin, HIGH);
        digitalWrite(wPin, LOW);
        digitalWrite(bPin, LOW);
      }
      else if (thisNote%3==1){    
        digitalWrite(rPin, LOW);
        digitalWrite(wPin, HIGH);
        digitalWrite(bPin, LOW);
      }
      else if (thisNote%3==2){    
        digitalWrite(rPin, LOW);
        digitalWrite(wPin, LOW);
        digitalWrite(bPin, HIGH);
      }

      // calculate the note duration. change tempo by changing 2000 to other values
      int noteDuration = 2000/noteDurations[thisNote];
      tone(piezoPin, melody[thisNote],noteDuration);
      
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well
      float pauseBetweenNotes = noteDuration * 1.30;
      
      //split the delay into two parts and check to see
      //whether the pushbutton is pressed to turn off
      //the sound and light
      delay(pauseBetweenNotes/2);
      if(digitalRead(pPin)==HIGH) {
        break;      
      }
      delay(pauseBetweenNotes/2);
      if(digitalRead(pPin)==HIGH) {
        break;      
      }
    }
  }
  else if (not ledOn) {
    digitalWrite(rPin, LOW);
    digitalWrite(wPin, LOW);
    digitalWrite(bPin, LOW);
  }
}
