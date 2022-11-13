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

  if(SCORE==LIGHT_T_1 ){NeoPixel.setPixelColor(0 , NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_2 ){NeoPixel.setPixelColor(1 , NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_3 ){NeoPixel.setPixelColor(2 , NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_4 ){NeoPixel.setPixelColor(3 , NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_5 ){NeoPixel.setPixelColor(4 , NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_6 ){NeoPixel.setPixelColor(5 , NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_7 ){NeoPixel.setPixelColor(6 , NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_8 ){NeoPixel.setPixelColor(7 , NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_9 ){NeoPixel.setPixelColor(8 , NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_10){NeoPixel.setPixelColor(9 , NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_11){NeoPixel.setPixelColor(10, NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_12){NeoPixel.setPixelColor(11, NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_13){NeoPixel.setPixelColor(12, NeoPixel.Color(RED, GREEN, BLUE));}
  if(SCORE==LIGHT_T_14){NeoPixel.setPixelColor(13, NeoPixel.Color(254, 221, 0));}
  if(SCORE==LIGHT_T_15){NeoPixel.setPixelColor(14, NeoPixel.Color(0, 0, 255));}





  
  NeoPixel.show();
}
