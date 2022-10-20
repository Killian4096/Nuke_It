#ifndef NUKE_CONFIG
#define NUKE_CONFIG
#include "Arduino.h"

//States
#define START_STATE    0
#define SELECT_STATE   1
#define SOLAR_STATE    2
#define WINDMILL_STATE 3
#define NUCLEAR_STATE  4
#define WIN_STATE      5
#define LOSS_STATE     6
#define VICTORY_STATE  7

//PINS
#define SOLAR_PIN A0
#define WINDMILL_PIN A1
#define NUCLEAR_PIN A2

#define LIGHT_PIN 7
#define SOUND_PIN 8
#define RELAY_PIN 9

//Debug
#define DEBUG_WIN 5
#define DEBUG_LOSS 6


//Solar Settings
#define SOLAR_CUTOFF 1.0

//Windmill Settings
#define WINDMILL_CUTOFF = 0.7

//Nuclear Settings

//Window Settings
#define START_WINDOW 2000
#define DECREMENT_WINDOW 1
#define ROUNDS 10

//Sound Settings

//Lights
#define LIGHT_NUM 8

//Color
#define RED    8
#define GREEN  0
#define BLUE   8

#endif
