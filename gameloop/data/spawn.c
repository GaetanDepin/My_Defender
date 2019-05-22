/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** spawn
*/

#include "defender.h"

void spawn(gameloop_t *gameloop)
{
    float live;

    if (time_to_second(gameloop->spawn_clock) >= gameloop->time_monster) {
        if (gameloop->time_monster > 0.05)
            gameloop->time_monster /= 1.01;
        gameloop->live_multi *= 1.01;
        live  = gameloop->live_multi;
        sfMusic_play(gameloop->music.tp);
        gameloop->score.nb += 5;
        gameloop->monster = new_monster(gameloop->pos_spawn, gameloop->monster,
        gameloop->monster_tex);
        gameloop->monster->hp = (float)gameloop->monster->hp * live;
        gameloop->monster->max_hp = gameloop->monster->hp;
        sfClock_restart(gameloop->spawn_clock);
    }
}

