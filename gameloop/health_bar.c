/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** health_bar
*/

#include "defender.h"

static const int BAR_W = 65;
static const int BAR_H = 6;

health_bar_t set_health_bar(void)
{
    health_bar_t temp;
    sfColor color = ini_color(216, 45, 45, 255);

    temp.bg_texture = sfTexture_createFromFile(BG_HEATLH_BAR.filepath, NULL);
    temp.bg = sfSprite_create();
    sfSprite_setTexture(temp.bg, temp.bg_texture, sfTrue);
    sfSprite_setOrigin(temp.bg, ini_vector(BG_HEATLH_BAR.w / 2, 0));
    temp.fr_texture = sfTexture_createFromFile(FR_HEATLH_BAR.filepath, NULL);
    temp.front = sfSprite_create();
    sfSprite_setTexture(temp.front, temp.fr_texture, sfTrue);
    sfSprite_setOrigin(temp.front, ini_vector(FR_HEATLH_BAR.w / 2, 0));
    temp.bar = sfRectangleShape_create();
    sfRectangleShape_setSize(temp.bar, ini_vector(BAR_W, BAR_H));
    sfRectangleShape_setFillColor(temp.bar, color);
    return (temp);
}

void move_health_bar(health_bar_t bar, sfVector2f pos)
{
    sfVector2f bar_pos = ini_vector(pos.x - BAR_W / 2, pos.y + 2);

    sfSprite_setPosition(bar.bg, pos);
    sfRectangleShape_setPosition(bar.bar, bar_pos);
    sfSprite_setPosition(bar.front, pos);
}

void update_health_bar(health_bar_t bar, int value, int max_value)
{
    float my_value = (float)value / (float)max_value;
    sfVector2f size = ini_vector(BAR_W * my_value, BAR_H);

    if (size.x >= 0)
        sfRectangleShape_setSize(bar.bar, size);
}

void display_health_bar(sfRenderWindow *win, health_bar_t bar)
{
    sfRenderWindow_drawSprite(win, bar.bg, NULL);
    sfRenderWindow_drawRectangleShape(win, bar.bar, NULL);
    sfRenderWindow_drawSprite(win, bar.front, NULL);
}

void free_health_bar(health_bar_t bar)
{
    sfSprite_destroy(bar.bg);
    sfSprite_destroy(bar.front);
    sfTexture_destroy(bar.bg_texture);
    sfTexture_destroy(bar.fr_texture);
    sfRectangleShape_destroy(bar.bar);
}