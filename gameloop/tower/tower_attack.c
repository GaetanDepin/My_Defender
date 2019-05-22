/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** tower_attack
*/

#include "defender.h"

static void remove_all_effect(monster_t *monster)
{
    while (monster) {
        monster->slow = 0;
        monster = monster->next;
    }
}

static void swith_tower(tower_t *tower, monster_t *monster)
{
    if (tower->sprite.sprite == NULL)
        return;
    switch (tower->type) {
    case 1:
        poison_attack(tower, monster);
        break;
    case 2:
        fire_attack(tower, monster);
        break;
    case 3:
        storm_attack(tower, monster);
        break;
    case 4:
        ice_attack(tower, monster);
        break;
    }
}

int tower_attack(tower_t **tower, monster_t *monster)
{
    remove_all_effect(monster);
    for (int i = 0 ; i < 13 ; i++)
        for (int ii = 0 ; ii < 24 ; ii++)
            swith_tower(&(tower[i][ii]), monster);
    return (SUCCESS);
}
