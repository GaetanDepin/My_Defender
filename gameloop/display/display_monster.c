/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Display the monsters sprites
*/

#include "defender.h"

void display_monster(gameloop_t *gameloop)
{
    monster_t *monster = gameloop->monster;
    sfRenderWindow *win = gameloop->window;

    while (monster != NULL) {
        sfRenderWindow_drawSprite(win, monster->sprite.sprite, NULL);
        if (monster->alive == true)
            display_health_bar(win, monster->heatlh_bar);
        monster = monster->next;
    }
}
