/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** set_rectangle_shape
*/

#include "defender.h"

int move_drag_indicator(gameloop_t *gameloop, sfVector2f mouse)
{
    int x = mouse.x / TILE_SIZE;
    int y = mouse.y / TILE_SIZE;
    sfVector2f pos = ini_vector(x * TILE_SIZE, y * TILE_SIZE);
    sfColor color;

    if (mouse.y >= 1079)
        return (SUCCESS);
    if (mouse.x >= 1577)
        color = ini_color(0, 0, 0, 0);
    else if (gameloop->tower_map[y][x].is_empty == true)
        color = ini_color(0, 208, 37, 180);
    else
        color = ini_color(200, 0, 0, 180);
    sfRectangleShape_setFillColor(gameloop->pos_tower, color);
    sfRectangleShape_setPosition(gameloop->pos_tower, pos);
    return (SUCCESS);
}
