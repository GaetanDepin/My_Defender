/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** set_tower_info
*/

#include "defender.h"

static text_t set_tower_text(sfVector2f pos)
{
    sfColor color = ini_color(0, 0, 0, 255);
    text_t my_text = ini_text(FONT2, 0, pos);

    sfText_setCharacterSize(my_text.text, 37);
    sfText_setColor(my_text.text, color);
    return (my_text);
}

int set_tower_info(tower_info_t *tower_info)
{
    sfVector2f pos = ini_vector(1825, 660);

    tower_info->txt_level = set_tower_text(pos);
    pos.y += 35;
    tower_info->txt_attack = set_tower_text(pos);
    pos.y += 35;
    tower_info->txt_atk_spd = set_tower_text(pos);
    pos.y += 35;
    tower_info->txt_range = set_tower_text(pos);
    pos.y += 35;
    tower_info->txt_slow = set_tower_text(pos);
    reset_tower_info(*tower_info);
    return (SUCCESS);
}
