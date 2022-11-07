#include "config.h"
#include "stdint.h"
#include "tactile_states.h"
#include "Arduino.h"

extern uint8_t STATE;
extern uint32_t WINDOW;

void SOLAR_HANDLER(void){
  uint32_t result;

  //Sound
  tone(SOUND_PIN, 300, 250);
  delay(250);

  result = TACTILE_CHECKER();

  if(result == SOLAR_STATE){
    STATE = WIN_STATE;
    return;
  }
  STATE = LOSS_STATE;
  return;
}


void WINDMILL_HANDLER(void){
  uint32_t result;

  tone(SOUND_PIN, 300, 83);
  delay(166);
  tone(SOUND_PIN, 300, 83);
  delay(83);

  result = TACTILE_CHECKER();

  if(result == WINDMILL_STATE){
    STATE = WIN_STATE;
    return;
  }
  STATE = LOSS_STATE;
  return;
}

void NUCLEAR_HANDLER(void){
  uint32_t result;

  tone(SOUND_PIN, 300, 50);
  delay(100);
  tone(SOUND_PIN, 300, 50);
  delay(100);
  tone(SOUND_PIN, 300, 50);
  delay(50);

  result = TACTILE_CHECKER();

  if(result == NUCLEAR_STATE){
    STATE = WIN_STATE;
    return;
  }
  STATE = LOSS_STATE;
  return;
}

uint32_t TACTILE_CHECKER(void){
  int reference;
  uint32_t counter;
  counter = 0;
  reference = analogRead(SOLAR_PIN);
  while(counter < WINDOW){
    if(analogRead(SOLAR_PIN) - reference >= SOLAR_CUTOFF){
      /*tone(SOUND_PIN, 100, 1000);
      delay(1000);*/
      return SOLAR_STATE;
    }
    if(analogRead(WINDMILL_PIN) >= WINDMILL_CUTOFF){
      /*tone(SOUND_PIN, 500, 1000);
      delay(1000);*/
      return WINDMILL_STATE;
    }
    if(digitalRead(NUCLEAR_PIN)){
      /*tone(SOUND_PIN, 1000, 1000);
      delay(1000);*/
      return NUCLEAR_STATE;
    }
    counter++;
    delay(1);
  }
  return LOSS_STATE;
}
