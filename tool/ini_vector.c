/*
** EPITECH PROJECT, 2019
** Zomby
** File description:
** Vector initialization
*/

#include "tool.h"

sfVector2f ini_vector(float fact_x, float fact_y)
{
    sfVector2f vector;

    vector.x = fact_x;
    vector.y = fact_y;
    return (vector);
}
