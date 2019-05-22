/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display the tower po
*/

#include "defender.h"

//NORM

static void display_po_draw(sfRenderWindow *window, tower_t tower)
{
    if (tower.sprite.sprite != NULL)
        sfRenderWindow_drawRectangleShape(window, tower.po, NULL);
}

int display_po(sfRenderWindow *window, my_sprite_t **sprite, tower_t **tower)
{
    for (int i = 0 ; sprite[i] != NULL ; i++)
        for (int ii = 0 ; sprite[i][ii].sprite != NULL ; ii++)
            display_po_draw(window, tower[i][ii]);
}
