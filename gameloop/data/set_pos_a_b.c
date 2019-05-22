/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** set pa and pb
*/

#include "defender.h"

sfVector2i set_pa(sfVector2f pos, sfVector2i c)
{
    sfVector2i pa;

    pa.x = ((int)pos.x - c.x + 10) / 83;
    pa.y = ((int)pos.y + 10 - c.y) / 83;
    return (pa);
}

sfVector2i set_pb(sfVector2f pos, sfVector2i c)
{
    sfVector2i pb;

    pb.x = ((int)pos.x - c.x + 73) / 83;
    pb.y = ((int)pos.y + 73 - c.y) / 83;
    return (pb);
}
