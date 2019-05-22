/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** set the monster direction
*/

#include <stdlib.h>
#include "defender.h"

void change_monster_texture(monster_t *monster, anim_texture_t *texture)
{
    int anim = 0;

    monster->dir == 'd' ? anim = 0 : anim;
    monster->dir == 'u' ? anim = 1 : anim;
    monster->dir == 'l' ? anim = 2 : anim;
    monster->dir == 'r' ? anim = 3 : anim;
    anim += (monster->type * 5);
    sfSprite_setTexture(monster->sprite.sprite, texture[anim].texture, sfTrue);
    monster->sprite.rect = ini_rect(0, 0, texture[anim].w, texture[anim].h);
    monster->sprite.w = texture[anim].w;
    monster->sprite.max_x = texture[anim].max_w;
    sfSprite_setTextureRect(monster->sprite.sprite, monster->sprite.rect);
}

char set_backup_dir(my_sprite_t **map, char t, sfVector2i pa, sfVector2i pb)
{
    if (t != 'u' && (map[pa.y + 1][pa.x].type == 3
        || map[pa.y + 1][pa.x].type == 5))
        return ('d');
    if (t != 'd' && (map[pb.y - 1][pb.x].type == 3
        || map[pb.y - 1][pb.x].type == 5))
        return ('u');
    if (t != 'l' && (map[pa.y][pa.x + 1].type == 3
        || map[pa.y][pa.x + 1].type == 5))
        return ('r');
    if (t != 'r' && (map[pb.y][pb.x - 1].type == 3
        || map[pb.y][pb.x - 1].type == 5))
        return ('l');
    return ('n');
}

char set_rand_dir(my_sprite_t **map, char t, sfVector2i pa, sfVector2i pb)
{
    int count = 0;
    int r = 0;

    while (1) {
        r = rand() % 4 + 1;
        if (t != 'u' && (map[pa.y + 1][pa.x].type == 3
            || map[pa.y + 1][pa.x].type == 5) && r == 1)
            return ('d');
        if (t != 'd' && (map[pb.y - 1][pb.x].type == 3
            || map[pb.y - 1][pb.x].type == 5) && r == 2)
            return ('u');
        if (t != 'l' && (map[pa.y][pa.x + 1].type == 3
            || map[pa.y][pa.x + 1].type == 5) && r == 3)
            return ('r');
        if (t != 'r' && (map[pb.y][pb.x - 1].type == 3
            || map[pb.y][pb.x - 1].type == 5) && r == 4)
            return ('l');
        if (++count >= 20)
            return (set_backup_dir(map, t, pa, pb));
    }
}

char set_front_dir(my_sprite_t **map, char t, sfVector2i pa, sfVector2i pb)
{
    if (t == 'd' && (map[pa.y + 1][pa.x].type == 3
        || map[pa.y + 1][pa.x].type == 5))
        return ('d');
    if (t == 'u' && (map[pb.y - 1][pb.x].type == 3
        || map[pb.y - 1][pb.x].type == 5))
        return ('u');
    if (t == 'r' && (map[pa.y][pa.x + 1].type == 3
        || map[pa.y][pa.x + 1].type == 5))
        return ('r');
    if (t == 'l' && (map[pb.y][pb.x - 1].type == 3
        || map[pb.y][pb.x - 1].type == 5))
        return ('l');
    return ('s');
}

void set_dir(monster_t *m, anim_texture_t *tex, my_sprite_t **map, sfVector2i c)
{
    sfVector2f pos = sfSprite_getPosition(m->sprite.sprite);
    sfVector2i pa = set_pa(pos, c);
    sfVector2i pb = set_pb(pos, c);
    char temp = m->dir;

    m->dir = 'n';
    if (map[pb.y][pb.x].type == 5 && map[pa.y][pa.x].type == 5) {
        m->dir = 'e';
        return;
    }
    m->dir = set_rand_dir(map, temp, pa, pb);
    if (set_front_dir(map, temp, pa, pb) != 's')
        m->dir = set_front_dir(map, temp, pa, pb);
    if (m->dir == 'n')
        m->dir = temp;
    if (temp != m->dir) {
        pos = ini_vector((float)pa.x * 83 + c.x, (float)pa.y * 83 + c.y);
        sfSprite_setPosition(m->sprite.sprite, pos);
        change_monster_texture(m, tex);
    }
}
