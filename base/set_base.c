/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** set the basic elements
*/

#include "defender.h"

static const char *MUSIC = "resource/song/music.ogg";

int set_basic(base_t *base)
{
    if (set_window(&base->window) == ERROR)
        return (ERROR);
    base->path_map = "map";
    base->music = sfMusic_createFromFile(MUSIC);
    sfMusic_setLoop(base->music, sfTrue);
    return (SUCCESS);
}
