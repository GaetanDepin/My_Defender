/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** move the monster
*/

#include <stdlib.h>
#include "defender.h"

static sfVector2f set_move(monster_t *monster)
{
    sfVector2f move;
    float speed = monster->speed;

    move.x = 0;
    move.y = 0;
    if (monster->slow != 0)
        speed -= (float)monster->slow / 100 * speed;
    if (monster->dir == 'd')
        move.y = speed;
    if (monster->dir == 'u')
        move.y = speed * -1;
    if (monster->dir == 'r')
        move.x = speed;
    if (monster->dir == 'l')
        move.x = speed * -1;
    return (move);
}

void move_monster(gameloop_t *game)
{
    monster_t *temp = game->monster;
    sfVector2f pos;

    while (temp) {
        if (temp->alive == true) {
            set_dir(temp, game->monster_tex, game->map, temp->center);
            sfSprite_move(temp->sprite.sprite, set_move(temp));
            pos = sfSprite_getPosition(temp->sprite.sprite);
            pos.y -= 10;
            pos.x += temp->sprite.w / 2;
            move_health_bar(temp->heatlh_bar, pos);
        }
        temp = temp->next;
    }
}
