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

#define SOUND_PIN 3

#define LIGHT_PIN 7

//Debug
#define DEBUG_WIN 5
#define DEBUG_LOSS 6


//Solar Settings
#define SOLAR_CUTOFF 51 //Normalize between 0 and 1024

//Windmill Settings
#define WINDMILL_CUTOFF  72

//Nuclear Settings

//Window Settings
#define START_WINDOW 2000
#define DECREMENT_WINDOW 20
#define ROUNDS 15


//Lights
#define LIGHT_NUM 15

//Color
#define RED    128
#define GREEN  128
#define BLUE   100

//LIGHT CONFIG
#define LIGHT_T_1  1
#define LIGHT_T_2  2
#define LIGHT_T_3  3
#define LIGHT_T_4  4
#define LIGHT_T_5  5
#define LIGHT_T_6  6
#define LIGHT_T_7  7
#define LIGHT_T_8  8
#define LIGHT_T_9  9
#define LIGHT_T_10 10
#define LIGHT_T_11 11
#define LIGHT_T_12 12
#define LIGHT_T_13 13
#define LIGHT_T_14 14
#define LIGHT_T_15 15

#endif
