/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** update the tool bar data
*/

#include "defender.h"

void tool_bar_data(gameloop_t *gameloop)
{
    char *text;

    text = mitoa(gameloop->gold.nb);
    text = str_cat(text, " $\0");
    sfText_setString(gameloop->gold.text, text);
    set_origin_text(gameloop->gold.text);
    text = mitoa(gameloop->score.nb);
    sfText_setString(gameloop->score.text, text);
    set_origin_text(gameloop->score.text);
    text = mitoa(gameloop->hp.nb);
    sfText_setString(gameloop->hp.text, text);
}
