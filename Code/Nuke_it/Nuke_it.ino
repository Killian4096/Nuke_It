#include "config.h"
#include "flow_states.h"
#include "tactile_states.h"

//State Identifier
uint8_t STATE;
uint8_t SCORE;
uint32_t WINDOW;

void setup() {
  STATE = START_STATE;
}

void loop() {
  while(1){
    switch(STATE){
      //Start State
      case START_STATE:
        START_HANDLER();
        break;
      
      //Selector State
      case SELECT_STATE:
        SELECT_HANDLER();
        break;
      
      //Tactile States
      case SOLAR_STATE:
        SOLAR_HANDLER();
        break;
      case WINDMILL_STATE:
        WINDMILL_HANDLER();
        break;
      case NUCLEAR_STATE:
        NUCLEAR_HANDLER();
        break;

      //Result States
      case WIN_STATE:
        WIN_HANDLER();
        break;
      case LOSS_STATE:
        LOSS_HANDLER();
        break;
      case VICTORY_STATE:
        VICTORY_HANDLER();
        break;
      default:
        UNDEFINED_HANDLER();
        break;
    }
  }
}
