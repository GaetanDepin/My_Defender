/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** animation for the portal
*/

#include "defender.h"

int animation_portal(my_sprite_t *portal1, my_sprite_t *portal2)
{
    move_rect(&portal1->rect, portal1->w, portal1->max_x);
    sfSprite_setTextureRect(portal1->sprite, portal1->rect);
    move_rect(&portal2->rect, portal2->w, portal2->max_x);
    sfSprite_setTextureRect(portal2->sprite, portal2->rect);
}
