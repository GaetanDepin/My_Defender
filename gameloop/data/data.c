/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** gameloop data gestion
*/

#include "defender.h"

int data(gameloop_t *gameloop)
{
    spawn(gameloop);
    move_monster(gameloop);
    scale_button(gameloop);
    tool_bar_data(gameloop);
    mouse_move_drag(gameloop->window, gameloop);
    tower_attack(gameloop->tower_map, gameloop->monster);
    die_monster(gameloop, &(gameloop->monster), gameloop->monster_tex);
    despawn(gameloop);
    return (SUCCESS);
}
