/*
** EPITECH PROJECT, 2019
** my defender
** File description:
** animation functions for the map elements
*/

#include "defender.h"

static void move_rect_map(my_sprite_t *map)
{
    if (map->animation == true) {
        move_rect(&map->rect, map->w, map->max_x);
        sfSprite_setTextureRect(map->sprite, map->rect);
    }
}

int animation_map(my_sprite_t **map)
{
    for (int i = 0 ; map[i] ; i++)
        for (int ii = 0 ; map[i][ii].sprite ; ii++)
            move_rect_map(&(map[i][ii]));
    return (SUCCESS);
}
