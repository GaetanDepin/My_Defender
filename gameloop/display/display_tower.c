/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display tower and portal
*/

#include <stdlib.h>
#include "defender.h"

static void display_tower1(sfRenderWindow *win, tower_t tower)
{
    if (tower.sprite.sprite == NULL)
        return;
    sfRenderWindow_drawSprite(win, tower.sprite.sprite, NULL);
}

int display_twr(sfRenderWindow *window, my_sprite_t **sprite, tower_t **tower)
{
    for (int i = 0 ; sprite[i] != NULL ; i++)
        for (int ii = 0 ; sprite[i][ii].sprite != NULL ; ii++)
            display_tower1(window, tower[i][ii]);
}
