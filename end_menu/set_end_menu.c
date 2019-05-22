/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** set_end_menu
*/

#include <stdlib.h>
#include "defender.h"
#include "end_menu.h"

static const char *TOOL = "resource/song/tool.ogg";
static const char *CLICK = "resource/song/click.ogg";

static int set_end_menu2(end_menu_t *data)
{
    data->move_block = create_table();
    if (data->move_block == NULL)
        return (ERROR);
    data->clock = sfClock_create();
    data->anim_status = true;
    data->button_status = 0;
    data->init = 0;
    data->game_over_txt = sfText_create();
    sfText_setString(data->game_over_txt, "Game over");
    sfText_setCharacterSize(data->game_over_txt, 150);
    sfText_setFont(data->game_over_txt, data->font);
    set_origin_text(data->game_over_txt);
    sfText_setPosition(data->game_over_txt, ini_vector(WINDOW_W / 2, 100));
    data->scale = 0.008;
    data->angle = 0.4;
    data->click = sfMusic_createFromFile(CLICK);
    data->tool = sfMusic_createFromFile(TOOL);
}

int set_end_menu(end_menu_t *data, int score)
{
    sfVector2f pos = ini_vector(WINDOW_W / 2, 600);

    data->font = sfFont_createFromFile(FONT2);
    if ((data->button = malloc(sizeof(button_t) * 3)) == NULL)
        return (ERROR);
    data->button[0] = create_button(BUTTON_IMG, "replay", data->font, 60);
    change_button_pos(&(data->button[0]), pos);
    pos.y += 150;
    data->button[1] = create_button(BUTTON_IMG, "menu", data->font, 60);
    change_button_pos(&(data->button[1]), pos);
    data->button[2].sprite = NULL;
    data->score_txt = sfText_create();
    sfText_setString(data->score_txt, str_cat("Score : ", mitoa(score)));
    sfText_setCharacterSize(data->score_txt, 100);
    sfText_setFont(data->score_txt, data->font);
    set_origin_text(data->score_txt);
    sfText_setPosition(data->score_txt, ini_vector(WINDOW_W / 2, 300));
    if (set_end_menu2(data) == ERROR)
        return (ERROR);
    return (SUCCESS);
}