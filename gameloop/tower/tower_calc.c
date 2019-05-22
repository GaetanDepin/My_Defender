/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** tower_alpha
*/

#include "defender.h"

int tower_a(float time, float attack)
{
    int alpha = 50;
    float value = time - attack / 2;

    if (time < attack / 2)
        alpha -= value * 40;
    else
        alpha += value * 40;
    return (alpha);
}

int get_monster_speed(int tower, int monster)
{
    if (monster > tower)
        return (monster);
    else
        return (tower);
}