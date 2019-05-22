/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** start_event
*/

#include "defender.h"
#include "start_menu.h"



static int menu_click(sfRenderWindow *win, map_choice_t *menu, int index)
{
    menu->status = index;
}

static int menu_evt(map_choice_t *men, sfMouseButtonEvent m, sfRenderWindow *w)
{
    sfFloatRect rect;

    for (int i = 0 ; men->button_array[i].sprite ; i++) {
        rect = sfSprite_getGlobalBounds(men->button_array[i].sprite);
        if (sfFloatRect_contains(&rect, m.x, m.y))
            return (menu_click(w, men, i));
    }
    rect = sfSprite_getGlobalBounds(men->button_quit.sprite);
    if (sfFloatRect_contains(&rect, m.x, m.y))
        men->status = -2;
    return (SUCCESS);
}

static int event_menu(sfRenderWindow *win, map_choice_t *menu, sfEvent event)
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
        break;
    }
    return (SUCCESS);
}

int map_event(sfRenderWindow *win, map_choice_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event) == sfTrue)
        return (event_menu(win, menu, event));
    return (SUCCESS);
}
