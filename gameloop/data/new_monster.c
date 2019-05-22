/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** make a new monster
*/

#include <stdlib.h>
#include "defender.h"

//NORM

static void *new_blue(monster_t **element, anim_texture_t *texture)
{
    (*element)->type = 0;
    (*element)->dir = 'n';
    (*element)->speed = 3;
    (*element)->hp = 100;
    (*element)->alive = true;
    (*element)->center.x = 12;
    (*element)->center.y = 2;
    (*element)->gold = rand() % 2 + 1;
    (*element)->score = 10;
    (*element)->texture = texture[0].texture;
    (*element)->sprite = set_sprite((*element)->texture, ini_vector(0, 0), 1);
    (*element)->sprite.rect = ini_rect(0, 0, texture[0].w, texture[0].h);
    (*element)->sprite.max_x = texture[0].max_w;
    (*element)->sprite.w = texture[0].w;
    (*element)->slow = 0;
    (*element)->heatlh_bar = set_health_bar();
    (*element)->max_hp = (*element)->hp;
    return ((*element));
}

static void *new_purple(monster_t **element, anim_texture_t *texture)
{
    (*element)->type = 1;
    (*element)->dir = 'n';
    (*element)->speed = 2.5;
    (*element)->hp = 120;
    (*element)->alive = true;
    (*element)->center.x = 6;
    (*element)->center.y = 8;
    (*element)->gold = rand() % 2 + 2;
    (*element)->score = 15;
    (*element)->texture = texture[4].texture;
    (*element)->sprite = set_sprite((*element)->texture, ini_vector(0, 0), 1);
    (*element)->sprite.rect = ini_rect(0, 0, texture[4].w, texture[4].h);
    (*element)->sprite.max_x = texture[4].max_w;
    (*element)->sprite.w = texture[4].w;
    (*element)->slow = 0;
    (*element)->heatlh_bar = set_health_bar();
    (*element)->max_hp = (*element)->hp;
    return ((*element));
}

static void *new_green(monster_t **element, anim_texture_t *texture)
{
    (*element)->type = 2;
    (*element)->dir = 'n';
    (*element)->speed = 2.5;
    (*element)->hp = 150;
    (*element)->alive = true;
    (*element)->center.x = 2;
    (*element)->center.y = 2;
    (*element)->gold = rand() % 3 + 2;
    (*element)->score = 30;
    (*element)->texture = texture[8].texture;
    (*element)->sprite = set_sprite((*element)->texture, ini_vector(0, 0), 1);
    (*element)->sprite.rect = ini_rect(0, 0, texture[8].w, texture[8].h);
    (*element)->sprite.max_x = texture[8].max_w;
    (*element)->sprite.w = texture[8].w;
    (*element)->slow = 0;
    (*element)->heatlh_bar = set_health_bar();
    (*element)->max_hp = (*element)->hp;
    return ((*element));
}

static void *new_red(monster_t **element, anim_texture_t *texture)
{
    (*element)->type = 3;
    (*element)->dir = 'n';
    (*element)->speed = 2;
    (*element)->hp = 200;
    (*element)->alive = true;
    (*element)->center.x = 8;
    (*element)->center.y = 8;
    (*element)->gold = rand() % 3 + 3;
    (*element)->score = 40;
    (*element)->texture = texture[12].texture;
    (*element)->sprite = set_sprite((*element)->texture, ini_vector(0, 0), 1);
    (*element)->sprite.rect = ini_rect(0, 0, texture[12].w, texture[12].h);
    (*element)->sprite.max_x = texture[12].max_w;
    (*element)->sprite.w = texture[12].w;
    (*element)->slow = 0;
    (*element)->heatlh_bar = set_health_bar();
    (*element)->max_hp = (*element)->hp;
    return ((*element));
}

monster_t *new_monster(sfVector2f pos, monster_t *llist, anim_texture_t *tex)
{
    monster_t *element = NULL;
    int type = rand() % 100;

    element = malloc(sizeof(monster_t));
    if (type >= 66 && type <= 100)
        new_blue(&element, tex);
    if (type >= 0 && type <= 35)
        new_purple(&element, tex);
    if (type >= 36 && type <= 50)
        new_green(&element, tex);
    if (type >= 51 && type <= 65)
        new_red(&element, tex);
    pos.x += element->center.x;
    sfSprite_setTextureRect(element->sprite.sprite, element->sprite.rect);
    sfSprite_setPosition(element->sprite.sprite, pos);
    element->next = llist;
    return (element);
}
