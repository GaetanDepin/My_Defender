/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** load_monster_texutre
*/

#include <stdlib.h>
#include "defender.h"

static anim_texture_t load_texture(img_data_t img)
{
    anim_texture_t temp;

    temp.texture = sfTexture_createFromFile(img.filepath, NULL);
    temp.max_w = img.img_w;
    temp.w = img.w;
    temp.h = img.h;
    return (temp);
}

static void load_all_monster(anim_texture_t *texture)
{
    texture[0] = load_texture(MONSTER_BLUE_D);
    texture[1] = load_texture(MONSTER_BLUE_U);
    texture[2] = load_texture(MONSTER_BLUE_L);
    texture[3] = load_texture(MONSTER_BLUE_R);
    texture[4] = load_texture(MONSTER_BLUE_DEATH);
    texture[5] = load_texture(MONSTER_PURPLE_D);
    texture[6] = load_texture(MONSTER_PURPLE_U);
    texture[7] = load_texture(MONSTER_PURPLE_L);
    texture[8] = load_texture(MONSTER_PURPLE_R);
    texture[9] = load_texture(MONSTER_PURPLE_DEATH);
    texture[10] = load_texture(MONSTER_GREEN_D);
    texture[11] = load_texture(MONSTER_GREEN_U);
    texture[12] = load_texture(MONSTER_GREEN_L);
    texture[13] = load_texture(MONSTER_GREEN_R);
    texture[14] = load_texture(MONSTER_GREEN_DEATH);
    texture[15] = load_texture(MONSTER_RED_D);
    texture[16] = load_texture(MONSTER_RED_U);
    texture[17] = load_texture(MONSTER_RED_L);
    texture[18] = load_texture(MONSTER_RED_R);
    texture[19] = load_texture(MONSTER_RED_DEATH);
}

anim_texture_t *load_monster_texture(void)
{
    anim_texture_t *temp = NULL;

    if ((temp = malloc(sizeof(anim_texture_t) * 21)) == NULL)
        return (NULL);
    temp[20].texture = NULL;
    load_all_monster(temp);
    return (temp);
}
