/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** map_choice_menu
*/

#include <stdlib.h>
#include "defender.h"
#include "start_menu.h"

static const char *TOOL = "resource/song/tool.ogg";
static const char *CLICK = "resource/song/click.ogg";

// NORM

static int set_map_menu(map_choice_t *menu)
{
    char str[11][9] = {"snake", "sinus", "rubik", "sniper", "pacman",
    "power", "mickey", "lost", "pyramid", "invader"};
    sfFont *font = sfFont_createFromFile(FONT2);
    sfVector2f pos = ini_vector(WINDOW_W / 2 - (BUTTON_IMG.w + 20) * 2, 600);

    if ((menu->button_array = malloc(sizeof(button_t) * 11)) == NULL)
        return (ERROR);
    menu->button_array[10].sprite = NULL;
    menu->font = font;
    for (int i = 0 ; i < 10 ; i++) {
        menu->button_array[i] = create_button(BUTTON_IMG, str[i], font, 60);
        change_button_pos(&(menu->button_array[i]), pos);
        pos.x += BUTTON_IMG.w + 20;
        if (i == 4)
            pos = ini_vector(WINDOW_W / 2 - (BUTTON_IMG.w + 20) * 2, 750);
    }
    menu->status = -1;
    menu->button_quit = create_button(BUTTON_IMG, "Quit", font, 60);
    change_button_pos(&(menu->button_quit), ini_vector(WINDOW_W / 2, 950));
    return (SUCCESS);
}

int display_map_menu(sfRenderWindow *win, map_choice_t c, start_menu_t *m)
{
    display_map(win, m->map, m->tower);
    sfRenderWindow_drawSprite(win, m->thumbnail.sprite, NULL);
    for (int i = 0 ; c.button_array[i].sprite ; i++)
        display_button(win, c.button_array[i]);
    display_button(win, c.button_quit);
}

static void anim_map_menu(start_menu_t *menu)
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
}

static void free_map_menu(map_choice_t data)
{
    sfFont_destroy(data.font);
    for (int i = 0 ; data.button_array[i].sprite ; i++)
        free_button(data.button_array[i]);
    free_button(data.button_quit);
}

int map_menu(sfRenderWindow *win, start_menu_t *menu, int *status)
{
    map_choice_t data;

    data.tool = menu->tool;
    data.click = menu->click;
    if (set_map_menu(&data) == ERROR)
        return (ERROR);
    while (sfRenderWindow_isOpen(win) && data.status == -1) {
        display_map_menu(win, data, menu);
        for (int i = 0 ; data.button_array[i].sprite != NULL ; i++)
            button_is_over(win, &(data.button_array[i]), 1.1, menu->tool);
        button_is_over(win, &(data.button_quit), 1.1, menu->tool);
        map_event(win, &data);
        anim_map_menu(menu);
        sfRenderWindow_display(win);
    }
    free_map_menu(data);
    *status = data.status;
    return (SUCCESS);
}
