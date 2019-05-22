/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** pause_menu
*/

#ifndef PAUSE_MENU_H_
#define PAUSE_MENU_H_

#include "defender.h"

typedef struct pause_menu_t {
    sfFont *font;
    sfText *text;
    button_t *button_array;
    int button_status;
    sfMusic *click;
    sfMusic *tool;
} pause_menu_t;

int event_pause_menu(sfRenderWindow *win, pause_menu_t *menu);

#endif /* !PAUSE_MENU_H_ */
