/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_spirte
*/

#include "defender.h"
#include "tool.h"

my_sprite_t set_sprite(sfTexture *texture, sfVector2f pos, float scale)
{
    my_sprite_t my_sprite;

    my_sprite.sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite.sprite, texture, sfTrue);
    sfSprite_setScale(my_sprite.sprite, ini_vector(scale, scale));
    sfSprite_setPosition(my_sprite.sprite, pos);
    return (my_sprite);
}