/*
** EPITECH PROJECT, 2019
** Zomby
** File description:
** event functions
*/

#include <stdlib.h>
#include "defender.h"

static int mouse_pressed(gameloop_t *gameloop, sfMouseButtonEvent mouse)
{
    sfMusic_play(gameloop->music.click);
    if (mouse_pressed_drag(gameloop, mouse) == 1) {
        reset_tower_info(gameloop->tower_info);
        return (SUCCESS);
    }
    if (event_upgrade(gameloop, mouse) == 1)
        return (SUCCESS);
    event_tower_click(gameloop, mouse);
}

static int mouse_released(gameloop_t *gameloop, sfMouseMoveEvent event)
{
    mouse_released_drag(gameloop, event);
    return (SUCCESS);
}

static int event_switch(gameloop_t *gameloop, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(gameloop->window);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            return (pause_menu(gameloop->window, &gameloop->status));
        break;
    case sfEvtMouseButtonPressed:
        mouse_pressed(gameloop, event.mouseButton);
        break;
    case sfEvtMouseButtonReleased:
        mouse_released(gameloop, event.mouseMove);
        break;
    }
    return (SUCCESS);
}

int event_gameloop(gameloop_t *gameloop, sfEvent event)
{
    while (sfRenderWindow_pollEvent(gameloop->window, &event) == sfTrue)
        if (event_switch(gameloop, event) == ERROR)
            return (ERROR);
    return (SUCCESS);
}
