/*
** EPITECH PROJECT, 2019
** Zomby
** File description:
** set window
*/

#include "defender.h"

int set_window(sfRenderWindow **window)
{
    sfVideoMode mode;

    mode.width = WINDOW_W;
    mode.height = WINDOW_H;
    mode.bitsPerPixel = 16;
    *window = sfRenderWindow_create(mode, "My defender", sfFullscreen, NULL);
    if (*window == NULL)
        return (ERROR);
    sfRenderWindow_setFramerateLimit(*window, 60);
    return (SUCCESS);
}
