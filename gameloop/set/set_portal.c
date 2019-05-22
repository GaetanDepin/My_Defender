/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** set the portals sprite
*/

#include "defender.h"

static my_sprite_t set_blue_portal(sfVector2f pos)
{
    my_sprite_t sprite;
    sfTexture *texture;

    texture = sfTexture_createFromFile("resource/Portal/blue_idle.png", NULL);
    sprite.sprite = sfSprite_create();
    sprite.solid = false;
    sprite.animation = true;
    sprite.max_x = 1327;
    sprite.w = TILE_SIZE;
    sprite.rect = ini_rect(0, 0, TILE_SIZE, 113);
    sprite.type = 5;
    sfSprite_setTexture(sprite.sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite.sprite, sprite.rect);
    pos.y -= 30;
    sfSprite_setPosition(sprite.sprite, pos);
    return (sprite);
}

static my_sprite_t set_red_portal(sfVector2f pos)
{
    my_sprite_t sprite;
    sfTexture *texture;

    texture = sfTexture_createFromFile("resource/Portal/red_idle.png", NULL);
    sprite.sprite = sfSprite_create();
    sprite.solid = false;
    sprite.animation = true;
    sprite.max_x = 1327;
    sprite.w = TILE_SIZE;
    sprite.rect = ini_rect(0, 0, TILE_SIZE, 113);
    sprite.type = 5;
    sfSprite_setTexture(sprite.sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite.sprite, sprite.rect);
    pos.y -= 30;
    sfSprite_setPosition(sprite.sprite, pos);
    return (sprite);
}

static sfVector2f found_type(my_sprite_t **map, int type)
{
    sfVector2f pos;
    int ii = 0;

    for (int i = 0 ; i <= 13 ; ) {
        if (map[i][ii].type == type) {
            pos.x = (float)ii * 83;
            pos.y = (float)i * 83;
            break;
        }
        if (++ii > 23) {
            i++;
            ii = 0;
        }
    }
    return (pos);
}

my_sprite_t set_portal(my_sprite_t **map, int mode)
{
    my_sprite_t sprite;
    sfVector2f pos;

    if (mode == 1) {
        pos = found_type(map, 4);
        sprite = set_blue_portal(pos);
    }
    if (mode == 2) {
        pos = found_type(map, 5);
        sprite = set_red_portal(pos);
    }
    return (sprite);
}
