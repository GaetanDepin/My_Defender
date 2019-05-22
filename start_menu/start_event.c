/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** start_event
*/

#include "defender.h"
#include "start_menu.h"

static int menu_click(sfRenderWindow *win, start_menu_t *menu, int index)
{
    int status = 0;
    char map[11][20] = {"map/map1", "map/map2", "map/map3", "map/map4",
    "map/map5", "map/map6", "map/map7", "map/map8", "map/map9",
    "map/map10"};

    if (index == 0) {
        map_menu(win, menu, &status);
        if (status < 0)
            return (SUCCESS);
        gameloop(win, map[status]);
    } else if (index == 1) {
        how2play(win, menu);
    } else
        return (ERROR);
    return (SUCCESS);
}

static int menu_evt(start_menu_t *men, sfMouseButtonEvent m, sfRenderWindow *w)
{
    sfFloatRect rect;

    for (int i = 0 ; men->button_array[i].sprite ; i++) {
        rect = sfSprite_getGlobalBounds(men->button_array[i].sprite);
        if (sfFloatRect_contains(&rect, m.x, m.y))
            return (menu_click(w, men, i));
    }
    return (SUCCESS);
}

static int event_menu(sfRenderWindow *win, start_menu_t *menu, sfEvent event)
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

int event_start_menu(sfRenderWindow *win, start_menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event) == sfTrue) {
        if (event_menu(win, menu, event) == ERROR)
            return (ERROR);
    }
    return (SUCCESS);
}
