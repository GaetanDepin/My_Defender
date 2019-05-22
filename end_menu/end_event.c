/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** end_event
*/

#include "defender.h"
#include "end_menu.h"

static int menu_click(sfRenderWindow *win, end_menu_t *menu, int index)
{
    if (index == 0) {
        menu->button_status = 1;
    } else if (index == 1) {
        menu->button_status = 2;
    }
    return (SUCCESS);
}

static int menu_evt(end_menu_t *men, sfMouseButtonEvent m, sfRenderWindow *w)
{
    sfFloatRect rect;

    for (int i = 0 ; men->button[i].sprite ; i++) {
        rect = sfSprite_getGlobalBounds(men->button[i].sprite);
        if (sfFloatRect_contains(&rect, m.x, m.y))
            return (menu_click(w, men, i));
    }
    return (SUCCESS);
}

static int event_menu(sfRenderWindow *win, end_menu_t *menu, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(win);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(win);
        break;
    case sfEvtMouseButtonPressed:
        sfMusic_play(menu->click);
        return (menu_evt(menu, event.mouseButton, win));
    }
    return (SUCCESS);
}

int event_end_menu(sfRenderWindow *win, end_menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event) == sfTrue) {
        if (event_menu(win, menu, event) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}