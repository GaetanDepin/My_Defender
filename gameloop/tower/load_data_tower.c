/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Load the towers data
*/

#include "defender.h"

static void poison_tower_data(tower_t *tower)
{
    sfColor color = ini_color(50, 200, 100, 65);

    tower->type = 1;
    tower->lvl = 1;
    tower->slow = 0;
    tower->damage = 5;
    tower->attack_speed = 0.2;
    tower->radius = 1;
    tower->attack_clock = sfClock_create();
    tower->po = create_po(1, color, tower->sprite.sprite);
}

static void fire_tower_data(tower_t *tower)
{
    sfColor color = ini_color(200, 50, 50, 50);

    tower->type = 2;
    tower->lvl = 1;
    tower->slow = 0;
    tower->damage = 50;
    tower->attack_speed = 2;
    tower->radius = 1;
    tower->attack_clock = sfClock_create();
    tower->po = create_po(1, color, tower->sprite.sprite);
}

static void storm_tower_data(tower_t *tower)
{
    sfColor color = ini_color(50, 50, 200, 50);

    tower->type = 3;
    tower->lvl = 1;
    tower->slow = 0;
    tower->damage = 5;
    tower->attack_speed = 0.4;
    tower->radius = 2;
    tower->attack_clock = sfClock_create();
    tower->po = create_po(2, color, tower->sprite.sprite);
}

static void ice_tower_data(tower_t *tower)
{
    sfColor color = ini_color(150, 200, 250, 65);

    tower->type = 4;
    tower->lvl = 1;
    tower->slow = 30;
    tower->damage = 0;
    tower->attack_speed = 0;
    tower->radius = 1;
    tower->attack_clock = NULL;
    tower->po = create_po(1, color, tower->sprite.sprite);
}

void load_data_tower(gameloop_t *gameloop, int x, int y)
{
    if (gameloop->select_tower == 0)
        poison_tower_data(&gameloop->tower_map[y][x]);
    if (gameloop->select_tower == 1)
        fire_tower_data(&gameloop->tower_map[y][x]);
    if (gameloop->select_tower == 2)
        storm_tower_data(&gameloop->tower_map[y][x]);
    if (gameloop->select_tower == 3)
        ice_tower_data(&gameloop->tower_map[y][x]);
}
