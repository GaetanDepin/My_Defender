/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** animation function for the towers
*/

#include "defender.h"

static void move_rect_tower(tower_t *tower)
{
    if (tower->sprite.sprite) {
        move_rect(&(tower->sprite.rect), tower->sprite.w, tower->sprite.max_x);
        sfSprite_setTextureRect(tower->sprite.sprite, tower->sprite.rect);
    }
}

int animation_tower(gameloop_t *game_data)
{
    my_sprite_t **map = game_data->map;
    tower_t **tower = game_data->tower_map;

    for (int i = 0 ; map[i] ; i++)
        for (int ii = 0 ; map[i][ii].sprite ; ii++)
            move_rect_tower(&(tower[i][ii]));
    return (SUCCESS);
}
