/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display the how2play menu
*/

#include "defender.h"
#include "start_menu.h"

void display_how2play(sfRenderWindow *win, start_menu_t *menu)
{
    display_map(win, menu->map, menu->tower);
    sfRenderWindow_drawSprite(win, menu->how2play.sprite, NULL);
}

int how2play_event1(sfRenderWindow *win, start_menu_t *menu, sfEvent event)
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
        return (1);
        break;
    }
    return (SUCCESS);
}

int how2play_event(sfRenderWindow *win, start_menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event) == sfTrue)
        return (how2play_event1(win, menu, event));
    return (SUCCESS);
}

void how2play(sfRenderWindow *win, start_menu_t *menu)
{
    while (sfRenderWindow_isOpen(win)) {
        display_how2play(win, menu);
        sfRenderWindow_display(win);
        if (how2play_event(win, menu) == 1)
            break;
    }
}
