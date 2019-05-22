/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** end_menu
*/

#include <stdlib.h>
#include "defender.h"
#include "end_menu.h"

static int anim_end_menu(sfRenderWindow *win, end_menu_t *data)
{
    sfVector2f scale = sfText_getScale(data->game_over_txt);
    float angle = sfText_getRotation(data->game_over_txt);

    for (int i = 0 ; data->button[i].sprite ; i++)
        button_is_over(win, &(data->button[i]), 1.2, data->tool);
    if ((angle > 10 && angle < 40) || (angle < 350 && angle > 320))
        data->angle *= -1;
    sfText_rotate(data->game_over_txt, data->angle);
    if (scale.x > 1.2 || scale.x < 1)
        data->scale *= -1;
    scale = ini_vector(scale.x + data->scale, scale.y + data->scale);
    sfText_setScale(data->game_over_txt, scale);
}

int end_menu(sfRenderWindow *win, gameloop_t *gameloop)
{
    end_menu_t data;

    if (set_end_menu(&data, gameloop->score.nb) == ERROR)
        return (ERROR);
    sfMusic_play(gameloop->music.game_over);
    while (sfRenderWindow_isOpen(win) && data.button_status == 0) {
        sfRenderWindow_clear(win, sfBlack);
        anim_end_menu(win, &data);
        end_anim(win, &data, gameloop);
        display_end_menu(win, data, *gameloop);
        if (event_end_menu(win, &data) == ERROR)
            return (ERROR);
        sfRenderWindow_display(win);
    }
    sfMusic_destroy(data.click);
    sfMusic_destroy(data.tool);
    return (data.button_status);
}
