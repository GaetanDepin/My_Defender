/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** set_tower_texture
*/

#include <stdlib.h>
#include "defender.h"

static my_texture_t create_tower_texture(img_data_t img_data)
{
    my_texture_t texture;

    texture.texture = sfTexture_createFromFile(img_data.filepath, NULL);
    texture.w = img_data.w;
    texture.h = img_data.h;
    texture.max_w = img_data.img_w;
    return (texture);
}

my_texture_t *set_tower_texture(void)
{
    my_texture_t *tower_texture = NULL;

    if ((tower_texture = malloc(sizeof(my_texture_t) * 5)) == NULL)
        return (NULL);
    tower_texture[4].texture = NULL;
    tower_texture[0] = create_tower_texture(POISON_IDLE);
    tower_texture[1] = create_tower_texture(FIRE_IDLE);
    tower_texture[2] = create_tower_texture(STORM_IDLE);
    tower_texture[3] = create_tower_texture(ICE_IDLE);
    return (tower_texture);
}
