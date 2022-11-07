#include "lights.h"
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#include "config.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

extern uint8_t SCORE;
extern Adafruit_NeoPixel NeoPixel;
extern Adafruit_7segment clockDisplay;

void update_lights(void){
  clockDisplay.print(SCORE, DEC);
  clockDisplay.writeDisplay();
  /*uint8_t s = (float)SCORE/((float)ROUNDS/(float)(LIGHT_NUM+1));
  if(s==0){return;}
  NeoPixel.setPixelColor(s-1, NeoPixel.Color(RED, GREEN, BLUE));*/
  NeoPixel.setPixelColor(0, NeoPixel.Color(RED, GREEN, BLUE));
  NeoPixel.show();
}
