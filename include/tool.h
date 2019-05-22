/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** tool
*/

#ifndef TOOL_H_
#define TOOL_H_

#include "defender.h"

//Basic lib function
int mstrlen(char *str);
int mputchar(char c);
int mputstr(char *str);
int mputerror(char *str);

//Initialisator
sfIntRect ini_rect(int x, int y, int width, int height);
sfVector2f ini_vector(float fact_x, float fact_y);
sfColor ini_color(int r, int g, int b, int a);
sfRectangleShape *ini_rectangle(int width, int height);
text_t ini_text(char const  *path, int nb, sfVector2f pos);

//Convertor
float time_to_second(sfClock *clock);
char *mitoa(int nbr);
char *str_cat(char *str1, char *str2);

//Sprite gestion
my_sprite_t set_sprite(sfTexture *texture, sfVector2f pos, float scale);
void move_rect(sfIntRect *rect, int offset, int max_value);
void set_origin_text(sfText *text);

// Button
button_t create_button(img_data_t bg, char *str, sfFont *font, int font_size);
void display_button(sfRenderWindow *win, button_t button);
void change_button_pos(button_t *button, sfVector2f pos);
void button_is_over(sfRenderWindow *win, button_t *button, float s, sfMusic *m);
void free_button(button_t button);

#endif /* !TOOL_H_ */
