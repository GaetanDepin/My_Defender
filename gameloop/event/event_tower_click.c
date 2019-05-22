/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** event_tower_click
*/

#include "defender.h"

//NORM

void change_tower_info(tower_info_t info, tower_t tower)
{
    char *text;

    sfText_setString(info.txt_level.text, mitoa(tower.lvl));
    set_origin_text(info.txt_level.text);
    sfText_setString(info.txt_attack.text, mitoa(tower.damage));
    set_origin_text(info.txt_attack.text);
    sfText_setString(info.txt_atk_spd.text, mitoa(tower.attack_speed * 10));
    set_origin_text(info.txt_atk_spd.text);
    sfText_setString(info.txt_range.text, mitoa(tower.radius));
    set_origin_text(info.txt_range.text);
    text = mitoa(tower.slow);
    text = str_cat(text, " %");
    sfText_setString(info.txt_slow.text, text);
    set_origin_text(info.txt_slow.text);
}

void reset_tower_info(tower_info_t info)
{
    sfText_setString(info.txt_level.text, "\0");
    set_origin_text(info.txt_level.text);
    sfText_setString(info.txt_attack.text, "\0");
    set_origin_text(info.txt_attack.text);
    sfText_setString(info.txt_atk_spd.text, "\0");
    set_origin_text(info.txt_atk_spd.text);
    sfText_setString(info.txt_range.text, "\0");
    set_origin_text(info.txt_range.text);
    sfText_setString(info.txt_slow.text, "\0");
    set_origin_text(info.txt_slow.text);
}

int event_tower_click(gameloop_t *gameloop, sfMouseButtonEvent mouse)
{
    int x = mouse.x / TILE_SIZE;
    int y = (mouse.y + TILE_SIZE / 4) / TILE_SIZE;
    tower_t tower;

    if (x < 0 || y < 0)
        return (SUCCESS);
    tower = gameloop->tower_map[y][x];
    if (tower.sprite.sprite != NULL) {
        gameloop->tower_info.select.x = x;
        gameloop->tower_info.select.y = y;
        sfMusic_play(gameloop->music.tower);
        change_tower_info(gameloop->tower_info, tower);
    } else {
        reset_tower_info(gameloop->tower_info);
        gameloop->tower_info.select.x = -1;
        gameloop->tower_info.select.y = -1;
    }
    return (SUCCESS);
}
