/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** tower_preview
*/

#include "defender.h"

my_sprite_t set_tower_preview(void)
{
    my_sprite_t tower_preview = set_sprite(NULL, ini_vector(0, 0), SCALE);
    return (tower_preview);
}
