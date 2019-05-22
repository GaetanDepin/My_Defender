/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

//Include CSFML Lib
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

//Basic variable
typedef enum Bool_e{
    true = 1,
    false = 0
} bool;

//Include all header
#include "img_data.h"
#include "base.h"
#include "gameloop.h"
#include "tool.h"

//Basic constant
static const int SUCCESS = 0;
static const int ERROR = 84;
static const int TRUE = 1;
static const int FALSE = 0;

//Constant to move
static const float SCALE = 1;
static const int TILE_SIZE = 83;
static const int MAP_W = 24;
static const int MAP_H = 13;

//Font
static const char *FONT = "resource/DK_Display_Patrol.otf";
static const char *FONT2 = "resource/Nickname.otf";

//Main function
int defender(int argc, char **argv);
int start_menu(sfRenderWindow *win);
int end_menu(sfRenderWindow *win, gameloop_t *gameloop);

#endif /* !DEFENDER_H_ */
