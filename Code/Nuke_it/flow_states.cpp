#include "flow_states.h"
#include "stdint.h"
#include "config.h"

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
}

void SELECT_HANDLER(void){
  //RNG HERE, for now we will work out solar logic
  STATE = SOLAR_STATE;
}

void WIN_HANDLER(void){
  //Handler for scoring a point

  //Move back to select handler
  STATE = SELECT_STATE;
}

void LOSS_HANDLER(void){
  //Game end state

  //Hold here, reset button must be pressed
  while(1);
}

void VICTORY_HANDLER(void){
  //Game win state

  //Hold here, reset must be pressed
  while(1);
}

void UNDEFINED_HANDLER(void){
  //GO back to start
  STATE = START_STATE;
}
