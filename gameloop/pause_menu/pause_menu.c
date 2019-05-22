/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** pause_menu
*/

#include <stdlib.h>
#include "pause_menu.h"

static const char *TOOL = "resource/song/tool.ogg";
static const char *CLICK = "resource/song/click.ogg";

static int set_pause_menu2(pause_menu_t *data, sfFont *font)
{
    char name[3][10] = {"resume", "menu", "quit"};
    sfVector2f pos = ini_vector(WINDOW_W / 2, 700);

    data->button_array = malloc(sizeof(button_t) * 4);
    if (data->button_array == NULL)
        return (ERROR);
    data->button_array[3].sprite == NULL;
    for (int i = 0 ; i < 3 ; i++) {
        data->button_array[i] = create_button(BUTTON_IMG, name[i], font, 50);
        change_button_pos(&(data->button_array[i]), pos);
        pos.y += 125;
    }
    return (SUCCESS);
}

static int set_pause_menu(pause_menu_t *data)
{
    sfFont *font = sfFont_createFromFile(FONT2);

    data->font = font;
    data->text = sfText_create();
    sfText_setString(data->text, "Pause");
    sfText_setCharacterSize(data->text, 200);
    sfText_setFont(data->text, data->font);
    set_origin_text(data->text);
    sfText_setPosition(data->text, ini_vector(WINDOW_W / 2, 100));
    data->button_status = -1;
    if (set_pause_menu2(data, font));
    return (SUCCESS);
}

static void display_pause(sfRenderWindow *win, pause_menu_t data)
{
    sfRenderWindow_drawText(win, data.text, NULL);
    for (int i = 0 ; i < 3 ; i++)
        display_button(win, data.button_array[i]);
}

static void anim_pause(sfRenderWindow *win, pause_menu_t data)
{
    for (int i = 0 ; i < 3 ; i++)
        button_is_over(win, &(data.button_array[i]), 1.2, data.tool);
}

int pause_menu(sfRenderWindow *win, int *status)
{
    pause_menu_t data;

    if (set_pause_menu(&data) == ERROR)
        return (ERROR);
    data.click = sfMusic_createFromFile(CLICK);
    data.tool = sfMusic_createFromFile(TOOL);
    while (sfRenderWindow_isOpen(win) && data.button_status == -1) {
        sfRenderWindow_clear(win, sfBlack);
        anim_pause(win, data);
        display_pause(win, data);
        if (event_pause_menu(win, &data) == ERROR)
            return (ERROR);
        sfRenderWindow_display(win);
    }
    sfMusic_destroy(data.click);
    sfMusic_destroy(data.tool);
    *status = data.button_status;
    return (SUCCESS);
}