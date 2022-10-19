#include "lights.h"
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#include "config.h"

extern uint8_t SCORE;
extern Adafruit_NeoPixel NeoPixel;

void update_lights(void){
  uint8_t s = (float)SCORE/((float)ROUNDS/(float)(LIGHT_NUM+1));
  if(s==0){return;}
  NeoPixel.setPixelColor(s-1, NeoPixel.Color(RED, GREEN, BLUE));
  NeoPixel.show();
}
