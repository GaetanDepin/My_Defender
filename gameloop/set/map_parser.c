/*
** EPITECH PROJECT, 2019
** my defender
** File description:
** Parser use in load map
*/

#include "defender.h"

int map_parser(sfVector2f pos, char flag, my_sprite_t *sprite)
{
    switch (flag) {
    case '1':
        *sprite = set_grass1(pos);
        return (SUCCESS);
    case '2':
        *sprite = set_grass2(pos);
        return (SUCCESS);
    case '3':
        *sprite = set_ground(pos);
        return (SUCCESS);
    case '8':
        *sprite = set_portal1(pos);
        return (SUCCESS);
    case '9':
        *sprite = set_portal2(pos);
        return (SUCCESS);
    }
    return (ERROR);
}
