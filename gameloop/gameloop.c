/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** gameloop
*/

#include "defender.h"

static int gameloop_core(gameloop_t *gameloop)
{
    sfEvent event;

    if (data(gameloop) == ERROR)
        return (ERROR);
    if (animation_gameloop(gameloop) == ERROR)
        return (ERROR);
    if (display_gameloop(gameloop) == ERROR)
        return (ERROR);
    if (event_gameloop(gameloop, event) == ERROR)
        return (ERROR);
}

int gameloop(sfRenderWindow *win, char *path_map)
{
    gameloop_t my_gameloop;

    if ((set_gameloop(path_map, &my_gameloop)) == ERROR)
        return (ERROR);
    my_gameloop.window = win;
    while (sfRenderWindow_isOpen(win) && my_gameloop.hp.nb > 0) {
        if (my_gameloop.status != 0)
            break;
        if (gameloop_core(&my_gameloop) == ERROR)
            return (ERROR);
    }
    if (my_gameloop.status == 0)
        if (end_menu(win, &my_gameloop) == 1)
            gameloop(win, path_map);
    free_gameloop(my_gameloop);
    if (my_gameloop.status == 2)
        sfRenderWindow_close(win);
    return (SUCCESS);
}
