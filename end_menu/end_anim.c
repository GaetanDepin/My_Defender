/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** end_anim
*/

#include <stdlib.h>
#include "defender.h"
#include "end_menu.h"

int **create_table(void)
{
    int **temp;

    temp = malloc(sizeof(int*) * (MAP_H + 1));
    if (temp == NULL)
        return (NULL);
    temp[MAP_H] = NULL;
    for (int i = 0 ; i < MAP_H ; i++) {
        temp[i] = malloc(sizeof(int) * (MAP_W + 1));
        if (temp[i] == NULL)
            return (NULL);
        for (int ii = 0 ; ii < MAP_W ; ii++)
            temp[i][ii] = 0;
        temp[i][MAP_W] = -1;
    }
    return (temp);
}

static int move_map_ligne(my_sprite_t *line, int *square, tower_t *tower)
{
    for (int ii = 0 ; square[ii] != -1 ; ii++) {
        if (square[ii] == 1)
            sfSprite_move(line[ii].sprite, ini_vector(0, line[ii].type));
        if (tower[ii].sprite.sprite) {
            sfSprite_move(tower[ii].sprite.sprite, ini_vector(0, 25));
            sfSprite_rotate(tower[ii].sprite.sprite, 5);
        }
    }
}

static void move_portal(gameloop_t *gameloop, end_menu_t end_menu)
{
    sfVector2f origin = ini_vector(44.2, 56.5);

    if (end_menu.init == 0) {
        sfSprite_setOrigin(gameloop->portal1.sprite, origin);
        sfSprite_setOrigin(gameloop->portal2.sprite, origin);
        sfSprite_setPosition(gameloop->tool_bar.sprite, ini_vector(1920, 1080));
        sfSprite_setOrigin(gameloop->tool_bar.sprite, ini_vector(343, 1080));
    }
    sfSprite_rotate(gameloop->portal1.sprite, 7);
    sfSprite_move(gameloop->portal1.sprite, ini_vector(0, 13));
    sfSprite_rotate(gameloop->portal2.sprite, 7);
    sfSprite_move(gameloop->portal2.sprite, ini_vector(0, 30));
    if (sfSprite_getRotation(gameloop->tool_bar.sprite) < 130)
        sfSprite_rotate(gameloop->tool_bar.sprite, 2.5);
    for (int i = 0 ; gameloop->button_tower[i].sprite ; i++)
        sfSprite_move(gameloop->button_tower[i].sprite, ini_vector(0, 15));
    sfText_move(gameloop->hp.text, ini_vector(0, 15));
    sfText_move(gameloop->gold.text, ini_vector(0, 17));
    sfText_move(gameloop->score.text, ini_vector(0, 20));
}

static void move_map(end_menu_t *data, gameloop_t *gameloop)
{
    int index = rand() % (MAP_W * MAP_H);
    my_sprite_t **map = gameloop->map;
    tower_t **tower = gameloop->tower_map;

    for (int i = 0 ; i < 20 ; i++) {
        index = rand() % (MAP_W * MAP_H);
        data->move_block[index / MAP_W][index % MAP_W] = 1;
        map[index / MAP_W][index % MAP_W].type = (rand() % 2) * 40;
    }
    for (int i = 0 ; data->move_block[i] ; i++)
        move_map_ligne(map[i], data->move_block[i], tower[i]);
}

int end_anim(sfRenderWindow *win, end_menu_t *menu, gameloop_t *gameloop)
{
    if (time_to_second(menu->clock) < 15) {
        move_portal(gameloop, *menu);
        move_map(menu, gameloop);
        end_anim_monster(gameloop->monster, *menu);
    }
    if (menu->init == 0)
        menu->init = 1;
    return (SUCCESS);
}