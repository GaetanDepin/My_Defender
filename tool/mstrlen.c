/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** mstrlen
*/

int mstrlen(char *str)
{
    int size = 0;

    for ( ; str[size] != '\0' ; size += 1);
    return (size);
}
