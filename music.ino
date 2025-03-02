#include <Arduino.h> 

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '0') {
      noTone(8); 
    }
    else if (c == '1') {
      play_style();
      noTone(8);
    }
    else if (c == '2') {
      play_kahoot();
      noTone(8);
    }
    else if (c == '3') {
      play_christmas();
      noTone(8);
    }
  }
}


int style_melody[] = {
  NOTE_FS3, NOTE_B3, NOTE_D4, NOTE_D4,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_B3,NOTE_B3,NOTE_B3,0,NOTE_B3,NOTE_D4,NOTE_D4,NOTE_B3,NOTE_B3,0,NOTE_B3,NOTE_B3,NOTE_B3,NOTE_B3,NOTE_B3, 
  // repeat!
  NOTE_FS3,NOTE_B3,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_B3,NOTE_B3,NOTE_B3,0,NOTE_B3,NOTE_D4,NOTE_D4,NOTE_B3,NOTE_B3,0, 
  // actual lyric part
  NOTE_E4,NOTE_FS4,NOTE_FS4,0,NOTE_D4,NOTE_E4,NOTE_FS4,0,NOTE_FS4,NOTE_E4,NOTE_E4,0,NOTE_D4,NOTE_E4,NOTE_FS4,NOTE_FS4,0,NOTE_B3,NOTE_CS4,NOTE_E4,0,NOTE_A3,NOTE_B3,NOTE_D4,0, 
  // and then repeatttt
  NOTE_E4,NOTE_FS4,NOTE_FS4,0,NOTE_D4,NOTE_E4,NOTE_FS4,0,NOTE_FS4,NOTE_E4,NOTE_E4,0,NOTE_D4,NOTE_E4,NOTE_FS4,NOTE_FS4,0,NOTE_B3,NOTE_CS4,NOTE_E4,0,NOTE_A3,NOTE_B3,NOTE_D4,0, 
  // next part woohoo
  NOTE_D4,NOTE_D4,NOTE_A4,NOTE_A4,NOTE_FS4,NOTE_E4,0,NOTE_A4, 
  // after oh
  0,NOTE_A4,NOTE_A4,0,NOTE_G4,NOTE_G4,0,NOTE_FS4,NOTE_FS4,0,NOTE_E4,NOTE_E4,0,NOTE_D4,NOTE_E4,NOTE_FS4,NOTE_FS4,0,NOTE_D4,NOTE_E4,NOTE_FS4,NOTE_FS4,0, 
  // and i should just tell u to leave cus i
  NOTE_D4,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_B3,NOTE_E4,NOTE_B3,NOTE_B3,0, 
  // know exactly where it leads but i
  NOTE_D4,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_B3,NOTE_E4,NOTE_B3,NOTE_B3,0, 
  // watch us go round and round each time
  NOTE_B3,NOTE_B3,NOTE_D4,NOTE_D4,NOTE_B3,NOTE_D4,NOTE_B3,NOTE_D4,0,NOTE_E4,NOTE_FS4,NOTE_A4,NOTE_A4,0, 
  // you got that james dean daydream look in ur eye
  NOTE_FS4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_FS4,NOTE_E4,NOTE_A4,0, 
  // and i got that red lip classic thing that u like
  NOTE_FS4,NOTE_E4,NOTE_D4,NOTE_B3,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_FS4,NOTE_E4,NOTE_A4,0,
  // and when we go crashing downnnnn
  NOTE_FS4,NOTE_E4,NOTE_D4,NOTE_B3,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_FS4,NOTE_E4,NOTE_A4, 0, 
  // we never go out of styleeee 
  NOTE_FS4,NOTE_E4,NOTE_D4,NOTE_B3,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_FS4,NOTE_E4,NOTE_D4,NOTE_B3,NOTE_D5,NOTE_D5,NOTE_D5, 
};


int style_note_durations[] = {
  8,8,4,4,4,4,8,4,8,8,8,8,8,4,4,8,8,8,4,4,8,8,8,8,8,4,4,4,4,8,4,8,8,8,8,8,4,4,8,8,4,
  // lyric part!!
  4,8,2,4,8,8,8,8,4,8,8,8,4,4,8,2,4,8,8,2,8,8,8,2,4,
  // repeat!
  4,8,2,4,8,8,8,8,4,8,8,8,4,4,8,2,4,8,8,2,8,8,8,2,4,
  // next part 
  8,8,4,4,4,4,
  8, 8, 8,// oh! 
  8,4,8,8,4,8,8,4,8,8,4,8,4,4,8,2,
  8,4,4,8,2,
  4, // pause
  8,8,8,8,8,8,4,8,4,4,
  8,8,8,8,8,8,4,8,4,4,
  8,8,4,4,8,4,4,4,8,
  8,8,4,4,8,
  4,4,4,2,2,2,2,4,8,3,2,16,
  4,8,8,4,2,2,2,2,4,8,3,2,16,
  4,8,8,4,2,2,2,4,4,4,8,3,2,16,
  4,8,8,4,3,3,2,4,8,8,4,3,3,2
};

void play_style() {
  for (int this_note = 0; this_note < 209; this_note++) {
    int note_duration = 1500 / style_note_durations[this_note];
    tone(8, style_melody[this_note], note_duration);
    int pause = note_duration * 1.1;
    delay(pause);
    noTone(8);
    char c = Serial.read();
      if (c == '0') {
      break;
  }
}
}

int kahoot_melody[] = {
  NOTE_C3,NOTE_G4,NOTE_G4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_B3,NOTE_C4,NOTE_G4,NOTE_G4,0,
  NOTE_G4,NOTE_G4,NOTE_F3,NOTE_F4,NOTE_F4,NOTE_F3,NOTE_F4,NOTE_F4,0,
  NOTE_F4,NOTE_F4,NOTE_E3,NOTE_D3,NOTE_E4,NOTE_E4,

  NOTE_C3,NOTE_G4,NOTE_G4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_B3,NOTE_C4,NOTE_G4,NOTE_G4,0,
  NOTE_G4,NOTE_G4,NOTE_F3,NOTE_F4,NOTE_F4,NOTE_F3,NOTE_F4,NOTE_F4,0,
  NOTE_F4,NOTE_F4,NOTE_E3,NOTE_D3,NOTE_E4,NOTE_E4,
  
  NOTE_E4,0,NOTE_E4,0,NOTE_G4,0,NOTE_G4,0,NOTE_C4,0,NOTE_C4,0,NOTE_G4,0,NOTE_G4,0,0,
  NOTE_G4,0,NOTE_G4,0,0,

  NOTE_G4,0,NOTE_G4,0,NOTE_F3,NOTE_F4,0,NOTE_F4,0,NOTE_F3,NOTE_F4,0,NOTE_F4,0,0,NOTE_F4,0,
  NOTE_F4,0,NOTE_E3,NOTE_D3,NOTE_E4,0,NOTE_E4,0,
  
  NOTE_E4,0,NOTE_E4,0,NOTE_G4,0,NOTE_G4,0,
  NOTE_C4,0,NOTE_C4,0,NOTE_G4,0,NOTE_G4,0,0,
 
  NOTE_G4,0,NOTE_G4,0,0,
  NOTE_G4,0,NOTE_G4,0,NOTE_F3,NOTE_F4,0,NOTE_F4,0,NOTE_F3,NOTE_F4,0,NOTE_F4,0,0,
  NOTE_F4,0,NOTE_F4,0,NOTE_E3,NOTE_D3,NOTE_E4,0,NOTE_E4,0,
  // 146 notes total 
};

int kahoot_note_durations[] = {
  4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4,
  8, 8, 4, 8, 8, 4, 8, 8, 4,
  8, 8, 8, 8, 8, 8,
  4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 4,
  8, 8, 4, 8, 8, 4, 8, 8, 4,
  8, 8, 8, 8, 8, 8,
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 4,
  16, 16, 16, 16, 4,
  16, 16, 16, 16, 4, 16, 16, 16, 16, 4, 16, 16, 16, 16, 4,
  16, 16, 16, 16, 8, 8, 16, 16, 16, 16,
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 4,
  16, 16, 16, 16, 4,
  16, 16, 16, 16, 4, 16, 16, 16, 16, 4, 16, 16, 16, 16, 4,
  16, 16, 16, 16, 8, 8, 16, 16, 16, 16,
}; 

void play_kahoot() {
  for (int this_note = 0; this_note < 146; this_note++) {
    int note_duration = 1500 / kahoot_note_durations[this_note];
    tone(8, kahoot_melody[this_note], note_duration);
    int pause = note_duration * 1.3;
    delay(pause);
    noTone(8);
    char c = Serial.read();
      if (c == '0') {
      break;
  }
}
}

int christmas_melody[] = {
  NOTE_G4,NOTE_B4,NOTE_D5,NOTE_FS5,NOTE_G5,NOTE_FS5,NOTE_D5,NOTE_B4,NOTE_G4,NOTE_C5,NOTE_D5,NOTE_G5,NOTE_D5,0,NOTE_A4,NOTE_G4,0,NOTE_B4,NOTE_D5,NOTE_FS5,NOTE_G5,NOTE_FS5,NOTE_E5,NOTE_D5,0,

  NOTE_A5,NOTE_G5,NOTE_G5,NOTE_FS5,NOTE_FS5,NOTE_G5,NOTE_FS5,NOTE_E5,NOTE_D5,0,
  
  NOTE_C5,NOTE_E5,NOTE_G5,NOTE_A5,NOTE_B5,NOTE_A5,NOTE_G5,NOTE_E5,0,NOTE_B5,NOTE_D6,NOTE_A5,NOTE_G5,NOTE_G5,NOTE_A5,NOTE_G5,NOTE_E5,NOTE_D5,0,

  NOTE_G5,NOTE_A5,NOTE_FS5,NOTE_G5,NOTE_E5,NOTE_FS5,NOTE_E5,NOTE_D5,0,
  
  NOTE_B5,NOTE_A5,NOTE_A5,NOTE_G5,NOTE_FS5,NOTE_E5,NOTE_FS5,NOTE_E5,NOTE_D5,0,

  NOTE_D5,NOTE_E5,NOTE_G5,NOTE_D6,NOTE_C6,NOTE_D6,NOTE_C6,0,NOTE_B5,NOTE_A5,NOTE_G5,NOTE_E5,NOTE_D5,NOTE_A5,NOTE_B5,NOTE_A5,NOTE_B5,NOTE_G5,NOTE_E5,NOTE_D5,0,

  NOTE_A5,NOTE_G5,
};

int christmas_note_durations[] = {
  3,3,3,3,3,3,3,3, //8
  3,3,3,3,2,4, //6
  3,2,4,3,3.5,4,3,3.5,3.5,3.5,4, //10
  3,4,4,3,3.5,3.5,3,3,3,4, //9
  4,4,3,4,3,4,3.5,3.5,4, //8
  4,4,4,3.5,4,3,4,3.5,4,4, //9
  3,4,3,4,3,4,4,4,4,
  3,4,4,3.5,4,3.5,4,4,3.5,4,
  3,4,4,4,4,8,2,
  3,3,3,3,3,2,2,3,10,10,10,10,4,4,
  1.8,1.8
};

void play_christmas() {
  for (int this_note = 0; this_note < 97; this_note++) {
    int note_duration = 1500 / christmas_note_durations[this_note];
    tone(8, christmas_melody[this_note], note_duration);
    int pause = note_duration * 1.1;
    delay(pause);
    noTone(8);
    char c = Serial.read();
      if (c == '0') {
      break;
  }
}
}
