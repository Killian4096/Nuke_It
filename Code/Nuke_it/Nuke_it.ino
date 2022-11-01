#include "config.h"
#include "flow_states.h"
#include "tactile_states.h"
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_NeoPixel NeoPixel(LIGHT_NUM, LIGHT_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_7segment clockDisplay = Adafruit_7segment();

//State Identifier
uint8_t STATE;
uint8_t SCORE;
uint32_t WINDOW;

void setup() {
  //DEBUG STUFF
  //pinMode(DEBUG_WIN, OUTPUT);
  //pinMode(DEBUG_LOSS, OUTPUT);
  randomSeed(analogRead(A3));


  clockDisplay.begin();

  //Clear
  NeoPixel.begin();
  NeoPixel.clear();
  NeoPixel.show();
  
  STATE = START_STATE;

  //Serial.begin(9600);
}

void loop() {
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
