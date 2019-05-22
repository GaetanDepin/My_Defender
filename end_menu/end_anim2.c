/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** end_anim2
*/

#include <stdlib.h>
#include "defender.h"
#include "end_menu.h"

static void init_monster_end(monster_t *monster)
{
    sfVector2f pos;
    sfFloatRect rect;

    while (monster) {
        rect = sfSprite_getGlobalBounds(monster->sprite.sprite);
        pos = ini_vector(rect.width / 2, rect.height / 2);
        sfSprite_setOrigin(monster->sprite.sprite, pos);
        monster->speed = (rand() % 2 + 1);
        monster = monster->next;
    }
}

void end_anim_monster(monster_t *monster, end_menu_t menu)
{
    sfVector2f pos;
    sfFloatRect rect;

    if (menu.init == 0) {
        init_monster_end(monster);
    }
    while (monster) {
        pos = ini_vector(0, monster->speed * 20);
        sfSprite_move(monster->sprite.sprite, pos);
        pos = sfSprite_getPosition(monster->sprite.sprite);
        pos.y -= 10;
        pos.x += monster->sprite.w / 2;
        move_health_bar(monster->heatlh_bar, pos);
        sfSprite_rotate(monster->sprite.sprite, monster->speed * 2);
        monster = monster->next;
    }
}