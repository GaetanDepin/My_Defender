/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** generate_button
*/

#include <stdlib.h>
#include "defender.h"

static sfVector2f get_tower_pos(int i)
{
    sfVector2f pos;

    i == 0 ? pos = ini_vector(WINDOW_W - 98, 184) : pos;
    i == 1 ? pos = ini_vector(WINDOW_W - 244, 184) : pos;
    i == 2 ? pos = ini_vector(WINDOW_W - 98, 342) : pos;
    i == 3 ? pos = ini_vector(WINDOW_W - 244, 342) : pos;
    i == 4 ? pos = ini_vector(WINDOW_W - 244, 880) : pos;
    i == 5 ? pos = ini_vector(WINDOW_W - 98, 880) : pos;
    return (pos);
}

my_sprite_t *set_tower_button(void)
{
    my_sprite_t *my_button = NULL;
    sfTexture *texture = NULL;
    sfIntRect rect;
    sfVector2f pos;

    my_button = malloc(sizeof(my_sprite_t) * 7);
    if (my_button == NULL)
        return (NULL);
    my_button[6].sprite = NULL;
    texture = sfTexture_createFromFile(IMG_BUTTON_TOWER, NULL);
    rect = ini_rect(0, 0, BUTTON_TOWER_W, BUTTON_TOWER_H);
    for (int i = 0 ; i < 6 ; i++) {
        my_button[i] = set_sprite(texture, get_tower_pos(i), SCALE);
        sfSprite_setTextureRect(my_button[i].sprite, rect);
        my_button[i].rect = rect;
        rect.left += BUTTON_TOWER_W;
        pos = ini_vector(BUTTON_TOWER_W / 2, 0);
        sfSprite_setOrigin(my_button[i].sprite, pos);
    }
    return (my_button);
}

void destroy_tower_button(my_sprite_t *button)
{
    for (int i = 0 ; button[i].sprite != NULL ; i++) {
        sfSprite_destroy(button[i].sprite);
    }
    free(button);
}
