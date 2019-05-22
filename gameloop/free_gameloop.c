/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** free_gameloop
*/

#include "defender.h"

void free_gameloop(gameloop_t gameloop)
{
    free_music(gameloop.music);
}