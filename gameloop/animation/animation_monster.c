/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** animation_monster
*/

#include "defender.h"

void animate_monster(monster_t *monster)
{
    while (monster != NULL) {
        move_rect(&monster->sprite.rect, monster->sprite.w,
        monster->sprite.max_x);
        sfSprite_setTextureRect(monster->sprite.sprite, monster->sprite.rect);
        monster = monster->next;
    }
}