/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** start_menu
*/

#include <stdlib.h>
#include <math.h>
#include "defender.h"
#include "start_menu.h"
#include "img_data.h"

static int display_menu(sfRenderWindow *win, start_menu_t menu)
{
    display_map(win, menu.map, menu.tower);
    for (int i = 0 ; menu.button_array[i].sprite ; i++)
        display_button(win, menu.button_array[i]);
    sfRenderWindow_drawSprite(win, menu.thumbnail.sprite, NULL);
    return (SUCCESS);
}

static void anim_menu(sfRenderWindow *win, start_menu_t *menu)
{
    sfSprite *sprite = menu->thumbnail.sprite;
    float angle = sfSprite_getRotation(sprite);
    sfVector2f scale = sfSprite_getScale(sprite);

    if ((angle > 15 && angle < 40) || (angle < 345 && angle > 320))
        menu->angle *= -1;
    sfSprite_rotate(sprite, menu->angle);
    if (scale.x > 1.2 || scale.x < 1)
        menu->scale *= -1;
    scale = ini_vector(scale.x + menu->scale, scale.y + menu->scale);
    sfSprite_setScale(sprite, scale);
    for (int i = 0 ; menu->button_array[i].sprite ; i++)
        button_is_over(win, &(menu->button_array[i]), 1.2, menu->tool);
}

int start_menu(sfRenderWindow *win)
{
    start_menu_t all;

    if (set_start_menu(&all) == ERROR)
        return (ERROR);
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_clear(win, sfWhite);
        display_menu(win, all);
        anim_menu(win, &all);
        if (event_start_menu(win, &all) == ERROR)
            sfRenderWindow_close(win);
        sfRenderWindow_display(win);
    }
    free_start_menu(all);
    return (SUCCESS);
}