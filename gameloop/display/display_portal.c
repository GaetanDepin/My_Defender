/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Display the portals
*/

#include <stdlib.h>
#include "defender.h"

// NORM

void display_portal(gameloop_t *gameloop)
{
    sfRenderWindow_drawSprite(gameloop->window, gameloop->portal1.sprite, NULL);
    sfRenderWindow_drawSprite(gameloop->window, gameloop->portal2.sprite, NULL);
}
