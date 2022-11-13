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
  tone(SOUND_PIN, 300, 100);
  delay(100);
  tone(SOUND_PIN, 400, 100);
  delay(100);
  tone(SOUND_PIN, 500, 100);
  delay(100);
  delay(500);

  if(SCORE==ROUNDS){
    STATE = VICTORY_STATE;
    return;
  }
  STATE = SELECT_STATE;
  return;
}

void LOSS_HANDLER(void){
  //Hold here, reset must be pressed
  tone(SOUND_PIN, 150, 250);
  delay(250);
  tone(SOUND_PIN, 100, 250);
  delay(250);
  tone(SOUND_PIN, 50, 250);
  delay(250);
  while(1){
    delay(1000);
  }
}

void VICTORY_HANDLER(void){
  //Game win state

  //Hold here, reset must be pressed
  for(int i=0;i<3;i++){
    tone(SOUND_PIN, 300, 150);
    delay(300);
    tone(SOUND_PIN, 300, 150);
    delay(150);
    tone(SOUND_PIN, 130, 150);
    delay(150);
    tone(SOUND_PIN, 450, 500);
    delay(500);
  }
  while(1){
    delay(1000);
  }
}

void UNDEFINED_HANDLER(void){
  //GO back to start
  STATE = START_STATE;
}
