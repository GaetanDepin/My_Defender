/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** free_tower
*/

#include <stdlib.h>
#include "defender.h"

void free_tower(tower_t tower)
{
    sfClock_destroy(tower.attack_clock);
    sfRectangleShape_destroy(tower.po);
    sfSprite_destroy(tower.sprite.sprite);
}