/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** die_monster
*/

#include <stdlib.h>
#include "defender.h"

// NORM

void free_monster(monster_t *monster)
{
    sfSprite_destroy(monster->sprite.sprite);
    free_health_bar(monster->heatlh_bar);
}

void remove_monster(monster_t **monst, monster_t *prev, monster_t **lis)
{
    monster_t *temp = NULL;

    if (prev == NULL) {
        temp = (*monst)->next;
        free_monster(*monst);
        *monst = temp;
        *lis = temp;
    } else {
        prev->next = (*monst)->next;
        free_monster(*monst);
        *monst = prev->next;
    }
}

static void to_dead_monster(monster_t *monster, anim_texture_t *texture)
{
    monster->alive = false;
    monster->texture = texture[monster->type * 5 + 4].texture;
    sfSprite_setTexture(monster->sprite.sprite, monster->texture,
    sfTrue);
    sfSprite_move(monster->sprite.sprite, ini_vector(0, 40));
    monster->sprite.w = texture[monster->type * 5 + 4].w;
    monster->sprite.max_x = texture[monster->type * 5 + 4].max_w;
    monster->sprite.rect.left = 0;
    monster->sprite.rect.width = texture[monster->type * 5 +4].w;
    monster->sprite.rect.height = texture[monster->type * 5 + 4].h;
    sfSprite_setTextureRect(monster->sprite.sprite,
    monster->sprite.rect);
}

void die_monster(gameloop_t *gameloop, monster_t **monst_l, anim_texture_t *t)
{
    monster_t *prev_monster = NULL;
    monster_t *monster = *monst_l;

    while (monster) {
        if (monster->hp <= 0 && monster->alive == true) {
            sfMusic_play(gameloop->music.die);
            gameloop->gold.nb += monster->gold;
            gameloop->score.nb += monster->score;
            to_dead_monster(monster, t);
        }
        if (monster->alive == false && monster->sprite.rect.left >= 1980) {
            remove_monster(&monster, prev_monster, monst_l);
        } else {
            prev_monster = monster;
            monster = monster->next;
        }
    }
}
