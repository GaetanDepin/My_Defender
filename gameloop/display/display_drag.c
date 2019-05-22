/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Display the drag and drop
*/

#include "defender.h"

void display_drag(gameloop_t *gameloop)
{
    sfRectangleShape *shape;
    sfSprite *sprite;

    if (gameloop->drag == true) {
        shape = gameloop->pos_tower;
        sprite = gameloop->drag_tower.sprite;
        sfRenderWindow_drawRectangleShape(gameloop->window, shape, NULL);
        sfRenderWindow_drawSprite(gameloop->window, sprite, NULL);
    }
}
