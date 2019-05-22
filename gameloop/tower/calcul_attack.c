/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** calcul_attack
*/

#include <math.h>
#include "defender.h"

// NORM

sfVector2f get_tower_pos(sfVector2f pos)
{
    sfVector2f tower_pos = {pos.x, pos.y + ICE_IDLE.h / 2};
    sfVector2i temp = {tower_pos.x / TILE_SIZE, tower_pos.y / TILE_SIZE};
    sfVector2f final_pos;

    final_pos.x = (temp.x + 0.5) * TILE_SIZE;
    final_pos.y = (temp.y + 0.5) * TILE_SIZE;
    return (final_pos);
}

void ice_attack(tower_t *tower, monster_t *monster)
{
    sfVector2f pos = get_tower_pos(sfSprite_getPosition(tower->sprite.sprite));
    float radius = (tower->radius + 0.5) * TILE_SIZE;
    sfVector2f m_pos;
    sfFloatRect rect;

    while (monster) {
        m_pos = sfSprite_getPosition(monster->sprite.sprite);
        rect = sfSprite_getLocalBounds(monster->sprite.sprite);
        m_pos.x += rect.width / 2;
        m_pos.y += rect.height / 2;
        if (fabs(m_pos.x - pos.x) <= radius && fabs(m_pos.y - pos.y) <= radius)
            monster->slow = get_monster_speed(tower->slow, monster->slow);
        monster = monster->next;
    }
}

void poison_attack(tower_t *tower, monster_t *monster)
{
    sfVector2f pos = get_tower_pos(sfSprite_getPosition(tower->sprite.sprite));
    float radius = (tower->radius + 0.5) * TILE_SIZE;
    sfVector2f m_pos;
    sfFloatRect rect;

    if (time_to_second(tower->attack_clock) < tower->attack_speed)
        return;
    sfClock_restart(tower->attack_clock);
    while (monster) {
        m_pos = sfSprite_getPosition(monster->sprite.sprite);
        rect = sfSprite_getLocalBounds(monster->sprite.sprite);
        m_pos.x += rect.width / 2;
        m_pos.y += rect.height / 2;
        if (fabs(m_pos.x - pos.x) <= radius && fabs(m_pos.y - pos.y) <= radius)
            monster->hp -= tower->damage;
        update_health_bar(monster->heatlh_bar, monster->hp, monster->max_hp);
        monster = monster->next;
    }
}

void storm_attack(tower_t *tower, monster_t *monster)
{
    sfVector2f pos = get_tower_pos(sfSprite_getPosition(tower->sprite.sprite));
    float radius = (tower->radius + 0.5) * TILE_SIZE;
    sfVector2f m_pos;
    sfFloatRect rect;
    int a = tower_a(time_to_second(tower->attack_clock), tower->attack_speed);

    sfRectangleShape_setFillColor(tower->po, ini_color(50, 50, 200, a));
    if (time_to_second(tower->attack_clock) < tower->attack_speed)
        return;
    sfClock_restart(tower->attack_clock);
    while (monster) {
        m_pos = sfSprite_getPosition(monster->sprite.sprite);
        rect = sfSprite_getLocalBounds(monster->sprite.sprite);
        m_pos.x += rect.width / 2;
        m_pos.y += rect.height / 2;
        if (fabs(m_pos.x - pos.x) <= radius && fabs(m_pos.y - pos.y) <= radius)
            monster->hp -= tower->damage;
        update_health_bar(monster->heatlh_bar, monster->hp, monster->max_hp);
        monster = monster->next;
    }
}

void fire_attack(tower_t *tower, monster_t *monster)
{
    sfVector2f pos = get_tower_pos(sfSprite_getPosition(tower->sprite.sprite));
    float radius = (tower->radius + 0.5) * TILE_SIZE;
    sfVector2f m_pos;
    sfFloatRect rect;
    int a = tower_a(time_to_second(tower->attack_clock), tower->attack_speed);

    sfRectangleShape_setFillColor(tower->po, ini_color(200, 50, 50, a));
    if (time_to_second(tower->attack_clock) < tower->attack_speed)
        return;
    sfClock_restart(tower->attack_clock);
    while (monster) {
        m_pos = sfSprite_getPosition(monster->sprite.sprite);
        rect = sfSprite_getLocalBounds(monster->sprite.sprite);
        m_pos.x += rect.width / 2;
        m_pos.y += rect.height / 2;
        if (fabs(m_pos.x - pos.x) <= radius && fabs(m_pos.y - pos.y) <= radius)
            monster->hp -= tower->damage;
        update_health_bar(monster->heatlh_bar, monster->hp, monster->max_hp);
        monster = monster->next;
    }
}
