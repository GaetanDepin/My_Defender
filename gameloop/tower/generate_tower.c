/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** generate_tower
*/

#include "defender.h"

// NORM

static void buy_tower(gameloop_t *gameloop, int gold)
{
    gameloop->gold.nb -= gold;
    sfMusic_play(gameloop->music.buy);
}

static int test_money(gameloop_t *gameloop)
{
    if (gameloop->select_tower == 0 && gameloop->gold.nb >= 20) {
        buy_tower(gameloop, 20);
        return (SUCCESS);
    }
    if (gameloop->select_tower == 1 && gameloop->gold.nb >= 15) {
        buy_tower(gameloop, 15);
        return (SUCCESS);
    }
    if (gameloop->select_tower == 2 && gameloop->gold.nb >= 10) {
        buy_tower(gameloop, 10);
        return (SUCCESS);
    }
    if (gameloop->select_tower == 3 && gameloop->gold.nb >= 15) {
        buy_tower(gameloop, 15);
        return (SUCCESS);
    }
    return (ERROR);
}

static void generate_tower1(gameloop_t *game , sfVector2f pos, sfVector2i pos2)
{
    tower_t new_tower;
    sfTexture *texture = NULL;

    texture = game->tower_texture[game->select_tower].texture;
    pos = ini_vector(pos.x + 2, pos.y - TILE_SIZE / 1.2);
    new_tower.sprite = set_sprite(texture, pos, 1);
    new_tower.sprite.rect = game->drag_tower.rect;
    sfSprite_setTextureRect(new_tower.sprite.sprite, new_tower.sprite.rect);
    new_tower.sprite.w = game->drag_tower.w;
    new_tower.sprite.max_x = game->drag_tower.max_x;
    new_tower.is_empty = false;
    game->tower_map[pos2.y][pos2.x] = new_tower;
    load_data_tower(game, pos2.x, pos2.y);
}

int generate_tower(gameloop_t *gameloop)
{
    tower_t new_tower;
    sfTexture *texture = NULL;
    sfVector2f pos = sfRectangleShape_getPosition(gameloop->pos_tower);
    sfVector2i pos2 = {pos.x / TILE_SIZE, (pos.y) / TILE_SIZE};

    if (pos.y > 1078)
        pos2.y = 12;
    if (gameloop->tower_map[pos2.y][pos2.x].is_empty == true) {
        if (test_money(gameloop) == ERROR)
            return (SUCCESS);
        generate_tower1(gameloop, pos, pos2);
    }
    return (SUCCESS);
}
