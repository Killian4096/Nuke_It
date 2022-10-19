#include "flow_states.h"
#include "stdint.h"
#include "config.h"
#include "lights.h"

extern uint8_t STATE;

extern uint8_t SCORE;
extern uint32_t WINDOW;

void START_HANDLER(void){
  
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
  STATE = SOLAR_STATE;
  return;
}

void WIN_HANDLER(void){
  update_lights();
  digitalWrite(DEBUG_WIN, 1);
  delay(1000);
  digitalWrite(DEBUG_WIN, 0);
  delay(1000);

  WINDOW = WINDOW - DECREMENT_WINDOW;
  SCORE++;

  if(SCORE==ROUNDS){
    STATE = VICTORY_STATE;
    return;
  }
  STATE = SELECT_STATE;
  return;
}

void LOSS_HANDLER(void){
  digitalWrite(DEBUG_LOSS, 1);
  delay(333);
  digitalWrite(DEBUG_LOSS, 0);
  delay(334);
  digitalWrite(DEBUG_LOSS, 1);
  delay(333);
  digitalWrite(DEBUG_LOSS, 0);
  delay(1000);

  //Hold here, reset button must be pressed
  while(1);
}

void VICTORY_HANDLER(void){
  //Game win state

  //Hold here, reset must be pressed
  while(1){
    digitalWrite(DEBUG_WIN, 1);
    delay(300);
    digitalWrite(DEBUG_WIN, 0);
    delay(300);
  }
}

void UNDEFINED_HANDLER(void){
  //GO back to start
  STATE = START_STATE;
}
