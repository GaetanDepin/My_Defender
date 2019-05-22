/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** free_start_menu
*/

#include <stdlib.h>
#include "defender.h"
#include "start_menu.h"

void free_start_menu(start_menu_t menu)
{
    sfFont_destroy(menu.font_button);
    for (int i = 0 ; menu.button_array[i].sprite ; i++)
        free_button(menu.button_array[i]);
    free(menu.button_array);
    sfTexture_destroy(menu.thumb_texture);
    sfSprite_destroy(menu.thumbnail.sprite);
    sfMusic_destroy(menu.click);
    sfMusic_destroy(menu.tool);
}