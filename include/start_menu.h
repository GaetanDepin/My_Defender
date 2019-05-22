/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** start_menu
*/

#ifndef START_MENU_H_
#define START_MENU_H_

#include "defender.h"

typedef struct start_menu_s {
    sfFont *font_button;
    my_sprite_t how2play;
    button_t *button_array;
    sfTexture *thumb_texture;
    my_sprite_t thumbnail;
    float angle;
    float scale;
    my_sprite_t **map;
    sfMusic *click;
    sfMusic *tool;
    tower_t **tower;
} start_menu_t;

typedef struct map_choice_s {
    button_t *button_array;
    sfFont *font;
    sfMusic *tool;
    sfMusic *click;
    int status;
    button_t button_quit;
} map_choice_t;

int event_start_menu(sfRenderWindow *win, start_menu_t *menu);
int set_start_menu(start_menu_t *all);
void free_start_menu(start_menu_t menu);
int map_menu(sfRenderWindow *win, start_menu_t *menu, int *status);
int map_event(sfRenderWindow *win, map_choice_t *menu);
void how2play(sfRenderWindow *win, start_menu_t *menu);

#endif /* !START_MENU_H_ */
