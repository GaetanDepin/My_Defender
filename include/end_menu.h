/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** end_menu
*/

#ifndef END_MENU_H_
#define END_MENU_H_

#include "defender.h"

typedef struct end_menu_s {
    sfFont *font;
    button_t *button;
    sfClock *clock;
    int **move_block;
    bool anim_status;
    int button_status;
    int init;
    sfText *score_txt;
    sfText *game_over_txt;
    float angle;
    float scale;
    sfMusic *tool;
    sfMusic *click;
} end_menu_t;

int display_end_menu(sfRenderWindow *win, end_menu_t data, gameloop_t game);
int event_end_menu(sfRenderWindow *win, end_menu_t *menu);
int end_anim(sfRenderWindow *win, end_menu_t *menu, gameloop_t *gameloop);
int **create_table(void);
void end_anim_monster(monster_t *monster, end_menu_t menu);
int set_end_menu(end_menu_t *data, int score);

#endif /* !END_MENU_H_ */
