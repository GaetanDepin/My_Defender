/*
** EPITECH PROJECT, 2019
** my defender
** File description:
** Parser use in load_map
*/

#include "defender.h"

int tower_parser(char flag, tower_t *tower)
{
    (*tower).sprite.sprite = NULL;
    switch (flag) {
    case '1':
        (*tower).is_empty = true;
        return (SUCCESS);
    case '2':
    case '3':
    case '8':
    case '9':
        (*tower).is_empty = false;
        return (SUCCESS);
    }
    return (ERROR);
}
