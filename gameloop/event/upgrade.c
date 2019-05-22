/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** parse and upgrade the tower
*/

#include "defender.h"

static void poison_tower_upgrade(tower_t *tower)
{
    tower->lvl++;
    tower->slow = 0;
    tower->damage += 5;
}

static void fire_tower_upgrade(tower_t *tower)
{
    tower->lvl++;
    tower->slow = 0;
    tower->damage += 50;
}

static void storm_tower_upgrade(tower_t *tower)
{
    tower->lvl++;
    tower->slow = 0;
    tower->damage += 5;
}

static void ice_tower_upgrade(tower_t *tower)
{
    tower->lvl++;
    tower->slow += 10;
    tower->damage = 0;
}

int parser_upgrade(gameloop_t *gameloop, tower_t *tower)
{
    if (gameloop->select_tower == 0 && tower->lvl < 3) {
        poison_tower_upgrade(tower);
        return (TRUE);
    }
    if (gameloop->select_tower == 1 && tower->lvl < 3) {
        fire_tower_upgrade(tower);
        return (TRUE);
    }
    if (gameloop->select_tower == 2 && tower->lvl < 3) {
        storm_tower_upgrade(tower);
        return (TRUE);
    }
    if (gameloop->select_tower == 3 && tower->lvl < 3) {
        ice_tower_upgrade(tower);
        return (TRUE);
    }
    return (FALSE);
}
