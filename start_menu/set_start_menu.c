/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** set_start_menu
*/

#include <stdlib.h>
#include "defender.h"
#include "start_menu.h"

static const char *TOOL = "resource/song/tool.ogg";
static const char *CLICK = "resource/song/click.ogg";
static const char *HOW2PLAY = "resource/how2play.png";

static int set_start_menu2(start_menu_t *all, sfVector2f pos)
{
    sfFont *my_font = all->font_button;

    all->angle = 0.4;
    all->scale = 0.008;
    if (load_map("menu", &all->map, &all->tower) == ERROR)
        return (ERROR);
    if ((all->button_array = malloc(sizeof(button_t) * 4)) == NULL)
        return (ERROR);
    all->button_array[0] = create_button(BUTTON_IMG, "Play", my_font, 60);
    change_button_pos(&(all->button_array[0]), pos);
    pos.y += BUTTON_IMG.h + 20;
    all->button_array[1] = create_button(BUTTON_IMG, "How2play", my_font, 60);
    change_button_pos(&(all->button_array[1]), pos);
    pos.y += BUTTON_IMG.h + 20;
    all->button_array[2] = create_button(BUTTON_IMG, "Quit", my_font, 60);
    change_button_pos(&(all->button_array[2]), pos);
    all->button_array[3].sprite = NULL;
    return (SUCCESS);
}

int set_start_menu(start_menu_t *all)
{
    sfFont *my_font = sfFont_createFromFile(FONT);
    sfVector2f pos = ini_vector(WINDOW_W / 2, WINDOW_H / 2 - 200);
    sfTexture *tex = sfTexture_createFromFile(IMG_THUMBNAIL.filepath, NULL);
    sfVector2f pos_thu = ini_vector(IMG_THUMBNAIL.w / 2, IMG_THUMBNAIL.h / 2);

    all->thumbnail = set_sprite(tex, pos, 1);
    tex = sfTexture_createFromFile(HOW2PLAY, NULL);
    all->how2play = set_sprite(tex, ini_vector(0, 0), 1);
    sfSprite_setOrigin(all->thumbnail.sprite, pos_thu);
    pos.y += 300;
    all->font_button = my_font;
    all->thumb_texture = tex;
    if (set_start_menu2(all, pos) == ERROR)
        return (ERROR);
    all->click = sfMusic_createFromFile(CLICK);
    all->tool = sfMusic_createFromFile(TOOL);
    return (SUCCESS);
}
