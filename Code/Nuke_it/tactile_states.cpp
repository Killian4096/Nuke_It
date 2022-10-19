#include "config.h"
#include "stdint.h"
#include "tactile_states.h"
#include "Arduino.h"

extern uint8_t STATE;
extern uint32_t WINDOW;

void SOLAR_HANDLER(void){
  int reference;
  uint32_t counter;

  counter = 0;

  reference = analogRead(SOLAR_PIN);

  while(counter < WINDOW){
    if(analogRead(SOLAR_PIN) >= 1024*(SOLAR_CUTOFF/5.00)){
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

  counter = 0;
  while(counter < WINDOW){
    if(digitalRead(WINDMILL_PIN)){
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
