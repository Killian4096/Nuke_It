#include "flow_states.h"
#include "stdint.h"
#include "config.h"
#include "lights.h"

extern uint8_t STATE;

extern uint8_t SCORE;
extern uint32_t WINDOW;


void START_HANDLER(void){

  update_lights();
  
  //Initialization if needed, most likely to add delay here

  //Init Score
  SCORE = 0;
  WINDOW = START_WINDOW;

  //Move to Selection State
  STATE = SELECT_STATE;
  return;
}

void SELECT_HANDLER(void){
  
  //RNG HERE, for now we will work out solar logic
  STATE = random(SOLAR_STATE,NUCLEAR_STATE+1);
  return;
}

void WIN_HANDLER(void){
  WINDOW = WINDOW - DECREMENT_WINDOW;
  SCORE++;
  update_lights();
  tone(SOUND_PIN, 300, 500);
  delay(1000);

  if(SCORE==ROUNDS){
    STATE = VICTORY_STATE;
    return;
  }
  STATE = SELECT_STATE;
  return;
}

void LOSS_HANDLER(void){
  //Hold here, reset must be pressed
  while(1){
    tone(SOUND_PIN, 200, 250);
    delay(250);
    tone(SOUND_PIN, 40, 250);
    delay(250);
  }
}

void VICTORY_HANDLER(void){
  //Game win state

  //Hold here, reset must be pressed
  while(1){
    tone(SOUND_PIN, 400, 250);
    delay(500);
    tone(SOUND_PIN, 400, 250);
    delay(500);
  }
}

void UNDEFINED_HANDLER(void){
  //GO back to start
  STATE = START_STATE;
}
