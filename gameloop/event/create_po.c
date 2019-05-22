/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** Create the po rectangle
*/

#include "defender.h"

sfRectangleShape *create_po(int po, sfColor color, sfSprite *sprite)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f pos = sfSprite_getPosition(sprite);

    pos.x -= po * 83 + 1;
    pos.y -= po * 83 - 68;
    po = (1 + (po * 2)) * 83;
    sfRectangleShape_setSize(rect, ini_vector(po, po));
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setPosition(rect, pos);
    return (rect);
}
