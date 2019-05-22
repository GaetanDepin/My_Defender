/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button
*/

#include "defender.h"
#include "img_data.h"
#include "tool.h"

button_t create_button(img_data_t bg, char *str, sfFont *font, int font_size)
{
    button_t button;
    sfFloatRect rect;

    button.bg = sfTexture_createFromFile(bg.filepath, NULL);
    button.sprite = sfSprite_create();
    button.text = sfText_create();
    button.rect = ini_rect(0, 0, bg.w, bg.h);
    button.scale = 0;
    sfSprite_setTexture(button.sprite, button.bg, sfTrue);
    sfSprite_setTextureRect(button.sprite, button.rect);
    sfSprite_setOrigin(button.sprite, ini_vector(bg.w / 2, bg.h / 2));
    sfSprite_setPosition(button.sprite, ini_vector(WINDOW_W/2, WINDOW_H/2));
    sfText_setColor(button.text, sfWhite);
    sfText_setFont(button.text, font);
    sfText_setString(button.text, str);
    sfText_setCharacterSize(button.text, font_size);
    rect = sfText_getLocalBounds(button.text);
    sfText_setOrigin(button.text, ini_vector(rect.width/2, rect.height));
    sfText_setPosition(button.text, ini_vector(WINDOW_W/2, WINDOW_H/2));
    return (button);
}

void change_button_pos(button_t *button, sfVector2f pos)
{
    sfSprite_setPosition(button->sprite, pos);
    sfText_setPosition(button->text, pos);
}

void display_button(sfRenderWindow *win, button_t button)
{
    sfRenderWindow_drawSprite(win, button.sprite, NULL);
    sfRenderWindow_drawText(win, button.text, NULL);
}

void button_is_over(sfRenderWindow *win, button_t *button, float s, sfMusic *m)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);
    sfVector2f scale = sfSprite_getScale(button->sprite);

    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        if (scale.x == 1)
            sfMusic_play(m);
        if (scale.x < s)
            button->scale = 0.08;
        else
            button->scale = 0;
    } else {
        if (scale.x > 1)
            button->scale = -0.08;
        else
            button->scale = 0;
    }
    scale = ini_vector(scale.x + button->scale, scale.y + button->scale);
    sfSprite_setScale(button->sprite, scale);
    sfText_setScale(button->text, scale);
}

void free_button(button_t button)
{
    sfText_destroy(button.text);
    sfSprite_destroy(button.sprite);
    sfTexture_destroy(button.bg);
}