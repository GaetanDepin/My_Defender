/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** despawn monster on portal
*/

#include "defender.h"

void despawn(gameloop_t *gameloop)
{
    monster_t *prev_monster = NULL;
    monster_t *monster = gameloop->monster;

    while (monster) {
        if (monster->dir == 'e') {
            sfMusic_play(gameloop->music.tp);
            gameloop->hp.nb--;
            remove_monster(&monster, prev_monster, &gameloop->monster);
        }
        if (monster) {
            prev_monster = monster;
            monster = monster->next;
        }
    }
}
