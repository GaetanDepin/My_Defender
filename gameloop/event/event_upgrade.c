/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** event_upgrade
*/

#include "defender.h"

int sell_tower(gameloop_t *gameloop, tower_info_t tower)
{
    int x = tower.select.x;
    int y = tower.select.y;

    if (gameloop->tower_map[y][x].sprite.sprite == NULL)
        return (SUCCESS);
    sfSprite_destroy(gameloop->tower_map[y][x].sprite.sprite);
    gameloop->tower_map[y][x].sprite.sprite = NULL;
    gameloop->tower_map[y][x].is_empty = true;
    gameloop->gold.nb += 10;
    reset_tower_info(gameloop->tower_info);
    return (SUCCESS);
}

int upgrade_tower(gameloop_t *gameloop, tower_info_t tower)
{
    int x = tower.select.x;
    int y = tower.select.y;

    if (gameloop->gold.nb >= 10) {
        if (gameloop->tower_map[y][x].sprite.sprite == NULL)
            return (SUCCESS);
        if (parser_upgrade(gameloop, &gameloop->tower_map[y][x]) == FALSE)
            return (SUCCESS);
        change_tower_info(tower, gameloop->tower_map[y][x]);
        gameloop->gold.nb -= 10;
    }
    return (SUCCESS);
}

int event_upgrade(gameloop_t *gameloop, sfMouseButtonEvent mouse)
{
    sfFloatRect rect;
    tower_info_t info = gameloop->tower_info;

    rect = sfSprite_getGlobalBounds(gameloop->button_tower[4].sprite);
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        if (info.select.x == -1 || info.select.y == -1)
            return (1);
        sfMusic_play(gameloop->music.buy);
        upgrade_tower(gameloop, info);
        return (1);
    }
    rect = sfSprite_getGlobalBounds(gameloop->button_tower[5].sprite);
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        if (info.select.x == -1 || info.select.y == -1)
            return (1);
        sfMusic_play(gameloop->music.buy);
        sell_tower(gameloop, info);
        return (1);
    }
    return (SUCCESS);
}
