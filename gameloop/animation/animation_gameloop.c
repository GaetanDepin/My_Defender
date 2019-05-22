/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** anim
*/

#include "defender.h"

int animation_gameloop(gameloop_t *gameloop)
{
    if (time_to_second(gameloop->anim_clock) > 0.07) {
        animation_tower(gameloop);
        animation_portal(&gameloop->portal1, &gameloop->portal2);
        animation_map(gameloop->map);
        animate_monster(gameloop->monster);
        sfClock_restart(gameloop->anim_clock);
    }
    return (SUCCESS);
}
