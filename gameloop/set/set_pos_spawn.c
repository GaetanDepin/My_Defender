/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Set the spawn portal position
*/

#include "defender.h"

sfVector2f set_pos_spawn(my_sprite_t **map)
{
    sfVector2f pos;
    int x = -1;
    int y = 0;

    while (map[y]) {
        if (++x >= 23) {
            y++;
            x = -1;
        } else if (map[y][x].type == 4)
            break;
    }
    pos.x = (float)x * 83;
    pos.y = (float)y * 83;
    return (pos);
}
