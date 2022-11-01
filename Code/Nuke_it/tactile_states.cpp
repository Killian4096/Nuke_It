#include "config.h"
#include "stdint.h"
#include "tactile_states.h"
#include "Arduino.h"

extern uint8_t STATE;
extern uint32_t WINDOW;

void SOLAR_HANDLER(void){
  int reference;
  uint32_t counter;

  //Sound
  tone(SOUND_PIN, 300, 250);
  delay(250);

  counter = 0;

  reference = analogRead(SOLAR_PIN);

  while(counter < WINDOW){
    if(analogRead(SOLAR_PIN) - reference >= SOLAR_CUTOFF){
      STATE=WIN_STATE;
      return;
    }
    counter++;
    delay(1);
  }
  STATE=LOSS_STATE;
  return;
}

void WINDMILL_HANDLER(void){
  uint32_t counter;

  tone(SOUND_PIN, 300, 83);
  delay(166);
  tone(SOUND_PIN, 300, 83);

  counter = 0;

  while(counter < WINDOW){
    if(analogRead(WINDMILL_PIN) >= WINDMILL_CUTOFF){
      STATE=WIN_STATE;
      return;
    }
    counter++;
    delay(1);
  }
  STATE=LOSS_STATE;
  return;
}

void NUCLEAR_HANDLER(void){
  uint32_t counter;

  tone(SOUND_PIN, 300, 50);
  delay(100);
  tone(SOUND_PIN, 300, 50);
  delay(100);
  tone(SOUND_PIN, 300, 50);

  counter = 0;
  while(counter < WINDOW){
    if(digitalRead(NUCLEAR_PIN)){
      STATE=WIN_STATE;
      return;
    }
    counter++;
    delay(1);
  }
  STATE=LOSS_STATE;
  return;
}
