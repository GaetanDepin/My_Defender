/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** scale the tower button
*/

#include "defender.h"

static void play_tool(sfVector2f scale, sfMusic *tool)
{
    if (scale.x == 1 && scale.y == 1)
        sfMusic_play(tool);
}

void scale_button1(sfVector2i mouse, sfFloatRect rect,
sfSprite *sprite, sfMusic *music)
{
    sfVector2f scale = sfSprite_getScale(sprite);

    if (mouse.x >= rect.left && mouse.x <= rect.left + rect.width) {
        if (mouse.y >= rect.top && mouse.y <= rect.top + rect.height) {
            play_tool(scale, music);
            sfSprite_setScale(sprite, ini_vector(1.1, 1.1));
        } else
            sfSprite_setScale(sprite, ini_vector(1, 1));
    } else
        sfSprite_setScale(sprite, ini_vector(1, 1));
}

void scale_button(gameloop_t *gameloop)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(gameloop->window);
    sfFloatRect rect;

    for (int i = 0 ; i < 6 ; i++) {
        rect = sfSprite_getGlobalBounds(gameloop->button_tower[i].sprite);
        scale_button1(mouse, rect, gameloop->button_tower[i].sprite,
        gameloop->music.tool);
    }
}
