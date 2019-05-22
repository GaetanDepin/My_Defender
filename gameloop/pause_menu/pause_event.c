/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** start_event
*/

#include "pause_menu.h"

static int menu_click(sfRenderWindow *win, pause_menu_t *menu, int index)
{
    menu->button_status = index;
    return (SUCCESS);
}

static int menu_evt(pause_menu_t *men, sfMouseButtonEvent m, sfRenderWindow *w)
{
    sfFloatRect rect;

    for (int i = 0 ; i < 3 ; i++) {
        rect = sfSprite_getGlobalBounds(men->button_array[i].sprite);
        if (sfFloatRect_contains(&rect, m.x, m.y))
            return (menu_click(w, men, i));
    }
    return (SUCCESS);
}

static int event_menu(sfRenderWindow *win, pause_menu_t *menu, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(win);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            menu->button_status = 0;
        break;
    case sfEvtMouseButtonPressed:
        sfMusic_play(menu->click);
        return (menu_evt(menu, event.mouseButton, win));
    }
    return (SUCCESS);
}

int event_pause_menu(sfRenderWindow *win, pause_menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event) == sfTrue) {
        if (event_menu(win, menu, event) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}
