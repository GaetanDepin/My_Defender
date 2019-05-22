/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** text initialisation
*/

#include "defender.h"

text_t ini_text(char const *path, int nb, sfVector2f pos)
{
    text_t text;

    text.nb = nb;
    text.font = sfFont_createFromFile(path);
    text.text = sfText_create();
    sfText_setString(text.text, "0");
    sfText_setFont(text.text, text.font);
    sfText_setCharacterSize(text.text, 50);
    sfText_setPosition(text.text, pos);
    return (text);
}
