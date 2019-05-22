/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** set the tool bar
*/

#include <stdlib.h>
#include "defender.h"

static const char *TOOL_BAR = "resource/UI/tool_bar.png";

int set_tool_bar(my_sprite_t *tool_bar)
{
    sfTexture *texture;

    texture = sfTexture_createFromFile(TOOL_BAR, NULL);
    tool_bar->sprite = sfSprite_create();
    sfSprite_setTexture(tool_bar->sprite, texture, sfTrue);
    tool_bar->rect = ini_rect(0, 0, 343, 1080);
    sfSprite_setPosition(tool_bar->sprite, ini_vector(1577, 0));
    sfSprite_setTextureRect(tool_bar->sprite, tool_bar->rect);
    return (SUCCESS);
}
