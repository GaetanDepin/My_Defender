/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Display the Graphical User Interface
*/

#include "defender.h"

static int display_tower_button(sfRenderWindow *win, my_sprite_t *button)
{
    for (int i = 0 ; button[i].sprite != NULL ; i++) {
        sfRenderWindow_drawSprite(win, button[i].sprite, NULL);
    }
}

int display_gui(gameloop_t *gameloop)
{
    sfSprite *sprite = gameloop->tool_bar.sprite;

    sfRenderWindow_drawSprite(gameloop->window, sprite, NULL);
    display_tower_button(gameloop->window, gameloop->button_tower);
}
