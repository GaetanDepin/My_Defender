/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Display the text
*/

#include "defender.h"

//NORM

void display_text(gameloop_t *gameloop)
{
    sfRenderWindow_drawText(gameloop->window, gameloop->gold.text, NULL);
    sfRenderWindow_drawText(gameloop->window, gameloop->hp.text, NULL);
    sfRenderWindow_drawText(gameloop->window, gameloop->score.text, NULL);
}
